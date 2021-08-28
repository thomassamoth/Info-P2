//ESIGELEC – Cycle Préparatoire Intégré International
/*
TP n°5 – Les fichiers
Exercice :
Cet exercice a pour but d'écrire un programme permettant de gérer un ensemble de
livres. Le programme principal demandé à la dernière question est à faire
progressivement afin de tester le bon fonctionnement de chaque fonction.
1. Définir une structure livre permettant de stocker les informations suivantes :
 titre (taille max=20),
 nom de l'auteur (taille max=20),
 année de parution.
2. Écrire une fonction permettant de saisir une structure livre.
3. Écrire une fonction permettant d'afficher une structure livre.
4. Écrire une fonction qui ajoute un livre dans le fichier livres.dat.
5. Écrire une fonction permettant d’afficher le contenu du fichier livres.dat.
6. Écrire une fonction permettant de rechercher les livres d'un auteur dont le nom
tapé au clavier.
7. Écrire une fonction permettant de modifier un livre donné par son titre.
8. Écrire un programme avec un menu permettant d'appeler ces fonctions.
*/
//Corrigé :

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 1) Structure contenant les propriétés d'un livre
struct livre
{
    char titre[20];
    char auteur[20];
    int annee;
};
// 2) Fonction permettant de saisir un livre
// Elle est appelée uniquement par la fonction ajouter.
struct livre saisir()
{
    struct livre bouquin;
    printf("Entrez le titre : ");
    __fpurge(stdin);
    fgets(bouquin.titre, 20, stdin);
    printf("Entrez le nom de l'auteur : ");
    __fpurge(stdin);
    fgets(bouquin.auteur, 20, stdin);
    printf("Entrez l'annee de parution : ");
    scanf("%d", & bouquin.annee);
    return bouquin;
}
// 3) Fonction affichant un livre
// Elle est appelée pour afficher le contenu du fichier
// et lors de la modification.
void afficher(struct livre bouquin)
{
    printf(" * %s", bouquin.titre);
    printf(" * %s", bouquin.auteur);
    printf(" * %d\n", bouquin.annee);
}
// 4) Ajout d'un livre dans le fichier
void ajouter()
{
    struct livre liv = saisir();
    FILE *fichier = fopen("livres.dat", "a"); // ouverture en mode ajout
    fwrite(&liv, sizeof(struct livre), 1, fichier); // Ecriture dans le fichier
    fclose(fichier); // Fermeture du fichier
}
// 5) Affichage du contenu du fichier :
void aff_fichier()
{
    struct livre liv;
    int i = 1;
    FILE *fichier = fopen("livres.dat", "r"); // Ouverture en mode lecture
    // Lecture de tous les enregistrements du fichier :
    while(!feof(fichier) && fread(&liv, sizeof(struct livre), 1, fichier))
    {
        printf("Livre n°%d : \n", i++);
        afficher(liv);
    }
    fclose(fichier);
}
// 6) Recherche dans le fichier :
void rechercher()
{
    struct livre bouquin;
    char auteur[20];
    FILE *fichier = fopen("livres.dat", "r"); // Ouverture en mode lecture
    int i = 1;
    printf("Nom de l'auteur : ");
    __fpurge(stdin);
    fgets(auteur, 20, stdin);
    // Lecture de tous les enregistrements du fichier :
    while(!feof(fichier) && fread(&bouquin, sizeof(struct livre), 1, fichier))
    {
        // Recherche du nom de l'auteur dans l'enregistrement :
        if(strcmp(auteur, bouquin.auteur) == 0)
        {
            printf("Livre n°%d : \n", i++);
            afficher(bouquin);
        }
    }
fclose(fichier);
}
// 7) Modification :
void modifier()
{
struct livre bouquin;
char titre[20];
FILE *fichier = fopen("livres.dat", "r+"); // Ouverture en
lecture/écriture
int trouve = 0;
printf("Titre du livre : ");
__fpurge(stdin);
fgets(titre, 20, stdin);
// Lecture de tous les enregistrements du fichier :
while(!feof(fichier) && fread(&bouquin, sizeof(struct livre), 1, fichier))
{
    if(strcmp(titre, bouquin.titre) == 0)
    {
        // Si le titre est trouvé, on affiche ses informations
        printf("Voici les informations sur le livre : \n");
        afficher(bouquin);
        // Et on demande les nouvelles informations
        printf("Donnez les nouvelles informations :\n");
        bouquin = saisir();
        fseek(fichier, -sizeof(struct livre), SEEK_CUR);
        fwrite(&bouquin, sizeof(struct livre), 1, fichier);
        trouve = 1;
    }
}
if(trouve == 0){
    printf("Le livre n'a pas ete trouve...\n\n");
    fclose(fichier);
}
// 8) Programme principal
main()
{
    int choix=0;
    struct livre book;
    while(choix != 5)
    {
        printf("1. Ajouter un livre\n");
        printf("2. Afficher la liste des livres\n");
        printf("3. Rechercher les livres d'un auteur\n");
        printf("4. Modifier un livre\n");
        printf("5. Quitter le programme\n");
        printf("\nVotre choix : ");
        scanf("%d", &choix);
        switch(choix)
        {
            case 1:
                ajouter();
            break;
            case 2:
                aff_fichier();
            break;
            case 3:
                rechercher();
            break;
            case 4:
                modifier();
            break;
            case 5:
                printf("Fin du programme\n\n");
            break;
            default:
                printf("Cette fonction n'est pas disponible\n\n");
        }
    }
}