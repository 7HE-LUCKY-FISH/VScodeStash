#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "CheckingAccount.cpp"
#include "SavingsAccount.cpp"
#include "Account.cpp"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main() {
    vector<Account*> accounts(2);
    // Example accounts added to the vector
    accounts[0] = new SavingsAccount(1000,.03);
    accounts[1] = new CheckingAccount(500,1);
    double amount;
    for(size_t i=0; i<accounts.size(); i++){
        cout<<"Account: "<<accounts[i]->getBalance()<<endl;

        cout << "Enter amount to deposit: ";
        cin >> amount;
        accounts[i]->credit(amount);
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        accounts[i]->debit(amount);
        SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*>(accounts[i]);
        if (savingsAccount) {
            double interest = savingsAccount->calculateInterest();
            savingsAccount->credit(interest);
            cout << "Interest added: " << interest << endl;
        }
        cout << "Updated: "<<accounts[i]->getBalance();
        cout << endl;
    }

    return 0;
}


