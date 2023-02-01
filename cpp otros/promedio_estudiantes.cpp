/*librerias*/
#include <iostream>
#include <locale.h>
#include <wchar.h>
using namespace std;

/*1. como crear una estructura(lo que supongo por que el enunciado es ambiguo)*/
/*le damos nombre a la estructura*/
struct datos
{ /*asignamos las variables y luego en la funcion pricipal(main)
     la llamamos*/
    double n_mate[3], n_fisica[3], n_ingles[3];
};
/*Variables globales*/

/*funciones*/
void pedir(datos &ped);
double calculo(double calcu[3]);
bool opcion();
void control(double &i);

/*fincion principal(main)*/
int main()
{ //uso esto para permitir al program imprimir caracteres especiales
    setlocale(LC_ALL,"es_ES");
    /*llamo a la estructuras*/
    do
    {
        cout << "Programa que hace el promedio de tres notas" << endl;
        cout << "*******************************************" << endl
             << endl;
        datos estudiantes;
        pedir(estudiantes);
        cout << "resultados:" << endl;
        cout << "***********" << endl
             << endl;
        cout << "Matematica: " << calculo(estudiantes.n_mate) << endl;
        cout << "Fisica: " << calculo(estudiantes.n_fisica) << endl;
        cout << "Ingles: " << calculo(estudiantes.n_ingles) << endl;

    } while (opcion());
    return 0;
}
/*esta fucnio sa bucles for para recorrer a los array 
y va almacenando datos*/
void pedir(datos &pe)
{
    cout << "ingresando notas:" << endl;
    cout << "****************" << endl
         << endl
         << endl;
    cout << "Matematicas" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout << "Nota" << i + 1 << "º :";
        cin >> pe.n_mate[i];
        control(pe.n_mate[i]);
    }
    cout << "Fisica" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout << "Nota" << i + 1 << "º :";
        cin >> pe.n_fisica[i];
        control(pe.n_fisica[i]);
    }
    cout << "Ingles" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout << "Nota" << i + 1 << "º :";
        cin >> pe.n_ingles[i];
        control(pe.n_ingles[i]);
    }
}/*esta funcion la utilizo para realizar los promedios de las notas
que el usuario ha ingresado */
double calculo(double calcu[3])
{
    double res;
    for (size_t i = 0; i < 3; i++)
    {
        res = res + calcu[i];
    }
    res = res / 3;
    return res;
}/*esta funcio la utilizo para devolver o verdadeo o falso
si la opcion elegida es si o no*/
bool opcion()
{
    char op;
    cout << "desea seguir haciendo calculos?(S/N):";
    cin >> op;
    while (op != 'n' and op != 'N' and op != 'S' and op != 's')
    {
        cout << "la opcion ingresada es incorrecta!(S/N):" << endl
             << endl;
        cout << "desea seguir haciendo calculos?(S/N):";
        cin >> op;
    }

    if (op == 'n' or op == 'N')
    {
        cout << "has salido del programa!";
        return 0;
    }
    if (op == 's' or op == 'S')
    {
        return 1;
    }
    return 0;
}/*y uso esta funcion para controlar si los datos
ingrsados son lo correctos*/
void control(double &i)
{
    while (i < 0)
    {
        cout << "la nota ingresads es menor a cero!(>0):" << endl;
        cout << "vuelve a ingresar la nota:";
        cin >> i;
    }
     while (i > 20)
    {
        cout << "la nota ingresads es mayor a 20!(<20):" << endl;
        cout << "vuelve a ingresar la nota:";
        cin >> i;
    }
}
