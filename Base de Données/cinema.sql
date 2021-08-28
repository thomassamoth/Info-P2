--
-- Création de la base de données :
--

DROP DATABASE IF EXISTS Cinema;

CREATE DATABASE Cinema CHARACTER SET 'utf8';

CONNECT Cinema;

--
-- Création des tables :
--

CREATE TABLE Acteur (
	act_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
	act_nom VARCHAR(30) NOT NULL,
	act_prenom VARCHAR(30) NOT NULL,
	act_naissance DATE,
	act_sexe CHAR(1),
	act_pays VARCHAR(10),
	PRIMARY KEY (act_id)
)
ENGINE=INNODB;


CREATE TABLE Studio (
	stu_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
	stu_nom VARCHAR(30) NOT NULL,
	PRIMARY KEY (stu_id)
)
ENGINE=INNODB;


CREATE TABLE Realisateur (
	rea_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
	rea_nom VARCHAR(30) NOT NULL,
	rea_prenom VARCHAR(30) NOT NULL,
	rea_naissance DATE,
	rea_sexe CHAR(1),
	rea_pays VARCHAR(10),
	PRIMARY KEY (rea_id)
)
ENGINE=INNODB;


CREATE TABLE Film (
	fil_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
	fil_titre VARCHAR(50) NOT NULL,
	fil_duree INT,
	fil_sortie SMALLINT UNSIGNED,
	fil_suite_de INT,
	fil_realisateur INT UNSIGNED,
	fil_genre VARCHAR(20),
	fil_studio INT UNSIGNED,
	fil_pays VARCHAR(10),
	PRIMARY KEY (fil_id),
	CONSTRAINT fk_fil_realisateur FOREIGN KEY (fil_realisateur) REFERENCES Realisateur(rea_id) ON DELETE SET NULL,
	CONSTRAINT fk_fil_studio FOREIGN KEY (fil_studio) REFERENCES Studio(stu_id)
)
ENGINE=INNODB;


CREATE TABLE Joue_dans (
	jou_acteur INT UNSIGNED NOT NULL,
	jou_film INT UNSIGNED NOT NULL,
	CONSTRAINT pk_joue_dans PRIMARY KEY(jou_acteur, jou_film),
	CONSTRAINT fk_jou_acteur FOREIGN KEY (jou_acteur) REFERENCES Acteur(act_id),
	CONSTRAINT fk_jou_film FOREIGN KEY (jou_film) REFERENCES Film(fil_id)
)
ENGINE=INNODB;


--
-- Insertion de valeurs dans les tables :
--

INSERT INTO Acteur
VALUES	(1, 'FONDA', 'Henry', '1905-05-16', 'M', 'USA'),
	(2, 'LEIGH', 'Viven', '1913-11-05', 'F', 'UK'),
	(3, 'FORD', 'Harrison', '1942-07-13', 'M', 'USA'),
	(4, 'HAMIL', 'Mark', '1951-09-25', 'M', 'USA'),
	(5, 'WINSLET', 'Kate', '1975-10-05', 'F', 'UK'),
	(6, 'DI CAPRIO', 'Leonardo', '1974-11-11', 'M', 'USA'),
	(7, 'CONNERY', 'Sean', '1930-08-30', 'M', 'UK'),
	(8, 'BRONSON', 'Charles', '1921-11-03', 'M', 'USA'),
	(9, 'FONDA', 'Jane', '1937-12-21', 'F', 'USA'),
	(10, 'FONDA', 'Peter', '1940-02-23', 'M', 'USA'),
	(11, 'COPPOLA', 'Sofia', '1971-05-14', 'F', 'USA'),
	(12, 'ALLEN', 'Woody', '1935-12-01', 'M', 'USA'),
	(13, 'FONDA', 'Bridget', '1964-01-27', 'F', 'USA'),
	(14, 'DUJARDIN', 'Jean', '1972-06-19', 'M', 'France'),
	(15, 'DELON', 'Alain', '1935-11-08', 'M', 'France'),
	(16, 'DEPARDIEU', 'Gérard', '1948-12-27', 'M', 'France'),
	(17, 'DELON', 'Anthony', '1964-09-30', 'M', 'France'),
	(18, 'DEPARDIEU', 'Guillaume', '1971-04-07', 'M', 'France'),
	(19, 'DEPARDIEU', 'Julie', '1973-06-18', 'F', 'France');


