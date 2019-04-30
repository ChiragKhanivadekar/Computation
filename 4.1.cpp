#include <iostream>
#include <cmath>
#include <stdio.h>
#define N 100
#define T pow(10,-8)
#define V x1
using namespace std;
int main(){
int n,i,j,k,flag;
cout<<"Enter size of Matrix: ";
cin>>n;
float a[n][n+1],A[n][n+1],x[n],x1[N],x2[N],x3[N],l,v;
cout<<endl;
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        cout<<"Enter element a"<<i<<j<<": ";
        cin>>a[i][j];
    }
}
for(i=1;i<=n;i++){
    cout<<"Enter element b"<<i<<": ";
    cin>>a[i][n+1];
}
cout<<"\nAugmented Matrix A is:\n";
for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
        cout<<" "<<a[i][j]<<"\t";
    }
    cout<<endl;
}
for(i=1;i<=n;i++){
    l=a[i][1];
    flag=1;
    for(j=2;j<=n;j++){
        if(a[i][j]>l){
            l=a[i][j];
            flag=j;
        }
    }
    for(j=1;j<=n+1;j++){
        A[flag][j]=a[i][j];
    }
}
cout<<"\nDiagonalized Matrix A is:\n";
for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
        cout<<" "<<A[i][j]<<"\t";
    }
    cout<<endl;
}
for(i=1;i<=n;i++){
    v=0;
    for(j=1;j<=n;j++){
        if(i!=j)
            v=v+abs(A[i][j]);
    }
    if(v>abs(A[i][i])){
        cout<<"\nGiven Matrix is not diagonally dominant.";
        return 0;
    }
}
for(i=1;i<=n;i++){
    cout<<"Enter guess value of x"<<i<<": ";
    cin>>x[i];
}
x1[0]=x[1];
x2[0]=x[2];
x3[0]=x[3];
for(k=1;k<N;k++){
    for(i=1;i<=n;i++){
        v=0;
        for(j=1;j<=n;j++){
            if(i!=j)
                v=v+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-v)/A[i][i];
    }
    x1[k]=x[1];
    x2[k]=x[2];
    x3[k]=x[3];
    if(abs(V[k]-V[k-1])<T)
        break;
}
cout<<endl;
for(i=1;i<=n;i++){
    printf("x%d=%f\n",i,x[i]);
}
cout<<"\nValues of x1 in each iteration are:\n";
for(i=0;i<=k;i++){
    printf("%d %f\n",i,x1[i]);
}
cout<<"\nValues of x2 in each iteration are:\n";
for(i=0;i<=k;i++){
    printf("%d %f\n",i,x2[i]);
}
cout<<"\nValues of x3 in each iteration are:\n";
for(i=0;i<=k;i++){
    printf("%d %f\n",i,x3[i]);
}
return 0;
}
