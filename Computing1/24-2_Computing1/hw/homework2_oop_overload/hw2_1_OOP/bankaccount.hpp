#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <iostream>
#include <fstream>

struct Transaction {
    double deposit;
    double withdraw;
    double balance;
};

using namespace std;

class BankAccount {
protected:
    double balance;
    std::vector<Transaction> transactionHistory;

public:
    /*============================= Q 1.1.1 =============================*/
    // TODO
    BankAccount(double initialBalance):balance(initialBalance){};
    /*============================= Q 1.1.2 =============================*/
    // TODO
    virtual void deposit(const double amount){
        balance += amount; // 현재 Balance 증가
        Transaction Tx; // 이렇게 Tx 로그 기록하는 게 맞나?
        Tx.withdraw = 0;
        Tx.deposit = amount;
        Tx.balance = balance;
        // log 기록
        transactionHistory.push_back(Tx);
    }
    /*============================= Q 1.1.3 =============================*/
    // TODO
    virtual void withdraw(const double amount) {
        // Widtdraw 실패 Case
        Transaction Tx;
        if(amount > balance){
            Tx.deposit = 0;
            Tx.withdraw = 0;
            Tx.balance = balance;
        }
        // Withdraw 성공
        else{
            balance -= amount;
            Tx.deposit = 0;
            Tx.withdraw = amount;
            Tx.balance = balance;            
        }
        // Log 기록
        transactionHistory.push_back(Tx);
    }
    /*============================= Q 1.1.4 =============================*/
    // TODO
    double getBalance() const{
        return balance;
    }
    /*============================= Q 1.1.5 =============================*/
    // TODO
    const vector<Transaction> getTransactionHistory(){
        return transactionHistory;
    }
    // Do not modify this section.
    virtual ~BankAccount() {}
};


class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    /*============================= Q 1.2.1 =============================
    Implement a constructor for the SavingsAccount class. This constructor should initialize
    the BankAccount base class with an initial balance and store the interest rate in the
    interestRate variable.
    */
    // TODO, 엄마Class base로 constructor를 어케 만들지..
    SavingsAccount(double initialBalance, double rate):interestRate(rate),BankAccount(initialBalance){};
    /*============================= Q 1.2.2 =============================*/
    // TODO
    // Derived에서 override하려면 base에서 virtual로 method가 선언되어 있어야 허네 ;;
    void deposit(double amount) override{
        balance += (amount + amount*interestRate);
        Transaction Tx;
        Tx.deposit = amount + amount * interestRate;
        Tx.withdraw = 0;
        Tx.balance = balance;
        transactionHistory.push_back(Tx);
    }
    /*============================= Q 1.2.3 =============================*/
    // TODO
    ~SavingsAccount(){
        cout << "SavingsAccount closed!!" << endl;
    }
};


class CheckingAccount : public BankAccount {
private:
    double transactionFee;

public:
    /*============================= Q 1.3.1 =============================*/
    // TODO
    CheckingAccount(double initialBalance,double fee):transactionFee(fee),BankAccount(initialBalance){};
    /*============================= Q 1.3.2 =============================*/ 
    // TODO
    void withdraw(double amount) override {
        Transaction Tx;
        // 실패 case
        if(balance < amount+transactionFee){
            Tx.balance = balance;
            Tx.deposit = 0;
            Tx.withdraw = 0;
        }//성공 case
        else{
            balance -= (amount + transactionFee);
            Tx.balance = balance;
            Tx.deposit = 0;
            Tx.withdraw = amount + transactionFee;                        
        }
        transactionHistory.push_back(Tx);
    }
    /*============================= Q 1.3.3 =============================*/
    // TODO
    ~CheckingAccount(){
        cout << "CheckingAccount Closed!!!" << endl;
    }
};


