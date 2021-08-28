#include <stdio.h>
#include <string.h>

void palindrome(char chaine[])
{
    int taille = strlen(chaine)-1;
    int ok = 1; // Si ok vaut 0, la chaine n'est pas un palindrome
    int debut = 0;
    int fin = taille-1;

    while(ok == 1 && debut <= fin) 
    {
        if(chaine[debut++] != chaine[fin--]) // Les caractères sont-ils identiques ?
            ok = 0;
    }
    if(ok == 1)
        printf("C'est un palindrome");
    else
        printf("Ce n'est pas un palindrome");
}

main()
{
    char phrase[80];
    fgets(phrase, 80, stdin);
    palindrome(phrase);
}