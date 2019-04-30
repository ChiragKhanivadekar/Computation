#include <stdio.h>
#include <math.h>
int main(){
int n,i,j,k;
printf("Enter order of matrix: ");
scanf("%d",&n);
float a[n][n],L[n][n],LT[n][n],A[n][n],s;
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
///Obtaining Matrix L
for(i=1;i<=n;i++){
    for(j=i+1;j<=n;j++){
        L[i][j]=0;
    }
}
for(i=1;i<=n;i++){
    for(j=1;j<=i;j++){
        s=0;
        if(i==j){
            for(k=1;k<j;k++){
                s=s+L[j][k]*L[j][k];
            }
            L[i][i]=sqrt(a[i][i]-s);
        }
        else{
            for(k=1;k<j;k++){
                s=s+L[i][k]*L[j][k];
            }
            L[i][j]=(a[i][j]-s)/L[j][j];
        }
    }
}
///Obtaining Matrix LT
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        LT[j][i]=L[i][j];
    }
}
///Obtaining Matrix A again
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        A[i][j]=0;
    }
}
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        for(k=1;k<=n;k++){
            A[i][j]=A[i][j]+L[i][k]*LT[k][j];
        }
    }
}
///Printing Matrix L
printf("\nMatrix L is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",L[i][j]);
    }
    printf("\n");
}
///Printing Matrix LT
printf("\nMatrix LT is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",LT[i][j]);
    }
    printf("\n");
}
///Printing Matrix A
printf("\nMatrix A after multiplying L & LT is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",A[i][j]);
    }
    printf("\n");
}
return 0;
}
