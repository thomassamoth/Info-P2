-- TP3 Base de donnee

-- Question 1
SELECT fil_pays, COUNT(*)
FROM Film
GROUP BY fil_pays

-- Question 2
SELECT fil_genre, AVG(fil_duree)
FROM Film
GROUP BY fil_genre

-- Question 3
SELECT fil_pays, COUNT(*)
FROM Film
WHERE fil_genre LIKE 'Aventure'
GROUP BY fil_pays

-- Question 4
SELECT fil_genre, AVG(fil_duree)
FROM Film
Where fil_sortie <= 2000
GROUP BY fil_genre

-- Question 5
SELECT a1.act_nom
FROM Acteur AS a1 INNER JOIN Acteur AS a2 ON a1.act_nom = a2.act_nom
WHERE a1.act_prenom != a2.act_prenom
Group by a1.act_nom

SELECT act_nom
FROM Acteur
Group by act_nom
Having Count(*)>1

-- Question 6
SELECT stu_nom, Count(*)
FROM Studio INNER JOIN Film ON stu_id = fil_studio
Group by stu_nom

-- Question 7
SELECT rea_nom, rea_prenom, COUNT(*)
FROM Realisateur INNER JOIN Film ON rea_id = fil_realisateur
Group by fil_realisateur
ORDER BY COUNT(*) DESC

-- Question 8
SELECT act_nom, act_prenom, COUNT(*)
FROM Acteur INNER JOIN Joue_dans ON act_id=jou_acteur
Group by jou_acteur
ORDER BY COUNT(*) DESC

-- Question 9
SELECT fil_titre, MAX(fil_duree)
FROM Film
WHERE fil_duree in
	(Select MAX(fil_duree)
    From Film);

-- Question 10
SELECT act_nom, act_prenom
FROM Acteur
WHERE act_naissance in
	(Select MAX(act_naissance)
    From Acteur);

-- Question 11
SELECT fil_titre
FROM Joue_dans 
INNER JOIN Film ON jou_film=fil_id
INNER JOIN Acteur ON jou_acteur=act_id
WHERE act_nom='Ford' && act_prenom='Harrison'

-- Question 12
SELECT act_nom, act_prenom
FROM Acteur
WHERE act_naissance >= 
	(SELECT Max(rea_naissance)
    From Realisateur);

-- Question 13
SELECT distinct stu_nom
FROM  Film AS t2 
INNER JOIN Studio ON t2.fil_studio=stu_id
INNER JOIN Film AS t1 ON t1.fil_id = t2.fil_suite_de
INNER JOIN Film AS t3 ON t2.fil_id = t3.fil_suite_de

-- Question 14
SELECT fil_titre
FROM  Joue_dans 
INNER JOIN Film ON fil_id=jou_film
INNER JOIN Acteur ON act_id=jou_acteur
WHERE 
