/*
Binding: method travels up the tree to the superclass of the object's class. The first method found in the hierarchy takes precedence

Static biding: without 'virtual' keyword, message-method binding happens at compile time.
Dynamic binding: 

*/


#include "bear.h"
#include "mommabear.h"

void Foo(Bear *aBear);
void Bar(Mommabear *aMommabear);

int main(){
    
    Bear *bear;
    Mommabear *mom = new Mommabear(100);
    // lecture 8
    bear=mom; //okay
    // mom = bear; // not okay    
    
    // Foo(mom);
    // Bar(bear); // ---------> not okay
    /* 한마디로, mom이 쳐들어가는건 괜찮다.*/

    bear.Meanness();

    return 0;

}