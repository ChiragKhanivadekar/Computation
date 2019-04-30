#include <stdio.h>
int main(){
int n,i,j,k;
printf("Enter order of matrix: ");
scanf("%d",&n);
float a[n][n+1],x[n],y,v;
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
        printf(" %lf\t",a[i][j]);
    }
    printf("\n");
}
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(i!=j){
            y=a[j][i]/a[i][i];
            for(k=1;k<=n+1;k++){
                a[j][k]=a[j][k]-y*a[i][k];
            }
        }
    }
}
for(i=1;i<=n;i++){
    v=a[i][i];
    for(j=1;j<=n+1;j++){
        a[i][j]=a[i][j]/v;
    }
}
printf("\nModified Augmented Matrix A is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
        printf(" %f\t",a[i][j]);
    }
    printf("\n");
}
for(i=1;i<=n;i++){
    x[i]=a[i][n+1];
    printf("\nx%d=%f",i,x[i]);
}
return 0;
}
