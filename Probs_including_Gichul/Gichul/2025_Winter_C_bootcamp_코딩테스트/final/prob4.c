#include <stdio.h>
#include <stdlib.h>

/* implement Car structure */
typedef struct Car {
    /*Write your code here*/
    int car_id;
    float distance;
    float fuel;
    float mileage;
    ////////////////////////
} Car;

/* implement set_mileage() */
void set_mileage(Car *car){
    /*Write your code here*/
    if(car->fuel == 0){
        car->mileage == 0;
        return;
    }
    car->mileage = car->distance / car->fuel;
    ////////////////////////
}


// Do not modify below (whole main function) //
int main(int argc, char * argv[]){
    if((argc-1)%3!=0) {
        printf("Invalid Input");
        return 0;
    }
    
    /* structure array initialization start */
    int num_cars = (argc-1)/3;
    Car cars[num_cars];

    for (int i=0; i<num_cars; i++) {
        cars[i].car_id = atoi(argv[i*3+1]);
        cars[i].distance = atof(argv[i*3+2]);
        cars[i].fuel = (float) atof(argv[i*3+3]);
        cars[i].mileage = 0.0;
    }
    /* structure array initialization end */

    for (int j=0; j<num_cars; j++) {
        set_mileage(cars+j);
    }

    for (int k=0; k<num_cars; k++) {
        printf("Car ID: %d, Mileage: %.2f km/l\n", cars[k].car_id, cars[k].mileage);
    }
}