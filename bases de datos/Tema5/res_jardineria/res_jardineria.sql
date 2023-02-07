/*1*/
select codigo_oficina, ciudad from oficina;
/*2*/
select ciudad, telefono from oficina where pais in ('españa');
/*3*/
SELECT nombre, apellido1, apellido2, email from empleado where codigo_jefe=7;
/*4*/
SELECT nombre, apellido1, apellido2, puesto from empleado where codigo_jefe is null;
/*5*/
SELECT nombre, apellido1, apellido2, puesto from empleado where  puesto not in ('representante ventas');
/*6*/
select * from cliente WHERE pais in ('spain');
/*7*/
SELECT estado from pedido;
/*8*/
select DISTINCT codigo_cliente from pago where year(fecha_pago) =2008;
select DISTINCT codigo_cliente from pago where  date_format(fecha_pago,'%Y')=2008;
select DISTINCT codigo_cliente from pago where fecha_pago BETWEEN '2008-01-01' and '2008-12-31';
/*9*/
select codigo_pedido, codigo_cliente, fecha_esperada,fecha_entrega from pedido where fecha_entrega > fecha_esperada;
/*10*/
select codigo_pedido, codigo_cliente, fecha_esperada,fecha_entrega from pedido where datediff(fecha_entrega,fecha_esperada)=-2;
select codigo_pedido, codigo_cliente, fecha_esperada,fecha_entrega from pedido where fecha_entrega = DATE_ADD(fecha_esperada, INTERVAL -2 DAY);
/*11*/
SELECT * from pedido where estado in ('rechazado') and year(fecha_pedido)=2009;
/*12*/
select * from pedido where estado in ('entregado') and date_format(fecha_pedido, '%m')=01;
/*13*/
select * from pago where forma_pago like '%paypal%' and date_format(fecha_pago, '%Y')=2008 ORDER BY fecha_pago asc;
/*14*/
SELECT DISTINCT forma_pago from pago;
/*15*/
select * from producto WHERE gama in ('ornamentales') AND cantidad_en_stock > 100 order by precio_venta desc;
/*16*/
select * from cliente where ciudad like '%Madrid%' and codigo_empleado_rep_ventas in (11,30);