create database ejercicio11 char set utf8mb4;

use ejercicio11;

create table empleado(
codemp int,
nif int,
nombre varchar (10),
apellido varchar(10),
direccion varchar(255),
telefono int,
fechanac date,
salarioo float
);

alter table empleado 
modify column codemp int not null unique primary key,
modify column nif int unique
;

create table empcapacitado(
codemp int
);
alter table empcapacitado
modify column codemp int not null unique primary key,
add foreign key (codemp) references empleado(codemp) 
on delete cascade
on update cascade
;

create table empnocapacitado(
codemp int
);

alter table empnocapacitado
modify column codemp int not null unique primary key,
add foreign key (codemp) references empleado(codemp) 
on delete cascade
on update cascade;

create table curso(
codcurso int,
nombre varchar(14),
duracion date,
coste float
);

alter table curso
modify column codcurso int not null unique primary key
;

create table prerrequisito(
cursosolicitado int,
cursoprevio int
);

alter table prerrequisito
add primary key (cursosolicitado, cursoprevio),
add column obligatorio enum("S" , "N"),
add foreign key (cursosolicitado) references curso(codcurso)
on delete cascade
on update cascade,
add foreign key (cursoprevio) references curso(codcurso)
on delete cascade
on update cascade
;

create table edicion(
codcurso int,
fechainicio date,
lugar varchar(25),
horario time,
profesor int
);

alter table edicion
add primary key(codcurso, fechainicio),
add foreign key(codcurso) references curso(codcurso)
on delete cascade
on update cascade,
add foreign key(profesor) references empcapacitado(codemp)
;

create table recibe (
codempleado int,
codcurso int,
fechainicio date
);



alter table recibe
add primary key(codempleado, codcurso, fechainicio);
alter table recibe add foreign key(codempleado) references empleado(codemp)
on delete cascade
on update cascade;
alter table recibe add foreign key (codcurso, fechainicio) references edicion(codcurso,fechainicio)
on delete cascade
on update cascade
;

