
#include <iostream>
#include <string>

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