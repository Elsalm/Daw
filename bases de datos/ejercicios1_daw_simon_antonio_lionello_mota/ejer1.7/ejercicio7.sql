create database ejercicio7 char set utf8mb4;

use ejercicio7;

create table municipio(
id varchar(5) primary key,
nombre varchar(14) not null,
codpostal int,
provincia varchar(7)
);

create table vivienda(
id varchar(7) primary key,
tipovia  varchar(10) default "calle",
nombrevia varchar(14) not null,
numero int not null,
idmunicipio varchar(5),
foreign key (idmunicipio) references municipio(id)
on update cascade
on delete cascade
);

create table persona(
dni int primary key,
nombre varchar(14) not null,
fechanac date,
sexo enum("H","M"),
idvivienda varchar(7),
foreign key (idvivienda) references vivienda(id)
on delete cascade
on update cascade,
check (sexo in("H","M"))
);

create table cabezafamilia(
dni int primary key,
idvivienda varchar(7) unique,
foreign key (dni) references persona(dni)
on update cascade
on delete cascade,
foreign key (idvivienda) references vivienda(id)
on update cascade 
on delete cascade
);

create table posee(
dni int,
idvivienda varchar(7),
primary key(dni, idvivienda),
foreign key (dni) references persona(dni) 
on update cascade
on delete cascade,
foreign key (idvivienda) references vivienda(id)
on update cascade
on delete cascade 
);