-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Окт 17 2017 г., 19:50
-- Версия сервера: 5.6.21
-- Версия PHP: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- База данных: `arena`
--

-- --------------------------------------------------------
CREATE DATABASE IF NOT EXISTS `arena` CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `arena`;
--
-- Структура таблицы `athlete`
--

CREATE TABLE IF NOT EXISTS `athlete` (
`id` int(10) unsigned NOT NULL,
  `full_name` varchar(255) NOT NULL,
  `DOB` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `career`
--

CREATE TABLE IF NOT EXISTS `career` (
`id` int(10) unsigned NOT NULL,
  `athleteID` int(11) NOT NULL,
  `sportID` int(11) NOT NULL,
  `category` int(11) NOT NULL,
  `coachID` int(11) NOT NULL,
  `clubID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `club`
--

CREATE TABLE IF NOT EXISTS `club` (
`id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `sport` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `club_competition`
--

CREATE TABLE IF NOT EXISTS `club_competition` (
`id` int(10) unsigned NOT NULL,
  `date` date NOT NULL,
  `name` varchar(255) NOT NULL,
  `cluboneID` int(11) NOT NULL,
  `clubtwoID` int(11) NOT NULL,
  `sportID` int(11) NOT NULL,
  `facilityID` int(11) NOT NULL,
  `sponsor` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `coach`
--

CREATE TABLE IF NOT EXISTS `coach` (
`id` int(10) unsigned NOT NULL,
  `full_name` varchar(255) NOT NULL,
  `sportID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `competition`
--

CREATE TABLE IF NOT EXISTS `competition` (
`id` int(10) unsigned NOT NULL,
  `date` date NOT NULL,
  `name` varchar(255) NOT NULL,
  `athleteID` int(11) NOT NULL,
  `sportID` int(11) NOT NULL,
  `facilityID` int(11) NOT NULL,
  `sponsor` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `facility`
--

CREATE TABLE IF NOT EXISTS `facility` (
`id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL,
  `address` varchar(255) NOT NULL,
  `capacity` int(32) unsigned NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `facility`
--

INSERT INTO `facility` (`id`, `name`, `type`, `address`, `capacity`) VALUES
(1, 'Заря', 'Стадион', 'г. Москва, ул. Гагарина 17а', 5000),
(4, 'Витебский ЦСК', 'стадион', 'г. Витебск, ул. Чапаева 1', 1000),
(6, 'Спартак', 'Стадион', 'г. Минск, пр-т Победителей 18', 5000);

-- --------------------------------------------------------

--
-- Структура таблицы `prize`
--

CREATE TABLE IF NOT EXISTS `prize` (
`id` int(10) unsigned NOT NULL,
  `competitionID` int(11) NOT NULL,
  `first` int(11) NOT NULL,
  `second` int(11) NOT NULL,
  `third` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `sport`
--

CREATE TABLE IF NOT EXISTS `sport` (
`id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `athlete`
--
ALTER TABLE `athlete`
 ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `career`
--
ALTER TABLE `career`
 ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `club`
--
ALTER TABLE `club`
 ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `club_competition`
--
ALTER TABLE `club_competition`
 ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `coach`
--
ALTER TABLE `coach`
 ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `competition`
--
ALTER TABLE `competition`
 ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `facility`
--
ALTER TABLE `facility`
 ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `prize`
--
ALTER TABLE `prize`
 ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `sport`
--
ALTER TABLE `sport`
 ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `athlete`
--
ALTER TABLE `athlete`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `career`
--
ALTER TABLE `career`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `club`
--
ALTER TABLE `club`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `club_competition`
--
ALTER TABLE `club_competition`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `coach`
--
ALTER TABLE `coach`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `competition`
--
ALTER TABLE `competition`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `facility`
--
ALTER TABLE `facility`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT для таблицы `prize`
--
ALTER TABLE `prize`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT для таблицы `sport`
--
ALTER TABLE `sport`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
