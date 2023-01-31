
DROP DATABASE IF EXISTS prueba; /*Borra la BD si existe*/

CREATE DATABASE prueba CHARACTER SET utf8mb4;/*Crea la BD*/
ALTER DATABASE prueba CHARACTER SET utf8mb3; /*Modifica el cjt de caracteres*/
SHOW CHARACTER SET; /*Muestra los conjuntos de caracteres que hay*/
SHOW COLLATION /*LIKE 'utf8%'*/; /*Muestra los cotejamientos*/
USE prueba; /*Activa la Bd para trabajar con ella*/
SHOW DATABASES; /*Muestra las BD*/
SHOW TABLES;	/*Muestra las tablas*/

CREATE TABLE IF NOT EXISTS ejemplo(	/*Creamos la tabla y sus campos*/
id int   primary key,
provincia VARCHAR(20) default('málaga'),
autor varchar(30) default ('Desconocido'),
numero INT AUTO_INCREMENT,
fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
periodicidad  enum('hola','adios') DEFAULT('hola'),
valores set('ddd','eee','fff') DEFAULT('ddd'),
edad int CHECK (edad NOT IN(22,33) ),
edad2 int CHECK (edad2 between 18 and 99 )
);
DROP TABLE IF EXISTS ejemplo;/*Borra la tabla*/


INSERT INTO ejemplo VALUES (100,'Cádiz','yo',3,'2023-01-9','adios','eee',31,53);/*inserta valores en todos los campos de una tabla*/

SELECT * from ejemplo;/*Consulta que nos muestra el contenido de una tabla*/

CREATE TABLE  IF NOT EXISTS ejemplo2 (
	id int,
    dni VARCHAR(9) UNIQUE,
    nombre VARCHAR(15) NOT NULL,
    edad int,
    idejemplo INT,
    FOREIGN KEY (idejemplo) REFERENCES ejemplo(id) ON UPDATE CASCADE ON DELETE CASCADE,
    constraint PK_ej2_id primary key (id),
    CONSTRAINT CK_ej2_eda CHECK (edad between 18 and 99 )
);


RENAME TABLE ejemplo to ejemplo1;/*Renombra una tabla*/

/*añadir un campo a la tabla  first(al principio), after campo(después del campo especificado)*/
ALTER TABLE ejemplo2 ADD apellidos VARCHAR(20) DEFAULT 'pérez' AFTER nombre;
ALTER TABLE ejemplo2 ADD CONSTRAINT fk_ej2_ide FOREIGN KEY (idejemplo) REFERENCES ejemplo1(id) ON UPDATE CASCADE ON DELETE CASCADE;

DESCRIBE  ejemplo2;/*Muestra la estructura de la tabla*/

/* modificar el tipo de datos de una columna y sus atributos*/
ALTER TABLE ejemplo2 MODIFY nombre VARCHAR(20) CHECK (nombre like 'a%');

/*cambiar el nombre de un campo, modificar el tipo de datos y sus atributos( hay q ponerlos todos aunque no se cambien*/
ALTER TABLE ejemplo2 CHANGE dni dni_usu INT ;

/*asignar un valor por defecto o eliminarlo*/
ALTER TABLE ejemplo2 ALTER nombre SET DEFAULT 'Andrés';
ALTER TABLE ejemplo2 ALTER nombre DROP DEFAULT;

/*insertamos datos en los campos especificados de la tabla*/
INSERT INTO ejemplo2(id,dni_usu,idejemplo) VALUES (6,24333654,100);
INSERT INTO ejemplo2(id,dni_usu,nombre,idejemplo) VALUES (6,24333654,'alicia',100);


/*permite eliminar una columna de la tabla o una constraint*/
ALTER TABLE ejemplo2 DROP edad;
ALTER TABLE ejemplo2 DROP CHECK CK_ej2_eda;
ALTER TABLE ejemplo2 DROP CONSTRAINT CK_ej2_eda;
ALTER TABLE ejemplo2 DROP FOREIGN KEY ejemplo2_ibfk_1;
 

/*activar/desactivar constraints y ver nombre si no lo he puesto yo*/
SHOW CREATE TABLE ejemplo2;/*Muestra la sentencia que se utiliza para crear la tabla y, por tanto, nos muestra el nombre que le han asignado por defecto a la constraint*/

/*vamos a modificar el campo referenciado  de la foreign*/
/*intento añadirle el autoincremento*/
ALTER TABLE ejemplo MODIFY id INT AUTO_INCREMENT;
/*no nos deja porque está referenciada por la foreign idejemplo*/
SET FOREIGN_KEY_CHECKS=0; /*Desactivamos las Foreigns y lo ejecutamos*/
SET FOREIGN_KEY_CHECKS=1;	/*Activamos otra vez las foreign*/
/*Otra opción sería borrar la constraint de la foreign, modificar y añadir otra vez la constraint*/