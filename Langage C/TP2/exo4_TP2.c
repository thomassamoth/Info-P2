#include <stdio.h>
#include <math.h>



void est_premier(int n)
{
    int i = 1;
    int premier = 1;
    do
    {
        if(n%++i == 0 && n!=i)
            premier = 0;
    } while(premier && i<=sqrt(n));
    if(premier)
        printf("%d est premier\n", n);
    else
        printf("%d n'est pas premier\n", n);
}



int main()
{
    int n;

    printf("Entrez n : ");
    scanf("%d", &n);
    for(n=2; n<100; n++)
        est_premier(n);

    return 0;
}



