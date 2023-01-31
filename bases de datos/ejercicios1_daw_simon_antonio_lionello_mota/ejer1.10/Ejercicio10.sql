create database ejercicio10 char set utf8mb4;

use ejercicio10;

create table telefono(
numero int
);

alter table telefono
modify column numero int not null unique primary key
;

create table cliente(
codcliente int,
nombre varchar(14),
calle varchar(14),
numero int,
comuna varchar(14),
ciudad varchar(7)
);

alter table cliente
modify column codcliente int not null unique primary key
;

create table asociado(
codcliente int,
numtelefono int
);

alter table asociado
add primary key (codcliente, numtelefono),
add foreign key (codcliente) references cliente(codcliente)
on delete cascade
on update cascade,
add foreign key (numtelefono) references telefono(numero)
on delete cascade
on update cascade
;

create table venta(
idventa int,
montototal float,
codcliente int
);

alter table venta
modify column idventa int not null unique primary key,
add foreign key(codcliente) references cliente(codcliente)
;

create table producto(
idproducto int,
nombre varchar(14),
precio float,
stock int,
idcategoria int,
idproveedor int
);

create table categoria (
idcategoria int,
nombre varchar(14),
descripcion varchar(255)
);

alter table categoria 
modify column idcategoria int not null unique primary key
;

create table proveedor(
codproveedor int,
nombre varchar (14),
direccion varchar(255),
telefono int,
web varchar(255)
);

alter table proveedor 
modify column codproveedor int not null unique primary key
;
alter table producto 
modify column idproducto int not null unique primary key,
add foreign key (idcategoria) references categoria(idcategoria)
on delete cascade
on update cascade,
add foreign key (idproveedor) references proveedor(codproveedor)
on delete cascade
on update cascade
;

create table incluye(
idventa int,
idproducto int,
cantidad int,
precioventa float
);

alter table incluye
add primary key (idventa, idproducto),
add foreign key (idventa) references venta(idventa)
on delete cascade 
on update cascade,
add foreign key (idproducto) references producto(idproducto)
;
