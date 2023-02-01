use empleados;
/*1*/
select apellido1 from empleado;
/*2*/
select distinct apellido1 from empleado;
/*3*/
SELECT * FROM empleado;
/*4*/
select nombre, apellido1, apellido2 from empleado;
/*5*/
select codigo_departamento from empleado;
/*6*/
select DISTINCT codigo_departamento from empleado;
/*7*/
SELECT nombre, apellido1,apellido2, concat(nombre," ",apellido1," ",apellido2) as n_completo FROM empleado;
/*8*/
SELECT nombre, apellido1,apellido2, upper(concat(nombre," ",apellido1," ",apellido2)) as n_completo FROM empleado;
/*9*/
SELECT nombre, apellido1,apellido2, lower( concat(nombre," ",apellido1," ",apellido2)) as n_completo FROM empleado;
/*10*/
SELECT substring(nif, 1,8) as nif_sinletra
 , substring(nif,9,1 ) as letra_nif from empleado;
 /*11*/
 select nombre, presupuesto - gastos as pres_actual from departamento;
 /*12*/
 select nombre,presupuesto - gastos as pres_actual from departamento ORDER BY 1,2 ASC;
 /*13*/
  select nombre from departamento ORDER BY 1 ASC;
  /*14*/
select nombre from departamento ORDER BY 1 DESC;
/*15*/
SELECT apellido1,apellido2, nombre  from empleado order by 1,2 asc;
/*16*/
SELECT nombre, presupuesto from departamento order by 2 DESC limit 3;
/*17*/
SELECT nombre, presupuesto from departamento order by 2 ASC limit 3;
/*18*/
select nombre, gasto from departamento ORDER BY 2 DESC limit 2;
/*19*/
select nombre, gasto from departamento ORDER BY 2 ASC limit 2;
/*20*/
select * From empleado limit 2,5;
/*21*/
select nombre, presupuesto from departamento where presupuesto >=150000;
/*22*/
select nombre, presupuesto from departamento where presupuesto <= 5000;
/*23*/
SELECT nombre, presupuesto from departamento where presuouesto >= 100000 and presupuesto <=200000;
/*24*/
SELECT nombre, presupuesto from departamento where not presupuesto >= 100000 and presupuesto <=200000;
/*25*/
select nombre from departamento where presupuesto BETWEEN 100000 and 200000;
/*26*/
select nombre from departamento where NOT presupuesto BETWEEN 100000 and 200000;
/*27*/
select nombre, gastos, presupuesto from departamento where gastos > presupuesto;
/*28*/
select nombre, gastos, presupuesto from departamento where gastos < presupuesto;
/*29*/
select nombre, gastos, presupuesto from departamento where gastos = presupuesto;
/*30*/
select * from empleado where apellido2 is null ;
/*31*/
select * from empleado where apellido2 is not NULL;
/*32*/
SELECT * FROM empleado where apellido2 like "%López%";
/*33*/
SELECT * FROM empleado where apellido2 like "%Diaz%" OR apellido2 like "%Moreno%";
/*34*/
SELECT * FROM empleado where apellido2 IN("Diaz", "Moreno");
/*35*/
select nombre, apellido1,apellido2, nif from empleado where codigo_departamento in(3);
/*36*/
select nombre, apellido1,apellido2, nif from empleado where codigo_departamento in(2,4,5);


