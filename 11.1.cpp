#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n,i,j,k;
cout>>"Enter no. of data points: ";
cin>>n;
double x[n],y[n];
cout<<"Enter data for x: ";
for(i=1;i<=n;i++){
    cin>>x[i];
}
cout<<"Enter data for y: ";
for(i=1;i<=n;i++){
    cin>>y[i];
}

return 0;
}
