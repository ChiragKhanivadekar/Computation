#include <iostream>
#define N 10000
#define m 10000
#define a1 3
#define a2 5
#define c1 7
#define c2 9
using namespace std;
int main(){
long i,M=0,rx[N+1],ry[N+1];
double x,y,pi;
cout<<"Enter seed for x and y: ";
cin>>rx[0]>>ry[0];
for(i=1;i<=N;i++){
    rx[i]=(a1*rx[i-1]+c1)%m;
    ry[i]=(a2*ry[i-1]+c2)%m;
    x=(double)rx[i]/m;
    y=(double)ry[i]/m;
    if(x*x+y*y<=1)
        M++;
}
pi=4.0*M/N;
cout<<"Estimated value of pi="<<pi;
return 0;
}
