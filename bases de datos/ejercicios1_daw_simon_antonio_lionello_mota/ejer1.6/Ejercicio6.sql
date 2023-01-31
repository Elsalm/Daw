create database ejercicio6 char set utf8mb4;

use ejercicio6;

create table director(
nombre varchar(14) primary key,
nacionalidad varchar(7)
);

create table pelicula(
id int primary key,
titulo varchar(14) not null,
productora varchar(14),
nacionalidad varchar(7),
fecha date,
director varchar(14),
foreign key (director) references director(nombre)
on update cascade
on delete cascade  
);

create table socio(
dni int primary key,
nombre varchar(14) not null,
direccion varchar(255),
telefono int,
avalador int,
foreign key (avalador) references socio(dni)
on delete cascade
on update cascade
);

 create table actores(
 nombre varchar(14) primary key,
 nacionalidad varchar(7),
 sexo enum("H","M")
 check(sexo in ("H","M"))
 );
 
create table ejemplar(
id_peli int,
numero int,
primary key(numero,id_peli),
estado varchar(12),
foreign key (id_peli) references pelicula(id)
on update cascade
on delete cascade
);

create table alquila(
dni int,
id_peli int,
numero int,
fechaalquiler date,
fechadevolcion date,
primary key(dni,id_peli,numero,fechaalquiler),
foreign key (dni) references socio(dni)
on update cascade
on delete cascade,
foreign key (id_peli) references ejemplar(id_peli)
on update cascade
on delete cascade,
foreign key (numero) references ejemplar(numero)
on update cascade
on delete cascade
);

create table actua(
actor varchar(14),
id_peli int,
prota enum("SI","NO") default "No",
primary key(actor,id_peli),
foreign key (actor)  references actores(nombre)
on update cascade
on delete cascade,
foreign key (id_peli) references pelicula(id)
on update cascade
on delete cascade,
check(prota in ("SI","NO"))
);

