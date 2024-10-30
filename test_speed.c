#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    //variable
    int na,nf, anw,*a, *b, *anws_seq, *anws_par;

    //input
    scanf("%d %d", &na, &nf);
    
    anw = na - nf + 1;
    //malloc
    a = malloc(sizeof(int) * na);
    b = malloc(sizeof(int) * nf);
    anws_seq = malloc(sizeof(int) * anw);
    anws_par = malloc(sizeof(int) * anw);

    //input
    for (int i = 0 ; i < na; i++)
        scanf("%d", &a[i]);
    for (int i = 0 ; i < nf; i++)
        scanf("%d", &b[i]);
    
    //implement
    double start_seq = omp_get_wtime();
    for (int i = 0 ; i < anw ; i++)
    {
        int total = 0;
        for(int j = 0; j < nf ; j++)
        {
            total += a[i+j] * b[nf-1-j];
        }
        anws_seq[i] = total;
    }
    double end_seq = omp_get_wtime();
    
    double start_par = omp_get_wtime();
    omp_set_num_threads(8);
    #pragma omp parallel for
    for (int i = 0 ; i < anw ; i++)
    {
        int total = 0;
        for(int j = 0; j < nf ; j++)
        {
            total += a[i+j] * b[nf-1-j];
        }
        anws_seq[i] = total;
    }
    double end_par = omp_get_wtime();

    //time result
    double seq_time = end_seq - start_seq;
    double par_time = end_par - start_par;
    printf("Time taken by sequential convolution is %f seconds\n", seq_time);
    printf("Time taken by parallel convolution (8 threads) is %f seconds\n", par_time);

    double speed_up = seq_time/par_time;
    printf("Speed up is %f times", speed_up);
    
    free(anws_seq);
    free(anws_par);
    free(a);
    free(b);
}