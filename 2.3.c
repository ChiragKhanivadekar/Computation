#include <stdio.h>
int main(){
int n,i,j,k;
printf("Enter order of matrix: ");
scanf("%d",&n);
float a[n][n],in[n][n],y,v;
printf("\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf("Enter element a%d%d: ",i,j);
        scanf("%f",&a[i][j]);
    }
}
printf("\nMatrix A is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",a[i][j]);
    }
    printf("\n");
}
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
    v=a[i][i];
    for(j=1;j<=n;j++){
        a[i][j]=a[i][j]/v;
        in[i][j]=in[i][j]/v;
    }
}
printf("\nModified Matrix A is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",a[i][j]);
    }
    printf("\n");
}
printf("\nInverse Matrix is\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",in[i][j]);
    }
    printf("\n");
}
return 0;
}
