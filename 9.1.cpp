#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n,i,j,k;
n=10;
double h,T[n][n+1],l[n][n],x[n],y[n],v;
h=10.0/(n+1);
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(i==j)
            T[i][j]=2+0.01*h*h;
        else if(abs(i-j)==1)
            T[i][j]=-1;
        else
            T[i][j]=0;
    }
}
T[1][n+1]=40+0.01*h*h*20;
T[n][n+1]=200+0.01*h*h*20;
for(i=2;i<n;i++){
    T[i][n+1]=0.01*h*h*20;
}
cout<<"Augmented Matrix T is:\n";
for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
        cout<<T[i][j]<<"\t";
    }
    cout<<endl;
}
///Thomas Algorithm (Tapan Mishra Method)
///Defining Matrix L
for(i=1;i<=n;i++){
    for(j=i+1;j<=n;j++){
        l[i][j]=0;
    }
    for(j=1;j<i-1;j++){
        l[i][j]=0;
    }
    l[i][i]=1;
}
///Obtaining Matrix U and L
for(i=2;i<=n;i++){
    l[i][i-1]=T[i][i-1]/T[i-1][i-1];
    T[i][i]=T[i][i]-l[i][i-1]*T[i-1][i];
    T[i][i-1]=0;
}
///Printing Matrix L
cout<<"\nMatrix L is:\n";
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        cout<<l[i][j]<<"\t";
    }
    cout<<endl;
}
///Printing Matrix U
cout<<"\nMatrix U is:\n";
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        cout<<T[i][j]<<"\t";
    }
    cout<<endl;
}
///Finding Matrix Y using forward substitution (LY=B)
y[1]=T[1][n+1];
for(i=2;i<=n;i++){
    y[i]=T[i][n+1]-l[i][i-1]*y[i-1];
}
///Finding Matrix X using backward substitution (UX=Y)
x[n]=y[n]/T[n][n];
for(i=n-1;i>=1;i--){
    x[i]=(y[i]-T[i][i+1]*x[i+1])/T[i][i];
}
cout<<"\nValues of temperature at specified distance are:\n0 40\n";
for(i=1;i<=n;i++){
    cout<<i*h<<" "<<x[i]<<endl;
}
cout<<"10 200";
return 0;
}
