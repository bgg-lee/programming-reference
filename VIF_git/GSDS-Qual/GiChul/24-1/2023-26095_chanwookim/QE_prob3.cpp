#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    static int aniNum;
    virtual string get_name(){return "Animal";}
    virtual int get_weight(){return 0;}
    Animal(){aniNum++;}
    ~Animal(){aniNum--;}
};

int Animal::aniNum = 0;

class Dog: public Animal{
public:
    virtual string get_name(){return "Dog";}
    virtual int get_weight(){return 10;}
};

class Pug: public Dog{
public:
    virtual string get_name(){return "Pug";}
    virtual int get_weight(){return 20;}
};


// int main(void){

//     Animal* animals[3];
//     animals[0] = new Animal();
//     animals[1] = new Dog();
//     animals[2] = new Pug();
//     cout << "Number of animals: " << Animal::aniNum << endl;

//     for(int i; i<3; i++){
//         cout << "Name: " << animals[i]->get_name() << ", Weight: "<< animals[i]->get_weight() << " kg\n";
//     }

//     for(int i; i<3; i++){
//         delete animals[i];
//     }
//     cout << "Number of animals: " << Animal::aniNum << endl;
//     return 0;
// }