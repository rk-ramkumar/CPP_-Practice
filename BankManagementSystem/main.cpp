
#include <string>

class Account{
    public:
        Account(std::string name, int initialPayment = 0, int minBal = 0): holderName(name), balance(initialPayment), minimumBalance(minBal) {}
        
        void withdraw(int amount);
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
    protected:
        int interestRate;
        int transactionLimit;
};


int main()
{
    return 0;
}