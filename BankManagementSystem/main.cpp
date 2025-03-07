
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
        void deposit(int amount);
        void checkBalance();
        
    protected:
        std::string holderName;
        int id;
        int balance;
        int minimumBalance;
    
};
class CurrentAccount: public Account 
{
    public:
        CurrentAccount(std::string name, int initialPayment = 0): Account(name, initialPayment, 1000) {} ;
};

class SavingAccount: public Account 
{
    public:
        SavingAccount(std::string name, int initialPayment = 0): Account(name, initialPayment) {
            interestRate = 5;
            transactionLimit = 10;
        }
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
    return 0;
}