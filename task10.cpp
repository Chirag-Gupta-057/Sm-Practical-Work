/*
    Reservoir System simulation using c++
*/
#include<iostream>
using namespace std;
void populateArray(int arr[50][12],int upper, int lower){
    for(int i=0;i<50;i++){
        for(int j=0;j<12;j++){
            arr[i][j] = (rand()%(upper - lower + 1)) + lower;
        }
    }
}
int main(){
    int vin=0,rain[50][12],rflow[50][12],volPrevious=0,tloss=0,
    seep[50][12],evap[50][12],demand[50][12],grossV=0,shortage=0,spill=0,vnet=0,diff=0,
    cap=0,losses=0;
    cap=10000;
    populateArray(rflow,100,10);
    populateArray(seep,20,1);
    populateArray(evap,15,5);
    populateArray(demand,150,50);
    populateArray(rain,10,5);
    for(int i=0;i<50;i++){
        for(int j=0;j<12;j++){
            vin = rain[i][j] + rflow[i][j];
            grossV = vin + volPrevious;
            tloss = seep[i][j] + evap[i][j];
            int dem = demand[i][j];

            if(tloss >= grossV){
                shortage += dem;
                volPrevious = 0;
                spill += 0;
                losses++;

            } else if(tloss<=grossV){

                vnet = grossV - tloss;

                if(dem >= vnet){

                    shortage = shortage + (dem - vnet);
                    spill+=0;
                    volPrevious = vnet;
                    losses++;

                } else if(dem < vnet){
                    diff = vnet - dem;

                    if(diff>cap){

                        spill = spill + (diff - cap);
                        volPrevious = cap;
                        losses++;

                    } else if(diff <= cap){
                        spill += 0;
                        volPrevious = diff;
                    }
                }
            }
        }
    }
    cout<<"Total shortage: "<<shortage<<endl;
    cout<<"Total spill: "<<spill<<endl;
    cout<<"Total fails: "<<losses<<endl;
    return 0;
}
