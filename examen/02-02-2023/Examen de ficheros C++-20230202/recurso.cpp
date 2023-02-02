/*librerias*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;
/*variables globales*/

/*struct datos
{
    data 
}; 
*/

/*funciones*/
/*esta funcion es para cambiar los espacios del las lineas introducidas por puntos*/
string espppun(string texto)
{
    for (size_t i = 0; i < texto.length(); i++)
    {
        if (texto[i] == ' ')
        {
            texto[i] == '.';
        }
    }
    return texto;
}
/*esta funcion hace lo inverso a espppun es decir cambia los puntos por espacios*/
string punpesp(string texto)
{
    for (size_t i = 0; i < texto.length(); i++)
    {
        if (texto[i] == '.')
        {
            texto[i] == ' ';
        }
    }
}
/*Esta funcion es para crear un archivo e introducir algo en el*/
void crear()
{
    string linea;
    ofstream file;
    file.open("algo.txt" /*c_str*/, ios::out);
    if (file.fail())
    {
        cout << "Ups, parece que algo a fallado!";
        exit(1);
    }
    else
    {
        cout << "Ingrese lo que quiera agregar:";

        getline(cin, linea);
        espppun(linea);
        file << espppun(linea) << endl;
        cout << "Archivo creado" << endl;
        return;
    }
}
/*esta funcion es para ver lo que hay en un archivo*/
void ver()
{
    string linea;
    ifstream file;
    file.open("algo.txt" /*c_str*/, ios::in);
    if (file.fail())
    {
        cout << "Ups, Parece que el archivo algo.txt no se encuentra en la carpeta";
        exit(1);
    }
    else
    {
        while (getline(file, linea))
        {
            cout << punpesp(linea);
        }
        return;
    }
}
/*esta es para meter mas cosas en un archivo ya creado*/
void aniadir()
{
    string linea;
    ofstream file;
    file.open("algo.txt" /*c_str*/, ios::app);
    if (file.fail())
    {
        cout << "Ups, parece que algo a fallado!";
        exit(1);
    }
    else
    {
        cout << "Ingrese lo que quiera agregar:";
        getline(cin, linea);
        espppun(linea);
        file << espppun(linea) << endl;
        cout << "Linea creada satisfactoriamente" << endl;
        return;
    }
}
/*con esta funcion puedo editar un dato especifico de un fichero  */
void editar(string codigo)
{
    int op;
    string linea;
    ifstream file;
    ofstream aux;
    file.open("algo.txt" /*c_str*/, ios::in);
    aux.open("algo_aux.txt" /*c_str*/, ios::out);
    if (file.fail() || aux.fail())
    {
        cout << "Ups, parece que algo ha fallado con los ficheros, por favor asegurate de que esten alli";
        exit(1);
    }
    else
    {
        while (getline(file, linea))
        {   /*recuerda meter las variable que faltan, con una estructura vamos bien la estructura tiene que ser global (-j0)*/
            stringstream memo(linea);
            /*     memo>>"variable"
               if (variable == codigo)
               {    do{
                   cout<<"Que te gustaria editar"<<endl;
                   cout<<"**********************"<<endl;
                   cout<<"1.algo"<<endl;
                   cout<<"2.salir"<<endl;
                   cout<<"elige una opcion: "
                   cin op;
                   if(cin.fail())
                   {
                       cin.clear();
                       cin.sync();
                       cout<<"La opcion introducida es incorrecta!. Porfavor introduzca una correcta"<<endl<<endl;
                   }
                   switch(op)
                   {
                       case 1:
                       cout << "Ingrese el algo:";
                       getline(cin, linea);
                        espppun(linea);
                           file << espppun(linea) << endl;
                        cout << "algo editado satisfactoriamente" << endl;
                       break;
                       case2:
                        cout<<"has salido de editar";
                       break;
                       default:
                        cout<<"La opcion introducida es incorrecta!. Porfavor introduzca una correcta"<<endl<<endl;
                       break;
                   }
                   }while(op!=2);
                   return;
               }
            */
        }
    }
}
/*y este es un menu too guapo :)*/
void menu()
{
    int op;
    do
    {
        cout << "opciones " << endl;
        cout << "******************" << endl;
        cout << "1.Crear/reemplazar" << endl;
        cout << "2.Ver" << endl;
        cout << "3.añadir" << endl;

        cout << "4.salir" << endl;
        cout << "******************" << endl;
        cout << "Elige una opcion: " << endl;
        cin >> op;
        if (cin.fail())
        {
            cin.clear(); /*se usa para limpiar el estado de error de el cin para que no falle*/
            cin.sync();  /*se usa para limpiar el buffer de cin*/
            cout << "La opcion introducida es incorrecta!. Porfavor introduzca una correcta" << endl
                 << endl;
        }

        switch (op)
        {
        case 1:
            crear();
            break;
        case 2:
            ver();
            break;
        case 3:
            aniadir();
            break;
        case 4:
            cout << "Has salido del programa";
            break;
        default:
            cout << "La opcion introducida es incorrecta!. Porfavor introduzca una correcta" << endl
                 << endl;
            break;
        }
    } while (op != 4);
}
