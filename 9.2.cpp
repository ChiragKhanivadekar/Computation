#include <iostream>
#include <fstream>
using namespace std;
ofstream out1,out2,out3;

int i=1,n;

double operation(double v);

int main(){
double v1,T1,v2,T2,v,T;
cout<<"Enter no. of intervals: ";
cin>>n;
///guess 1
cout<<"Enter guess value: ";
cin>>v1;
out1.open("1.txt");
T1=operation(v1);
out1.close();
///guess 2
cout<<"Enter another guess value: ";
cin>>v2;
out2.open("2.txt");
T2=operation(v2);
out2.close();
///required value
v=v1+(200-T1)*(v2-v1)/(T2-T1);
out3.open("3.txt");
T=operation(v);
out3.close();
cout<<"Required value of v="<<v;
return 0;
}

double operation(double v){
    double x=0,h=10.0/n,T=40,Tk1,Tk2,Tk3,Tk4,vk1,vk2,vk3,vk4;
    if(i==1)
        out1<<x<<"\t"<<T<<endl;
    else if(i==2)
        out2<<x<<"\t"<<T<<endl;
    else
        out3<<x<<"\t"<<T<<endl;
    for(x=0;x+h<=10;x=x+h){
        vk1=0.01*(T-20);
        Tk1=v;
        vk2=0.01*(T+Tk1*h/2-20);
        Tk2=v+vk1*h/2;
        vk3=0.01*(T+Tk2*h/2-20);
        Tk3=v+vk2*h/2;
        vk4=0.01*(T+Tk3*h-20);
        Tk4=v+vk3*h;
        v=v+(vk1+2*vk2+2*vk3+vk4)*h/6;
        T=T+(Tk1+2*Tk2+2*Tk3+Tk4)*h/6;
        if(i==1)
            out1<<x+h<<"\t"<<T<<endl;
        else if(i==2)
            out2<<x+h<<"\t"<<T<<endl;
        else
            out3<<x+h<<"\t"<<T<<endl;
    }
    i++;
    return T;
}
