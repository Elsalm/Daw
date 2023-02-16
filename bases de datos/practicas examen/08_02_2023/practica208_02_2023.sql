drop DATABASE IF EXISTS practica2_08_02_2023;
create DATABASE practica2_08_02_2023 CHAR SET utf8mb4;
use practica2_08_02_2023;


create table clientes
(
	id int,
    nombre VARCHAR(50),
    email varchar(100),
    felefono varchar(20)
);
alter table clientes
add PRIMARY KEY(id);

create table pedidos
(
	id int,
    fecha date,
    cliente_id int,
    total DECIMAL(6,2)
);
alter table pedidos
add PRIMARY KEY(id),
add FOREIGN KEY (cliente_id) references clientes(id);

CREATE table productos
(
	id int,
    nombre varchar(50),
    precio DECIMAL(10,2),
	cantidad int
);

alter table productos
add constraint pk_id primary key(id),
add unique (nombre);

create table detalles_pedido 
(
id int,
pedido_id int,
producto_id INT,
cantidad INT,
precio decimal(10,2)
);
alter table detalles_pedido
add constraint fk_pedido_id 
foreign key(pedido_id) REFERENCES pedido(id) 
on update cascade
on delete cascade,
add CONSTRAINT fk_producto_id
 FOREIGN KEY (producto_id)references producto(id)
 on UPDATE cascade
 on delete cascade;
 create table usuarios
 (
	id int,
    nombre varchar(50),
    email varchar(100)
 );
 alter table ususarios
 add CONSTRAINT pk_id PRIMARY KEY(id),
 add unique(email),
 MODIFY nombre VARCHAR(50) not null,
 modify email VARCHAR(100) not null;
 
 create table direcciones
 (
 
 );
 

/*create table paises
(	id int,
	nombre VARCHAR(50)
);
alter TABLE paises
MODIFY column id int PRIMARY key,
MODIFY column nombre VARCHAR(50) unique;
*/
