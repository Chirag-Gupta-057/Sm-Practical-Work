/*
Write a progran in to simulate the pure pursuit problem finding out
whether the fighter aircraft will be ablt to reach with in the firing
distance from bomber.
*/


#include <bits/stdc++.h>
using namespace std;

inline double distance(double xf, double yf, double xb, double yb){
    return sqrt(pow(yb - yf,2) + pow(xb - xf,2));
}

inline double sineAngle(double yb, double yf, double distance){
    return ((yb - yf)/distance);
}

inline double cosAngle(double xb, double xf, double distance){
    return ((xb - xf)/distance);
}

int main()
{
    int t = 0;
    double xb, yb, xf, yf, vf, dist;
    bool fire;
    cin>>xb>>yb;
    cin>>xf>>yf;
    cin>>vf;
    cout<<"Bomber's coordinates: ("<<xb<<", "<<yb<<")";
    cout<<"\nFighter's coordinates: ("<<xf<<", "<<yf<<")";
    cout<<"\nFighter's velocity: "<<vf<<" mph";
    while(t <= 12) {
        dist = distance(xf,yf,xb,yb);
        if(dist <= 10.0l && t <= 11) {
            cout<<"\nIs Within Range: "<<dist<<" kms at time: "<<t<<" seconds.";
            fire = true;
            break;
        } else if(t > 11) {
            cout<<"\nTarget Escaped!!";
            fire = false;
            break;
        }
        xf = xf + vf * cosAngle(xb, xf, dist);
        yf = yf + vf * sineAngle(yb, yf, dist);
        t += 1;
    }
    return 0;
}
