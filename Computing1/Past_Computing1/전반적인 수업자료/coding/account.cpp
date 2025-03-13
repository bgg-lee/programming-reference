#include <stdio.h>
#include <stdlib.h>
#include "account.h"

Account::Account(void){
    balance = 0.0;
    transactions = 0;

}

void Account::Withdraw(float amt){
    balance = balance - amt;
    transactions +=1;
};
void Account::Deposit(float amt){
    balance = balance + amt;
    transactions +=1;
};
float Account::GetBalance(float amt){
    return balance;
};
void Account::EndMonthUtil(void){
    printf("End!\n");
}

class MonthlyFee: public Account{
    void EndMonth(void); // 여기에는 왜 virtual 없나요 --> 부모가 그렇게 정의해놓으면 자녀는 자동임. 그치만 헷갈리니까 제발 써라.
};

void MonthlyFee::EndMonth(){
    Withdraw(5);
    Account::EndMonthUtil();  
}

/* 헷갈림 주의
Overloading: compile time, same name,    different argument permutation or return type.     (Compile time poliymorphism)
Overriding: Run time, same name,         same argument sequence and return type.            (Run time polymorphism)
*/