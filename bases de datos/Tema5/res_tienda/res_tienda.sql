/*1*/
SELECT nombre FROM producto;
/*2*/
SELECT nombre , precio FROM producto;
/*3*/
SELECT * FROM producto;
/*4*/
SELECT nombre, precio, precio *1.90  AS dolares FROM producto;
/*5*/
SELECT nombre AS "nombre de producto", precio AS euros, precio*1.09 AS dólares FROM producto;
/*6*/
SELECT upper(nombre), precio FROM producto;
/*7*/
SELECT lower(nombre), precio FROM producto;
/*8*/
SELECT nombre,upper(left(nombre,2)) FROM fabricante;
/*9*/
SELECT nombre, round(precio) FROM producto;
/*10*/
SELECT nombre, truncate(precio,0) FROM producto;
/*11*/
SELECT codigo_fabricante FROM producto;
/*12*/
SELECT DISTINCT codigo_fabricante FROM producto;
/*13*/
SELECT nombre FROM fabricante ORDER BY nombre ASC;
/*14*/
SELECT nombre FROM fabricante ORDER BY nombre DESC;
/*15*/
SELECT nombre, precio FROM producto ORDER BY nombre ASC, precio desc;
/*16*/
SELECT * FROM fabricante LIMIT 5;
/*17*/
SELECT * FROM fabricante LIMIT 3,2;
/*18*/
SELECT nombre, precio FROM producto ORDER BY precio ASC LIMIT 1;
/*19*/
SELECT nombre, precio FROM producto ORDER BY precio DESC LIMIT 1;
/*20*/
SELECT nombre FROM fabricante WHERE codigo=2;
/*21*/
SELECT nombre FROM producto WHERE precio<=120;
/*22*/
SELECT nombre FROM producto WHERE precio>=400;
/*23*/
SELECT nombre FROM producto WHERE precio<400;
/*24*/
SELECT nombre FROM producto WHERE precio>=80 AND precio<300;
/*25*/
SELECT nombre FROM producto WHERE precio BETWEEN 60 AND 200;
/*26*/
SELECT nombre FROM producto WHERE precio>200 AND codigo_fabricante=6;
/*27*/
SELECT nombre FROM producto WHERE codigo_fabricante=1 OR codigo_fabricante=3 OR codigo_fabricante=5;
/*28*/
SELECT nombre FROM producto WHERE codigo_fabricante IN (1,3,5);
/*29*/
SELECT nombre,precio, precio*100 AS centimos FROM producto;
/*30*/
SELECT nombre FROM fabricante WHERE nombre LIKE ('s%');
/*31*/
SELECT nombre FROM fabricante WHERE nombre LIKE ('%e');
/*32*/
SELECT nombre FROM fabricante WHERE nombre LIKE ('%w%');
/*33*/
SELECT nombre FROM fabricante WHERE nombre LIKE ('__');
/*34*/
SELECT nombre FROM producto WHERE nombre LIKE ('%portatil%');
/*35*/
SELECT nombre FROM producto WHERE nombre LIKE ('%monitor%') AND precio<215;
/*36*/
SELECT  nombre, precio FROM producto WHERE precio>=180 ORDER BY precio DESC, nombre ASC;