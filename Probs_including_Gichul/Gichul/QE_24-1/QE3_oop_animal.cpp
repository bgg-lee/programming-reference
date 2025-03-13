#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    static int aniNum;
    virtual string get_name(){return "Animal";};
    virtual int get_weight(){return 0;};
    Animal(){
        aniNum ++ ;
    }
    virtual ~Animal(){
        aniNum -- ;
    }
};

int Animal::aniNum = 0; // 이렇게 해주는 구나

class Dog : public Animal{
public:
    string get_name() override{
        return "Dog";
    };
    int get_weight() override{
        return 10;
    };
    // ~Dog()  {aniNum = 123;} // 내 test
};

class Pug : public Dog{
public:
    string get_name(){return "Pug";};
    int get_weight() override {
        return 20;
    }
    // ~Pug()  {aniNum = 999;} // 내 test

};


int main(void){

    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Pug();
    cout << "Number of animals: " << Animal::aniNum << endl;

    for(int i; i<3; i++){
        cout << "Name: " << animals[i]->get_name() << ", Weight: "<< animals[i]->get_weight() << " kg\n";
    }

    for(int i=0; i<3; i++){
        delete animals[i];
    }
    cout << "Number of animals: " << Animal::aniNum << endl;
    return 0;
}