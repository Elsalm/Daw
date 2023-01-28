#include <iostream>
#include <wchar.h>
#include <vector>
#include <locale.h>
#include <math.h>
using namespace std;
struct datos
{
    vector<string> nombre;
    vector<double> masa, talla, imc;
    int nusuarios;
};
void pedir(datos &pe);
string resultados(double re);
void imprimir(datos im);
int main()
{   
    datos dat;
    setlocale(LC_ALL,"spanish");
    cout << "Programa que calcula estadisticas del IMC de n usuarios!" << endl
         << endl;
    cout << "------------------------------------------------" << endl
         << endl
         << endl;
         pedir(dat);
         imprimir(dat);
    
}
void pedir(datos &pe)
{   string memo;
    cout << "De cuantos usuarios quieres calcular las estadisticas:";
    cin >> pe.nusuarios;
    for (size_t i = 0; i < pe.nusuarios; i++)
    {
        cout << "Captura y validación de datos" << endl;
        cout << "-------------------------------" << endl;
        cout << "Digite el nombre del paciente: ";
        cin >> memo;
        pe.nombre.push_back(memo);
        cout << "Digite la masa en KG: ";
        cin >> pe.masa[i];
        cout << "Digite la talla en m: ";
        cin >> pe.talla[i];
    }

    cout << "Calculando y Valorando el I.M.C...." << endl
         << endl;
}
string resultados(double re)
{
    if (re < 18.5)
    {
        return "insuficiencia ponderal";
    }
    else if (re >= 18.5 or re <= 24.9)
    {
        return "Intervalo normal";
    }
    else if (re >= 25 or re <= 29.9)
    {
        return "Preobecidad";
    }
    else if (re >= 30 or re <= 34.9)
    {
        return "obeciadad clase I";
    }
    else if (re >= 35 or re <= 39.9)
    {
        return "obeciadad clase II";
    }
    else if (re >= 40)
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
    cout << "No.       Nombre         Masa(Kg)       Talla(M)       I.M.C.      Valora IMC"<<endl;
    cout << "---     -----------     ---------       --------       -------     ----------"<<endl;
    
    for (size_t i = 0; i < im.nusuarios; i++)
    {

        cout<<" "<<i<<"    "<<im.nombre[i]<<"    "<<im.talla[i]<<"    "<<im.imc[i]<<"    "<<resultados(im.imc[i]);
    }
    
}