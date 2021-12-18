# Les Enregistrements 💾

Les types vus jusqu'à présent permettent de facilement représenter des données élémentaires ou un ensemble de données, par exemple   
- une note représentée par un nombre réel  
- un ensemble de notes représenté par un tableau   

Quand il s'agit de représenter des concepts composés de plusieurs données, (par exemple une voiture), on pourrait avoir   
- une variable `marque` : char  
- une variable `cylindree` : entier  
- une variable `nombre_de_porte` : entier  
 ## Utiliser un enregistrement
 
  #### Defintion
 Les enregistrements permettent de créer un nouveau type composé de plusieurs champs de types différents.  
 Par exemple, une voiture sera composée des champs `marque`, `cylindree`, `nb_portes`
 
 #### Syntaxe : 
``` Python
NomDuType : ENREGISTREMENT
  champ1 : type1
  champ2 : type2
  ...
FIN ENREGISTREMENT
```
#### Exemple : 
``` Python
Voiture : ENREGISTREMENT
  marque : tableau de 30 char
  cylindree : réel
  nb_portes : entier
FIN ENREGISTREMENT
```
``` Python
Ennemi : ENREGISTREMENT
  nom : tableau de 20 caractere
  pt_vie : entier
  arme : tableau de 20 caractere
FIN ENREGISTREMENT
```
une fois le type crée : 
`maVariable : nomDuType`  
_exemple_ : `titine : Voiture`

 - On accède aux champs d'une variable de type enregistrement à l'aide de `.`
``` Python
# Modification des valeurs
titine.marque ← "Peugeot"
titine.cylindree ← 1,2
titine.nb_portes ← 5

# Utilisation des valeurs
afficher(titine.marque)
SI titine.nb_portes > 3
  afficher("Portes a l'arrière")
FIN SI
```

### Enregistrements imbriqués

On parle d'enregistrements imbriqués quand la définition d'un enrgistrement contient au moins un autre enregistrement.
``` Python
Conducteur : ENREGISTREMENT
 nom : tableau de 30 caracteres
 permis : char
 sa_voiture : Voiture // enregistrement Voiture
FIN
```

``` Python
Concessionnaire : ENREGISTREMENT
 adresse : tableau de 30 char
 catalogue : tableau de 50 Voiture
 FIN
 ```
 #### Accès aux valeurs
 ```Python
titine ← Voiture
Pierre ← Conducteur
Pierre.sa_voiture.marque ← "Marque"

Garage ← Concessionnaire
Garage.catalogue[0] ← titine
Garage.catalogue[0].cylindree ← 2.3
```