class BusinessAccount : public BankAccount {
private:
    double creditLine;

public:
    /*============================= Q 1.4.1 =============================*/
    // TODO
    BusinessAccount(double initialBalance,double credit):creditLine(credit),BankAccount(initialBalance){};
    /*============================= Q 1.4.2 =============================*/
    // TODO
    // Override하려고 하는 Base함수에 const 같은 거 없으면 override 할 때도 당연히 const 못 쓴다. 즉 base-derived 함수 내에서 form을 똑같이 맞춰야 한다.
    void withdraw(double amount) override{ 
        Transaction Tx;
        //실패 case
        if(amount > balance + creditLine){
            Tx.deposit = 0;
            Tx.withdraw = 0;
            Tx.balance = balance;
        }
        // 성공 case
        else{
            balance -= amount;
            Tx.deposit = 0;
            Tx.withdraw = amount;
            Tx.balance = balance;
        }
        transactionHistory.push_back(Tx);
    }

    /*============================= Q 1.4.3 =============================*/
    // TODO
    ~BusinessAccount(){
        cout << "BusinessAccount closed!!!" << endl;
    }
};
// Shared Pointer 문제다.. -_- ;;
class AccountManager {
private:
    std::vector<std::shared_ptr<BankAccount>> accounts;
public:
    /*============================= Q 1.5.1 =============================*/
    // TODO
    void addAccount(const shared_ptr<BankAccount>& account){
        accounts.push_back(account);
    }
    /*============================= Q 1.5.2 =============================*/
    // TODO
    // Invalid index에 대해서 throw는 우찌 날릴꼬..
    void transferFunds(int fromIndex,int toIndex,double amount){
        //throw case
        int n = accounts.size();
        if(fromIndex<0||toIndex<0||fromIndex>=n||toIndex>=n){
            throw runtime_error("Invalid account index!!!");
            // return; //필요? NOPE
        }
        shared_ptr<BankAccount> from = accounts[fromIndex];
        shared_ptr<BankAccount> to = accounts[toIndex];
        // Withdraw 실패 case
        if(from -> getBalance() < amount) return;
        // Withdraw 성공 case
        from -> withdraw(amount);
        to -> deposit(amount);
    }

    /*============================= Q 1.5.3 =============================*/
    // TODO
    shared_ptr<BankAccount> getAccount(int idx){
        int n = accounts.size();
        //throw case
        if(idx < 0 || idx > n-1) throw runtime_error("Invalid idx!!");
        //정상 case
        return accounts[idx];
    }
};

#endif  // BANKACCOUNT_HPP



