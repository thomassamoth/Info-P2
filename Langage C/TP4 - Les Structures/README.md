# Les Structures
*Réécriture du cours sur les structures*

## Introduction
- équivaut aux enregistrements en algorithmique

- 1 personne ➡ plusieurs variables ➡ **Comment faire avec plusieurs personnes ?**  
      ↘ on utilise 1 seule variable (structure) et on a ensuite un tableau de structures

## Structure 
1. Déclaration d'une structure

``` C
struct Personne
{
  // ce sont les variables ou attributs
  char nom[20];
  char prenom[20];
  int age;
}; // ne pas oublier le ; à la fin !!
```
2. Déclaration d'une variable
``` C
//Declaration d'une personne
struct Personne perso; // une personne
struct Personne employes[100]; //tableau de personnes
// dans chaque case, on peut avoir 1 Personne
```
3. Utilisation de la variable  
*On accède aux champs avec la notation ```.```*
  
``` C
// saisie : 
printf("Entrer le prénom : ");
scanf("%s", perso.nom);
printf("Entrer le prénom : ");
scanf("%s", perso.prenom);
printf("Entrer age : ");
printf("%d", perso.age);
```
``` C
//affichage
printf("Nom : %s \n", perso.nom);
printf("Prenom : %s \n", perso.prenom);
printf("Age : %d \n", perso.age);
```
#### Remarque
⚠️ Si vous avez 2 `struct Personne` p1 et p2, on ne peut pas les comparer directement   
on ne peut pas avoir `p1 == p2`
il faut donc comparer les champs **2 à 2**

## Fonction de la saisie
on ne peut pas faire :
``` C
void saisir_perso(struct Personne* perso)
```
**on doit plutôt faire :**
``` C
struct Personne saisir_personne()
``` 
- Exemple :
 #### Saisie
``` C
// La fonction retourne une valeur de type struct Personne
struct Personne saisir_personne()
{
  // variable pour demander la saisie
  struct Personne p;
  printf("Entrer le nom : ");
  scanf("%s", p.nom);
  printf("Entrer le prénom : ");
  scanf("%s", p.prenom);
  printf("Entrer l'age : ");
  scanf("%d", &p.age);
  return p;
}
``` 
#### Affichage
``` C
void afficher_personne(struct Personne p)
{
  printf("Nom : %s \n", p.nom);
  printf("Prenom : %s \n", p.prenom);
  printf("Age : %s \n", p.age);
}
``` 
#### Principale
``` C
int main()
{
  // Declaration d'une personne
  struct Personne perso; // une personne
  //saisie : 
  perso = saisir_personne();
  // affichage :
  afficher_personne();
  return 0;
}
``` 
## Structures imbriquées  
*1 structure qui contient au moins un champ qui est une structure*
- Exemple : 
``` C
struct Date
{
  int jour;
  int mois;
  int annee;
}; // attention au ;

struct Personne
{
  char nom[20];
  char prenom[20];
  struct Date anniversaire; // structure imbriquée
}

//saisie
struct Personne saisir_personne()
{
  struct Personne p;
  printf("Entrer le jour d'anniversaire : ");
  scanf("%d", &p.anniversaire.jour);
  // ... idem avec mois et annee
  return p
 }
```
 
