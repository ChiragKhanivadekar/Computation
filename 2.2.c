#include <stdio.h>
int main(){
int n,i,j,k;
printf("Enter order of matrix: ");
scanf("%d",&n);
float a[n][n+1],l[n][n],x[n],y[n],v;
printf("\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf("Enter element a%d%d: ",i,j);
        scanf("%f",&a[i][j]);
    }
}
printf("\n");
for(i=1;i<=n;i++){
    printf("Enter element b%d: ",i);
    scanf("%f",&a[i][n+1]);
}
printf("\nAugmented Matrix A is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
        printf(" %f\t",a[i][j]);
    }
    printf("\n");
}
///Defining Matrix L
for(i=1;i<=n;i++){
    for(j=i+1;j<=n;j++){
        l[i][j]=0;
    }
    l[i][i]=1;
}
///Obtaining Matrix U and L
for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        l[j][i]=a[j][i]/a[i][i];
        for(k=1;k<=n;k++){
            a[j][k]=a[j][k]-l[j][i]*a[i][k];
        }
    }
}
///Printing Matrix L
printf("\nMatrix L is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",l[i][j]);
    }
    printf("\n");
}
///Printing Matrix U
printf("\nMatrix U is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",a[i][j]);
    }
    printf("\n");
}
///Finding Matrix Y using forward substitution (LY=B)
y[1]=a[1][n+1];
for(i=2;i<=n;i++){
    v=0;
    for(j=1;j<i;j++){
        v=v+l[i][j]*y[j];
    }
    y[i]=a[i][n+1]-v;
}
///Finding Matrix X using backward substitution (UX=Y)
x[n]=y[n]/a[n][n];
for(i=n-1;i>=1;i--){
    v=0;
    for(j=i+1;j<=n;j++){
        v=v+a[i][j]*x[j];
    }
    x[i]=(y[i]-v)/a[i][i];
}
///Printing Matrix X
printf("\n");
for(i=1;i<=n;i++){
    printf("x%d=%f\n",i,x[i]);
}
return 0;
}
