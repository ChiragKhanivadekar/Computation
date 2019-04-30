#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10000
using namespace std;
int main(){
int i,M=0;
double x,y,pi;
srand(time(NULL));
for(i=0;i<N;i++){
    x=(double)rand()/RAND_MAX;
    y=(double)rand()/RAND_MAX;
    if(x*x+y*y<=1)
        M++;
}
pi=4.0*M/N;
cout<<"Estimated value of pi="<<pi;
return 0;
}
