#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale.h>
#include <wchar.h>
#include <string>

using namespace std;
struct asesoria
{
    string codigo, nombres, apellidos, edad, ciudad, genero, consulta;
    string codi, lineac;
    char op;
    int op2;
    bool encontrado = 0;
};
void buya(asesoria &bu); /*buya= buscar y añadir*/
void mos(asesoria mo);/*esto es nuevo es una funcion para mostrar lo que hay en el fichero*/
void editar(asesoria &ed);/*esta funcion es para acceder a un menu de edicion*/
void espp(asesoria &es); /*espacios por puntos*/
/*Generar un programa que pueda modificar, tantos asesores como se desee,
cualquier dato de un asesor en el archivo asesoria.txt, luego se debe mostrar los
datos de todos los asesores. Los campos del archivo asesoría son: código,
nombres, apellidos, edad, ciudad, género y consulta. */
int main()/*el main es super largo, pero la verdad es que lo largo de este programa son los no recuerdo como se les dice
eso que usamos para prevenir los errores en el programa por culpa del user*/
{
    setlocale(LC_ALL, "es_ES");
    asesoria asesores;
    do
    {
        cout << "Programa que modifica cualquier dato de un asesor" << endl;
        cout << "*************************************************" << endl
             << endl
             << endl;
        cout << "Introduzca el codigo del asesor que desea editar: ";
        getline(cin, asesores.codi);
        buya(asesores);
        while (asesores.encontrado == 0)
        {                          /*lo que hace es que mientras no encuentre el codigo del asesor pues te moleste hasta que metas uno bueno
                         aun que le deberia colocar una opcion de salida XD sera luego un 10 profe
                         */
            remove("auxiliar.xd"); // esto por si la de abajo no lo borra
            cout << "codigo no encontrado" << endl;
            cout << "*****************************" << endl;
            cout << "1) volver a intentarlo." << endl;
            cout << "0) salir." << endl;
            cout << "*****************************" << endl;
            cout << "Opcion:";
            fflush(stdin);
            cin >> asesores.op2;
            while (asesores.op2 != 1 && asesores.op2 != 0)
            { /*control para el control, la seguridadd es primero, creo que lo explique antes pero el fflush es una funcion de la libreria cstdlib
                 que nos permite limpiar el buffer de los cin, ak lo que dice es si lo que introdujo el usuario pues es incorrecto osea no es ni uno ni 0
                 pues lo molesta hasta que se ponga las pilas (ojo)
             */
                cout << "Opcion incorrecta, intentelo de nuevo.(1/0)" << endl;
                cout << "*****************************" << endl;
                cout << "1) volver a intentarlo." << endl;
                cout << "0) salir." << endl;
                cout << "*****************************" << endl;
                cout << "Opcion:";
                fflush(stdin);
                cin >> asesores.op2;
                cout << endl;
            }
            switch (asesores.op2)
            {
            case 1:
                cout << "Introduzca el codigo del asesor que desea editar: ";
                fflush(stdin);
                getline(cin, asesores.codi);
                buya(asesores);
                break;
            case 0:
                cout << "has salido del programa!";
                exit(1);
                break;
            }
        }

        cout << "Quieres editar otro asesor?(s/n):";
        cin >> asesores.op;
        while (asesores.op != 'N' && asesores.op != 'n' && asesores.op != 's' && asesores.op != 'S')
        {
            cout << "El parametro introducido es incorrecto, intentenlo de nuevo." << endl;
            cout << string(100, '\n');
            cout << "Quieres editar otro asesor?(s/n):";
            fflush(stdin);
            cin >> asesores.op;
        }
        if (asesores.op == 'N' || asesores.op == 'n')
        {
            cout << "has salido del programa!";
            exit(1);
        }

    } while (asesores.op == 's' || asesores.op == 'S');
}
void buya(asesoria &bu)
{
    ifstream file;
    fstream aux;
    file.open("asesoria.txt", ios::in);
    aux.open("auxiliar.xd", ios::out);

    string linea; /*lineac= linea de control*/
    if (file.fail() || aux.fail())
    {
        if (file.fail())
        {
            cout << "no se ha podido encontrar Asesoria.txt";
            exit(1);
        }
        else
        {
            cout << "no se ha podido encontrar auxiliar.xd";
            exit(1);
        }
    }

    while (!file.eof())
    {
        file >> bu.codigo;
        file >> bu.nombres;
        file >> bu.apellidos;
        file >> bu.ciudad;
        file >> bu.edad;
        file >> bu.genero;
        file >> bu.consulta;
        if (bu.codi == bu.codigo)
        {
            editar(bu);
            bu.encontrado = true;
        }
        bu.lineac = bu.codigo + " " + bu.nombres + " " + bu.apellidos + " " + bu.ciudad + " " + bu.edad + " " + bu.genero + " " + bu.consulta;
        aux << bu.lineac << endl;
        cout << linea;
    }
    if (bu.encontrado == 0)
    {
        remove("auxiliar.xd");
    }
    else if (bu.encontrado == 1)
    {
        remove("Asesoria.txt");
        rename("auxiliar.txt", "Asesoria.txt");
        mos(bu);
    }

    file.close();
    aux.close();
}
void editar(asesoria &ed)
{
    int op;
    cout << "\t\tEditando al acesor: " << ed.nombres << " " << ed.apellidos << endl;
    cout << "**********************************************************************" << endl;
    cout << "1) Nombres: " << ed.nombres << endl;
    cout << "2) apellidos: " << ed.apellidos << endl;
    cout << "3) ciudad: " << ed.ciudad << endl;
    cout << "4) edad: " << ed.edad << endl;
    cout << "5) genero: " << ed.genero << endl;
    cout << "6) consulta: " << ed.consulta << endl;
    cout << "0) salir." << endl;
    cout << "**********************************************************************" << endl;
    cout << " elija una opcion: ";
    cin >> op;
    while (op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 0)
    {
        /* mientras no sea ninguna de las opciones molesta al ususario :D */
        cout << "opcion incorrecta, intentelo de nuevo(1,2,3,4,5,6,0)." << endl;
        cout << string(100, '\n');
        int op;
        cout << "\t\tEditando al acesor: " << ed.nombres << " " << ed.apellidos << endl;
        cout << "**********************************************************************" << endl;
        cout << "1) Nombres: " << ed.nombres << endl;
        cout << "2) apellidos: " << ed.apellidos << endl;
        cout << "3) ciudad: " << ed.ciudad << endl;
        cout << "4) edad: " << ed.edad << endl;
        cout << "5) genero: " << ed.genero << endl;
        cout << "6) consulta: " << ed.consulta << endl;
        cout << "0) salir." << endl;
        cout << "**********************************************************************" << endl;
        cout << " elija una opcion: ";
        cin >> op;
    }

    fflush(stdin);
    switch (op)
    {
    case 1:
        cout << "Nuevos nombres: ";
        getline(cin, ed.nombres);
        break;
    case 2:
        cout << "Nuevos apellidos: ";
        getline(cin, ed.apellidos);
        break;
    case 3:
        cout << "Nueva ciudad: ";
        getline(cin, ed.ciudad);
        break;
    case 4:
        cout << "Nueva edad: ";
        getline(cin, ed.edad);
        break;
    case 5:
        cout << "Nuevo genere: "; /*jsjsjsjsjsj, echo a proposito*/
        getline(cin, ed.genero);
        break;
    case 6:
        cout << "Nueva consulta: ";
        getline(cin, ed.consulta);
        break;
    case 0:
        break;
    default:
        cout << "opcion erronea" << endl;
        cout << "**********************************************************************" << endl
             << endl
             << endl;
        cout << "1) Nombres: " << ed.nombres << endl;
        cout << "2) apellidos: " << ed.apellidos << endl;
        cout << "3) ciudad: " << ed.ciudad << endl;
        cout << "4) edad: " << ed.edad << endl;
        cout << "5) genero: " << ed.genero << endl;
        cout << "6) consulta: " << ed.consulta << endl;
        cout << "0) salir." << endl;
        cout << "**********************************************************************" << endl;
        cout << " elija una opcion: ";
        cin >> op;
        break;
    }
    espp(ed);
}
void espp(asesoria &es)
{
    for (size_t i = 0; i < es.nombres.size(); i++)
    {
        if (es.nombres[i] == ' ')
        {
            es.nombres[i] = '.';
        }
    }

    for (size_t i = 0; i < es.apellidos.size(); i++)
    {
        if (es.apellidos[i] == ' ')
        {
            es.apellidos[i] = '.';
        }
    }

    for (size_t i = 0; i < es.consulta.size(); i++)
    {
        if (es.consulta[i] == ' ')
        {
            es.consulta[i] = '.';
        }
    }
    for (size_t i = 0; i < es.genero.size(); i++)
    {
        if (es.genero[i] == ' ')
        {
            es.genero[i] = '.';
        }
    }
}
void mos(asesoria mo)
{/*Esto es muy censillo abre el fichero extrae espcio por espacio los datos el cod, el nombre, etc. etc. luego y lo mas interesante
    uso la funcion resize para que si el nombre o las variables que coloque no son del tamaño que coloque entonces les cambie el tamaño
    a uno minimo rellenandolas con espacios eso me permite un mejor ajuste del contenido que voy a mostrar*/
    ifstream file;
    file.open("asesoria.txt", ios::in);
    cout << "Mostrando archivo." << endl;
    cout << "******************"<<endl<<endl<<endl;
    cout << "Codigo      Nombres          Apellidos       Cidudad    Edad   Genero       Consulta" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    while (getline(file, mo.lineac))
    {
        file >> mo.codigo;
        file >> mo.nombres;
        file >> mo.apellidos;
        file >> mo.ciudad;
        file >> mo.edad;
        file >> mo.genero;
        file >> mo.consulta;
        if (file.eof())
        {
            break;
        }

        if (mo.nombres.length() < 15)
        {
            mo.nombres.resize(15, ' ');
        }
        if (mo.apellidos.length() < 15)
        {
            mo.apellidos.resize(15, ' ');
        }
        if (mo.ciudad.length() < 7)
        {
            mo.ciudad.resize(7, ' ');
        }
        if (mo.genero.length() < 9)
        {
            mo.genero.resize(9, ' ');
        }

        cout << mo.codigo + "    " + mo.nombres + "    " + mo.apellidos + "    " + mo.ciudad + "    " + mo.edad + "    " + mo.genero + "    " + mo.consulta << endl;
    }
    cout << "---------------------------------------------------------------------------------------" << endl<<endl<<endl;
}/*ejer25.2.0 terminado wajajajajaj :)*/
