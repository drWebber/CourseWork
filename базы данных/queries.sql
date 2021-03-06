------------------------------------------------------------------------
-- q1
------------------------------------------------------------------------
SELECT *
FROM `facility`
WHERE `type` = "Стадион" AND `capacity` > 1000

------------------------------------------------------------------------
-- q2
------------------------------------------------------------------------
SELECT *
FROM `athlete`
WHERE `id` IN (
	(SELECT `athleteID`
	 FROM `career`
	 WHERE `sportID` = 
		(SELECT `id`
		 FROM `sport`
		 WHERE `name` = "Хоккей")
	 AND `category` > 1
	)
)

------------------------------------------------------------------------
-- q3
------------------------------------------------------------------------
SELECT *
FROM `athlete`
WHERE `id` IN (
	SELECT `athleteID`
	FROM `career`
	WHERE `coachID` = 
		(SELECT `id`
		 FROM `coach`
		 WHERE full_name = "Сергей Гуренко")
	AND `category` > 0		
) 
------------------------------------------------------------------------
-- q4
------------------------------------------------------------------------
-- 1. Получаем id спортсменов, занимающихся более чем одним видом спорта
SELECT `athleteID`
FROM `career`
GROUP BY `athleteID`
HAVING COUNT(`athleteID`) > 1

-- 2. Получаем id в карьере, id спортсмена, id спорта
SELECT `athleteID`, `sportID` 
FROM `career`
WHERE `athleteID` IN(
	SELECT `athleteID`
	FROM `career`
	GROUP BY `athleteID`
	HAVING COUNT(`athleteID`) > 1
)

-- 3. Заменяем athleteID на реальное ФИО
SELECT ath.full_name, cr.sportID
FROM `athlete` AS ath 
INNER JOIN (
	SELECT `athleteID`, `sportID` 
	FROM `career`
	WHERE `athleteID` IN(
		SELECT `athleteID`
		FROM `career`
		GROUP BY `athleteID`
		HAVING COUNT(`athleteID`) > 1
	)
) AS cr
ON ath.id = cr.athleteID

-- 4. Заменяем sportID на реальное название
SELECT athCr.aName, sp.name
FROM `sport` AS sp
INNER JOIN (
	SELECT ath.full_name AS aName, cr.sportID AS sID
	FROM `athlete` AS ath 
	INNER JOIN (
		SELECT `athleteID`, `sportID` 
		FROM `career`
		WHERE `athleteID` IN(
			SELECT `athleteID`
			FROM `career`
			GROUP BY `athleteID`
			HAVING COUNT(`athleteID`) > 1
		)
	) AS cr
	ON ath.id = cr.athleteID
) AS athCr
ON sp.id = athCr.sID
ORDER BY athCr.aName ASC
------------------------------------------------------------------------
-- q5
------------------------------------------------------------------------
SELECT `full_name`
FROM `coach`
WHERE `id` IN (
	SELECT `coachID`
	FROM `career`
	WHERE `athleteID` IN(
		SELECT `id`
		FROM `athlete`
		WHERE `full_name` = "Васин Василий Васильевич"
	)
)
------------------------------------------------------------------------
-- q6
------------------------------------------------------------------------
SELECT *
FROM `competition`
WHERE `date` >= '1998-02-04' AND `date` <= '2000-02-05' AND `sponsor` = 'ОАО \"Витязь\"';
------------------------------------------------------------------------
-- q7
------------------------------------------------------------------------
SELECT spz.gpzG, spz.gpzS, bAth.full_name
FROM `athlete` AS bAth 
INNER JOIN
	(SELECT gpz.gName AS gpzG, sAth.full_name AS gpzS, gpz.bID AS gpzB
	 FROM `athlete` AS sAth 
	 INNER JOIN
		(SELECT gAth.full_name AS gName, pz.silver AS sID, pz.bronze AS bID
		 FROM `athlete` AS gAth
		 INNER JOIN 
			(SELECT `goldMedalAthleteID` AS gold, `silverMedalAthleteID` AS silver, `bronzeMedalAthleteID` AS bronze
			 FROM `prize`
			 WHERE `competitionID` = 
				(SELECT `id`
				 FROM `competition`
				 WHERE `name` = 'Золотая осень 2000')
			) AS pz
		 ON pz.gold = gAth.id) AS gpz
	ON gpz.sID = sAth.id) AS spz
ON spz.gpzB = bAth.id
------------------------------------------------------------------------
-- q8
------------------------------------------------------------------------
SELECT aDate, aName, spName, facility.name
FROM `facility`
INNER JOIN (
	SELECT `date` AS aDate, cName AS aName, sport.name AS spName, fID
	FROM `sport`
	INNER JOIN (
		SELECT `date`, `name` AS cName, `sportID` AS sID, `facilityID` AS fID
		FROM `competition`
		WHERE `facilityID` = (
			SELECT `id`
			FROM `facility`
			WHERE `name` = "Витебский ЦСК" AND `sportID` = (
				SELECT `id`
				FROM `sport`
				WHERE `name` = "Бильярд"
			)
		)
	) AS cmp
	ON sport.id = cmp.sID
) AS dCmp
ON facility.id = dCmp.fID
------------------------------------------------------------------------
-- q9
------------------------------------------------------------------------
-- Получаем список ИД клубов, подходящих по условиям
SELECT `homeClubID` AS cID
FROM `club_competition`
WHERE `date` >= '1998-02-04' AND `date` <= '2008-02-04'
UNION
SELECT `awayClubID`
FROM `club_competition`
WHERE `date` >= '1998-02-04' AND `date` <= '2008-02-04'

