CREATE DATABASE  IF NOT EXISTS `clinica` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `clinica`;
-- MySQL dump 10.13  Distrib 8.0.31, for Win64 (x86_64)
--
-- Host: localhost    Database: clinica
-- ------------------------------------------------------
-- Server version	8.0.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ejemplo1`
--

DROP TABLE IF EXISTS `ejemplo1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ejemplo1` (
  `id` int NOT NULL AUTO_INCREMENT,
  `provincia` varchar(20) DEFAULT (_utf8mb4'málaga'),
  `autor` varchar(30) DEFAULT (_utf8mb4'Desconocido'),
  `numero` int DEFAULT '1',
  `fecha` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `periodicidad` enum('hola','adios') DEFAULT (_utf8mb4'hola'),
  `valores` set('ddd','eee','fff') DEFAULT (_utf8mb4'ddd'),
  `edad` int DEFAULT NULL,
  `edad2` int DEFAULT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `ejemplo1_chk_1` CHECK ((`edad` not in (22,33))),
  CONSTRAINT `ejemplo1_chk_2` CHECK ((`edad2` between 18 and 99))
) ENGINE=InnoDB AUTO_INCREMENT=101 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ejemplo1`
--

LOCK TABLES `ejemplo1` WRITE;
/*!40000 ALTER TABLE `ejemplo1` DISABLE KEYS */;
INSERT INTO `ejemplo1` VALUES (100,'Cádiz','yo',3,'2023-01-08 23:00:00','adios','eee',31,53);
/*!40000 ALTER TABLE `ejemplo1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ejemplo2`
--

DROP TABLE IF EXISTS `ejemplo2`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ejemplo2` (
  `id` int NOT NULL,
  `dni` varchar(9) DEFAULT NULL,
  `nombre` varchar(15) NOT NULL,
  `edad` int DEFAULT NULL,
  `idejemplo` int DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `dni` (`dni`),
  KEY `idejemplo` (`idejemplo`),
  CONSTRAINT `ejemplo2_ibfk_1` FOREIGN KEY (`idejemplo`) REFERENCES `ejemplo1` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `CK_ej2_eda` CHECK ((`edad` between 18 and 99))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ejemplo2`
--

LOCK TABLES `ejemplo2` WRITE;
/*!40000 ALTER TABLE `ejemplo2` DISABLE KEYS */;
/*!40000 ALTER TABLE `ejemplo2` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-01-16 17:03:20
