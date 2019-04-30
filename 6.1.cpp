#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main(){
int n=2,i,j,k;
float a[n][n],r[n][n],rt[n][n],d[n][n],x[n][n],_b,t,c,s,y1,y2;
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        cout<<"Enter element a"<<i<<j<<": ";
        cin>>a[i][j];
    }
}
_b=(a[1][1]-a[2][2])/a[1][2];
if(_b<0)
    t=(_b+sqrt(_b*_b+4))/2;
else
    t=(_b-sqrt(_b*_b+4))/2;
c=1/sqrt(1+t*t);
s=c*t;
y1=c*c*a[1][1]+s*s*a[2][2]-2*c*s*a[1][2];
y2=c*c*a[2][2]+s*s*a[1][1]+2*c*s*a[1][2];
cout<<"\nEigenvalues are:\n"<<y1<<endl<<y2<<endl;
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(i==j){
            r[i][j]=c;
            rt[i][j]=c;
        }
        else if(i<j){
            r[i][j]=s;
            rt[i][j]=-s;
        }
        else{
            r[i][j]=-s;
            rt[i][j]=s;
        }
    }
}
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        x[i][j]=0;
        for(k=1;k<=n;k++){
            x[i][j]=x[i][j]+rt[i][k]*a[k][j];
        }
    }
}
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        d[i][j]=0;
        for(k=1;k<=n;k++){
            d[i][j]=d[i][j]+x[i][k]*r[k][j];
        }
    }
}
cout<<"\nMatrix D is:\n";
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf("%f\t",d[i][j]);
    }
    cout<<endl;
}
return 0;
}
