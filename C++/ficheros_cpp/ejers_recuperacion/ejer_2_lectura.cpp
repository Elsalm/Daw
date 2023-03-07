/*Ejercicio 2: Realice un programa que pida al usuario el nombre o ubicación de un fichero de texto a continuación de lectura a todo el fichero.*/
#include <iostream>
#include<cstdlib>
#include<fstream>

/*parametros*/
using namespace std;

/*funciones*/
/*Esta funcion sirve para leer*/
void leer(string narchivo);

/*variables*/
string narchivo, line;
bool eprimera=true;

/*Funcion principal*/
int main()
{
    cout<< "Por favor introduce el nombre de el archivo que deseas buscar:";

    fflush(stdin);
    getline(cin, narchivo);

    leer(narchivo);
    return 0;
}
void leer(string narchivo)
{
    ifstream file;
    file.open(narchivo.c_str(), ios::in);

    if (file.fail())
    {
        cout<<"Ups, parece que ha habido un problema, Revisa si el fichero existe"<<endl;

    }
    else
    {
        while (getline(file, line))
        {
            if (eprimera)
            {
                cout<<line;
                eprimera=false;
            }
            else
            {
                cout<<"\n"<<line;
            }
            
        }
        cout<<"\n";
        system("pause");
        file.close();
    }

}