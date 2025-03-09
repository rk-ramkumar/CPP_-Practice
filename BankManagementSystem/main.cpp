
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Account{
    private:
        static int NextId;
    public:
        Account(std::string name, int initialPayment = 0, int minBal = 0): holderName(name), balance(initialPayment), minimumBalance(minBal) {
            id = NextId++;
        }
        
        virtual void withdraw(int amount)
        {
            if(amount <= 0)
            {
                std::cout << "Please Enter a Valid Amount\n";
                return;
            }
            if(amount > balance or balance - amount < minimumBalance){
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
        void checkBalance()
        {
            std::cout << "Account Holder: " << holderName << ".\nBalance: " << balance << "\n";
        };

        int getId() const { return id; }
        std::string getName() const { return holderName; }
        
    protected:
        std::string holderName;
        int id;
        int balance;
        int minimumBalance;
    
};
class CurrentAccount: public Account 
{
    public:
        CurrentAccount(std::string name, int initialPayment = 0, int minBal = 1000): Account(name, initialPayment, minBal) {} ;
};

class SavingAccount: public Account 
{
    public:
        SavingAccount(std::string name, int initialPayment = 0, int minBal = 0, int rate = 5, int limit = 10): 
        Account(name, initialPayment, minBal), interestRate(rate), transactionLimit(limit) {}

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

int Account::NextId = 1000;

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
                case 1: newAccount = std::make_unique<Account>(name, initialDeposit); break;
                case 2: newAccount = std::make_unique<Account>(name, initialDeposit); break;
                default: std::cout << "Invalid Choice!\n"; return;
            }
            accounts.push_back(std::move(newAccount));
            std::cout << "Account Created Successfully! Account ID: " << newAccount->getId() << "\n";
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
};

int main()
{
    CurrentAccount ca("ram", 2000);
    ca.deposit(500);
    ca.withdraw(1000);
    ca.checkBalance();

    SavingAccount sa("Alice", 3000);
    sa.withdraw(100);
    sa.withdraw(200);
    sa.withdraw(300);
    sa.withdraw(400);
    sa.withdraw(500);
    sa.withdraw(600);
    return 0;
}