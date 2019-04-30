#include <stdio.h>
#include <math.h>
int main(){
int i,j,k,n=5,m=2,e=1;
double Z[n][m],D[n],Zt[m][n],R[n][n],I[m][m],L[m][m],U[m][m],P[n][n],delta_A[m][m];
double X[5]={0.25,0.75,1.25,1.75,2.25};
double Y[5]={0.28,0.57,0.68,0.74,0.79};
double a0=1.0,a1=1.0,t,c,errora0,errora1;
do{
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(j==0){
                Z[i][j]= 1-exp(-a1*X[i]);
            }
            else{
                Z[i][j]=a0*X[i]*exp(-a1*X[i]);
            }
        }
    }
    for(i=0;i<n;i++){
         D[i]= Y[i]- a0*(1-exp(-a1*X[i]));
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            Zt[j][i]=Z[i][j];
       }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            t=0;
            for(k=0;k<n;k++){
                t=t+Zt[i][k]*Z[k][j];
            }
            R[i][j]=t ;
        }
    }
    ///Inverse
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            U[i][j]=0;
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            if(i==j){
                I[i][j]=1;
                L[i][j]=1;
            }
            else{
                I[i][j]=0;
                L[i][j]=0;
            }
        }
    }
    ///finding B
    for(j=0; j<m; j++){
        for(i=j+1; i<m; i++){
            c=R[i][j]/R[j][j];
            L[i][j]=c;
            for(k=0; k<m; k++){
                R[i][k]=R[i][k]-c*R[j][k];
                I[i][k]=I[i][k]-c*I[j][k];
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0; j<m; j++){
            U[i][j]=R[i][j];
        }
    }
    ///finding lower matrix D
    for(i=0;i<m;i++){
        for(j=i+1; j<m; j++){
            c=R[i][j]/R[j][j];
            for(k=0; k<m; k++){
                R[i][k]=R[i][k]-c*R[j][k];
                I[i][k]=I[i][k]-c*I[j][k];
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            I[i][j]=I[i][j]/R[i][i];
        }
    }
    ///Zt*D
    for(i=0;i<m;i++){
        t=0;
        for(k=0;k<n;k++){
            t=t+Zt[i][k]*D[k];
        }
        P[i][0]=t;
    }
    ///delta_A
    for(i=0;i<m;i++){
        t=0;
        for(j=0;j<m;j++){
            t=t+I[i][j]*P[j][0];
        }
        delta_A[i][0]=t;
    }
    a0=a0+delta_A[0][0];
    a1=a1+delta_A[1][0];
    errora0=fabs(delta_A[0][0]/a0)*100;
    errora1=fabs(delta_A[1][0]/a1)*100;
    e++;
}while(errora0 >0.1 && errora1 > 0.1);
printf("\n%d\n",e);
printf("\n%lf\t%lf\n",a0,a1);
return 0;
}
