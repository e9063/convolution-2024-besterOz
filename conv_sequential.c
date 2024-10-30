#include <stdio.h>
#include <stdlib.h>

int main(){
    //variable
    int na,nf, anw,*a, *b, *anws;

    //input
    scanf("%d %d", &na, &nf);
    
    anw = na - nf + 1;
    //malloc
    a = malloc(sizeof(int) * na);
    b = malloc(sizeof(int) * nf);
    anws = malloc(sizeof(int) * anw);

    //input
    for (int i = 0 ; i < na; i++)
        scanf("%d", &a[i]);
    for (int i = 0 ; i < nf; i++)
        scanf("%d", &b[i]);
    
    //implement
    for (int i = 0 ; i < anw ; i++)
    {
        int total = 0;
        for(int j = 0; j < nf ; j++)
        {
            total += a[i+j] * b[nf-1-j];
        }
        anws[i] = total;
    }

    for (int i = 0; i < anw; i++)
    {
        printf("%d\n", anws[i]);
    }
    
    free(anws);
    free(a);
    free(b);

    return(0);
}