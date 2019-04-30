#include <iostream>
#include <fstream>
#define Pi 3.14159265359
#define h 0.02*2*Pi
#define L 4*Pi
#define T (2*Pi)
using namespace std;
int main(){
double t,x=1,x2,x3,xn,v=0,v2,v3,vn,fv,fx,E;
ofstream out1,out2,out3,out4;
///Euler's method
out1.open("Euler - total energy.txt");
out2.open("Euler - phase space trajectory.txt");
for(t=0;t<=L;t=t+h){
    E=v*v/2+x*x/2;
    out1<<t/T<<"\t"<<E<<endl;
    out2<<x<<"\t"<<v<<endl;
    vn=v-x*h;
    x=x+v*h;
    v=vn;
}
out1.close();
out2.close();
///RK-4 method
x=1;
v=0;
out3.open("RK-4 - total energy.txt");
out4.open("RK-4 - phase space trajectory.txt");
for(t=0;t<=L;t=t+h){
    E=v*v/2+x*x/2;
    out3<<t/T<<"\t"<<E<<endl;
    out4<<x<<"\t"<<v<<endl;
    v2=v-x*h/2;
    x2=x+v*h/2;
    v3=v-x2*h/2;
    x3=x+v2*h/2;
    vn=v-x3*h;
    xn=x+v3*h;
    fv=-(x+2*x2+2*x3+xn)/6;
    fx=(v+2*v2+2*v3+vn)/6;
    vn=v+fv*h;
    xn=x+fx*h;
    v=vn;
    x=xn;
}
out3.close();
out4.close();
return 0;
}
