/* 1) Affichez les noms et prénoms des étudiants de 1ère année, dans l'ordre alphabétique */
SELECT nom,prenom
FROM etudiant
WHERE niveau='1'
ORDER BY nom,prenom asc;

/* 2) Affichez les noms et prénoms des étudiants dont la première lettre de nom est comprise entre A et C */
SELECT nom,prenom
FROM etudiant
WHERE nom BETWEEN 'A' AND 'C';

/* 3) Affichez les noms et prénoms des étudiants dont le nom ressemble à « … Du… » */
SELECT nom,prenom 
FROM etudiant
WHERE nom LIKE '%Du%';

/* 4) Affichez les noms et prénoms des étudiants du département informatique nés en 1977 et 1978 */
SELECT nom,prenom
FROM etudiant
WHERE departement='Informatique' AND (Anniversaire LIKE '%/%/1977' OR Anniversaire LIKE '%/%/1978');

/* 5) Affichez les noms et prénoms des étudiants en précisant leur âge. La fonction SYSDATE permet 
	  de fournir la date d’aujourd’hui. */
SELECT nom, prenom,extract(YEAR FROM SYSDATE)- extract(YEAR FROM TO_DATE(anniversaire))
FROM Etudiant;

/* 6) Affichez les étudiants qui n’ont pas de date d’anniversaire */
SELECT * 
FROM Etudiant
WHERE anniversaire IS NULL;

/* 7) Affichez la liste des étudiants de deuxième année qui ont eu la moyenne dans la matière CX56 */
SELECT * 
FROM Etudiant
JOIN Moyenne ON Etudiant.num = Moyenne.numEtudiant
WHERE niveau='2' AND moyenne>=10 AND numCours='CX56';

/* 8) Affichez, pour chaque matière, la note minimale attribuée, la note maximale, la note moyenne */
SELECT numCours, MIN(moyenne), MAX(moyenne), AVG(moyenne)
FROM Moyenne
GROUP BY numCours;

/* 9) Affichez le classement des étudiants. Vous devez utiliser la moyenne générale de chaque
      étudiant (cette moyenne doit être calculée en sachant que toutes les matières ont le 
	  même coefficient) */
SELECT nom,prenom,AVG(moyenne)
FROM moyenne m
JOIN etudiant e ON m.numEtudiant=e.num
GROUP BY numEtudiant,nom,prenom
ORDER BY AVG(moyenne) DESC;

/* 10) Faitez en sorte que GMP soit remplacé par « Génie Mécanique et Productique » dans la table " étudiants " */
ALTER TABLE etudiant
MODIFY departement VARCHAR2(50);

UPDATE etudiant
SET departement = 'Génie Mécanique et Productique'
WHERE departement = 'GMP';

/* 11) Supprimez l’enregistrement correspondant à l’étudiant numéro 15 */
DELETE FROM moyenne
WHERE numEtudiant=15;

DELETE FROM etudiant
WHERE num=15;