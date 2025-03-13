/*

Abstaction(implementation hiding)
Representing essential features without including the unnecessary implementation details


Encapsulation(data hiding)
class 안의 variable들을 숨기는 것. public으로 만든 애들만 접근 가능하도록. setter getter라는 public method로 접근하도록
wrapping up of data and functions into a single unit
focus on provider perspective. company does not allow you to present details.


Inheritance


Polymorphism.

*/

/*
How to compile

ex: g++ -o hw2 main.cpp  Electronics.cpp

*/
#include "bear.h"
#include "mommabear.h"

void Foo(Bear *aBear);
void Bar(Mommabear *aMommabear);

int main(){
    Mommabear::TestBears();

    return 0;

}