/*Ejercicio 1: Realice un programa que pida al usuario el nombre de un fichero de texto y, continuación permita almacenar al usuario tantas frases como el usuario desee.*/
/*librerias*/
#include <iostream>
#include <cstdlib> 
#include<fstream>

/*parametros*/
using namespace std;

/*funciones*/

void escribir(string nombre);
bool continua();
void limcin()
{ if(cin.fail())
      {
            cin.clear();
            cin.sync();
      }}

/*Variables*/
char op;
string linea,nombre;
bool eprimera=1;

int main()
{
cout<<"Introduce el nombre del archivo: ";
cin>>nombre;
escribir(nombre);
return 0;
}

void escribir(string nombre)
{   
    ofstream file;
    file.open(nombre.c_str(), ios::out);

    if(file.fail())
    {
        cout<<"ups, parece que algo ha fallado, porfavor revisa el fichero"<<endl;
    }

    else
    {
        do
        {
            cout<<"Introdue la frase que gustes: ";
            fflush(stdin);
            getline(cin, linea);

            if (eprimera)
            {
               file<<linea;
               eprimera=0;
            }
            else
            {
                file<<"\n"<<linea;
            }
            
        } while (continua());

        cout<<"Has salido de el programa";
        file.close();
    }


}

bool continua()
{
      cout<<"te gustaria seguir añadiendo frases(y/n): ";
      cin>>op;
   op=toupper(op);
   cout<<op;
    while (op != 'Y' && op != 'N')
    {   
        cout<<"El parametro introducido es incorrecto ( 0j0)!\n\n";
        cout<<"te gustaria seguir añadiendo frases(y/n): ";
        cin>>op;
        op=toupper(op);
    }
    return op == 'Y' ? true :op == 'N'? false:false;
}