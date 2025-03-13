#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
/*
Write your code here.
*/
    // a
class Engine{
public:
    Engine(){}
    ~Engine(){}
    virtual void startEngine() = 0;
};
    // b
class GasolineEngine : public Engine{
protected :
    float fuelEfficiency;
public:
    GasolineEngine(float f):fuelEfficiency(f){}
    //c
    void startEngine() override{
        cout << "Gasoline engine started."<<endl;;
    }
    float getFuelEfficiency(){return fuelEfficiency;}
    float computeFuelConsumption(float dist){
        return dist/fuelEfficiency;
    }
};
    //d
class HybridEngine : public GasolineEngine{
protected:
    float batteryCapacity;
    float efficiencyFactor;
    bool hybridMode;
public:
    HybridEngine(float fuel, float bat,float eff, bool mode):GasolineEngine(fuel),batteryCapacity(bat),efficiencyFactor(eff),hybridMode(mode){}
    // e
    void startEngine() override{
        cout<<"Hybrid engine started."<<endl; // 줄바꿈도 하는지 언급이 없다.
        GasolineEngine::startEngine(); // 이게 맞나..?
        if(hybridMode){
            cout<<"Electric motor started."<<endl;
        }
    }
    void displaySpecs(){
        cout<<"Hybrid engine specifications:" << endl;
        cout<<"Fuel efficiency: "<< getFuelEfficiency() << endl;
        cout<<"Battery capacity: " << batteryCapacity << endl;
        cout<<"Hybrid mode: ";
        if(hybridMode) cout << "Enabled"<<endl;
        else cout << "Disabled"<<endl;
    }
    float computeBatteryConsumption(float dist){return dist/efficiencyFactor;}
    void computeTotalPowerConsumption(float dist){
        // float total = (computeFuelConsumption(dist)*9.7) + computeBatteryConsumption(dist);
        // hybrid 7 : 3(배터리) , Nope 100:0(배터리)
        cout << "Computing power consumption for "<<dist<<" km:" << endl;
        if(!hybridMode){
            float total = (computeFuelConsumption(dist)*9.7);
            cout << "Fuel used: " << computeFuelConsumption(dist) <<" liters" << endl;
            cout << "Battery used: " << 0.0 <<" kWh" << endl;
            cout << "Total power used: " << total << " kWh"<< endl;
        }else{
            float total = (computeFuelConsumption(dist)*9.7)*0.7 + computeBatteryConsumption(dist)*0.3;
            cout << "Fuel used: " << computeFuelConsumption(dist)* 0.7<<" liters" << endl;
            cout << "Battery used: " << computeBatteryConsumption(dist)* 0.3 <<" kWh" << endl;
            cout << "Total power used: " << total << " kWh"<< endl;            
        }

    }

};

// Main function to test the hybrid engine system
// int main() {
//     cout << std::fixed << setprecision(1);

//     GasolineEngine gasoline(20);
//     gasoline.startEngine(); // 가솔린 start
//     cout << "Fuel consumption is " << gasoline.computeFuelConsumption(100) << " liters." << endl;
//     // 5.0 l litter

//     // Create a HybridEngine object
//     HybridEngine hybrid(18.5, 15.0, 7.0, true);

//     // Start the hybrid engine
//     hybrid.startEngine();

//     // Display engine specifications
//     hybrid.displaySpecs();
//     // fuel 18.5 , battery: 15.0, mode: Enabled
//     cout << endl;
//     // Compute power used for a given distance
//     hybrid.computeTotalPowerConsumption(100);
//     // for 100km, fuel 3.8 liter, battery 3.4kwH, power 41.0kWh
//     HybridEngine hybrid2(18.5, 15.0, 7.0, false);
//     hybrid2.startEngine();
//     hybrid2.displaySpecs();
//     // 18.5 / 15.0
//     cout << endl;
//     hybrid2.computeTotalPowerConsumption(100);
//     // 100, 5.4, 0.0, 52.4
//     return 0;
// }