#include <stdio.h>
int main(){
int n,i,j,k;
printf("Enter order of matrix: ");
scanf("%d",&n);
float a[n][n],in[n][n],l[n][n],x[n][n],y[n][n],v;
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
///Finding Matrix Y using forward substitution (LY=I)
for(k=1;k<=n;k++){
    y[1][k]=in[1][k];
    for(i=2;i<=n;i++){
        v=0;
        for(j=1;j<i;j++){
            v=v+l[i][j]*y[j][k];
        }
        y[i][k]=in[i][k]-v;
    }
}
///Finding Matrix X using backward substitution (UX=Y)
for(k=1;k<=n;k++){
    x[n][k]=y[n][k]/a[n][n];
    for(i=n-1;i>=1;i--){
        v=0;
        for(j=i+1;j<=n;j++){
            v=v+a[i][j]*x[j][k];
        }
        x[i][k]=(y[i][k]-v)/a[i][i];
    }
}
///Printing Inverse Matrix X
printf("\nInverse Matrix X is\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf(" %f\t",x[i][j]);
    }
    printf("\n");
}
return 0;
}
