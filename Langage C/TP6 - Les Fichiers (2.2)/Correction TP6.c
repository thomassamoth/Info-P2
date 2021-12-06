/*
ESIGELEC � Cycle Pr�paratoire Int�gr� International
TP n�6 � Les fichiers
Exercice :
Cet exercice a pour but d'�crire un programme permettant de g�rer la liste des �l�ves
de l'Esigelec.
1. D�finir une structure eleve permettant de stocker les informations suivantes :
    - nom de l'�l�ve (taille max=25),
    - pr�nom de l'�l�ve (taille max=25),
    - date de naissance,
    - groupe de l'�l�ve (1, 2, etc...).

2. La liste des �l�ves doit �tre stock�e dans un tableau (un tableau de taille 100
suffira pour cet exercice).
�crire des fonctions permettant :
    - D'ajouter un �l�ve dans le tableau,
    - D'afficher le contenu du tableau,
    - De modifier le groupe d'un �l�ve dont le nom et le pr�nom seront demand�s �
l'utilisateur
    - De supprimer un �l�ve du tableau.
3. �crire une fonction permettant d'enregistrer le contenu du tableau dans le fichier
eleves.dat.

4. �crire une fonction permettant de lire le contenu du fichier eleves.dat, et de le
stocker dans un tableau. Cette fonction sera appel�e lors du lancement du
programme.

� la fin, votre programme principal pourra par exemple avoir le menu suivant :
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
// D�finition de la structure eleve et de sa sous-structure date :
struct date
{
    int jour;
    int mois;
    int annee;
};

struct eleve
{
    char nom[25];
    char prenom[25];
    struct date anniversaire;
    int groupe;
};
// Fonction permettant d'ajouter un �l�ve � une position donn�e d'un tableau
void ajouter(struct eleve tab[], int position)
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
// Fonction permettant d'afficher les informations d'un �l�ve :
void afficher_eleve(struct eleve e)
{
    printf(" %s %s ne le %d/%d/%d\n Groupe %d\n", e.nom, e.prenom,
    e.anniversaire.jour, e.anniversaire.mois, e.anniversaire.annee, e.groupe);
}
// Fonction permettant d'afficher les informations des �l�ves d'un tableau :
void afficher(struct eleve tab[], int position)
{
    int i;
    for(i=0; i < position; i++)
    afficher_eleve(tab[i]);
}
// Fonction permettant de modifier les informations d'un �l�ve du tableau :
void modifier(struct eleve tab[], int position)
{
    char nom[25], prenom[25];
    int trouve=0; //ESIGELEC � Cycle Pr�paratoire Int�gr� International
    int i=0;
    // Demander � l'utilisateur le nom et le pr�nom de l'�l�ve � modifier :
    fflush(stdin);
    printf("Entrez le nom : ");
    fgets(nom, 25, stdin);
    fflush(stdin);
    printf("Entrez le prenom : ");
    fgets(prenom, 25, stdin);
    // Recherche de l'�l�ve dans le tableau :
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
    if(trouve == 0)
    printf("Eleve inconnu\n");
}
// Supprimer un �l�ve du tableau
// La fonction retourne 1 si la suppression a �t� faite, et 0 sinon.
int supprimer(struct eleve tab[], int position)
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
            // Supprimer le contenu de la case en d�calant:
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
    printf("Eleve inconnu\n"); //ESIGELEC � Cycle Pr�paratoire Int�gr� International
    else
    printf("Eleve supprime\n");
    return trouve;
}
// Enregistrement des �l�ves du tableau dans le fichier eleves.dat
void enregistrer(struct eleve tab[], int position)
{
    FILE *fichier;
    int i;
    fichier = fopen("eleves.dat", "w");
    for(i=0; i < position; i++)
    fwrite(&tab[i], sizeof(struct eleve), 1, fichier);
    fclose(fichier);
}
// Lecture du fichier eleves.dat et �criture dans le tableau
int lire(struct eleve tab[])
{
    int i=0;
    FILE *fichier=fopen("eleves.dat", "r");
    while(fread(&tab[i], sizeof(struct eleve), 1, fichier) && !feof(fichier))
    i++;
    return i;
}

int main()
{
    struct eleve tableau[taille];
    int indice=0;
    int choix, resultat;
    indice = lire(tableau);
    do // Affichage du menu de choix :
    {
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
