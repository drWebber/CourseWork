-- База данных: `arena`
-- DROP DATABASE IF EXISTS `arena`;
CREATE DATABASE IF NOT EXISTS `arena`;
USE `arena`;
-- --------------------------------------------------------

-- Структура таблицы `athlete`
CREATE TABLE `athlete` (
  `id` int(10) UNSIGNED NOT NULL,
  `full_name` varchar(255) NOT NULL,
  `DOB` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `club`
CREATE TABLE `club` (
  `id` int(10) UNSIGNED NOT NULL,
  `name` varchar(255) NOT NULL,
  `sportID` int(11) UNSIGNED
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `club_competition`
CREATE TABLE `club_competition` (
  `id` int(10) UNSIGNED NOT NULL,
  `date` date NOT NULL,
  `homeClubID` int(11) UNSIGNED NOT NULL,
  `awayClubID` int(11) UNSIGNED NOT NULL,
  `sportID` int(11) UNSIGNED NOT NULL,
  `facilityID` int(11) UNSIGNED NOT NULL,
  `sponsor` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `coach`
CREATE TABLE `coach` (
  `id` int(10) UNSIGNED NOT NULL,
  `full_name` varchar(255) NOT NULL,
  `sportID` int(11) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `competition`
CREATE TABLE `competition` (
  `id` int(10) UNSIGNED NOT NULL,
  `date` date NOT NULL,
  `name` varchar(255) NOT NULL,
  `sportID` int(11) UNSIGNED NOT NULL,
  `facilityID` int(11) UNSIGNED NOT NULL,
  `sponsor` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `facility`
CREATE TABLE `facility` (
  `id` int(10) UNSIGNED NOT NULL,
  `name` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL,
  `address` varchar(255) NOT NULL,
  `capacity` int(32) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `prize`
CREATE TABLE `prize` (
  `id` int(10) UNSIGNED NOT NULL,
  `competitionID` int(11) UNSIGNED NOT NULL,
  `goldMedalAthleteID` int(11) UNSIGNED NOT NULL,
  `silverMedalAthleteID` int(11) UNSIGNED NOT NULL,
  `bronzeMedalAthleteID` int(11) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `sport`
CREATE TABLE `sport` (
  `id` int(10) UNSIGNED NOT NULL,
  `name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `career`
CREATE TABLE `career` (
  `id` int(10) UNSIGNED NOT NULL,
  `athleteID` int(11) UNSIGNED NOT NULL,
  `sportID` int(11) UNSIGNED NOT NULL,
  `category` int(11) UNSIGNED NOT NULL,
  `coachID` int(11) UNSIGNED NOT NULL,
  `clubID` int(11) UNSIGNED DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `participation`
CREATE TABLE `participation` (
  `id` int(10) UNSIGNED NOT NULL,
  `athleteID` int(10) UNSIGNED NOT NULL,
  `competitionID` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `salary`
CREATE TABLE `salary` (
  `id` int(10) UNSIGNED NOT NULL,
  `date` DATE,
  `athleteID` int(10) UNSIGNED NOT NULL,
  `salary` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
-- --------------------------------------------------------

-- Индексы таблицы `athlete`
ALTER TABLE `athlete`
  ADD PRIMARY KEY (`id`);

-- Индексы таблицы `salary`
ALTER TABLE `salary`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_salary_athlete` (`athleteID`);  

-- Индексы таблицы `career`
ALTER TABLE `career`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_career_athlete` (`athleteID`),
  ADD KEY `FK_career_sport` (`sportID`),
  ADD KEY `FK_career_coach` (`coachID`),
  ADD KEY `FK_career_club` (`clubID`);

-- Индексы таблицы `club`
ALTER TABLE `club`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_club_sport` (`sportID`);

-- Индексы таблицы `club_competition`
ALTER TABLE `club_competition`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_clubCompetition_homeCulb` (`homeClubID`),
  ADD KEY `FK_clubCompetition_awayCulb` (`awayClubID`),
  ADD KEY `FK_clubCompetition_sport` (`sportID`),
  ADD KEY `FK_clubCompetition_facility` (`facilityID`);

-- Индексы таблицы `coach`
ALTER TABLE `coach`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_coach_sport` (`sportID`);

-- Индексы таблицы `competition`
ALTER TABLE `competition`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_competition_sport` (`sportID`),
  ADD KEY `FK_competition_facility` (`facilityID`);

-- Индексы таблицы `facility`
ALTER TABLE `facility`
  ADD PRIMARY KEY (`id`);

-- Индексы таблицы `prize`
ALTER TABLE `prize`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_prize_competitionID` (`competitionID`),
  ADD KEY `FK_prize_athleteG` (`goldMedalAthleteID`),
  ADD KEY `FK_prize_athleteS` (`silverMedalAthleteID`),
  ADD KEY `FK_prize_athleteB` (`bronzeMedalAthleteID`);

-- Индексы таблицы `sport`
ALTER TABLE `sport`
  ADD PRIMARY KEY (`id`);
  
-- Индексы таблицы `participation`
ALTER TABLE `participation`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_participation_athlete` (`athleteID`),
  ADD KEY `FK_participation_competition` (`competitionID`);
-- --------------------------------------------------------

-- AUTO_INCREMENT для таблицы `athlete`
ALTER TABLE `athlete`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
  
-- AUTO_INCREMENT для таблицы `salary`
ALTER TABLE `salary`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1;
  
-- AUTO_INCREMENT для таблицы `career`
ALTER TABLE `career`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

-- AUTO_INCREMENT для таблицы `club`
ALTER TABLE `club`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

-- AUTO_INCREMENT для таблицы `club_competition`
ALTER TABLE `club_competition`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

-- AUTO_INCREMENT для таблицы `coach`
ALTER TABLE `coach`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

-- AUTO_INCREMENT для таблицы `competition`
ALTER TABLE `competition`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

-- AUTO_INCREMENT для таблицы `facility`
ALTER TABLE `facility`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

-- AUTO_INCREMENT для таблицы `prize`
ALTER TABLE `prize`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

-- AUTO_INCREMENT для таблицы `sport`
ALTER TABLE `sport`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

  -- AUTO_INCREMENT для таблицы `competition`
ALTER TABLE `competition`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=0;
  
  -- AUTO_INCREMENT для таблицы `participation`
ALTER TABLE `participation`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1;
-- --------------------------------------------------------

-- Ограничения внешнего ключа таблицы `career`
ALTER TABLE `career` 
	ADD CONSTRAINT `FK_career_athlete` FOREIGN KEY (`athleteID`) REFERENCES `athlete` (`id`) ON DELETE RESTRICT ON UPDATE CASCADE,
	ADD CONSTRAINT `FK_career_sport` FOREIGN KEY (`sportID`) REFERENCES `sport` (`id`) ON DELETE RESTRICT ON UPDATE CASCADE,
	ADD CONSTRAINT `FK_career_coach` FOREIGN KEY (`coachID`) REFERENCES `coach` (`id`) ON DELETE RESTRICT ON UPDATE CASCADE,
	ADD CONSTRAINT `FK_career_club` FOREIGN KEY (`clubID`) REFERENCES `club` (`id`) ON DELETE RESTRICT ON UPDATE CASCADE;

-- Ограничения внешнего ключа таблицы `coach`
ALTER TABLE `coach`
  ADD CONSTRAINT `FK_coach_sport` FOREIGN KEY (`sportID`) REFERENCES `sport` (`id`) ON DELETE RESTRICT ON UPDATE CASCADE;

-- Ограничения внешнего ключа таблицы `club`
ALTER TABLE `club`
  ADD CONSTRAINT `FK_club_sport` FOREIGN KEY (`sportID`) REFERENCES `sport` (`id`) ON DELETE RESTRICT ON UPDATE CASCADE;
  
-- Ограничения внешнего ключа таблицы `club_competition`
ALTER TABLE `club_competition`
  ADD CONSTRAINT `FK_clubCompetition_homeCulb` FOREIGN KEY (`homeClubID`) REFERENCES `club` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_clubCompetition_awayCulb` FOREIGN KEY (`awayClubID`) REFERENCES `club` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_clubCompetition_sport` FOREIGN KEY (`sportID`) REFERENCES `sport` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_clubCompetition_facility` FOREIGN KEY (`facilityID`) REFERENCES `facility` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE;  
	
-- Ограничения внешнего ключа таблицы `club_competition`
ALTER TABLE `participation`
  ADD CONSTRAINT `FK_participation_athlete` FOREIGN KEY (`athleteID`) REFERENCES `athlete` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_participation_competition` FOREIGN KEY (`competitionID`) REFERENCES `competition` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE; 

-- Ограничения внешнего ключа таблицы `competition`
ALTER TABLE `competition`
  ADD CONSTRAINT `FK_competition_sport` FOREIGN KEY (`sportID`) REFERENCES `sport` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_competition_facility` FOREIGN KEY (`facilityID`) REFERENCES `facility` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE; 
	
-- Ограничения внешнего ключа таблицы `prize`
ALTER TABLE `prize`
  ADD CONSTRAINT `FK_prize_competitionID` FOREIGN KEY (`competitionID`) REFERENCES `competition` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_prize_athleteG` FOREIGN KEY (`goldMedalAthleteID`) REFERENCES `athlete` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_prize_athleteS` FOREIGN KEY (`silverMedalAthleteID`) REFERENCES `athlete` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_prize_athleteB` FOREIGN KEY (`bronzeMedalAthleteID`) REFERENCES `athlete` (`id`) 
	ON DELETE RESTRICT ON UPDATE CASCADE;
	
-- Ограничения внешнего ключа таблицы `salary`
ALTER TABLE `salary` 
	ADD CONSTRAINT `FK_salary_athlete` FOREIGN KEY (`athleteID`) REFERENCES `athlete` (`id`) ON DELETE RESTRICT ON UPDATE CASCADE;	
 
-- --------------------------------------------------------

-- Триггеры `career`
DELIMITER $$
CREATE TRIGGER `before_insert_coachID`
BEFORE INSERT ON `career`
FOR EACH ROW IF NEW.coachID NOT IN(SELECT `id` FROM `coach` WHERE `sportID` = NEW.sportID) THEN 
		SIGNAL SQLSTATE '45000' SET MYSQL_ERRNO=30000;
END IF
$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER `before_update_coachID`
BEFORE UPDATE ON `career`
FOR EACH ROW
IF NEW.coachID NOT IN(SELECT `id` FROM `coach` WHERE `sportID` = NEW.sportID) THEN 
		SIGNAL SQLSTATE '45000' SET MYSQL_ERRNO=30001;
END IF
$$
DELIMITER ;

-- Дамп данных таблицы `athlete`
INSERT INTO `athlete` (`id`, `full_name`, `DOB`) VALUES
(1, 'Васильев Василий Васильевич', '1984-01-04'),
(3, 'Васин Василий Васильевич', '1989-01-01'),
(4, 'Алексей Мохнач', '2002-03-03'),
(5, 'Антон Шунто', '1993-12-07'),
(6, 'Евгений Костюкевич', '1989-12-09'),
(7, 'Павел Волчецкий', '1997-12-16'),
(8, 'Александр Варванин', '1991-01-01'),
(9, 'Александр Скшинецкий', '2000-01-07'),
(10, 'Алексей Василевский', '1995-09-09'),
(11, 'Артем Челядинский', '1993-07-06'),
(12, 'Богдан Рудюк', '1990-08-21'),
(13, 'Сергей Чиж', '1991-01-01'),
(14, 'Василий Перепелкин', '1990-01-01'),
(16, 'Петров Петр', '1986-01-01');

-- Дамп данных таблицы `facility`
INSERT INTO `facility` (`id`, `name`, `type`, `address`, `capacity`) VALUES
(1, 'Заря', 'Стадион', 'г. Москва, ул. Гагарина 17а', 5000),
(2, 'Витебский ЦСК', 'Стадион', 'г. Витебск, ул. Чапаева 1', 1000),
(3, 'Спартак', 'Стадион', 'г. Минск, пр-т Победителей 18', 5000),
(4, 'СДЮШОР № 4', 'Теннисный корт', 'г. Витебск Московский проспект, 27, корп. 1', 500);

-- Дамп данных таблицы `sport`
INSERT INTO `sport` (`id`, `name`) VALUES
(1, 'Футбол'),
(5, 'Бильярд'),
(6, 'Хоккей'),
(7, 'Теннис'),
(9, 'Акробатика'),
(10, 'Велоспорт');

-- Дамп данных таблицы `coach`
INSERT INTO `coach` (`id`, `full_name`, `sportID`) VALUES
(1, 'Степанов Семен Петрович', 1),
(2, 'Шевченко Семен Петрович', 5),
(3, 'Стасенко Валерий Сергеевич', 1),
(5, 'Алексей Кучук', 6),
(6, 'Сергей Гуренко', 6),
(7, 'Алексей Кучук', 7),
(9, 'Акробатов Аркадий', 9);

-- Дамп данных таблицы `competition`
INSERT INTO `competition` (`id`, `date`, `name`, `sportID`, `facilityID`, `sponsor`) VALUES
(1, '2000-01-01', 'Золотая осень 2000', 7, 1, 'ОАО \"Витязь\"'),
(2, '1999-01-02', 'Золотой шар', 5, 2, 'ОАО \"Витебск Водоканал\"'),
(3, '2001-06-04', 'Первенство по акробатике', 9, 4, 'УО \"ВГУ\" им. П. М. Машерова'),
(4, '2000-05-11', 'Мир труд май', 9, 4, 'ОАО \"Нафтан\"'),
(5, '2000-06-02', 'Восьмерка', 10, 2, 'ОАО \"Витавтоматика\"'),
(7, '2007-04-30', 'Весна 2007', 7, 1, 'ОАО \"Нафтан\"'),
(8, '2008-03-17', 'Большой шлем', 7, 2, 'ОАО \"Витебск Водоканал\"'),
(9, '2003-01-01', 'Большой шлем 2003', 7, 3, 'ОАО \"Витязь\"'),
(13, '2007-01-01', 'Tour de France', 10, 4, 'ОАО \"Витебск Водоканал\"');

INSERT INTO `club` (`id`, `name`, `sportID`) VALUES
(1, 'Динамо', 6),
(2, 'Трактор', 6),
(3, 'Юность', 6),
(4, 'Крумкачи', 6),
(5, 'Нет', NULL);

-- Дамп данных таблицы `career`
INSERT INTO `career` (`id`, `athleteID`, `sportID`, `category`, `coachID`, `clubID`) VALUES
(3, 3, 5, 1, 2, 5),
(8, 1, 1, 1, 1, 5),
(9, 3, 7, 3, 7, 5),
(11, 4, 6, 1, 5, 4),
(12, 5, 6, 1, 5, 4),
(13, 6, 6, 1, 5, 4),
(14, 7, 6, 1, 5, 4),
(15, 8, 6, 1, 5, 4),
(16, 9, 6, 1, 6, 1),
(17, 10, 6, 2, 6, 1),
(18, 11, 6, 3, 6, 1),
(19, 12, 6, 2, 6, 1),
(20, 13, 6, 1, 6, 1),
(21, 14, 6, 2, 6, 1),
(22, 4, 7, 3, 7, 5),
(23, 5, 7, 3, 7, 5),
(24, 1, 1, 1, 3, 5),
(26, 16, 9, 4, 9, 5);

-- Дамп данных таблицы `prize`
INSERT INTO `prize` (`id`, `competitionID`, `goldMedalAthleteID`, `silverMedalAthleteID`, `bronzeMedalAthleteID`) VALUES
(1, 1, 7, 10, 9),
(2, 2, 13, 12, 11),
(3, 4, 4, 7, 5);

-- Дамп данных таблицы `club_competition`
INSERT INTO `club_competition` (`id`, `date`, `homeClubID`, `awayClubID`, `sportID`, `facilityID`, `sponsor`) VALUES
(1, '2000-01-01', 1, 4, 6, 2, 'ОАО \"Витязь\"'),
(2, '2013-01-02', 4, 1, 6, 2, 'ОАО \"Витебские продукты\"'),
(3, '2004-07-05', 1, 4, 6, 2, 'ООО \"Витэлла\"'),
(4, '2007-12-06', 4, 1, 6, 3, 'ООО \"ОкнаПлюс\"');

-- Дамп данных таблицы `participation`
INSERT INTO `participation` (`id`, `athleteID`, `competitionID`) VALUES
(1, 13, 1),
(2, 14, 2),
(4, 12, 5),
(5, 8, 3),
(6, 4, 8),
(7, 5, 8);
-- --------------------------------------------------------

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