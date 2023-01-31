create database ejercicio9 char set utf8mb4;

use ejercicio9;

create table cliente(
numcliente int,
saldo float,
limcredito float,
descuento float
);

alter table cliente
modify column numcliente int not null primary key
auto_increment;


create table direccion(
coddireccion int,
via enum("s", "n"),
nombrevia varchar(20),
numero int,
piso int,
portal int,
codpostal int
);

alter table direccion
modify column coddireccion int not null primary key
;

create table posee(
numcliente int,
coddireccion int
);

alter table posee
add primary key(numcliente, coddireccion),
add foreign key (numcliente) references cliente(numcliente)
on update cascade
on delete cascade,
add foreign key (coddireccion) references direccion(coddireccion)
on update cascade
on delete cascade
;

create table pedido(
numpedido int,
fecha date,
numcliente int,
coddireccion int
);

alter table pedido
modify column numpedido int not null primary key,
add foreign key (numcliente) references cliente(numcliente)
on update cascade 
on delete cascade,
add foreign key (coddireccion) references direccion(coddireccion)
on delete cascade
on update cascade
;

create table articulo(
numarticulo int,
descripcion varchar(255)
);

alter table articulo
modify column numarticulo int not null primary key auto_increment
;

create table incluye(
numpedido int,
numarticulo int,
cantidad int
);

alter table incluye 
add primary key (numpedido, numarticulo),
add foreign key (numpedido) references pedido(numpedido)
on delete cascade
on update cascade,
add foreign key (numarticulo) references articulo(numarticulo)
;

create table fabrica(
numfabrica int,
telefono int
);

alter table fabrica 
modify column numfabrica int not null primary key auto_increment
;

create table distribuye(
numarticulo int,
numfabrica int,
cantsuministro int,
existencias int
);

alter table distribuye
add primary key (numarticulo, numfabrica),
add foreign key (numarticulo) references articulo(numarticulo)
on delete cascade 
on update cascade,
add foreign key (numfabrica) references fabrica(numfabrica)
;