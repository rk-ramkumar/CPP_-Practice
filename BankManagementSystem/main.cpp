
#include <string>

class Account{
    public:
        std::string holderName;
        int id;
        
        void withdraw(int amount);
        void deposit(int amount);
        void checkBalance();
        
    protected:
        int balance;
};

int main()
{
    return 0;
}