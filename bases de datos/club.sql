DROP DATABASE IF EXISTS club1;
CREATE DATABASE club1 CHARACTER SET utf8mb4;
use club1;
 drop table if exists socios;
drop table if exists inscritos;

 create table socios(
  numero integer auto_increment primary key,
  documento VARCHAR(8),
  nombre VARCHAR(20),
  domicilio VARCHAR(20)
 );
 
 create table inscritos (
  numerosocio integer not null,
  deporte VARCHAR(20) not null,
  cuotas integer,
  primary key(numerosocio,deporte),
  FOREIGN KEY (numerosocio) REFERENCES socios(numero)
 );
 
 insert into socios(documento,nombre,domicilio) values('23333333','Alberto Paredes','Colon 111');
 insert into socios(documento,nombre,domicilio) values('24444444','Carlos Conte','Sarmiento 755');
 insert into socios(documento,nombre,domicilio) values('25555555','Fabian Fuentes','Caseros 987');
 insert into socios(documento,nombre,domicilio) values('26666666','Hector Lopez','Sucre 344');

 insert into inscritos values(1,'tenis',1);
 insert into inscritos values(1,'basquet',2);
 insert into inscritos values(1,'natacion',1);
 insert into inscritos values(2,'tenis',9);
 insert into inscritos values(2,'natacion',1);
 insert into inscritos values(2,'basquet',0);
 insert into inscritos values(2,'futbol',2);
 insert into inscritos values(3,'tenis',8);
 insert into inscritos values(3,'basquet',9);
 insert into inscritos values(3,'natacion',0);
 insert into inscritos values(4,'basquet',10);