-- Question 1

SELECT *
FROM Acteur

-- Question 2
SELECT fil_titre, fil_sortie, fil_duree
FROM Film

-- Question 3
SELECT *
FROM Acteur
ORDER BY act_naissance DESC

-- Question 4 : Affichez les films triés par ordre alphabétique du nom de pays et (pour un même pays)
-- du plus récent au plus ancien.

SELECT *
FROM Film 
ORDER BY fil_pays, fil_sortie 

-- Question 5 : 
SELECT concat(act_nom," ", act_prenom) AS Acteur
FROM Acteur

-- Question 6 : Affichez la liste des films qui sont la suite d’un autre film.
SELECT *
FROM Film
WHERE fil_suite_de IS NOT NULL

-- Question 7 : Affichez la liste des films ayant le chiffre 7 dans leur titre

SELECT *
FROM Film
WHERE fil_titre LIKE "%7%"

 -- Question 8 : Affichez tous les films qui durent plus de 2 heures
SELECT *
FROM Film
WHERE fil_duree >= 120
ORDER BY fil_duree

 -- Question 9 : Affichez le nom de tous les réalisateurs américains (USA et Canada)
SELECT rea_nom, rea_prenom
FROM Realisateur
WHERE rea_pays LIKE 'USA' OR 'Canada' 

-- Question 10 : Affichez le titre de tous les films avec la durée, sur 2 colonnes, exprimée en heures et
--en minutes

SELECT fil_titre AS Titre,  fil_duree div(60) AS Heure, fil_duree mod(60) AS Minutes
FROM Film
WHERE fil_duree IS NOT NULL 

-- Question 11
SELECT count(DISTINCT act_pays) AS 'Nombre de pays'
FROM Acteur

-- Question 12 :
SELECT round(avg(fil_duree), 2) AS 'Durée moyenne'
FROM Film

 -- Question 13 :
SELECT COUNT(DISTINCT fil_titre) AS "Nombre de films"
FROM Film

-- Question 14 : 
SELECT min(fil_sortie) AS 'Film le plus vieux'
FROM Film

-- Question 15 : 
SELECT count(fil_titre) AS 'Film japonais de moins de 2h'
FROM Film
WHERE fil_duree <= 120 AND fil_pays LIKE 'Japon'

-- Question 16 : 
SELECT *
FROM Film
WHERE fil_titre LIKE "%7%" AND  fil_titre NOT LIKE "%007"

-- Question 17 : 
SELECT max(act_naissance)
FROM Acteur
WHERE act_sexe LIKE "M"
UNION
SELECT max(act_naissance) 
FROM Acteur
WHERE act_sexe LIKE "F"
