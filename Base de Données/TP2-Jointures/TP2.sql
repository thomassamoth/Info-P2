-- Question 1 : 1. Affichez le titre des films ainsi que le nom et le prénom de leur réalisateur.

SELECT fil_titre AS Titre, rea_nom AS Nom, rea_prenom AS Prenom
FROM Film
INNER JOIN Realisateur
ON fil_realisateur = rea_id

-- Question 2 : 2. Affichez dans l’ordre alphabétique le titre des films pour lesquels on connaît au moins

SELECT fil_titre AS Titre
FROM Film
INNER JOIN Joue_dans
ON jou_film = fil_id

-- Question 3 : Affichez le titre et l’année de sortie des films produits par le studio “United Artists”
du plus récent au plus ancien.

SELECT fil_titre AS Titre, fil_sortie
FROM Film
INNER JOIN Studio
ON fil_studio = stu_id
WHERE stu_nom =  "United Artists"
ORDER BY fil_sortie DESC

-- Question 4 : Combien d’acteurs jouent au moins dans un film ?

SELECT count(DISTINCT act_id) 
From Acteur
INNER JOIN Joue_dans
ON jou_acteur = act_id

--Question 5  Affichez les acteurs qui sont également réalisateurs.

SELECT act_nom, act_prenom
From Acteur
inner join Realisateur
ON act_id = rea_id

-- Question 6 : Affichez le titre des films qui ont eu une suite.

SELECT fil1.fil_titre
From Film as fil1
INNER JOIN Film AS fil2
ON fil1.fil_id = fil2.fil_suite_de;



--Question 7 : Affichez l’ensemble des acteurs ayant joué dans un film produit aux “USA”.

SELECT DISTINCT act_nom, act_prenom
From Acteur 
INNER JOIN Joue_dans
ON act_id = jou_film
INNER JOIN Film
ON jou_film = fil_id
WHERE fil_pays LIKE "USA"



-- Question 8 : Affichez le titre des films qui ont eu une suite, ainsi que le titre de cette suite.

SELECT fil1.fil_titre, fil2.fil_titre AS SUITE
From Film as fil1
INNER JOIN Film AS fil2
ON fil1.fil_id = fil2.fil_suite_de;



-- Question 9 : Affichez le nom et le prénom des réalisateurs ayant tourné au moins un film étranger.

SELECT rea_nom, rea_prenom
FROM Realisateur
INNER JOIN Film
ON fil_realisateur = rea_id
WHERE rea_pays NOT LIKE fil_pays


-- Question 10 : Affichez tous les acteurs pour lesquels il existe au moins un autre acteur ayant le même
nom.
SELECT act1.act_nom, act1.act_prenom
FROM Acteur AS act1
INNER JOIN Acteur AS act2
ON act1.act_nom = act2.act_nom
WHERE act1.act_prenom != act2.act_prenom




-- Question 11 : AAffichez les titres de films qui ont eu une suite tournée par un réalisateur différent.
SELECT fil1.fil_titre
From Film as fil1
INNER JOIN Film AS fil2
ON fil1.fil_id = fil2.fil_suite_de
WHERE fil1.fil_realisateur != fil2.fil_realisateur;



-- Question 12 : AAffichez la liste de tous les films avec les acteurs qui jouent dedans, triés par année de
sortie.
SELECT fil_titre, concat(act_nom, " ", act_prenom) AS Acteur, fil_sortie
FROM Film
INNER JOIN Joue_dans
ON jou_film = fil_id
INNER JOIN Acteur 
ON jou_acteur = act_id
ORDER BY fil_sortie


-- Question 13 : A Affichez tous les films, et pour chacun le nom du studio de production lorsqu’il est
connu.
SELECT fil_titre AS Titre, stu_nom AS Studio
FROM Film
INNER JOIN Studio
ON fil_studio = stu_id




-- Question 14 : A Affichez les films qui ont eu au moins 2 suites.
SELECT fil1.fil_titre AS Titre
From Film as fil1
INNER JOIN Film AS fil2
ON fil1.fil_id = fil2.fil_suite_de
INNER JOIN Film AS fil3
ON fil2.fil_id = fil3.fil_suite_de;

--Question 15 : Affichez les acteurs ayant joué dans au moins un film qui n’est pas de leur nationalité.
SELECT concat(act_prenom, " ", act_nom) AS Acteur
FROM Film
INNER JOIN Joue_dans
ON fil_id = jou_film
INNER JOIN Acteur
ON jou_acteur = act_id
WHERE act_pays NOT LIKE fil_pays



-- Question 16 : Affichez le titre et la durée de tous les films ainsi que le nom et le prénom de tous les
réalisateurs (y compris les films dont on ne connaît pas le réalisateur et les réalisateurs
pour lesquels on ne connaît pas de films).

SELECT fil_titre, fil_duree, rea1.rea_nom, rea1.rea_prenom
FROM Film
LEFT OUTER JOIN Realisateur AS rea1
ON fil_realisateur = rea1.rea_id
UNION
SELECT fil_titre, fil_duree, rea2.rea_nom, rea2.rea_prenom
FROM Film
RIGHT OUTER JOIN Realisateur AS rea2 
ON fil_realisateur = rea2.rea_id

--Question 17 : Affichez le nom et le prénom des acteurs qui jouent dans un film dont ils sont également
producteurs.


--Question 18 :  Affichez le nom et le prénom des acteurs ayant tourné des films avec au moins 2 studios
différents.
