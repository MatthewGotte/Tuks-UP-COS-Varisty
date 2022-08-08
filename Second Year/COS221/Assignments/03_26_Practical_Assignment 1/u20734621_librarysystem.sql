-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: wheatley.cs.up.ac.za    Database: u20734621_librarysystem
-- ------------------------------------------------------
-- Server version	5.5.5-10.3.23-MariaDB-0+deb10u1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `book` (
  `isbn` varchar(17) NOT NULL,
  `book_title` varchar(45) DEFAULT NULL,
  `book_author` varchar(45) DEFAULT NULL,
  `book_genre` varchar(45) DEFAULT NULL,
  `year_published` int(4) DEFAULT NULL,
  PRIMARY KEY (`isbn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES ('978-0-7981-8166-2','Donkerdrif','Deon Meyer','Crime',2020),('978-0307474278','The Da Vinci Code','Dan Brown','Mystery',2003),('978-0345391803','The Hichhiker\'s Guide to the Galaxy','Douglas Adams','Science Fiction',1979),('978-1455519132','Egghead','Bo Burnham','Poetry',2013),('978-1983699740','The Prince Of Milk','Exurb1a','Science Fiction',2018),('9780241257265','How to Play Chess','Claire Summerscale','Non Fiction',2016),('9780330241182','To Kill a Mockingbird','Harper Lee','Domestic Fiction',1960),('9780451532244','Frankenstein','Mary Shelley','Horror Fiction',2013),('9780804172264','Inferno','Fan Brown','Mystery',2013),('9781250010292','White Crow','Marcus Sedgwick','Horror Fiction',2010),('9781439149034','Under the Dome','Stephen King','Horror Fiction',2009),('9781841351414','The Secret Island','Enid Blyton','Adventure',2002);
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `borrowed`
--

DROP TABLE IF EXISTS `borrowed`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `borrowed` (
  `borrowed_id` int(4) NOT NULL,
  `isbn` varchar(17) DEFAULT NULL,
  `member_id` int(4) DEFAULT NULL,
  `taken_date` date DEFAULT NULL,
  PRIMARY KEY (`borrowed_id`),
  KEY `isbn` (`isbn`),
  KEY `member_id` (`member_id`),
  CONSTRAINT `isbn` FOREIGN KEY (`isbn`) REFERENCES `book` (`isbn`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `member_id` FOREIGN KEY (`member_id`) REFERENCES `member` (`member_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `borrowed`
--

LOCK TABLES `borrowed` WRITE;
/*!40000 ALTER TABLE `borrowed` DISABLE KEYS */;
INSERT INTO `borrowed` VALUES (1110,'978-0345391803',1013,'2021-02-10'),(1111,'9780451532244',1010,'2021-02-14'),(1112,'9780241257265',1018,'2021-02-15'),(1113,'9781250010292',1016,'2021-02-12'),(1114,'9780330241182',1010,'2021-02-20'),(1115,'978-0-7981-8166-2',1016,'2021-02-22'),(1116,'9781841351414',1012,'2021-02-26'),(1117,'9781439149034',1019,'2021-02-05'),(1118,'978-0307474278',1018,'2021-02-10');
/*!40000 ALTER TABLE `borrowed` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `member`
--

DROP TABLE IF EXISTS `member`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `member` (
  `member_id` int(4) NOT NULL,
  `mem_lname` varchar(45) DEFAULT NULL,
  `mem_fname` varchar(45) DEFAULT NULL,
  `mem_initial` varchar(4) DEFAULT NULL,
  `mem_phone` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`member_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `member`
--

LOCK TABLES `member` WRITE;
/*!40000 ALTER TABLE `member` DISABLE KEYS */;
INSERT INTO `member` VALUES (1010,'Jefferson','Mike','W','0833335345'),(1011,'Smith','Kayla','A','0844842223'),(1012,'Botha','Kyle','F','0623478921'),(1013,'Thomas','Jeorge','H','0849236712'),(1014,'Dunne','Amy','Y','0612784390'),(1015,'Williams','Michelle','M','0825280001'),(1016,'De Beer','Johan','B','0725142783'),(1017,'Hoen Derdos','Dylan','D','0831119081'),(1018,'Govender','Brent','E','0741789012'),(1019,'Meyer','Marlize','P','0824462842');
/*!40000 ALTER TABLE `member` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-03-31 15:53:49
