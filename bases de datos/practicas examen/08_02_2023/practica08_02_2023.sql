drop DATABASE IF EXISTS practica08_02_2023;
create DATABASE practica08_02_2023 CHAR SET utf8mb4;
use practica08_02_2023;

create table usuario(
id varchar(9) unique primary key,
nombre VARCHAR(10),
email VARCHAR(50),
fecha_registro DATE
);

create table productos
(id VARCHAR(9) unique PRIMARY key,
nombre varchar(10),
decripcion varchar(225),
precio FLOAT
);
create table ventas
(id varchar(9) unique PRIMARY key,
	usuario_id VARCHAR(9) ,
    fecha_ventas DATE,
    cantidad INT,
    FOREIGN KEY (usuario_id) references usuario(id) 
    ON UPDATE CASCADE
    on delete cascade
);
create table categorias(
id VARCHAR(9) unique primary key,
nombre VARCHAR(10)
);
create table proveedores
(
id VARCHAR(9) unique primary key,
nombre varchar(9),
direccion varchar(255),
telefono VARCHAR(9)
);
create table pedidos(
id varchar(9) unique primary key, 
proveedor_id VARCHAR(9),
producto_id varchar(9),
fecha_pedido date,
cantidad INT,
FOREIGN KEY (proveedor_id) references proveedores(id) 
on DELETE cascade 
on update cascade,
FOREIGN KEY (producto_id) REFERENCES productos(id) 
on delete cascade
on UPDATE cascade
);
create table clientes
(
id varchar(9)primary key unique,
nombre varchar(15),
direccion VARCHAR(255),
telefono varchar(9)
);
create table detalles_pedido
(
id varchar(9) PRIMARY key unique,
pedido_id VARCHAR(9),
producto_id VARCHAR(9),
cantidad int,
FOREIGN KEY (producto_id) references productos(id) 
on delete CASCADE
on UPDATE cascade,
FOREIGN KEY (pedido_id) references pedidos(id)
);
create table factura
(	id varchar(9) unique primary key,
cliente_id varchar(9),
venta_id VARCHAR(9),
fecha_factura DATE,
FOREIGN KEY (cliente_id) REFERENCES clientes(id)
on UPDATE CASCADE
on DELETE cascade, 
FOREIGN KEY (venta_id) references ventas(id)
on update cascade
on delete cascade
);
create TABLE calificaciones(
id varchar(9) unique primary key,
usuario_id VARCHAR(9),
producto_id VARCHAR(9),
calificaion VARCHAR(255),
FOREIGN KEY (usuario_id) references usuario(id) 
on update cascade
on delete cascade,
foreign key (producto_id) references productos(id) 
on update cascade
on delete cascade
);