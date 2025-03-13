#include <iostream>
#include <iomanip>
using namespace std;

/*

Write your code here.

*/


// Main function to test the hybrid engine system
int main() {
    cout << std::fixed << setprecision(1);

    GasolineEngine gasoline(20);
    gasoline.startEngine();
    cout << "Fuel consumption is " << gasoline.computeFuelConsumption(100) << " liters." << endl;

    // Create a HybridEngine object
    HybridEngine hybrid(18.5, 15.0, 7.0, true);

    // Start the hybrid engine
    hybrid.startEngine();

    // Display engine specifications
    hybrid.displaySpecs();

    // Compute power used for a given distance
    hybrid.computeTotalPowerConsumption(100);

    HybridEngine hybrid2(18.5, 15.0, 7.0, false);
    hybrid2.startEngine();
    hybrid2.displaySpecs();
    hybrid2.computeTotalPowerConsumption(100);

    return 0;
}