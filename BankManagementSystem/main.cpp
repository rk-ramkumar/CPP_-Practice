
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
const std::string filePath = "temp/accounts.json";

class Account{
    private:
        static int NextId;
        int id;
        int balance;
        int minimumBalance;
        std::string holderName;
        char type;

    public:
        Account(std::string name, char t, int initialPayment = 0, int minBal = 0): holderName(name), type(t), balance(initialPayment), minimumBalance(minBal) {
            id = NextId++;
        }
        
        virtual void withdraw(int amount)
        {
            if(amount <= 0)
            {
                std::cout << "Please Enter a Valid Amount\n";
                return;
            }
            if(amount > balance || balance - amount < minimumBalance){
                std::cout << "Withdrawal failed! Insufficient funds.\n";
            }else{
                balance -= amount;
                std::cout << holderName << " withdrew " << amount << ". Remaining Balance: " << balance << "\n";
            }
        };
        void deposit(int amount)
        {
            if(amount <= 0)
            {
                std::cout << "Please Enter a Valid Amount\n";
                return;
            }
            balance += amount;
            std::cout << holderName << " deposited " << amount << ". New Balance: " << balance << "\n";
        };
        void checkBalance() const
        {
            std::cout << "Account Holder: " << holderName << ".\nBalance: " << balance << "\n";
        };

        json toJson() const {
            return json{ {"id", id}, {"holderName", holderName}, {"balance", balance}, {"type", std::string(1, type)} };
        }

       
        int getId() const { return id; };
        void setId(int newId) { id = newId; };
        std::string getName() const { return holderName; };
        static void setNextId(int newId) { NextId = newId; }
};

int Account::NextId = 1000;

class CurrentAccount: public Account 
{
    public:
        CurrentAccount(std::string name, int initialPayment = 0, int minBal = 1000): Account(name, 'C', initialPayment, minBal) {};
};

class SavingAccount: public Account 
{
    public:
        SavingAccount(std::string name, int initialPayment = 0, int minBal = 0, int rate = 5, int limit = 10): 
        Account(name, 'S', initialPayment, minBal), interestRate(rate), transactionLimit(limit) {}

        void withdraw(int amount) override{
            static int transactions = 0;
            if (transactions >= transactionLimit){
                std::cout << "Withdrawal failed! Transaction limit exceeded.\n";
                return;
            }

            Account::withdraw(amount);
            transactions++;
        }
    private:
        int interestRate;
        int transactionLimit;
};

class Bank
{
    private:
        std::vector<std::unique_ptr<Account>> accounts;
    
    public:
        void createAccount()
        {
            std::string name;
            int type, initialDeposit;

            std::cout << "Enter Account Holder Name: ";
            std::cin >> name;
            std::cout << "Enter Initial Deposit: ";
            std::cin >> initialDeposit;
            std::cout << "Select Account Type (1 = Current, 2 = Savings): ";
            std::cin >> type;

            std::unique_ptr<Account> newAccount = nullptr;
            
            switch (type) {
                case 1: accounts.push_back(std::make_unique<CurrentAccount>(name, initialDeposit)); break;
                case 2: accounts.push_back(std::make_unique<SavingAccount>(name, initialDeposit)); break;
                default: std::cout << "Invalid Choice!\n"; return;
            }
            std::cout << "Account Created Successfully! Account ID: " << accounts.back()->getId() << "\n";
        }

        void updateAccount()
        {
            int updateId;
            int choice, amount;
            std::cout << "Enter Account ID to update:";
            std::cin >> updateId;

            Account* acc = findAccount(updateId);

            if(!acc){
                std::cout << "Account not found!\n";
                return;
            }

            std::cout << "1. Deposit\n2. Withdraw\nEnter your choice: ";
            std::cin >> choice;

            std::cout << "Enter Amount: ";
            std::cin >> amount;

            if (choice == 1) {
                acc->deposit(amount);
            } else if (choice == 2) {
                acc->withdraw(amount);
            } else {
                std::cout << "Invalid choice!\n";
            }
        };
        void deleteAccount() {
            int id;
            std::cout << "Enter Account ID to delete: ";
            std::cin >> id;
            auto it = std::find_if(accounts.begin(), accounts.end(),[&](const std::unique_ptr<Account>& acc){
                return acc->getId() == id;
            });

            if(it == accounts.end()){
                std::cout << "Account not found!\n";
                return;
            }
            accounts.erase(it);
            std::cout << "Account deleted successfully!\n";    
        };

        void displayAccounts() {
            if (accounts.empty()) {
                std::cout << "No accounts available!\n";
                return;
            }
    
            for (const auto& acc : accounts) {
                acc->checkBalance();
                std::cout << "----------------------\n";
            }
        }

        Account* findAccount(int id)
        {
            for(std::unique_ptr<Account> &account: accounts)
            {
                if(id == account->getId())
                {
                    return account.get();
                }
            };

            return nullptr;
        };
        void saveAccountsToJson();
        void loadAccountsFromJson();
};

void Bank::saveAccountsToJson()
{
    json jArray;
    for (const auto& acc : accounts)
    {
        jArray.push_back(acc->toJson());
    }

    std::ofstream file(filePath);
    file << jArray.dump(4);
    file.close();
    std::cout << "Accounts saved successfully!\n";
};

void Bank::loadAccountsFromJson()
{
    std::ifstream file(filePath);

    if (!file) {
        std::cout << "No previous accounts found.\n";
        return;
    }
    json jArray{};
    file >> jArray;
    file.close();
    accounts.clear();

    int maxId = 0;

    for (const auto& j : jArray)
    {
        std::string name = j["holderName"];
        int balance = j["balance"];
        int id = j["id"];
        char accType = j["type"].get<std::string>()[0];

        maxId = std::max(maxId, id);
        if (accType == 'C') {
            auto acc = std::make_unique<CurrentAccount>(name, balance);
            acc->setId(id);  // Restore ID
            accounts.push_back(std::move(acc));
        }
        else if (accType == 'S') {
            auto acc = std::make_unique<SavingAccount>(name, balance);
            acc->setId(id);  // Restore ID
            accounts.push_back(std::move(acc));
        }
    }
    Account::setNextId(maxId + 1);
    std::cout << "Accounts loaded successfully!\n";
}
int main()
{
    Bank bank;
    int choice;
    bank.loadAccountsFromJson();
    while (true) {
        std::cout << "\n--- Bank Management System ---\n";
        std::cout << "1. Create Account\n2. Update Account\n3. Delete Account\n4. Display Accounts\n5. Save & Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.updateAccount(); break;
            case 3: bank.deleteAccount(); break;
            case 4: bank.displayAccounts(); break;
            case 5: bank.saveAccountsToJson(); return 0;
            default: std::cout << "Invalid choice!\n";
        }
    }
    return 0;
}