/*
GPT 풀이
#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <vector>
#include <iostream>
#include <memory>
#include <stdexcept>

// Structure to store transaction details
struct Transaction {
    double deposit;  // Amount deposited
    double withdraw; // Amount withdrawn
    double balance;  // Account balance after transaction
};

// Base class representing a generic bank account
class BankAccount {
protected:
    double balance;  // Current account balance
    std::vector<Transaction> transactionHistory; // List of transactions

public:
    // Constructor to initialize account balance
    BankAccount(double initialBalance) : balance(initialBalance) {}

    virtual ~BankAccount() {}

    // Method to deposit an amount into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back({amount, 0, balance});
        }
    }

    // Method to withdraw an amount from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory.push_back({0, amount, balance});
        } else {
            transactionHistory.push_back({0, 0, balance}); // Log failed withdrawal attempt
        }
    }

    // Method to retrieve the current balance
    double getBalance() const {
        return balance;
    }

    // Method to retrieve transaction history
    const std::vector<Transaction>& getTransactionHistory() const {
        return transactionHistory;
    }
};

// Derived class representing a savings account with interest
class SavingsAccount : public BankAccount {
private:
    double interestRate; // Interest rate applied to deposits

public:
    // Constructor to initialize savings account with balance and interest rate
    SavingsAccount(double initialBalance, double rate) : BankAccount(initialBalance), interestRate(rate) {}

    ~SavingsAccount() {
        std::cout << "SavingsAccount closed" << std::endl;
    }

    // Override deposit method to include interest
    void deposit(double amount) override {
        if (amount > 0) {
            double interest = amount * interestRate;
            balance += (amount + interest);
            transactionHistory.push_back({amount + interest, 0, balance});
        }
    }
};

// Derived class representing a checking account with transaction fees
class CheckingAccount : public BankAccount {
private:
    double transactionFee; // Fee applied per withdrawal

public:
    // Constructor to initialize checking account with balance and transaction fee
    CheckingAccount(double initialBalance, double fee) : BankAccount(initialBalance), transactionFee(fee) {}

    ~CheckingAccount() {
        std::cout << "CheckingAccount closed" << std::endl;
    }

    // Override withdraw method to include transaction fee
    void withdraw(double amount) override {
        if (amount > 0 && (amount + transactionFee) <= balance) {
            balance -= (amount + transactionFee);
            transactionHistory.push_back({0, amount + transactionFee, balance});
        } else {
            transactionHistory.push_back({0, 0, balance}); // Log failed withdrawal attempt
        }
    }
};

// Derived class representing a business account with a credit line
class BusinessAccount : public BankAccount {
private:
    double creditLine; // Available credit line for overdraft

public:
    // Constructor to initialize business account with balance and credit line
    BusinessAccount(double initialBalance, double credit) : BankAccount(initialBalance), creditLine(credit) {}

    ~BusinessAccount() {
        std::cout << "BusinessAccount closed" << std::endl;
    }

    // Override withdraw method to allow overdrafts up to credit line
    void withdraw(double amount) override {
        if (amount > 0 && amount <= (balance + creditLine)) {
            balance -= amount;
            transactionHistory.push_back({0, amount, balance});
        } else {
            transactionHistory.push_back({0, 0, balance}); // Log failed withdrawal attempt
        }
    }
};

// Class responsible for managing multiple accounts
class AccountManager {
private:
    std::vector<std::shared_ptr<BankAccount>> accounts; // List of managed accounts

public:
    // Method to add an account to the manager
    void addAccount(const std::shared_ptr<BankAccount>& account) {
        accounts.push_back(account);
    }

    // Method to transfer funds between accounts
    void transferFunds(int fromIndex, int toIndex, double amount) {
        if (fromIndex < 0 || fromIndex >= accounts.size() || toIndex < 0 || toIndex >= accounts.size()) {
            throw std::runtime_error("Invalid account index");
        }
        if (amount > 0) {
            double initialBalance = accounts[fromIndex]->getBalance();
            accounts[fromIndex]->withdraw(amount);
            if (accounts[fromIndex]->getBalance() < initialBalance) {
                accounts[toIndex]->deposit(amount);
            }
        }
    }

    // Method to retrieve an account by index
    std::shared_ptr<BankAccount> getAccount(int index) {
        if (index < 0 || index >= accounts.size()) {
            throw std::runtime_error("Invalid account index");
        }
        return accounts[index];
    }
};

#endif


*/


/*
1. 업캐스팅과 다운캐스팅 개념
업캐스팅(Upcasting, ✅ 가능)

cpp
복사
편집
std::shared_ptr<BankAccount> acc1 = std::make_shared<SavingsAccount>(1000.0, 0.05);
✅ SavingsAccount 객체를 BankAccount 타입으로 참조하는 것은 업캐스팅이며, 이는 안전합니다.
SavingsAccount는 BankAccount의 모든 멤버를 가지고 있기 때문에 BankAccount처럼 다룰 수 있습니다.
다운캐스팅(Downcasting, ❌ 불가능)

cpp
복사
편집
std::shared_ptr<SavingsAccount> acc1 = std::make_shared<BankAccount>(1000.0);
❌ BankAccount는 SavingsAccount가 아니므로 std::shared_ptr<SavingsAccount>로 변환될 수 없습니다.
BankAccount에는 SavingsAccount에 있는 interestRate 등의 멤버 변수가 없으므로 객체 크기 및 데이터 구조가 다름.
객체가 SavingsAccount 타입이 아니므로, 이를 SavingsAccount로 캐스팅하는 것은 논리적으로 불가능.

*/