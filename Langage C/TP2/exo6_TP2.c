#include <stdio.h>


int puissance(int n, int p);



int main()
{
    int n, p;
    int resultat;
    printf("Entrez n : ");
    scanf("%d", &n);
    printf("Entrez p : ");
    scanf("%d", &p);
    if(p>=0)
    {
        resultat = puissance(n, p);
        printf("%d^%d=%d", n, p, resultat);
    }
    return 0;
}


int puissance(int n, int p)
{
    if(p==0)
        return 1;
    else
        if(p%2==0)
            return puissance(n*n, p/2);
        else
            return n*puissance(n, p-1);
}

