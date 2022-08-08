-- MariaDB dump 10.19  Distrib 10.4.18-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: u20734621_carrentals
-- ------------------------------------------------------
-- Server version	10.4.18-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `cars`
--

DROP TABLE IF EXISTS `cars`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cars` (
  `CarID` int(11) NOT NULL,
  `Description` varchar(45) DEFAULT NULL,
  `YearModel` year(4) DEFAULT NULL,
  PRIMARY KEY (`CarID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cars`
--

LOCK TABLES `cars` WRITE;
/*!40000 ALTER TABLE `cars` DISABLE KEYS */;
INSERT INTO `cars` VALUES (1,'Red Mercedez AMG',2020),(2,'White BMW XS',2017),(3,'Grey Mini Cooper JCW',2020),(4,'Silver Toyota Corolla',2015),(5,'Yellow Honda Jazz Sport',2021),(6,'Blue Nissan Amra',2018),(7,'Orange Toyota Hilux',2020);
/*!40000 ALTER TABLE `cars` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `CustomerID` int(11) NOT NULL,
  `Name` varchar(45) DEFAULT NULL,
  `Surname` varchar(45) DEFAULT NULL,
  `Title` varchar(45) DEFAULT NULL,
  `Address` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`CustomerID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'Mohammed','Abraham','Mr','2 Jean Drive'),(2,'Abby','Smith','Ms','514 Mackenzie St'),(3,'Refiloe','Molete','Mrs','6 Joker St'),(4,'Corlize','van Heerden','Ms','12 Lotus Ave'),(5,'Simone','Fourie','Dr','2 Duncan St'),(6,'Samantha','Hanna','Mrs','34 Lynwood St'),(7,'Rebecca','Duncan','Ms','111 Bondev Drive'),(8,'Gary','Lou','Mr','5555 Rands St'),(9,'Ronald','Wang','Prof','65 Quinton Ave'),(10,'Fatima','Vallee','Ms','987 Sable Road'),(11,'Thando','Moloi','Dr','9 Lira St'),(12,'Sphephle','Mangena','Ms','3333 Warden St'),(13,'Daniel','Alberts','Mrs','3 Peso St'),(14,'Jason','Mackenzie','Mr','98 Theo St'),(15,'Michael','Nouwens','Mr','18 De Villiers St');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer_bike`
--

DROP TABLE IF EXISTS `customer_bike`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer_bike` (
  `CustID` int(11) DEFAULT NULL,
  `BID` int(11) DEFAULT NULL,
  `RentedDate` date DEFAULT NULL,
  KEY `CustID_fk1` (`CustID`),
  KEY `BID_fk2` (`BID`),
  CONSTRAINT `BID_fk2` FOREIGN KEY (`BID`) REFERENCES `motorbikes` (`BikeID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `CustID_fk1` FOREIGN KEY (`CustID`) REFERENCES `customer` (`CustomerID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer_bike`
--

LOCK TABLES `customer_bike` WRITE;
/*!40000 ALTER TABLE `customer_bike` DISABLE KEYS */;
INSERT INTO `customer_bike` VALUES (1,1,'2021-11-11'),(4,2,'2020-12-10'),(8,3,'2020-08-14'),(9,4,'2020-07-06'),(14,5,'2021-11-11'),(15,6,'2020-11-11'),(14,7,'2020-11-11');
/*!40000 ALTER TABLE `customer_bike` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer_car`
--

DROP TABLE IF EXISTS `customer_car`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer_car` (
  `CustID` int(11) DEFAULT NULL,
  `CID` int(11) DEFAULT NULL,
  `ReturnedDate` date DEFAULT NULL,
  KEY `CID_fk1` (`CID`),
  KEY `CustID_fk2` (`CustID`),
  CONSTRAINT `CID_fk1` FOREIGN KEY (`CID`) REFERENCES `cars` (`CarID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `CustID_fk2` FOREIGN KEY (`CustID`) REFERENCES `customer` (`CustomerID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer_car`
--

LOCK TABLES `customer_car` WRITE;
/*!40000 ALTER TABLE `customer_car` DISABLE KEYS */;
INSERT INTO `customer_car` VALUES (1,1,'2021-11-11'),(4,2,'2020-11-09'),(8,3,'2020-02-14'),(9,4,'2020-06-06'),(14,5,'2021-11-11'),(1,6,'2021-01-01'),(4,7,'2020-11-09');
/*!40000 ALTER TABLE `customer_car` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `motorbikes`
--

DROP TABLE IF EXISTS `motorbikes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `motorbikes` (
  `BikeID` int(11) NOT NULL,
  `Type` varchar(45) DEFAULT NULL,
  `YearModel` year(4) DEFAULT NULL,
  PRIMARY KEY (`BikeID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `motorbikes`
--

LOCK TABLES `motorbikes` WRITE;
/*!40000 ALTER TABLE `motorbikes` DISABLE KEYS */;
INSERT INTO `motorbikes` VALUES (1,'Ducat\' V4S',2021),(2,'BMW S1000RR',2020),(3,'Honda Fireblade SP',2018),(4,'Yamaha YZF-R1M',2015),(5,'Kawasaki Ninja H2',2017),(6,'Kawasaki ZX-10R SE',2019),(7,'Yamaha YZF-R1',2020);
/*!40000 ALTER TABLE `motorbikes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `returned_bike`
--

DROP TABLE IF EXISTS `returned_bike`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `returned_bike` (
  `CustID` int(11) DEFAULT NULL,
  `BID` int(11) DEFAULT NULL,
  `ReturnedDate` date DEFAULT NULL,
  KEY `CustID` (`CustID`),
  KEY `BID` (`BID`),
  CONSTRAINT `BID` FOREIGN KEY (`BID`) REFERENCES `cars` (`CarID`),
  CONSTRAINT `CustID` FOREIGN KEY (`CustID`) REFERENCES `customer` (`CustomerID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `returned_bike`
--

LOCK TABLES `returned_bike` WRITE;
/*!40000 ALTER TABLE `returned_bike` DISABLE KEYS */;
INSERT INTO `returned_bike` VALUES (4,2,'2020-12-14'),(9,4,'2020-08-06'),(14,7,'2021-01-11'),(15,6,'2021-02-14');
/*!40000 ALTER TABLE `returned_bike` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `returned_car`
--

DROP TABLE IF EXISTS `returned_car`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `returned_car` (
  `CustID` int(11) DEFAULT NULL,
  `CID` int(11) NOT NULL,
  `ReturnedDate` date DEFAULT NULL,
  PRIMARY KEY (`CID`),
  KEY `CustID_fk` (`CustID`),
  CONSTRAINT `CID` FOREIGN KEY (`CID`) REFERENCES `cars` (`CarID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `CustID_fk` FOREIGN KEY (`CustID`) REFERENCES `customer` (`CustomerID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `returned_car`
--

LOCK TABLES `returned_car` WRITE;
/*!40000 ALTER TABLE `returned_car` DISABLE KEYS */;
INSERT INTO `returned_car` VALUES (4,2,'2020-12-14'),(8,3,'2020-02-16'),(9,4,'2020-08-06'),(4,7,'2020-12-14');
/*!40000 ALTER TABLE `returned_car` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-21  1:57:45
