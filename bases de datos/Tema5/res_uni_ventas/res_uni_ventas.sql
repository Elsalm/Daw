use universidad;
-- select*from persona;
/*1*/
select apellido1,apellido2,nombre from persona where tipo = 'alumno' order by 1 desc;
/*2*/
select apellido1,apellido2,nombre from persona where telefono is null and tipo = 'alumno';
select *from persona where year(fecha_nacimiento)=1999 and tipo = 'alumno';
/*4*/
select*from persona where telefono is null and nif like '%k' and tipo = 'profesor';
/*5*/
select*from asignatura where cuatrimestre = 1 and curso=3 and id_grado= 7;
/*ventas*/
use ventas;
/*1*/
select * from pedido where fecha order by fecha desc;  
/*2*/
select * from pedido where fecha order by total desc limit 2;  
/*3*/
select distinct id_cliente from pedido;
/*4*/
select * from pedido where year(fecha)=2017 and total>500;
/*5*/
select nombre, apellido1,apellido2 from comercial where comisión between 0.05 and 0.11;
/*6*/
select comisión from comercial order by 1 desc limit 1;
/*7*/
select nombre,apellido1,apellido2 from cliente where apellido2 is not null order by 2 asc;
/*8*/
select nombre from cliente where nombre like 'A%n' or nombre like 'P%'  order by 1;
/*9*/
select nombre from cliente where not nombre like 'A%'order by 1;
/*10*/
select distinct nombre from comercial where nombre like  '%el' or  nombre like '%o';

