/* 1) Affichez les noms et pr�noms des �tudiants de 1�re ann�e, dans l'ordre alphab�tique */
SELECT nom,prenom
FROM etudiant
WHERE niveau='1'
ORDER BY nom,prenom asc;

/* 2) Affichez les noms et pr�noms des �tudiants dont la premi�re lettre de nom est comprise entre A et C */
SELECT nom,prenom
FROM etudiant
WHERE nom BETWEEN 'A' AND 'C';

/* 3) Affichez les noms et pr�noms des �tudiants dont le nom ressemble � � � Du� � */
SELECT nom,prenom 
FROM etudiant
WHERE nom LIKE '%Du%';

/* 4) Affichez les noms et pr�noms des �tudiants du d�partement informatique n�s en 1977 et 1978 */
SELECT nom,prenom
FROM etudiant
WHERE departement='Informatique' AND (Anniversaire LIKE '%/%/1977' OR Anniversaire LIKE '%/%/1978');

/* 5) Affichez les noms et pr�noms des �tudiants en pr�cisant leur �ge. La fonction SYSDATE permet 
	  de fournir la date d�aujourd�hui. */
SELECT nom, prenom,extract(YEAR FROM SYSDATE)- extract(YEAR FROM TO_DATE(anniversaire))
FROM Etudiant;

/* 6) Affichez les �tudiants qui n�ont pas de date d�anniversaire */
SELECT * 
FROM Etudiant
WHERE anniversaire IS NULL;

/* 7) Affichez la liste des �tudiants de deuxi�me ann�e qui ont eu la moyenne dans la mati�re CX56 */
SELECT * 
FROM Etudiant
JOIN Moyenne ON Etudiant.num = Moyenne.numEtudiant
WHERE niveau='2' AND moyenne>=10 AND numCours='CX56';

/* 8) Affichez, pour chaque mati�re, la note minimale attribu�e, la note maximale, la note moyenne */
SELECT numCours, MIN(moyenne), MAX(moyenne), AVG(moyenne)
FROM Moyenne
GROUP BY numCours;

/* 9) Affichez le classement des �tudiants. Vous devez utiliser la moyenne g�n�rale de chaque
      �tudiant (cette moyenne doit �tre calcul�e en sachant que toutes les mati�res ont le 
	  m�me coefficient) */
SELECT nom,prenom,AVG(moyenne)
FROM moyenne m
JOIN etudiant e ON m.numEtudiant=e.num
GROUP BY numEtudiant,nom,prenom
ORDER BY AVG(moyenne) DESC;

/* 10) Faitez en sorte que GMP soit remplac� par � G�nie M�canique et Productique � dans la table " �tudiants " */
ALTER TABLE etudiant
MODIFY departement VARCHAR2(50);

UPDATE etudiant
SET departement = 'G�nie M�canique et Productique'
WHERE departement = 'GMP';

/* 11) Supprimez l�enregistrement correspondant � l��tudiant num�ro 15 */
DELETE FROM moyenne
WHERE numEtudiant=15;

DELETE FROM etudiant
WHERE num=15;