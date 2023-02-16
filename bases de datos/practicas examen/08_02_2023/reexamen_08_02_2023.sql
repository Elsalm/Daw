drop database if EXISTS ciclos;
create DATABASE ciclos character set utf8mb4;
use ciclos;

create table profesor
(
nif CHAR(9) unique primary key not null,
nombre varchar(50),
apedllidos VARCHAR(50),
telefono varchar(9),
sueldo decimal(4,2),
especialidad varchar(50),
fecha_alta DATE,
CONSTRAINT check_sueldo CHECK (sueldo BETWEEN 1500 and 2000)
);
create TABLE modulo
(
	codigo char(9) unique primary key not null,
    nombre VARCHAR(50),
    descripcion VARCHAR(255),
    horas int,
    nif_profesor char(9),
    foreign key (nif_profesor) references profesor(nif) 
    ON delete cascade 
    on update cascade,
   CONSTRAINT check_horas check(horas <= 300 )
);
CREATE table alumno
(
	num_expediente char(9) unique primary key not null,
    nif varchar(9) unique,
    nombre VARCHAR(50),
    apellidos varchar(50),
    domicilio varchar(50),
    poblacion varchar(50),
    cod_postal varchar(5),
    provincia varchar(50),
    telefono char(9)NOT null,
    sexo enum('hombre','mujer'),
    fec_nacimiento DATE not null
);

create table matricula
(
	expediente_alumno char(9) UNIQUE,
    cod_modulo char(9) unique,
    curso_escolar int not NULL,
    nota decimal(2,2),
    PRIMARY KEY(expediente_alumno, cod_modulo, curso_escolar),
    FOREIGN KEY (expediente_alumno) references alumno(num_expediente)
    on DELETE cascade 
    on update CASCADE,
    FOREIGN KEY (cod_modulo) references modulo(codigo)
    on DELETE cascade 
    on update CASCADE
);
alter table profesor
drop constraint check_sueldo,
add column cargo varchar(50),
rename column sueldo to salario
;
alter table modulo
drop column descripcion;
ALTER table modulo rename to ASIGNATURA;

alter table matricula 
add CONSTRAINT CHECK_nota CHECK(nota BETWEEN 0 and 10);
set foreign_key_checks=0;

alter table alumno
modify column sexo enum('h','m') CHECK (sexo in ('h','m'));
set foreign_key_checks=1;

