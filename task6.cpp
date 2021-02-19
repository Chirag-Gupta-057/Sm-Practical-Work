/*
 The problem is to manage a tyre store, where
 we replenish tyre quantities by placing reorders.
 Each reorder takes 3 days to arrive.
 This is repeated for 90 days(initially)
 for set of values of p(reorder level) and
 q(reorder quantity).

*/
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;
int main(){
    const int p = 175;
    const int q = 300;
    const float goodWill = 2.00;
    const float lossSale = 16.00;
    const float lossToday = goodWill + lossSale;
    const float carryCost = 0.75;
    const float reorderCost = 1.25*q;

    int dayToday = 1, currentStock = 115, demandToday = 0, unitsDue = 0, nextOrderOn = 0;
    float totalCost = 0;

    ///srand(time(0));

    while(dayToday <= 180){
        /// check if it's due date for reorder supplies
        if (nextOrderOn == dayToday) {
            currentStock += unitsDue;
            unitsDue = 0;
        }

        /// generate demand today
        demandToday = rand() % 100;

        /// check in inventory for today's demand
        if (demandToday <= currentStock) {
            currentStock -= demandToday;
            totalCost = totalCost + demandToday * carryCost;
        } else {
            totalCost = totalCost + lossToday * (demandToday - currentStock);
            currentStock = 0;
        }

        /// check if there is shortage in inventory
        if (currentStock + unitsDue <= p) {
            unitsDue = q;
            nextOrderOn = dayToday + 3;
            totalCost += reorderCost;
        }
        dayToday++;
    }
    cout<<"Total Cost After 180 Days: Rs."<<totalCost;
    cout<<"\nReorder Level: "<<p<<"\nReorder Quantity: "<<q;
    return 0;
}
