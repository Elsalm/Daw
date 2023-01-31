create database ejercicio_1 character set utf8mb4;

use ejercicio_1;

create table profesor(
IdProfesor varchar(7) primary key,
NIF_P varchar(9) unique, 
Nombre varchar(14),
Especialidad varchar(7),
Telefono int(9)
);

create table Asignatura(CodAsignatura varchar(7) primary key,
Nombre varchar(14),/*14 por nombre y apellido no estoy seguro si se requiere nombre y apellido*/
IdProfesor varchar(7), 
FOREIGN KEY(IdProfesor) REFERENCES profesor(IdProfesor) 
on update cascade 
on delete cascade
);

Create table Alumno(
NumMatricula int primary key,
Nombre varchar(14),
FechaNacimiento date,
Telelfono int);

create table Recibe(
NumMatricula int,
IdProfesor varchar(7),
CursoEscolar int(4),/*yo supongo que es el año a lo que se refiere*/
primary key(NumMatricula, IdProfesor),
foreign key (NumMatricula)
references Alumno(NumMatricula)
on update cascade
on delete cascade,
foreign key (IdProfesor)
references profesor(IdProfesor)
on update cascade
on delete cascade
);

alter table profesor rename to Docente;