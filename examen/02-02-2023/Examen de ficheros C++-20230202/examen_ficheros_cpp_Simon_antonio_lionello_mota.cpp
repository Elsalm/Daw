/*librerias*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <locale.h>
#include <wchar.h>
using namespace std;
/*variables globales*/

struct datos
{
    string codigo, nombres, apellido1, apellido2, asignatura;
    int nota_1, nota_2, nota_3, nota_final;
};
datos alumno;
/*funciones*/
void menu();
void agregar();
void buscar();
void modificar();
void eliminar();
void mosall();
void contnotas(int &notas);
void espppun(string &texto);
void elili();
/*funcion principal*/
int main()
{
    setlocale(LC_ALL, "es_ES");
    elili();
    menu();
    return 0;
}
/*y este es un menu too guapo :)*/
void menu()
{
    int op;
    do
    {
        cout << "opciones " << endl;
        cout << "******************" << endl;
        cout << "1.agregar alumno" << endl;
        cout << "2.buscar amuno" << endl;
        cout << "3.modificar alumno" << endl;
        cout << "4.eliminar alumno" << endl;
        cout << "5.ver todos los alumnos" << endl;
        cout << "6.salir" << endl;
        cout << "******************" << endl;
        cout << "Elige una opcion: ";
        cin >> op;
        if (cin.fail())
        {
            cin.clear(); /*se usa para limpiar el estado de error de el cin para que no falle*/
            cin.sync();  /*se usa para limpiar el buffer de cin*/
        }

        switch (op)
        {
        case 1:
            agregar();
            break;
        case 2:
            buscar();
            break;
        case 3:
            modificar();
            break;
        case 4:
            eliminar();
            break;
        case 5:
            mosall();
            break;
        case 6:
            cout << "Has salido del programa";
            break;
        default:
            cout << "La opcion introducida es incorrecta!. Porfavor introduzca una correcta" << endl
                 << endl;
            break;
        }
    } while (op != 6);
}
/*esta funcion cambia los espacios por puntos*/
void espppun(string &texto)
{
    for (size_t i = 0; i < texto.length(); i++)
    {
        if (texto[i] == ' ')
        {
            texto[i] = '.';
        }
    }
    return;
}
/*esta controla las notas si estan fuera del rango pues molesta a el usuario*/
void contnotas(int &notas)
{
    while (notas < 0 or notas > 10)
    {
        cout << "como un alumno va as sacar: " << notas << "?" << endl;
        cout << "introduce la nota correctamente" << endl;
        cin.sync();
        cin >> notas;
    }
    return;
}
/*esta funcion agrega alumnos*/
void agregar()
{
    string linea;
    ofstream file;
    file.open("alumnos.txt", ios::app);
    if (file.fail())
    {
        cout << "Ups,Parece que ha habido un porblema al encontrar el fichero";
        exit(1);
    }
    else
    {
        cout << "Porfavor, ingrese los siguientes datos:" << endl
             << endl;
        fflush(stdin);
        cout << "Codigo: ";
        getline(cin, alumno.codigo);
        cout << "Nombre: ";
        getline(cin, alumno.nombres);
        espppun(alumno.nombres);
        cout << "Apellido 1: ";
        getline(cin, alumno.apellido1);
        cout << "Apellido2: ";
        getline(cin, alumno.apellido2);
        cout << "Asignatura: ";
        getline(cin, alumno.asignatura);
        espppun(alumno.asignatura);
        cout << "Nota1: ";
        cin.sync();
        cin >> alumno.nota_1;
        contnotas(alumno.nota_1);
        cout << "Nota2: ";
        cin >> alumno.nota_2;
        contnotas(alumno.nota_2);
        cout << "Nota3: ";
        cin >> alumno.nota_3;
        contnotas(alumno.nota_3);
        cout << "Nota final: ";
        cin >> alumno.nota_final;
        contnotas(alumno.nota_final);
        stringstream cont(linea);
        cout << "\nEl alumno se ha añadido satisfactoriamente" << endl;
        file << "\n" << alumno.codigo << " " << alumno.nombres << " " << alumno.apellido1 << " " << alumno.apellido2 << " " << alumno.asignatura << " " << alumno.asignatura << " " << alumno.nota_1 << " " << alumno.nota_2 << " " << alumno.nota_3 << " " << alumno.nota_final << endl;
        file.close();
        return;
    }
}
/*esta funcion es para bucar a los alumnos*/
void buscar()
{
    string linea, codaux;
    ifstream file;
    file.open("alumnos.txt", ios::in);
    if (file.fail())
    {
        cout << "Ups,Parece que ha habido un porblema al encontrar el fichero";
        exit(1);
    }
    else
    {
        cout << "Porfavor ingresa el codigo del alumno que buscas" << endl;
        cout << "codigo: ";
        fflush(stdin);
        getline(cin, codaux);

        while (getline(file, linea))
        {
            stringstream cont(linea);
            cont >> alumno.codigo;
            cont >> alumno.nombres;
            cont >> alumno.apellido1;
            cont >> alumno.apellido2;
            cont >> alumno.asignatura;
            cont >> alumno.nota_1;
            cont >> alumno.nota_2;
            cont >> alumno.nota_3;
            cont >> alumno.nota_final;
            if (codaux == alumno.codigo)
            {
                cout << "Alumno encontrado satisfactoraimente" << endl;
                cout << "************************************" << endl
                     << endl
                     << endl;
                cout << "Datos Alumno" << endl;
                cout << "***************" << endl
                     << endl;
                cout << "Codigo \t Nombre \t Apellido1 \t Apellido2 \t Asignatura \t Nota1 \t Nota2 \t Nota3 \t Nota Final" << endl;
                cout << "*******************************************************************************************************************************************************************" << endl;
                cout << alumno.codigo << " \t " << alumno.nombres << "  \t " << alumno.apellido1 << "  \t " << alumno.apellido2 << "  \t " << alumno.asignatura << "  \t " << alumno.asignatura << "  \t " << alumno.nota_1 << "  \t " << alumno.nota_2 << "  \t " << alumno.nota_3 << "  \t " << alumno.nota_final << endl;
                cout << "******************************************************************************************************************************************************************" << endl
                     << endl;
                file.close();
                return;
            }
        }
        return;
    }
}
/*esta para modificar puedes legir un valor a tu gusto*/
void modificar()
{
    int op;
    string linea, codaux;
    ifstream file;
    ofstream aux;
    file.open("alumnos.txt", ios::in);
    aux.open("alumnos.txt", ios::out);
    if (file.fail())
    {
        cout << "Ups,Parece que ha habido un porblema al encontrar el fichero";
        exit(1);
    }
    else
    {
        cout << "Porfavor ingresa el codigo del alumno que buscas" << endl;
        cout << "codigo: ";
        fflush(stdin);
        getline(cin, codaux);
        while (getline(file, linea))
        {
            stringstream cont(linea);
            cont >> alumno.codigo;
            cont >> alumno.nombres;
            cont >> alumno.apellido1;
            cont >> alumno.apellido2;
            cont >> alumno.asignatura;
            cont >> alumno.nota_1;
            cont >> alumno.nota_2;
            cont >> alumno.nota_3;
            cont >> alumno.nota_final;
            if (codaux == alumno.codigo)
            {
                cout << "Alumno encontrado satisfactoraimente" << endl;
                cout << "************************************" << endl
                     << endl
                     << endl;
                cout << "Datos actuales" << endl;
                cout << "***************" << endl
                     << endl;
                cout << "Codigo \t Nombre \t Apellido1 \t Apellido2 \t Asignatura \t Nota1 \t Nota2 \t Nota3 \t Nota Final" << endl;
                cout << "*******************************************************************************************************************************************************************" << endl;
                cout << alumno.codigo << " \t " << alumno.nombres << "  \t " << alumno.apellido1 << "  \t " << alumno.apellido2 << "  \t " << alumno.asignatura << "  \t " << alumno.asignatura << "  \t " << alumno.nota_1 << "  \t " << alumno.nota_2 << "  \t " << alumno.nota_3 << "  \t " << alumno.nota_final << endl;
                cout << "******************************************************************************************************************************************************************" << endl
                     << endl;
                do
                {
                    cout << "Que te gustaria editar" << endl;
                    cout << "**********************" << endl;
                    cout << "1.Codigo" << endl;
                    cout << "2.Nombre" << endl;
                    cout << "3.Apellido 1" << endl;
                    cout << "4.Apellido2" << endl;
                    cout << "5.Asignatura" << endl;
                    cout << "6.Nota1" << endl;
                    cout << "7.Nota2" << endl;
                    cout << "8.Nota3" << endl;
                    cout << "9.Nota final" << endl;
                    cout << "10.salir" << endl;
                    cout << "elige una opcion: ";
                    cin.sync();
                    cin >> op;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout << "La opcion introducida es incorrecta!. Porfavor introduzca una correcta" << endl
                             << endl;
                    }
                    switch (op)
                    {
                    case 1:
                        cout << "Ingrese el Nuevo codigo:";
                        getline(cin, alumno.codigo);
                        espppun(alumno.codigo);

                        cout << "codigo editado satisfactoriamente" << endl;

                        break;
                    case 2:
                        cout << "Ingrese el Nuevo Nombre:";
                        getline(cin, alumno.nombres);
                        espppun(alumno.nombres);
                        cout << "Nombre editado satisfactoriamente" << endl;

                        break;
                    case 3:
                        cout << "Ingrese el Nuevo Apellido 1:";
                        getline(cin, alumno.apellido1);
                        espppun(alumno.apellido1);
                        cout << "Apellido1 editado satisfactoriamente" << endl;

                        break;
                    case 4:
                        cout << "Ingrese el Nuevo Apellido 2:";
                        getline(cin, alumno.apellido2);
                        espppun(alumno.apellido2);
                        cout << "Apellido 2 editado satisfactoriamente" << endl;

                        break;
                    case 5:
                        cout << "Ingrese la Nueva Asignatura :";
                        getline(cin, alumno.asignatura);
                        espppun(alumno.asignatura);
                        cout << "Asignatura editada satisfactoriamente" << endl;
                        break;
                    case 6:
                        cout << "Ingrese la Nueva Nota1:";
                        cin >> alumno.nota_1;
                        contnotas(alumno.nota_1);
                        cout << "Nota1 editada satisfactoriamente" << endl;

                        break;
                    case 7:
                        cout << "Ingrese la Nueva Nota2:";
                        cin >> alumno.nota_2;
                        contnotas(alumno.nota_2);
                        cout << "Nota2 editada satisfactoriamente" << endl;

                        break;
                    case 8:
                        cout << "Ingrese la Nueva Nota3:";
                        cin >> alumno.nota_3;
                        contnotas(alumno.nota_3);
                        cout << "Nota3 editada satisfactoriamente" << endl;
                        break;
                    case 9:
                        cout << "Ingrese la Nueva Nota Final:";
                        cin >> alumno.nota_final;
                        contnotas(alumno.nota_final);
                        cout << "Nota Final editada satisfactoriamente" << endl;
                        break;
                    case 10:
                        cout << "has salido de editar";
                       
                        aux<< "\n" << alumno.codigo << " " << alumno.nombres << " " << alumno.apellido1 << " " << alumno.apellido2 << " " << alumno.asignatura << " " << alumno.asignatura << " " << alumno.nota_1 << " " << alumno.nota_2 << " " << alumno.nota_3 << " " << alumno.nota_final << endl;;
                        break;
                    default:
                        cout << "La opcion introducida es incorrecta!. Porfavor introduzca una correcta" << endl
                             << endl;
                        break;
                    }

                } while (op != 2);
            }
            aux << "\n" << alumno.codigo << " " << alumno.nombres << " " << alumno.apellido1 << " " << alumno.apellido2 << " " << alumno.asignatura << " " << alumno.asignatura << " " << alumno.nota_1 << " " << alumno.nota_2 << " " << alumno.nota_3 << " " << alumno.nota_final << endl;
        }
        remove("alumnos.txt");
        rename("auxiliar.txt", "alumnos.txt");
        file.close();
        aux.close();
        return;
    }
}
/*esta funcion es para eliminar a los usuarios wajajaj*/
void eliminar()
{
    string linea, codaux;
    ifstream file;
    ofstream aux;
    file.open("alumnos.txt", ios::in);
    aux.open("alumnos.txt", ios::out);
    if (file.fail())
    {
        cout << "Ups,Parece que ha habido un porblema al encontrar el fichero";
        exit(1);
    }
    else
    {
        cout << "Porfavor ingresa el codigo del alumno que buscas" << endl;
        cout << "codigo: ";
        fflush(stdin);
        getline(cin, codaux);
        while (getline(file, linea))
        {
            stringstream cont(linea);
            cont >> alumno.codigo;
            cont >> alumno.nombres;
            cont >> alumno.apellido1;
            cont >> alumno.apellido2;
            cont >> alumno.asignatura;
            cont >> alumno.nota_1;
            cont >> alumno.nota_2;
            cont >> alumno.nota_3;
            cont >> alumno.nota_final;
            if (codaux == alumno.codigo)
            {
                cout << "Alumno eliminado satisfactoraimente" << endl;
                cout << "************************************" << endl;
            }
            aux << alumno.codigo << alumno.nombres << alumno.apellido1 << alumno.apellido2 << alumno.asignatura << alumno.asignatura << alumno.nota_1 << alumno.nota_2 << alumno.nota_3 << alumno.nota_final << endl;
        }
    }
    remove("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
    file.close();
    aux.close();
    return;
}
/*esta para mostrar a todos os usuarios*/
void mosall()
{   
    string linea;
    ifstream file;
    file.open("alumnos.txt", ios::in);
    if (file.fail())
    {
        cout << "Ups,Parece que ha habido un porblema al encontrar el fichero";
        exit(1);
    }
    else
    {
        cout << "Mostrando a todos los alumnos" << endl;
        cout << "************************************" << endl
             << endl
             << endl;
        cout << "Codigo \t Nombre \t Apellido1 \t Apellido2 \t Asignatura \t Nota1 \t Nota2 \t Nota3 \t Nota Final" << endl;
        cout << "*******************************************************************************************************************************************************************" << endl;
        while (getline(file, linea))
        {
            stringstream cont(linea);
            cont >> alumno.codigo;
            cont >> alumno.nombres;
            cont >> alumno.apellido1;
            cont >> alumno.apellido2;
            cont >> alumno.asignatura;
            cont >> alumno.nota_1;
            cont >> alumno.nota_2;
            cont >> alumno.nota_3;
            cont >> alumno.nota_final;
         
            cout << alumno.codigo << " \t " << alumno.nombres << "  \t " << alumno.apellido1 << "  \t " << alumno.apellido2 << "  \t " << alumno.asignatura << "  \t " << alumno.asignatura << "  \t " << alumno.nota_1 << "  \t " << alumno.nota_2 << "  \t " << alumno.nota_3 << "  \t " << alumno.nota_final << endl;
        }
        cout << "*******************************************************************************************************************************************************************" << endl;
        return;
    }
}
/*y esta funcion se supone que espara eliminar a las linas bacias*/
void elili()
{
    string linea, codaux;
    ifstream file;
    ofstream aux;
    file.open("alumnos.txt", ios::in);
    aux.open("alumnos.txt", ios::out);
    if (file.fail())
    {
        cout << "Ups,Parece que ha habido un porblema al encontrar el fichero";
        exit(1);
    }
    else
    {
        
        while (getline(file, linea))
        {
            stringstream cont(linea);
            cont >> alumno.codigo;
            cont >> alumno.nombres;
            cont >> alumno.apellido1;
            cont >> alumno.apellido2;
            cont >> alumno.asignatura;
            cont >> alumno.nota_1;
            cont >> alumno.nota_2;
            cont >> alumno.nota_3;
            cont >> alumno.nota_final;
            if (linea.length()<4)
            {
                cout << "Alumno eliminado satisfactoraimente" << endl;
                cout << "************************************" << endl;
            }
            aux << alumno.codigo << alumno.nombres << alumno.apellido1 << alumno.apellido2 << alumno.asignatura << alumno.asignatura << alumno.nota_1 << alumno.nota_2 << alumno.nota_3 << alumno.nota_final << endl;
        }
    }
    remove("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
    file.close();
    aux.close();
    return;
}