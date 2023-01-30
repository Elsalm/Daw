#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale>
#include <wchar.h>
#include <string>
#include <sstream>
using namespace std;
void buscar(string cod_alt,bool &encontrado);/*pues esta funcion busca XD(la explicacion esta mas abajo)*/
void mos()/*esta es para mostrar uwu*/;
void camtam(string &nombre, string &apellido, string &ciudad, string &genero)/*esta para cabiar el tamaño de los strings (esta funcion es para evitar tocks)*/;
bool yon(char op)/*esta funcion es para el bucle la verdad es que con un bool puedes hacer muchas cosas jjsjs*/;
int main()
{
    string cod_alt;
     bool encontrado = 0;
    char op;
do
{   fflush(stdin);
     cout << "por favor introducir el codigo del asesor a eliminar: ";
    getline(cin, cod_alt);
    buscar(cod_alt,encontrado);
    if (encontrado)
    {
       mos();
    }
    cout<<endl<<"te gustaria seguir eliminando asesores?(S/N):";
    cin>>op;
    fflush(stdin);
} while (yon(op));

   
    return 0;
}
void buscar(string cod_alt, bool &encontrado )
/*esta funcion es sencilla, lo que dice es abre auxiliar en modo escritura y a asesoria en modo escritura luego mientras sigas detectando lineas  vas a almacenar los datos
de la linea en cont y con los pasa a la variable corespondiente que es codigo en este caso luego si el codigo de la linea es igual al codigo ingresado por el usuario
se lo salta e ingresa las demas lineas en el archivo auxiliar, si encuentra el codigo entonces elimina asesoria.txt y renombra axuliar con el nombre del anterior,
y si no lo encuentra pues muestra un mensajito y elimnia auxiliar.txt es decir no hace ningun cambio
*/
{  
    string codigo, linea, nombres, apellidos, edad, ciudad, genero, consulta;
    ifstream file;
    ofstream aux;
    aux.open("auxiliar.txt", ios::out);
    file.open("asesoria.txt", ios::in);
    if (file.fail() || aux.fail())
    {
        cout << "No he podido encontrar asesoria.txt" << endl;
        exit(1);
    }

    while (getline(file, linea))
    {   
         stringstream cont(linea);
         cont>>codigo;
        
        if (codigo == cod_alt)
        {
            cout << "Se a eliminado al asesor OjO" << endl;
            encontrado = 1;
            continue;
        }
        else
        {

            aux << linea << endl;
        }
    }
    file.close();
    aux.close();

    if (encontrado == 1)
    {
        remove("asesoria.txt");
        rename("auxiliar.txt", "asesoria.txt");
    }
    else
    {   
        cout<<"El asesor ya ha sido eliminado o no existe"<<endl;
        remove("auxiliar.txt");
    }
}
void mos()
{/*mos se usa para mostrar lo que se encuentra en asesoria .txt lo que dice es mientras detecte lineas entonces las vas a pasar a cont y con las va a pasar a 
sus respectivas variables y luego llama a la funcion camtam(jjsjs que no voy a explicar ak sino mas abajo) que "acomoda las variables nombres, apellidos,ciudad y genero"
y luego hace un cout con los datos de los acesores*/
    string codigo ,linea ,nombres, apellidos, edad, ciudad, genero, consulta;
    ifstream file;
    file.open("asesoria.txt", ios::in);

    if (file.fail())
    {
        cout << "Archivo no encontrado" << endl;
    }
    cout << "Codigo      Nombres          Apellidos       Cidudad    Edad   Genero       Consulta" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    while (getline(file,linea)){
       stringstream cont(linea);
       cont>>codigo >> nombres >> apellidos >> ciudad >> edad >> genero >> consulta;
        
        camtam(nombres, apellidos, ciudad, genero);

        cout << codigo << "    " << nombres << "    " << apellidos << "    " << ciudad << "    " << edad << "    " << genero << "    " << consulta << endl;
    }
    cout << "---------------------------------------------------------------------------------------" << endl
         << endl
         << endl;
    file.close();
}
void camtam(string &nombre, string &apellido, string &ciudad, string &genero)
/*oks este es camtam esta funcion revisa el tamaño de las variables nombres, apellidos,ciudad y genero luego si el tamaño de estas es menor al promedio asignado 
esta les cambia el tamaño y las rellena con espacios de esta forma se pueden alinear todas las filas de datos mas comodamente wajajajaj
*/
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
bool yon(char op)/*esta funcion pues no es la gran cosa pues lo que haces es controlar si ingreso s o n para el control de arriba uwu*/
{
    while ( op != 's' && op != 'S' &&op != 'n' &&op != 'N')
    {
       cout<<"Prametro ingresado incorrecto, intentelo de nuevo.(S/N): ";
        cin>>op;
    }
    if (op == 'n' or op=='N')
    {
        cout<<"has salido del programa! :)"<<endl;
        return 0;
    }
    else
    {
        return 1;
    }
    

}
/*Generar un programa que pueda eliminar, tantos asesores como se desee,
cualquier asesor en el archivo asesoria.txt, luego se debe mostrar los datos de
todos los asesores. Los campos del archivo asesoría son: código, nombres,
apellidos, edad, ciudad, género y consulta. */