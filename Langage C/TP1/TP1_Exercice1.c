/*
Correction de l'exercice 1 du TP 1
Réalisé par : TIC

Sujet : Écrire un programme qui comporte un menu proposant à l'utilisateur
de faire un des choix suivants :
    1. Le calcul de a^b à partir de 2 entiers a et b demandés à l'utilisateur,
    2. L'affichage des tirages de n dés, n étant un entier demandé à l'utilisateur,
    3. Entrer des entiers (20 au maximum) jusqu'à ce que la valeur saisie soit 0.
    Tous les nombres sont alors affichés dans l'ordre inverse de la saisie,
    4. Quitter l'application.
*/

#include <stdio.h>
#include <time.h>
#define TAILLE 20 // Correspond à la taille du tableau pour la question 3)
int main()
{
    int a, b; // Les nombres utilisés pour la question 1
    int resultat;
    int n; // Nombre de tirages
    int tableau[TAILLE]; // Tableau de la question 3
    int i, j; // compteurs
    int signe; // Pour conserver le signe de b à la question 1
    int choix; // Pour le choix du menu
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires
    do
    {
        printf("1 - Calcul de a^b\n");
        printf("2 - Tirage de n des\n");
        printf("3 - Saisie de %d valeurs maximum\n", TAILLE);
        printf("4 - Quitter l'application\n\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); // Supprime le caractère \n du buffer d'entrée
        // et évite l'utilisation de fpurge()
        switch(choix)
        {
            case 1:
                printf("Entrez a : ");
                scanf("%d", &a);
                getchar(); // Idem
                printf("Entrez b : ");
                scanf("%d", &b);
                getchar(); // Idem
                resultat = 1;
                if(b >= 0)
                signe = 1; // b est positif
                else
                {
                    signe = -1;
                    b = -b;
                }
                for(i=0; i<b; i++)
                resultat *= a;
                if(signe == 1)
                printf("%d^%d=%d\n\n",a, b, resultat);
                else
                printf("%d^%d=%f\n\n",a, b, (float) 1/resultat); // Un cast
            break;

            case 2:
                printf("Combien de tirage voulez-vous : ");
                scanf("%d", &n);
                getchar(); // Idem
                for(i=0; i<n; i++)
                printf("Tirage %d : %d\n", i+1, rand() % 6 + 1);
            break;

            case 3:
                i = 0;
                do
                {
                    printf("Entrez un nombre : ");
                    scanf("%d", &tableau[i]);
                    getchar(); // Idem
                    i++;
                }
                while(i<TAILLE && tableau[i-1] != 0);
                printf("Les valeurs saisies sont : ");
                for(j=i-1; j>=0; j--)
                printf("%d ", tableau[j]);
                printf("\n");
            break;

            case 4:
                printf("Fin du programme\n");
            break;

            default:
                printf("Choix non disponible !");
        }
    } while (choix != 4);
return 0;
}
