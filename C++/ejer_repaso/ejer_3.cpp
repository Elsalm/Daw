#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <math.h>
using namespace std;
int i;
struct datos
{
    char nombre[10];
    float masa, talla, imc;
};
void pedir(datos &pe);
void imprimir(datos im);
string resultado(datos re);
int main()
{setlocale(LC_ALL, "");
    char pro = 's';
    while (int(pro) == 115 || int(pro) == 83)
    {
        cout << "Programa que calcula el índice de masa corporal!" << endl;
        cout << "------------------------------------------------" << endl
             << endl
             << endl;
        
        datos dat;
        pedir(dat);
        imprimir(dat);
        cout << "------------------------------------------------" << endl
             << endl
             << endl
             << endl;
        cout << "Desea procesar otro paciete: S o N  ";
        cin >> pro;
        while (int(pro) != 115 && int(pro) != 83 && int(pro) != 110 && int(pro) != 78) //esto fue un lio jsjsj, esta comprovacion lo que hace es ver si has introducido un caracte diferente a s,S,N,n
        {
            cout << "parametro incorrecto!" << endl;
            cout << "Desea procesar otro paciete: S o N:  ";
            cin >> pro;
        }
        
        if (int(pro) == 110 || int(pro) == 78)
        {
            cout<<"has salido del programa"<< endl;
            break;
        }
        
    }

    return 0;
}
// Aqui pide los datos del usuario
void pedir(datos &pe)
{
    cout << "Captura y validación de datos" << endl;
    cout << "-------------------------------" << endl;
    cout << "Digite el nombre del paciente: ";
    cin >> pe.nombre;
    cout << "Digite la masa en KG: ";
    cin >> pe.masa;
    cout << "Digite la talla en m: ";
    cin >> pe.talla;
    cout << "Calculando y Valorando el I.M.C...." << endl
         << endl;
}
// esta funcion es para dar la valoracion del IMC
string resultados(datos re)
{
    if (re.imc < 18.5)
    {
        return "insuficiencia ponderal";
    }
    else if (re.imc >= 18.5 or re.imc <= 24.9)
    {
        return "Intervalo normal";
    }
    else if (re.imc >= 25 or re.imc <= 29.9)
    {
        return "Preobecidad";
    }
    else if (re.imc >= 30 or re.imc <= 34.9)
    {
        return "obeciadad clase I";
    }
    else if (re.imc >= 35 or re.imc <= 39.9)
    {
        return "obeciadad clase II";
    }
    else if (re.imc >= 40)
    {
        return "obeciadad clase III";
    }
    return "a";
}
// esta funcion es para entregar todos los datos recogidos y los resultados
void imprimir(datos im)
{
    cout << "                         Imprimir datos y resultados" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "Nombre del paciente:                          ";
    for (i = 0; i < 10; i++)
    {
        if (int(im.nombre[i]) == 00) // aca prove usar ascii para controlar el salto de linea de la letra final del nombre del usuario
        {                            // 00 es caracter nulo mi array solo soporta 10 caracteres si el nombre es mas corto que eso pues hace el salto de linea cuando deje de detectar caracteres validos
            cout << im.nombre[i] << endl;
            i = 9;
        }
        else if (int(im.nombre[i]) != 00)
        {
            cout << im.nombre[i];
        }
    }
    cout << "Masa del paciente en KG:                      " << im.masa << endl;
    cout << "Talla del paciente en m:                      " << im.talla << endl;
    im.imc = im.masa / (pow(im.talla, 2));
    cout << "Indice de masa corporal KG/m2:                " << im.imc << endl;
    cout << "Valoracion del IMC:                           " << resultados(im) << endl;
}
