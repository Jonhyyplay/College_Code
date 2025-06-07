-- MySQL dump 10.13  Distrib 8.0.42, for Win64 (x86_64)
--
-- Host: localhost    Database: db_locadora
-- ------------------------------------------------------
-- Server version	8.0.42

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
-- Table structure for table `locacao`
--

DROP TABLE IF EXISTS `locacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `locacao` (
  `id` int NOT NULL AUTO_INCREMENT,
  `data_Inicio` date NOT NULL,
  `data_Termino` date NOT NULL,
  `valor` decimal(10,2) DEFAULT NULL,
  `forma_Pagamento` varchar(50) DEFAULT NULL,
  `status` varchar(30) DEFAULT NULL,
  `id_Cliente` int NOT NULL,
  `id_Veiculo` int NOT NULL,
  `id_Funcionario` int NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_Cliente` (`id_Cliente`),
  KEY `id_Veiculo` (`id_Veiculo`),
  KEY `id_Funcionario` (`id_Funcionario`),
  CONSTRAINT `locacao_ibfk_1` FOREIGN KEY (`id_Cliente`) REFERENCES `cliente` (`id`),
  CONSTRAINT `locacao_ibfk_2` FOREIGN KEY (`id_Veiculo`) REFERENCES `veiculo` (`id`),
  CONSTRAINT `locacao_ibfk_3` FOREIGN KEY (`id_Funcionario`) REFERENCES `funcionario` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `locacao`
--

LOCK TABLES `locacao` WRITE;
/*!40000 ALTER TABLE `locacao` DISABLE KEYS */;
INSERT INTO `locacao` VALUES (1,'2025-05-28','2026-05-27',2745.00,'Cartão de Crédito','Ativa',1,1,1),(2,'2025-05-27','2025-06-03',1050.00,'Pix','Ativa',2,3,2),(3,'2025-05-25','2025-05-27',180.00,'Dinheiro','Finalizada',3,2,3),(4,'2025-05-29','2025-06-05',1260.00,'Débito','Ativa',4,5,1),(5,'2025-05-26','2025-05-29',330.00,'Cartão de Crédito','Finalizada',5,4,2);
/*!40000 ALTER TABLE `locacao` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-06-06 22:59:28
