#include "Electronics.h"

// Fill in here
#include <iostream>
using namespace std;

int Electronics::GetSize(){return Size;}
void Electronics::SetSize(int size){Size = size;}

Electronics::Electronics(int size):Size(size){};
TV::TV(int size):Electronics(size){};
Computer::Computer(int size):Electronics(size){};
Cellphone::Cellphone(int size):Electronics(size){};
Laptop::Laptop(int size):Computer(size){};


void TV::PrintSelf(void){ cout << "It is a TV, Size="<<GetSize()<<", Price="<<GetPrice()<<endl;}
void Computer::PrintSelf(void){ cout << "It is a Computer, Size="<<GetSize()<<", Price="<<GetPrice()<<endl;}
void Cellphone::PrintSelf(void){ cout << "It is a Cellphone, Size="<<GetSize()<<", Price="<<GetPrice()<<endl;}
void Laptop::PrintSelf(void){ 
    cout << "It is a Laptop with "<< gpunum<<" GPU(s), Size="<<GetSize()<<", Price="<<GetPrice()<< ", Total Price="<<GetTotalPrice()<<endl;}

float TV::GetPrice(){return 1.8*GetSize();}
float Computer::GetPrice(){return 0.6*GetSize();}
float Cellphone::GetPrice(){return 0.7*GetSize();}
float Laptop::GetPrice(){
    if (gpunum==0){return 0.6*GetSize();}
    else {return 1.2*GetSize();}
}
float Laptop::GetTotalPrice(){
    float price = GetPrice();
    if (gpunum==1){price += gpu1->GetPrice();}
    if (gpunum==2){price += gpu1->GetPrice(); price += gpu2->GetPrice();}
    return price;
}

void Laptop::AddGPU(Electronics *aGPU){
    if (gpunum==0) {gpu1 = aGPU;}
    else if (gpunum==1) {gpu2 = aGPU;}
    else {cout << "we already have "<< gpunum << "GPU(s).";}
    gpunum +=1;
}