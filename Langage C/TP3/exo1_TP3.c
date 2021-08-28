/*
    Exercice 1 TP 3
    Manipulation d'un chaine saisie au clavier :
        - calcul de la longuieur,
        - nombre de caractère 'e',
        - affichage en sens inverse,
        - suppression des 'e'.
    Fait le 22 octobre 2013
    Par le Departement TIC de l'Esigelec
*/


#include <stdio.h>
#define TAILLE 100


int longueur(char chaine[])
{
    int l=0;
    while(chaine[l] != '\n') // Car la chaine est lue avec fgets
        l++;
    return l;
}

void nombre_e(char chaine[])
{
    int i=0;
    int nombre = 0;
    while(chaine[i] != '\n')
    {
        if(chaine[i] == 'e') // Si le caractère est un 'e'
            nombre++;        // on augment nombre de 1
        i++;
    }
    printf("La phrase contient %d 'e'\n", nombre);
}

void afficher_inverse(char chaine[])
{
    int i;
    int l = longueur(chaine);
    for(i=l-1; i>=0; i--) // Affichage du dernier caractère au premier
        printf("%c", chaine[i]);
    printf("\n");
}


void supprime_e(char chaine[])
{
    int i=0, j;
    int l=longueur(chaine);
    while(i <= l)
    {
        if(chaine[i] == 'e') // Si on trouve un 'e'
        {
            for(j=i; j<= l+1; j++) // On décale tout vers la gauche
                chaine[j] = chaine[j+1];
            l--;
        }
        if(chaine[i] != 'e') // Si le nouveau caractère n'est pas un i, on avance
            i++;
    }
}


int main()
{
    char phrase[TAILLE];
    int taille_phrase;
    // Question 1 :
    printf("Entrez une phrase : ");
    fgets(phrase, TAILLE, stdin);
    // Question 2
    printf("La phrase est de longueur %d\n", longueur(phrase));
    // Question 3
    nombre_e(phrase);
    // Question 4
    afficher_inverse(phrase);
    // Question 5
    supprime_e(phrase);
    printf("Nouvelle phrase : %s", phrase);

    return 0;
}
