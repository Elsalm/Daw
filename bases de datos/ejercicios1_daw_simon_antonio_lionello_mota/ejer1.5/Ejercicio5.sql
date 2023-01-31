create database ejercicio5 char set utf8mb4;

use ejercicio5;

create table sucursal(
codigo varchar(7) primary key,
direccion varchar(255),
telefono int
);

create table empleado(
dni int primary key,
nombre varchar(14) not null,
direccion varchar(255),
telefono int,
sucursal varchar(7),
foreign key (sucursal) references sucursal(codigo)
on update cascade
on delete cascade
);

create table revista(
numreg int primary key,
titulo varchar(60) not null,
periodicidad enum("Semanal", "Quincenal",
"Mensual","Trimestral" , "Anual") default "Mensual",
tipo varchar(10),
sucursal varchar(7),
foreign key (sucursal) references sucursal(codigo)
on update cascade
on delete cascade);

create table periodista(
dni varchar(9) primary key,
nombre varchar(14) not null,
direccion varchar(255),
telefono int,
especialisa varchar(20));

create table numrevista(
numreg int,
numero int,
numpaginas int,
fecha date,
cantvendidas int,
primary key(numreg,numero),
foreign key (numreg) references revista(numreg)
);