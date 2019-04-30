#include <stdio.h>
#include <math.h>
#define N 200
#define T pow(10,-8)

int n,i,j,k;

double operation();

int main(){
printf("Enter size of Matrix: ");
scanf("%d",&n);
double a[n][n],x[N][n],largest,in[n][n],y,smallest;
printf("\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf("Enter element a%d%d: ",i,j);
        scanf("%lf",&a[i][j]);
    }
}
printf("\nEnter guess values of eigenvector: ");
for(i=1;i<=n;i++){
    scanf("%lf",&x[0][i]);
}
printf("\nValues of largest eigenvalue in each iteration are:\n");
largest=operation(a,x);
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(i==j)
            in[i][j]=1;
        else
            in[i][j]=0;
    }
}
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(i!=j){
            y=a[j][i]/a[i][i];
            for(k=1;k<=n;k++){
                a[j][k]=a[j][k]-y*a[i][k];
                in[j][k]=in[j][k]-y*in[i][k];
            }
        }
    }
}
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        in[i][j]=in[i][j]/a[i][i];
    }
}
printf("\nValues of smallest eigenvalue in each iteration are:\n");
smallest=1/operation(in,x);
printf("\nLargest eigenvalue=%lf\nSmallest eigenvalue=%lf",largest,smallest);
return 0;
}

double operation(double a[n][n], double x[N][n]){
double l,v;
for(k=1;k<N;k++){
    for(i=1;i<=n;i++){
        x[k][i]=0;
        for(j=1;j<=n;j++){
            x[k][i]=x[k][i]+a[i][j]*x[k-1][j];
        }
    }
    l=x[k][1];
    for(i=2;i<=n;i++){
        if(fabs(x[k][i])>fabs(l)){
            l=x[k][i];
        }
    }
    for(i=1;i<=n;i++){
        x[k][i]=x[k][i]/l;
    }
    printf("%d %lf\n",k,l);
    v=0;
    for(i=1;i<=n;i++){
        v=v+fabs(x[k][i]-x[k-1][i]);
    }
    if(v<T)
        break;
}
return l;
}
