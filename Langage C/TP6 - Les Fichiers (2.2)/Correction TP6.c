/*
ESIGELEC – Cycle Preparatoire Integre International
TP n°6 – Les fichiers
Exercice :
Cet exercice a pour but d'ecrire un programme permettant de gerer la liste des eleves
de l'Esigelec.
1. Definir une structure eleve permettant de stocker les informations suivantes :
    - nom de l'eleve (taille max=25),
    - prenom de l'eleve (taille max=25),
    - date de naissance,
    - groupe de l'eleve (1, 2, etc...).
2. La liste des eleves doit être stockee dans un tableau (un tableau de taille 100
suffira pour cet exercice).
Écrire des fonctions permettant :
    - D'ajouter un eleve dans le tableau,
    - D'afficher le contenu du tableau,
    - De modifier le groupe d'un eleve dont le nom et le prenom seront demandes à
l'utilisateur
    - De supprimer un eleve du tableau.
3. Écrire une fonction permettant d'enregistrer le contenu du tableau dans le fichier
eleves.dat.
4. Écrire une fonction permettant de lire le contenu du fichier eleves.dat, et de le
stocker dans un tableau. Cette fonction sera appelee lors du lancement du
programme.
À la fin, votre programme principal pourra par exemple avoir le menu suivant :
1. Ajouter un eleve
2. Afficher la liste des eleves
3. Changer un eleve de groupe
4. Supprimer un eleve
5. Enregistrer dans le fichier
6. Quitter
*/

#include <stdio.h>
#include <string.h>
#define taille 100
// Definition de la structure eleve et de sa sous-structure date :
struct Date
{
    int jour;
    int mois;
    int annee;
};

struct Eleve
{
    char nom[25];
    char prenom[25];
    struct Date anniversaire;
    int groupe;
};
// Fonction permettant d'ajouter un eleve à une position donnee d'un tableau
void ajouter(struct Eleve tab[], int position)
{
    fflush(stdin);
    printf("Entrez le nom : ");
    fgets(tab[position].nom, 25, stdin);
    fflush(stdin);
    printf("Entrez le prenom : ");
    fgets(tab[position].prenom, 25, stdin);
    printf("Jour de naissance : ");
    scanf("%d", &tab[position].anniversaire.jour);
    printf("Mois de naissance : ");
    scanf("%d", &tab[position].anniversaire.mois);
    printf("Annee de naissance : ");
    scanf("%d", &tab[position].anniversaire.annee);
    printf("Numero du groupe : ");
    scanf("%d", &tab[position].groupe);
}
// Fonction permettant d'afficher les informations d'un eleve :
void afficher_eleve(struct Eleve e)
{
    printf(" %s %s ne le %d/%d/%d\n Groupe %d\n", e.nom, e.prenom,
    e.anniversaire.jour, e.anniversaire.mois, e.anniversaire.annee, e.groupe);
}

// Fonction permettant d'afficher les informations des eleves d'un tableau :
void afficher(struct Eleve tab[], int position)
{
    int i;
    for(i=0; i < position; i++)
    {
        afficher_eleve(tab[i]);
        printf("------------------\n");
    }
}
// Fonction permettant de modifier les informations d'un eleve du tableau :
void modifier(struct Eleve tab[], int position)
{
    char nom[25], prenom[25];
    int trouve=0;
    int i=0;
    // Demander a l'utilisateur le nom et le prenom de l'eleve a modifier :
    fflush(stdin);
    printf("Entrez le nom : ");
    fgets(nom, 25, stdin);
    fflush(stdin);
    printf("Entrez le prenom : ");
    fgets(prenom, 25, stdin);
    // Recherche de l'eleve dans le tableau :
    while(trouve == 0 && i < position)
    {
        if(strcmp(tab[i].nom, nom) == 0 && strcmp(tab[i].prenom, prenom) == 0)
        {
            printf("Nouveau numero de groupe : ");
            scanf("%d", &tab[i].groupe); // Affectation du nouveau groupe
            trouve=1;
        }
        i++;
    }
    if(trouve == 0){
    printf("Eleve inconnu\n");
    }

}

// Supprimer un eleve du tableau
// La fonction retourne 1 si la suppression a ete faite, et 0 sinon.
int supprimer(struct Eleve tab[], int position)
{
    char nom[25], prenom[25];
    int trouve=0;
    int i=0;
    int j;
    fflush(stdin);
    printf("Entrez le nom : ");
    fgets(nom, 25, stdin);
    fflush(stdin);
    printf("Entrez le prenom : ");
    fgets(prenom, 25, stdin);
    while(trouve == 0 && i < position)
    {
        if(strcmp(tab[i].nom, nom) == 0 && strcmp(tab[i].prenom, prenom) == 0)
        {
            trouve=1;
            // Supprimer le contenu de la case en decalant:
            for(j=i+1; j < position; j++)
            {
                strcpy(tab[j-1].nom, tab[j].nom);
                strcpy(tab[j-1].prenom, tab[j].prenom);
                tab[j-1].anniversaire.jour = tab[j].anniversaire.jour;
                tab[j-1].anniversaire.mois = tab[j].anniversaire.mois;
                tab[j-1].anniversaire.annee = tab[j].anniversaire.annee;
                tab[j-1].groupe = tab[j].groupe;
            }
        }
        i++;
    }
    if(trouve == 0)
        printf("Eleve inconnu\n");
    else
        printf("Eleve supprime\n");
    return trouve;
}
// Enregistrement des eleves du tableau dans le fichier eleves.dat
void enregistrer(struct Eleve tab[], int position)
{
    FILE *fichier;
    int i;
    fichier = fopen("eleves.dat", "w");
    for(i=0; i < position; i++)
    {
        fwrite(&tab[i], sizeof(struct Eleve), 1, fichier);
    }

    fclose(fichier);
}
// Lecture du fichier eleves.dat et ecriture dans le tableau
int lire(struct Eleve tab[])
{
    int i=0;
    FILE *fichier=fopen("eleves.dat", "r");
    while(fread(&tab[i], sizeof(struct Eleve), 1, fichier) && !feof(fichier))
    {
        i++;
        return i;
    }
}

int main()
{
    struct Eleve tableau[taille];
    int indice=0;
    int choix, resultat;
    indice = lire(tableau);
    do // Affichage du menu de choix :
    {
        printf(" === MENU ===\n");
        printf("1. Ajouter un eleve\n");
        printf("2. Afficher la liste des eleves\n");
        printf("3. Changer un eleve de groupe\n");
        printf("4. Supprimer un eleve\n");
        printf("5. Enregistrer dans le fichier\n");
        printf("6. Quitter\n");
        scanf("%d", &choix);
        switch(choix) // Traitement des choix possibles :
        {
            case 1 :
                if(indice < taille-1)
                {
                    ajouter(tableau, indice);
                    indice++;
                }
                else
                    printf("Tableau plein\n");
            break;

            case 2 :
                printf("Liste des eleves :\n");
                afficher(tableau, indice);
            break;

            case 3 :
                modifier(tableau, indice);
            break;

            case 4 :
                resultat = supprimer(tableau, indice);
                if(resultat == 1)
                    indice--;
            break;

            case 5 :
                enregistrer(tableau, indice);
            break;

            case 6 :
                printf("Fin du programme, enregistrement dans le fichier\n");
                enregistrer(tableau, indice);
            break;

            default :
                printf("Choix non valide\n");
        }
    }while (choix != 6);

return 0;
}
