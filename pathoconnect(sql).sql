-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Apr 10, 2019 at 09:02 PM
-- Server version: 5.7.24
-- PHP Version: 7.2.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `pathoconnect`
--

-- --------------------------------------------------------

--
-- Table structure for table `blood`
--

DROP TABLE IF EXISTS `blood`;
CREATE TABLE IF NOT EXISTS `blood` (
  `ID` varchar(4) NOT NULL,
  `Scientific_Name` text NOT NULL,
  `Category` text NOT NULL,
  `Reports` text NOT NULL,
  `Symptoms` text NOT NULL,
  `Prerrequisites` text NOT NULL,
  `cost` text NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `blood`
--

INSERT INTO `blood` (`ID`, `Scientific_Name`, `Category`, `Reports`, `Symptoms`, `Prerrequisites`, `cost`) VALUES
('B001', 'CHOLESTEROL, TOTAL', 'Cardiologist', 'Daily', 'High CHOLESTEROL Lead to Heart Problems', 'None', '100');

-- --------------------------------------------------------

--
-- Table structure for table `dc`
--

DROP TABLE IF EXISTS `dc`;
CREATE TABLE IF NOT EXISTS `dc` (
  `ID` varchar(4) NOT NULL,
  `Name` text NOT NULL,
  `Address` varchar(50) NOT NULL,
  `Locality` varchar(20) NOT NULL,
  `City` varchar(15) NOT NULL,
  `State` varchar(20) NOT NULL,
  `Ratings` text NOT NULL,
  `Timings` varchar(20) NOT NULL,
  `Contact Numer` text NOT NULL,
  `HCFacility` text NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `dc`
--

INSERT INTO `dc` (`ID`, `Name`, `Address`, `Locality`, `City`, `State`, `Ratings`, `Timings`, `Contact Numer`, `HCFacility`) VALUES
('D001', 'Shilpa Scan Centre\r\n\r\n', 'Palakol, Palakollu, Opp.Tele Phone ExchangeWest ', 'Godavari', 'Godavari', 'Andhra Pradesh', '4', '10:00 - 22:00', '8814223366', 'Available');

-- --------------------------------------------------------

--
-- Table structure for table `patients`
--

DROP TABLE IF EXISTS `patients`;
CREATE TABLE IF NOT EXISTS `patients` (
  `username` varchar(20) NOT NULL,
  `name` char(20) NOT NULL,
  `contact` varchar(13) NOT NULL,
  `DOB` varchar(9) NOT NULL,
  `password` varchar(15) NOT NULL,
  `email` varchar(30) NOT NULL,
  PRIMARY KEY (`username`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `patients`
--

INSERT INTO `patients` (`username`, `name`, `contact`, `DOB`, `password`, `email`) VALUES
('akashksinghal', 'Akash Kumar Singhal', '9868238010', '24022000', '12345678', 'akashksinghal@gmail.com'),
('rajneesh', 'Rajneesh', '8628089154', '222222\r3', 'dhedgvyf', 'jgdcehh@gmail.com');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
