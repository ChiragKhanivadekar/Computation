#include <iostream>
#define Pi 3.14159265359
#define L 4*Pi
using namespace std;
int main(){
double h,t,x=1,x2,v=0,vn,v2,fv,fx;
cout<<"Enter value of interval: ";
cin>>h;
///Euler's method
cout<<"\nUsing Euler's method:\n";
for(t=0;t<=L;t=t+h){
    cout<<t<<"\t"<<x<<endl;
    vn=v-x*h;
    x=x+v*h;
    v=vn;
}
///Mid-point method
x=1;
v=0;
cout<<"\nUsing mid-point method:\n";
for(t=0;t<=L;t=t+h){
    cout<<t<<"\t"<<x<<endl;
    v2=v-x*h/2;
    x2=x+v*h/2;
    vn=v-x2*h;
    x=x+v2*h;
    v=vn;
}
///Heun's method
x=1;
v=0;
cout<<"\nUsing Heun's method:\n";
for(t=0;t<=L;t=t+h){
    cout<<t<<"\t"<<x<<endl;
    fv=v-x*h;
    fx=x+v*h;
    vn=v-(x+fx)*h/2;
    x=x+(v+fv)*h/2;
    v=vn;
}
return 0;
}
