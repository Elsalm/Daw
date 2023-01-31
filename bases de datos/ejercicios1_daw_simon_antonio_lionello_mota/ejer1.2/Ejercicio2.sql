create database Ejercicio2 char set utf8mb4;
 use Ejercicio2;
 create table Region(
 CodRegion varchar(7) primary key,
 Nombre varchar(8)
 );
 
 create table Provincia(
 CodProvincia varchar(7) primary key, 
 Nombre varchar(8),
 CodRegion varchar(7), 
 foreign key(CodRegion) references Region(CodRegion)
 on update cascade
 on delete cascade
 );
 
 create table Localidad(
 CodLocalidad varchar(7) primary key,
 Nombre varchar(8),
 CodProvincia varchar(7),
 foreign key (CodProvincia) references Provincia(CodProvincia)
 on update cascade
 on delete cascade
 );
 
 Create table Empleado(
 ID int primary key,
 DNI int unique,
 Nombre varchar(14),
 FechaNac date,
 Salario int,
 CodLocalidad varchar(7),
 foreign key(CodLocalidad) references Localidad(CodLocalidad)
 on update cascade
 on delete cascade
 );
 