-- Получаем список ИД клубов, с кол-вом игроков
SELECT `clubID`, COUNT(`athleteID`)
FROM `career`
WHERE `clubID` IN(
	SELECT `homeClubID` AS cID
	FROM `club_competition`
	WHERE `date` >= '1998-02-04' AND `date` <= '2008-02-04'
	UNION
	SELECT `awayClubID`
	FROM `club_competition`
	WHERE `date` >= '1998-02-04' AND `date` <= '2008-02-04'
)
GROUP BY `clubID`

-- Заменяем ИД на названия клубов
SELECT `name`, icb.cn
FROM `club`
INNER JOIN(
	SELECT `clubID` AS cID, COUNT(`athleteID`) AS cn
	FROM `career`
	WHERE `clubID` IN(
		SELECT `homeClubID` AS cID
		FROM `club_competition`
		WHERE `date` >= '1998-02-04' AND `date` <= '2008-02-04'
		UNION
		SELECT `awayClubID`
		FROM `club_competition`
		WHERE `date` >= '1998-02-04' AND `date` <= '2008-02-04'
		)
		GROUP BY `clubID`
) AS icb
ON club.id = icb.cID
------------------------------------------------------------------------
-- q10
------------------------------------------------------------------------
SELECT ic.fn, `name` 
FROM `sport`
INNER JOIN (
	SELECT `full_name` AS fn, `sportID` AS sID
	FROM `coach`
	WHERE `sportID` = (
		SELECT `id`
		FROM `sport`
		WHERE `name` = "Футбол"
	)
) AS ic
ON sport.id = ic.sID
------------------------------------------------------------------------
-- q11
------------------------------------------------------------------------
SELECT *
FROM `athlete`
WHERE `id` IN(
	SELECT `id`
	FROM `athlete`
	WHERE `id` NOT IN (
		SELECT DISTINCT `athleteID`
		FROM `participation`
		WHERE `competitionID` IN(
			SELECT `id`
			FROM `competition`
			WHERE `date` >= '1995-02-04' AND `date` <= '2018-02-04'
		)
	)
)
------------------------------------------------------------------------
-- q12
------------------------------------------------------------------------
SELECT `sponsor`, COUNT(id)
FROM `competition`
WHERE `date` >= '2000-02-04'
GROUP BY `sponsor`
------------------------------------------------------------------------
-- q13
------------------------------------------------------------------------
SELECT `name`, cmp.date
FROM `facility`
INNER JOIN (
	SELECT `facilityID` AS id, `date`
	FROM `competition`
	WHERE `date` >= '2000-02-04' AND `date` <= '2007-02-04'
) AS cmp
ON facility.id = cmp.id
ORDER BY cmp.date ASC
------------------------------------------------------------------------
-- TRIGGER 1 - запрет внесения записи, если установленный тренер не тренерует по установленному спорту
------------------------------------------------------------------------
DELIMITER $$
CREATE TRIGGER `before_insert_coachID`
BEFORE INSERT ON `career`
FOR EACH ROW IF NEW.coachID NOT IN(SELECT `id` FROM `coach` WHERE `sportID` = NEW.sportID) THEN 
		SIGNAL SQLSTATE '45000' SET MYSQL_ERRNO=30000;
END IF
$$
DELIMITER ;
------------------------------------------------------------------------
-- TRIGGER 2 - запрет изменения записи, если установленный тренер не тренерует по установленному спорту
------------------------------------------------------------------------
DELIMITER $$
CREATE TRIGGER `before_update_coachID`
BEFORE UPDATE ON `career`
FOR EACH ROW
IF NEW.coachID NOT IN(SELECT `id` FROM `coach` WHERE `sportID` = NEW.sportID) THEN 
		SIGNAL SQLSTATE '45000' SET MYSQL_ERRNO=30001;
END IF
$$
DELIMITER ;
------------------------------------------------------------------------
-- Хранимая процедура
------------------------------------------------------------------------
-- Хранимая процедура начисления зп
DELIMITER $$  
CREATE PROCEDURE `pay_a_salary` (IN sal INT)  
BEGIN  
    DECLARE isLast BOOL;
	DECLARE aID, k INT;
    DECLARE cur CURSOR FOR SELECT athleteID, category FROM career;	
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET isLast = FALSE;  
    OPEN cur;  
  
	DELETE FROM `salary` WHERE `date` = DATE_SUB(CURRENT_DATE,INTERVAL DAYOFMONTH(CURRENT_DATE)-1 DAY);
    SET isLast = TRUE;  
    WHILE isLast DO  
        FETCH cur INTO aID, k;
		INSERT INTO `salary`(`date`, `athleteID`, `salary`) VALUES(DATE_SUB(CURRENT_DATE,INTERVAL DAYOFMONTH(CURRENT_DATE)-1 DAY), aID, k*sal);
    END WHILE;  
  
    CLOSE cur;    
END
$$
DELIMITER ;

SET @p0='200'; CALL `pay_a_salary`(@p0);