create database ejercicio8 char set utf8mb4;
use ejercicio8;

create table cliente(
dni int,
nombre varchar(14),
direccion varchar(255),
localidad varchar (20),
fechanac date,
sexo enum("H", "M")
);

alter table cliente
add primary key(dni)
;

create table sucursal(
codsucursal int,
nombre varchar (14),
direccion varchar(255),
localidad varchar(20)
);

alter table sucursal
modify column codsucursal int  auto_increment,
auto_increment=101,
add primary key (codsucursal)
;

create table cuenta(
codsucursal int,
codcuenta varchar(7)
);

alter table cuenta
add primary key(codsucursal, codcuenta),
add foreign key(codsucursal) references sucursal(codsucursal) 
on update cascade 
on delete cascade
;

create table transaccion(
codsucursal int,
codcuenta varchar(7),
numtransaccion int,
fecha date,
cantidad int,
tipo varchar(7)
);


alter table transaccion
add primary key(codsucursal,codcuenta,numtransaccion),
add foreign key(codsucursal, codcuenta) references cuenta(codsucursal, codcuenta) 
on update cascade 
on delete cascade
;


create table cli_cuenta(
codsucursal int,
codcuenta varchar(7),
dni int
);

alter table cli_cuenta
add primary key(codsucursal, codcuenta, dni),
add foreign key(dni) references cliente(dni) 
on update cascade 
on delete cascade,
add foreign key(codsucursal, codcuenta) references cuenta(codsucursal,codcuenta) 
on update cascade 
on delete cascade
;
