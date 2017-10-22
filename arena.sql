-- База данных: `arena`
DROP DATABASE IF EXISTS `arena`;
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
  `sportID` int(11) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Структура таблицы `club_competition`
CREATE TABLE `club_competition` (
  `id` int(10) UNSIGNED NOT NULL,
  `date` date NOT NULL,
  `name` varchar(255) NOT NULL,
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
  `athleteID` int(11) UNSIGNED NOT NULL,
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
  `clubID` int(11) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
-- --------------------------------------------------------

-- Индексы таблицы `athlete`
ALTER TABLE `athlete`
  ADD PRIMARY KEY (`id`);

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
  ADD PRIMARY KEY (`id`);

-- Индексы таблицы `facility`
ALTER TABLE `facility`
  ADD PRIMARY KEY (`id`);

-- Индексы таблицы `prize`
ALTER TABLE `prize`
  ADD PRIMARY KEY (`id`);

-- Индексы таблицы `sport`
ALTER TABLE `sport`
  ADD PRIMARY KEY (`id`);
-- --------------------------------------------------------

-- AUTO_INCREMENT для таблицы `athlete`
ALTER TABLE `athlete`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
  
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
-- --------------------------------------------------------


-- Дамп данных таблицы `athlete`
INSERT INTO `athlete` (`id`, `full_name`, `DOB`) VALUES
(1, 'Васильев Василий Васильевич', '1984-01-04'),
(2, 'Семенов Станислав Петрович', '2000-01-01'),
(3, 'Васин Василий Васильевич', '1989-01-01');

-- Дамп данных таблицы `facility`
INSERT INTO `facility` (`id`, `name`, `type`, `address`, `capacity`) VALUES
(1, 'Заря', 'Стадион', 'г. Москва, ул. Гагарина 17а', 5000),
(2, 'Витебский ЦСК', 'Стадион', 'г. Витебск, ул. Чапаева 1', 1000),
(3, 'Спартак', 'Стадион', 'г. Минск, пр-т Победителей 18', 5000),
(4, ' СДЮШОР № 4', 'Теннисный корт', 'г. Витебск Московский проспект, 27, корп. 1', 500);

-- Дамп данных таблицы `sport`
INSERT INTO `sport` (`id`, `name`) VALUES
(1, 'Футбол'),
(5, 'Бильярд');

-- Дамп данных таблицы `coach`
INSERT INTO `coach` (`id`, `full_name`, `sportID`) VALUES
(1, 'Степанов Семен Петрович', 1),
(2, 'Шевченко Семен Петрович', 5),
(3, 'Стасенко Валерий Сергеевич', 1);

-- Дамп данных таблицы `career`
INSERT INTO `career` (`id`, `athleteID`, `sportID`, `category`, `coachID`, `clubID`) VALUES
(1, 1, 1, 1, 2, NULL),
(2, 2, 5, 2, 1, NULL),
(3, 3, 1, 1, 3, NULL);