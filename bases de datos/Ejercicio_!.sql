create database Ejercicio_1 character set utf8mb4;

use Ejercicio_1;
create table Profesor(idprofesor varchar(4) primary key,
 NIF_P varchar(9),Nombre varchar(14), 
 Especialidad varchar(6),telefono int(9));
create table Asignatura(CodAsignatura varchar(5) primary key, 
Nombre varchar(14), 
idprofesor varchar(4),
foreign key(idprofesor)  references Profesor(idprofesor) on update cascade on delete cascade);
create table Alumno(NumMatricula varchar(17) primary key,
