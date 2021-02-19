/*
Single server single queue simulation
*/
#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[],
                                   int wt[], int at[])
{
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    for (int i = 1; i < n ; i++)
    {
        service_time[i] = service_time[i-1] + bt[i-1];

        wt[i] = service_time[i] - at[i];

        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[],
                                      int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}


void findavgTime(int processes[], int customer_count, int serviceTime[], int arrivalTime[]) {
    int wt[customer_count], tat[customer_count];
    findWaitingTime(processes,customer_count,serviceTime,wt,arrivalTime);
    findTurnAroundTime(processes,customer_count,serviceTime,wt,tat);
    cout << "Processes " << " Service Time " << " Arrival Time "<< " Waiting Time " << " Turn-Around Time "<< " Completion Time \n";
    int total_wt = 0, total_tat = 0;
    for (int i = 0 ; i < customer_count ; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + arrivalTime[i];
        cout << " " << i+1 << "\t\t" << serviceTime[i] << "\t\t"
             << arrivalTime[i] << "\t\t" << wt[i] << "\t\t "
             << tat[i]  <<  "\t\t " << compl_time << endl;
    }

    cout << "Average waiting time = "<< (float)total_wt / (float)customer_count;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)customer_count;

}
int main() {
    int customer_count, arrivalTime[100] = {}, serviceTime[100] = {};
    int serviceBeginAt[100] = {}, serviceEndAt[100], wait[100], processes[100] = {};
    cin>>customer_count;
    for(int i = 1; i < customer_count; i++) {
        int arrivalIn;
        cin>>arrivalIn;
        arrivalTime[i] = arrivalTime[i-1] + arrivalIn;
    }
    for(int i = 0; i < customer_count; i++) {
        cin>>serviceTime[i];
        processes[i] = i+1;
    }
    findavgTime(processes,customer_count,serviceTime,arrivalTime);
    return 0;
}
