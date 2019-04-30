#include <iostream>
using namespace std;

double T(double x, double y){
    double f;
    f=2*x*y+2*x-x*x-2*y*y+72;
    return f;
}

int main(){
int m,n,i,j;
m=12;
n=12;
double h,k,t,a[m+1][n+1];
h=8.0/m;
k=6.0/n;
///Trapezoidal Rule
t=T(0,0)+T(0,6)+T(8,0)+T(8,6);
for(j=1;j<n;j++){
    t=t+2*(T(0,j*k)+T(8,j*k));
}
for(i=1;i<m;i++){
    t=t+2*(T(i*h,0)+T(i*h,6));
}
for(i=1;i<m;i++){
    for(j=1;j<n;j++){
        t=t+4*T(i*h,j*k);
    }
}
t=t*h*k/4;
cout<<"Average temperature using Trapezoidal Rule="<<t/(8*6)<<endl;
///Simpson's 1/3 Rule
a[0][0]=1;
a[0][n]=1;
a[m][0]=1;
a[m][n]=1;
for(i=1;i<m;i++){
    if(i%2==1){
        a[i][0]=4;
        a[i][n]=4;
    }
    else{
        a[i][0]=2;
        a[i][n]=2;
    }
}
for(j=1;j<n;j++){
    if(j%2==1){
        a[0][j]=4;
        a[m][j]=4;
    }
    else{
        a[0][j]=2;
        a[m][j]=2;
    }
}
for(i=1;i<m;i++){
    for(j=1;j<n;j++){
        a[i][j]=a[i][0]*a[0][j];
    }
}
t=0;
for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
        t=t+a[i][j]*T(i*h,j*k);
    }
}
t=t*h*k/9;
cout<<"Average temperature using Simpson's 1/3 Rule="<<t/(8*6)<<endl;
///Simpson's 3/8 Rule
for(i=1;i<m;i++){
    if(i%3==0){
        a[i][0]=2;
        a[i][n]=2;
    }
    else{
        a[i][0]=3;
        a[i][n]=3;
    }
}
for(j=1;j<n;j++){
    if(j%3==0){
        a[0][j]=2;
        a[m][j]=2;
    }
    else{
        a[0][j]=3;
        a[m][j]=3;
    }
}
for(i=1;i<m;i++){
    for(j=1;j<n;j++){
        a[i][j]=a[i][0]*a[0][j];
    }
}
t=0;
for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
        t=t+a[i][j]*T(i*h,j*k);
    }
}
t=t*h*k*9/64;
cout<<"Average temperature using Simpson's 3/8 Rule="<<t/(8*6);
return 0;
}
