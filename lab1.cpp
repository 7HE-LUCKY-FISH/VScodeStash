#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Account {
protected:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance > 0.0 ? initialBalance : 0.0) {
        if (initialBalance < 0.0) {
            cout << "Error: Initial balance was invalid." << endl;
        }
    }

    virtual void credit(double amount) {
        if(amount <0){
            cout<<"Cannot set withdraw to negative. Setting deposit to 0"<<endl;
            amount =0.0;
        };
        balance += amount;
    }

    virtual bool debit(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    double getBalance() const {
        return balance;
    }

    virtual void display() const = 0; // Making Account an abstract base class

    virtual ~Account() = default; // Virtual destructor for polymorphic use
};



class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance), interestRate(rate) {}

    double calculateInterest() const {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "Savings Account Balance: " << getBalance() << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};
class CheckingAccount : public Account {
private:
    double transactionFee;

    void chargeFee() {
        balance -= transactionFee;
    }

public:
    CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance), transactionFee(fee) {}

    void credit(double amount) override {
        Account::credit(amount);
        chargeFee();
    }

    bool debit(double amount) override {
        bool success = Account::debit(amount);
        if (success) {
            chargeFee();
            return true;
        }
        return false;
    }

    void display() const override {
        cout << "Checking Account Balance: " << getBalance() << endl;
        cout << "Transaction Fee: " << transactionFee << endl;
    }
};

int main() {
    vector<unique_ptr<Account>> accounts;

    // Example accounts added to the vector
    accounts.push_back(make_unique<SavingsAccount>(1000, 3)); // $1000 balance, 3% interest
    accounts.push_back(make_unique<CheckingAccount>(500, 1)); // $500 balance, $1 transaction fee

    double amount;
    for (auto& account : accounts) {
        account->display();

        cout << "Enter amount to deposit: ";
        cin >> amount;
        account->credit(amount);

        cout << "Enter amount to withdraw: ";
        cin >> amount;
        account->debit(amount);

        // Check if account is a SavingsAccount and apply interest
        SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*>(account.get());
        if (savingsAccount) {
            double interest = savingsAccount->calculateInterest();
            savingsAccount->credit(interest);
            cout << "Interest added: " << interest << endl;
        }
        cout << "Updated ";
        account->display();
        cout << endl;
    }
    return 0;
}


