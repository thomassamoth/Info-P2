#include <stdio.h>
#include <string.h>
#define MAXI 80

int est_voyelle(char carac)
{
    if(carac == 'a' || carac == 'A' ||
       carac == 'e' || carac == 'E' ||
       carac == 'i' || carac == 'I' ||
       carac == 'o' || carac == 'O' ||
       carac == 'u' || carac == 'U' ||
       carac == 'y' || carac == 'Y')
        return 1;
    else
        return 0;
}

int est_consonne(char carac)
{
    if((carac >= 'a' && carac <= 'z') || (carac >= 'A' && carac <= 'Z'))
        return 1-est_voyelle(carac);
    else
        return 0;
}

void separation(char chaine[])
{
    char ch1[MAXI];
    char ch2[MAXI];
    int compteur1 = 0; // Pour la chaine ch1
    int compteur2 = 0; // Pour la chaine ch2
    int i;

    for(i=0; i< strlen(chaine)-1; i++)
    {
        if(est_consonne(chaine[i]))
            ch1[compteur1++] = chaine[i];
        if(est_voyelle(chaine[i]))
            ch2[compteur2++] = chaine[i];
    }
    ch1[compteur1] = '\0'; // Fin de la première chaine
    ch2[compteur2] = '\0'; // Fin de la deuxième chaine

    printf("%s\n%s\n", ch1, ch2);

}

main()
{
    char phrase[MAXI];
    fgets(phrase, MAXI, stdin);
    separation(phrase);
}