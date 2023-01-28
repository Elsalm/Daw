#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale>
#include <wchar.h>
#include <string>
using namespace std;
void buscar(string cod_alt, bool &encontrado);
void mos();
void camtam(string &nombre, string &apellido, string &ciudad, string &genero);
int main()
{
    string cod_alt;
    bool encontrado = 0;

    cout << "por favor introducir el codigo del asesor a eliminar: ";
    getline(cin, cod_alt);
    buscar(cod_alt, encontrado);
    mos();
    return 0;
}
void buscar(string cod_alt, bool &encontrado)
{
    string codigo, linea, nombres, apellidos, edad, ciudad, genero, consulta;
    ifstream file;
    ofstream aux;
    aux.open("auxiliar.txt", ios::out);
    file.open("asesoria.txt", ios::in);
    if (file.fail() || aux.fail())
    {
        cout << "No he podido encontrar asesoria.txt" << endl;
    }

    while (!file.eof())
    {
        file >> codigo;
        getline(file, linea);
        if (codigo == cod_alt)
        {
            cout << "Se a eliminado al asesor OjO" << endl;
            encontrado = 1;
            continue;
        }
        else
        {
            aux << codigo << linea << endl;
        }
    }
    file.close();
    aux.close();
    if (encontrado = 1)
    {
        remove("asesoria.txt");
        rename("auxiliar.txt", "asesoria.txt");
    }
    else
    {
        remove("auxiliar.txt");
    }
}
void mos()
{
    string codigo, linea, nombres, apellidos, edad, ciudad, genero, consulta;
    ifstream file;
    file.open("asesoria.txt", ios::in);

    if (file.fail())
    {
        cout << "Archivo no encontrado" << endl;
    }
    cout << "Codigo      Nombres          Apellidos       Cidudad    Edad   Genero       Consulta" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    while (!file.eof())
    {
        file >> codigo;
        file >> nombres;
        file >> apellidos;
        file >> ciudad;
        file >> edad;
        file >> genero;
        file >> consulta;

        camtam(nombres, apellidos, ciudad, genero);
        cout << codigo << "    " << nombres << "    " << apellidos << "    " << ciudad << "    " << edad << "    " << genero << "    " << consulta<<endl; 
    }
    cout << "---------------------------------------------------------------------------------------" << endl
         << endl
         << endl;
    file.close();
}
void camtam(string &nombre, string &apellido, string &ciudad, string &genero)
{
    if (nombre.length() < 15)
    {
        nombre.resize(15, ' ');
    }
    if (apellido.length() < 15)
    {
        apellido.resize(15, ' ');
    }
    if (ciudad.length() < 7)
    {
        ciudad.resize(7, ' ');
    }
    if (genero.length() < 9)
    {
        genero.resize(9, ' ');
    }
}
/*Generar un programa que pueda eliminar, tantos asesores como se desee,
cualquier asesor en el archivo asesoria.txt, luego se debe mostrar los datos de
todos los asesores. Los campos del archivo asesoría son: código, nombres,
apellidos, edad, ciudad, género y consulta. */