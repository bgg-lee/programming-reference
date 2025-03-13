#include <stdio.h>
#include "mommabear.h"
#include <iostream>

using namespace std;
Mommabear::Mommabear(float aWeight) : Bear(aWeight){cub = NULL;}

Bear* Mommabear::GetCub(void){ return cub;}
void Mommabear::SetCub(Bear *aCub){ cub = aCub;}

float Mommabear::Meanness(void){
    return (Bear::Meanness() * 2);
}

float Mommabear::TotalMeanness(void){
    float cubMeanness;
    if (cub!=NULL){
        cubMeanness = cub->Meanness();
    }
    else{
        cubMeanness = 0.0;
    }
    return Meanness() + cubMeanness;
}

void Mommabear::TestBears(){
    Bear *cub;
    Mommabear *mom;
    cub = new Bear(50);
    mom = new Mommabear(300);

    cout << cub->Meanness() << endl;
    cout << mom->Meanness() << endl;
    mom->SetCub(cub);
    cub->SetWeight(75);
    cout << mom->TotalMeanness() << endl;
}
