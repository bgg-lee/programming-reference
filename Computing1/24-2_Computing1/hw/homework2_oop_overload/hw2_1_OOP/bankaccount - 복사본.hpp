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

class BankAccount {
protected:
    double balance;
    std::vector<Transaction> transactionHistory;

public:
    /*============================= Q 1.1.1 =============================*/
    // TODO


    /*============================= Q 1.1.2 =============================*/
    // TODO


    /*============================= Q 1.1.3 =============================*/
    // TODO


    /*============================= Q 1.1.4 =============================*/
    // TODO


    /*============================= Q 1.1.5 =============================*/
    // TODO


    // Do not modify this section.
    virtual ~BankAccount() {}
};


class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    /*============================= Q 1.2.1 =============================*/
    // TODO


    /*============================= Q 1.2.2 =============================*/
    // TODO


    /*============================= Q 1.2.3 =============================*/
    // TODO

};


class CheckingAccount : public BankAccount {
private:
    double transactionFee;

public:
    /*============================= Q 1.3.1 =============================*/
    // TODO


    /*============================= Q 1.3.2 =============================*/ 
    // TODO


    /*============================= Q 1.3.3 =============================*/
    // TODO

};


class BusinessAccount : public BankAccount {
private:
    double creditLine;

public:
    /*============================= Q 1.4.1 =============================*/
    // TODO


    /*============================= Q 1.4.2 =============================*/
    // TODO


    /*============================= Q 1.4.3 =============================*/
    // TODO

};

class AccountManager {
private:
    std::vector<std::shared_ptr<BankAccount>> accounts;

public:
    /*============================= Q 1.5.1 =============================*/
    // TODO


    /*============================= Q 1.5.2 =============================*/
    // TODO


    /*============================= Q 1.5.3 =============================*/
    // TODO


};

#endif  // BANKACCOUNT_HPP