INSERT INTO Studio	
VALUES	(1, '20th Century Fox'),
	(2, 'United Artists'),
	(3, 'Paramount Pictures'),
	(4, 'Studio Ghibli'),
	(5, 'Warner Bros'),
	(6, 'Pathé');



INSERT INTO Realisateur
VALUES	(1, 'CAMERON', 'James', '1954-08-16', 'M', 'Canada'),
	(2, 'LANDAU', 'Jon', '1960-07-23', 'M', 'USA'),
	(3, 'LUMET', 'Sidney', '1924-06-25', 'M', 'USA'),
	(4, 'SPIELBERG', 'Steven', '1946-12-18', 'M', 'USA'),
	(5, 'DILLER', 'Barry', '1942-02-02', 'M', 'USA'),
	(6, 'LUCAS', 'George', NULL, 'M', 'USA'),
	(7, 'VARDA', 'Agnès', '1928-05-30', 'F', 'France'),
	(8, 'FORD', 'Harrison', '1942-07-13', 'M', 'USA'),
	(9, 'KUROSAWA', 'Akira', '1910-03-23', 'M', 'Japon'),
	(10, 'MIYAZAKI', 'Hayao', '1941-01-05', 'M', 'Japon'),
	(11, 'TAKAHATA', 'Isao', '1935-10-29', 'M', 'Japon'),
	(12, 'COPPOLA', 'Francis Ford', '1939-04-07', 'M', 'USA'),
	(13, 'FONDA', 'Peter', '1940-02-23', 'M', 'USA'),
	(14, 'COPPOLA', 'Sofia', '1971-05-14', 'F', 'USA'),
	(15, 'ALLEN', 'Woody', '1935-12-01', 'M', 'USA'),
	(16, 'HAZANAVICIUS', 'Michel', '1967-03-29', 'M', 'France'),
	(17, 'STURGES', 'John', '1910-01-03', 'M', 'USA'),
	(18, 'KENNEDY', 'Burt', '1922-09-03', 'M', 'USA'),
	(19, 'JACKSON', 'Peter', '1961-10-31', 'M', 'NZL'),
	(20, 'LELOUCH', 'Claude', '1937-10-30', 'M', 'France');


