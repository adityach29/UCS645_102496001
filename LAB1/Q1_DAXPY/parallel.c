#include <stdio.h>
#include <omp.h>
#define N (1<<16)
int main(){
double x[N],y[N];
double a=5;
int i;
for(i=0;i<N;i++)
{
x[i]=i;
y[i]=i+1;
}
double start=omp_get_wtime();
#pragma omp parallel for
for(i=0;i<N;i++)
{
x[i] = a * x[i] + y[i];
}
double end=omp_get_wtime();
printf("time taken=%f", end - start);
return 0;
} 
