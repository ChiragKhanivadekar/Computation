#include <iostream>
#include <cmath>
using namespace std;
int main(){
double h,x,y=2,y2,f,f2;
cout<<"Enter value of interval: ";
cin>>h;
///Euler's method
cout<<"\nUsing Euler's method:\n0\t2\n";
for(x=0;x+h<=4;x=x+h){
    f=4*exp(0.8*x)-0.5*y;
    y=y+f*h;
    cout<<x+h<<"\t"<<y<<endl;
}
///Mid-point method
y=2;
cout<<"\nUsing mid-point method:\n0\t2\n";
for(x=0;x+h<=4;x=x+h){
    f=4*exp(0.8*x)-0.5*y;
    y2=y+f*h/2;
    f=4*exp(0.8*(x+h/2))-0.5*y2;
    y=y+f*h;
    cout<<x+h<<"\t"<<y<<endl;
}
///Heun's method
y=2;
cout<<"\nUsing Heun's method:\n0\t2\n";
for(x=0;x+h<=4;x=x+h){
    f=4*exp(0.8*x)-0.5*y;
    y2=y+f*h;
    f2=4*exp(0.8*(x+h))-0.5*y2;
    y=y+(f+f2)*h/2;
    cout<<x+h<<"\t"<<y<<endl;
}
return 0;
}
