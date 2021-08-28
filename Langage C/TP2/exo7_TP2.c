#include <stdio.h>

int combinaison(int n, int p)
{
    if(n==p || n==0)
        return 1;
    else
        return combinaison(n, p-1)+combinaison(n-1, p-1);
}

int main()
{
    int i, j, n;
    printf("Entrez n : ");
    scanf("%d", &n);
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=i; j++)
            printf("%d  ", combinaison(j, i));
        printf("\n");
    }
    return 0;
}
