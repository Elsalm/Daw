create schema ejercicio4 char set utf8mb4;

use ejercicio4;

create table cliente(
codcliente varchar(7) primary key,
dni int unique,
nombre varchar(14) not null,
direccion varchar(255),
telefono int
);

create table reserva(
numero int primary key,
fechainicio int,
fechafin int,
preciototal float,
codcliente varchar(7),
foreign key (codcliente) references cliente(codcliente)
on update cascade
on delete cascade
);

create table coche(
matricula varchar(5) primary key,
marca varchar(7) not null,
modelo varchar(7) not null,
color varchar(7),
preciohora float
);

create table avala(
avalado varchar(7) primary key,
avalador varchar(7),
foreign key (avalado) references cliente(codcliente)
on update cascade
on delete cascade,
foreign key (avalador) references cliente(codcliente)
on update cascade
on delete cascade
);

create table incluye(
numero int,
matricula varchar(5),
litrosgas float,
primary key(numero, matricula),
foreign key (numero) references reserva(numero)
on update cascade
on delete cascade,
foreign key (matricula) references coche(matricula)
);
 
 