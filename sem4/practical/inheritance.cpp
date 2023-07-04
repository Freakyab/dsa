#include <iostream>
#include <string>

using namespace std;

class Accounts{
    protected:
        string name;
        int accountNo;
        double balance;
    public:
        Accounts(string name,int accountNo,double balance){
            this->name = name;
            this->accountNo=accountNo;
            this->balance=balance;
        }
        void deposit(double amount){
            balance +=amount;
            cout << "\n---Details---\n" ;
            cout << "\tAccount no: " << accountNo << "\n\tCredited with Rs: " << amount << "\n\tBalance: Rs"<<balance <<endl;
        }

        void withdraw(double amount){
            if(amount <=balance){
                balance -= amount;
                cout << "\n---Details---\n" ;
                cout << "\tAccount no: " << accountNo << "\n\tDebited with Rs: " << amount << "\n\tBalance: Rs"<<balance <<endl;
            }
            else{
                cout << "Insufficient balance." << endl;
            }
        }
        void display() {
            cout << "---Account details---\n";
            cout << "\tAccount Number: " << accountNo << endl;
            cout << "\tAccount Holder Name: " << name << endl;
            cout << "\tBalance: " << balance << endl;
    }
};

class SavingAcc: public Accounts{
    public:
        SavingAcc(string name,int accountNo,double balance):Accounts(name,accountNo,balance){
            this->name = name;
            this->accountNo = accountNo;
            this->balance =  balance;
        }
        void calculateInterest(){
            double interest = balance * 0.05; // 5% interest rate
            balance += interest;
            cout << "\nInterest calculated and added to the account.\n\n";
        }
};

class CurrentAcc: public Accounts{
    public:
        CurrentAcc(string name,int accountNo,double balance):Accounts(name,accountNo,balance){
            this->name = name;
            this->accountNo = accountNo;
            this->balance =  balance;
        }
        void calculateInterest(){
           cout << "No interest is calculated for current accounts.\n\n";
        }
};

class CreditCardAcc: public Accounts{
    public:
        CreditCardAcc(string name,int accountNo,double balance):Accounts(name,accountNo,balance){
            this->name = name;
            this->accountNo = accountNo;
            this->balance =  balance;
        }
        void calculateInterest(){
            double interest = balance * 0.1; // 5% interest rate
            balance += interest;
            cout << "Interest calculated and added to the account.\n\n";
        }
};

int main() {
    // Creating objects of different account types
    SavingAcc savingsAcc("John Smith", 123, 5000);
    CurrentAcc currentAcc("Jane Doe",456, 10000);
    CreditCardAcc creditCardAcc("David Johnson",789, -2000);

    // Performing operations on the accounts
    savingsAcc.deposit(1000);
    savingsAcc.calculateInterest();
    savingsAcc.display();
    savingsAcc.withdraw(200);

    cout << endl;

    currentAcc.withdraw(500);
    currentAcc.calculateInterest();
    currentAcc.display();

    cout << endl;

    creditCardAcc.withdraw(100);
    creditCardAcc.calculateInterest();
    creditCardAcc.display();

    return 0;
}