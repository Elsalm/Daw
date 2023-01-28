#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <math.h>
using namespace std;
int i;
struct datos
{
     char descripcion[10], codigo[10];
     string tipopago[3]{"Efectivo", "Cheque", "Tarjeta"};
     float precio, cantidad;
     int opciontp;
};
float filtronum(float &numero);
char filtroop(char letra);
void captura(datos &cap);
void imprimir(datos imp);
float descuento(datos desc);
int main()
{    datos venta;
     char pro;
     setlocale(LC_ALL, "");
     
     do
     {
          cout << "Programa que calcula el total a pagar de una factura!"<<endl;
          cout << "-----------------------------------------------------"<<endl;
          captura(venta);
          imprimir(venta);
          descuento(venta);
          cout << "-------------------------------------------" << endl;
          cout << "Desea procesar otra compra: S o N  ";
          cin >> pro;
          filtroop(pro);
        

char filtroop(char letra)
{
     while (int(letra) != 115 && int(letra) != 83 && int(letra) != 110 && int(letra) != 78)
     {
          cout << "parametro incorrecto!" << endl;
          cout << "Desea procesar otra compra: S o N:  ";
          cin >> letra;
     }
     return letra;
}
float filtronum(float &numero)
{
     while (numero < 0)
     {
          cout << "parametro incorrecto!" << endl;
          cout << "ingrese el valor nuevamente: ";
          cin >> numero;
     }
     return numero;
}

void captura(datos &cap)
{
     cout << "Captura y validación de datos...." << endl;
     cout << "Dijite el codigo del articulo: ";
     cin >> cap.codigo;
     cout << endl;
     cout << "Dijite la descripción del articulo: ";
     cin >> cap.descripcion;
     cout << endl;
     cout << "Digite el precio del articulo: ";
     cin >> cap.precio;
     filtronum(cap.precio);
     cout << endl;
     cout << "Ingrese la cantidad de compra: ";
     cin >> cap.cantidad;
     filtronum(cap.cantidad);
     cout << endl;
     cout << "Digite el numero del metdodo de pago: ";
     for (i = 0; i < 3; i++)
     {
          if (i == 2)
          {
               cout << i + 1 << ". " << cap.tipopago[i] << ": ";
          }
          else
          {
               cout << i + 1 << ". " << cap.tipopago[i] << " ";
          }
     }

     cin >> cap.opciontp;
     while (cap.opciontp <= 0 || cap.opciontp > 3)
     {
          cout << "parametro incorrecto!" << endl;
          cout << "ingrese el valor nuevamente: ";
          cin >> cap.opciontp;
     }
     cout << endl
          << endl;
     cout << "Calculando la cantidad a pagar...";
     cout << endl
          << endl
          << endl;
}
void imprimir(datos imp)
{
     cout << "      Imprimir datos y resultados" << endl;
     cout << "-------------------------------------------" << endl;
     cout << "Código del artículo:        " << imp.codigo << endl;
     cout << "Descripción del artículo:   " << imp.descripcion << endl;
     cout << "Precio del artículo:        " << imp.precio << endl;
     cout << "Cantidad compra:            " << imp.cantidad << endl;
     cout << "Total venta:                " << (imp.cantidad * imp.precio) << endl;
     cout << "Forma de pago:              " << imp.tipopago[imp.opciontp - 1] << endl;
     cout << "Descuento a aplicar:        " << descuento(imp) << endl;
     cout << "Valor a pagar:              " << (imp.cantidad * imp.precio) - descuento(imp) << endl;
}
float descuento(datos desc)
{ float descu;
     switch (desc.opciontp)
     {
     case 1:
          descu=(desc.cantidad * desc.precio) * 0.1;
          break;
     case 2:
          descu=(desc.cantidad * desc.precio) * 0.5;
          break;
     case 3:
         descu=(desc.cantidad * desc.precio);
          break;
     }
     return descu;
}