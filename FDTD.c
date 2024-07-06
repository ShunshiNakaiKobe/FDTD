#include<stdio.h>
#include<math.h>

int main(){
    double L = 100;
    int nx = 100;
    double dx = L/nx;
    double T = 50;
    int nt = 100;
    double dt = T/nt;
    double c = 1;
    double e = 8.85e-12;
    double t0 = 25*dt;
    double alpha = (4/t0)*(4/t0);
    double E[nt][nx],B[nt][nx];
    double J[nt][nx];
    int i,j;

    //初期条件//
    for(i=0;i<nt;i++){
        for(j=0;j<nx;j++){
            E[i][j] = 0;
            E[i][j] = 0;
            B[i][j] = 0;
            B[i][j] = 0;
            J[i][j] = 0;
        }
    }

    for(i=1;i<nt;i++){
        /* printf("%d ,%f,  %f\n", i,alpha,E[i][0]); */
        for(j=1;j<(nx-1);j++){
            E[i][j] = E[i-1][j] + dt*(-1*c*c*(B[i-1][j]-B[i-1][j-1])/dx-(J[i][j]/e));
        }

        E[i][0] = exp(-1*alpha*(i*dt-t0)*(i*dt-t0));

        for(j=0;j<(nx-1);j++){
            B[i][j] = B[i-1][j] - dt*((E[i][j+1]-E[i][j])/dx);
        }
        E[i][nx-1] = 0;
    }

    for(i=0;i<nt;i++){
        for(j=0;j<nx;j++){
            printf("E[%d][%d] = %f,", i,j,E[i][j]);
            printf("B[%d][%d] = %f\n", i,j,B[i][j]);
        }
    }
}