INSERT INTO Film
VALUES	(1, '12 hommes en colère', 96, 1957, NULL, 3, 'Drame', NULL, 'USA'),
	(2, 'Autant en emporte le vent', 224, 1939, NULL, NULL, 'Romance', NULL, 'USA'),
	(3, 'Star Wars', 121, 1977, NULL, 6, 'Science-fiction', NULL, 'USA'),
	(4, 'Titanic', 194, 1997, NULL, 1, 'Romance', 1, 'USA'),
	(5, 'Les Aventuriers de l''arche perdue', 115, 1981, NULL, 4, 'Aventure', 3, 'USA'),
	(6, 'Indiana Jones et le Temple maudit', 118, 1984, 5, 4, 'Aventure', 3, 'USA'),
	(7, 'Indiana Jones et la Dernière Croisade', 127, 1989, 6, 4, 'Aventure', 3, 'USA'),
	(8, 'King Kong', 188, 2005, NULL, NULL, 'Aventure', NULL, 'USA'),
	(9, 'King Kong', 105, 1933, NULL, NULL, 'Aventure', NULL, 'USA'),
	(10, 'L''Empire contre-attaque', 124, 1980, 3, 6, 'Science-fiction', NULL, 'USA'),
	(11, 'Indiana Jones et le Royaume du crâne de cristal', 123, 2008, 7, 4, 'Aventure', 3, 'USA'),
	(12, 'Les 7 mercenaires', NULL, 1960, NULL, 17, 'Western', 2, 'USA'),
	(13, 'Le retour des 7', 95, 1966, 12, 18, 'Western', NULL, 'USA'),
	(14, 'Il était une fois dans l''ouest', 180, 1968, NULL, NULL, 'Western', 3, 'USA'),
	(15, 'Les 7 samourais', 208, 1954, NULL, 9, 'Aventure', NULL, 'Japon'),
	(16, 'Dodeskaden', 140, NULL, NULL, 9, 'Drame', NULL, 'Japon'),
	(17, 'James Bond 007 contre Dr No', 110, 1962, NULL, NULL, 'Action', 2, 'UK'),
	(18, 'Cléo de 5 à 7', 90, 1962, NULL, NULL, 'Drame', NULL, 'France'),
	(19, '7 ans', 86, 2007, NULL, NULL, 'Drame', NULL, 'France'),
	(20, 'Princesse Mononoke', 134, 1997, NULL, 10, 'Animation', 4, 'Japon'),
	(21, 'Le tombeau des lucioles', 89, 1988, NULL, 11, 'Animation', 4, 'Japon'),
	(22, 'Mon voisin Totoro', 86, 1988, NULL, 10, 'Animation', 4, 'Japon'),
	(23, 'Manhattan', 96, 1979, NULL, 15, 'Comédie', 2, 'USA'),
	(24, 'Le Parrain', 175, 1972, NULL, 12, 'Gangsters', 3, 'USA'),
	(25, 'Le Parrain 2', 192, 1974, 24, 12, 'Gangsters', 3, 'USA'),
	(26, 'Le Parrain 3', 163, 1990, 25, 12, 'Gangsters', 3, 'USA'),
	(27, 'OSS 117 : Le Caire, nid d''espions', 99, 2006, NULL, 16, 'Comédie', NULL, 'France'),
	(28, 'OSS 117 : Rio ne répond plus', 99, 2009, 27, 16, 'Comédie', NULL, 'France'),
	(29, 'Le nom de la rose', 131, 1986, NULL, NULL, 'Aventure', NULL, 'France'),
	(30, 'Les aventuriers', 112, 1967, NULL, NULL, 'Aventure', NULL, 'France'),
	(31, 'Après la pluie', 92, 2000, NULL, NULL, 'Aventure', NULL, 'Japon'),
	(32, 'Itinéaraire d''un enfant gaté', 124, 1988, NULL, 20, 'Aventure', NULL, 'France'),
	(33, 'La guerre du feu', 100, 1981, NULL, NULL, 'Aventure', NULL, 'France'),
	(34, 'Dersou Ouzala', 141, 1975, NULL, 9, 'Aventure', NULL, 'Japon'),
	(35, 'La forteresse cacgée', 139, 1958, NULL, 9, 'Aventure', NULL, 'Japon'),
	(36, 'Robin des bois', 116, 1991, NULL, NULL, 'Aventure', NULL, 'Canada'),
	(37, 'The Viking', 70, 1931, NULL, NULL, 'Aventure', NULL, 'Canada'),
	(38, 'La Communauté de l''anneau', 219, 2001, NULL, 19, 'Aventure', NULL, 'NZL'),
	(39, 'Les deux tours', 235, 2002, 38, 19, 'Aventure', NULL, 'NZL'),
	(40, 'Le retour du roi', 252, 2003, 39, 19, 'Aventure', NULL, 'NZL');


INSERT INTO Joue_dans
VALUES	(1, 1),
	(2, 2),
	(3, 3),
	(3, 8),
	(6, 4),
	(5, 4),
	(3, 5),
	(3, 6),
	(7, 6),
	(3, 11),
	(8, 12),
	(8, 14),
	(7, 17),
	(12, 23),
	(11, 24),
	(13, 26),
	(14, 27),
	(14, 28),
	(7, 29);


-- 
-- Requêtes :
--









