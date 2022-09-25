SELECT avnum,avnom FROM avion
WHERE avnum IN (
	SELECT trajet.avnum FROM trajet GROUP BY trajet.avnum);