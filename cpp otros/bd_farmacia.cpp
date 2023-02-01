/*librerias*/
#include<iostream>
#include<string>
#include<locale.h>
#include<wchar.h>

using namespace std;

/*estructura*/
struct Medicina {
    string nombre;
    int codigo;
    int cantidad;
    float costo;
};
// Crear un arreglo de 500 elementos de tipo Medicinea
Medicina medicinas[500];
/*Variables globales*/
int count= 0;
/*funciones*/
void añamedicina();
void inventario();
void buscarmedicina();
void acomodarnombre(string &nombre);
void modificar();
void menu();
int main()
{
    menu();
    return 0;
}
/*sencillo uso esta funcion para añadir medicamentos a el sistema*/
void añamedicina()
{ /*como uso un contador para contar la cantidad de medicina que ingreso el if es
    un control para que cuando el contador llegue a 500 pues muestre un mensaje 
    y cierre la cuncion*/
    if (count == 500) {
        cout << "No se pueden agregar más medicamentos, inventario lleno." << endl;
        return;
    }
    Medicina m;
    /*se usa para limpiar el buffer de la entrada de datos*/
    fflush(stdin); 
    cout << "Ingrese el nombre del medicamento: ";
    getline(cin,m.nombre);
    cout << "Ingrese el código del medicamento: ";
    cin >> m.codigo;
    cout << "Ingrese la cantidad disponible: ";
    cin >> m.cantidad;
    cout << "Ingrese el costo unitario: ";
    cin >> m.costo;
    acomodarnombre(m.nombre);
    medicinas[count] = m;
    count++;
    cout << "Medicamento agregado al inventario." << endl;

}
/*esta fincion usa un for para ir recorriendo el arreglo hasta que llegue a la cantida
almacenada de medicamentos se vuelve a usar el contador como control dado que alli se
al macena la cantidad de datos que hemos metido*/
void inventario() {
    double total=0;
    if (count==0)
    {
       cout<<"primero ingrese los datos"<<endl;
       return;
    }
    cout << "Nombre        Código      Cantidad   Costo" << endl;
    for (int i = 0; i < count; i++) {
        cout << medicinas[i].nombre << "     " << medicinas[i].codigo << "          " << medicinas[i].cantidad << "        " << medicinas[i].costo << endl;
        total=total+medicinas[i].costo;
    }
    cout<<"Costo total del almacen:"<<total<<endl;
}
void acomodarnombre(string &nombre)
{
    if (nombre.length()<10)
    {
        nombre.resize(10,' ');
    }
    
}
/*bucar medicina lo que dice es si codigo almacenado es igual a codigo ingresado
entonces muestra uso el bucle for para recorrer el arreglo*/
void buscarmedicina() {
    int code;
    if (count==0)
    {
       cout<<"primero ingrese los datos"<<endl;
       return;
    }
    
    cout << "Ingrese el código del medicamento a buscar: ";
    cin >> code;
    for (int i = 0; i < count; i++) {
      if (medicinas[i].codigo == code) {
            cout << "Medicamento encontrado: " << endl;
            cout << "Nombre: " << medicinas[i].nombre << endl;
            cout << "Cantidad: " << medicinas[i].cantidad<< endl;
            cout << "Costo unitario: " << medicinas[i].costo<< endl;
            return;
        }
    }
    cout << "Medicamento no encontrado en el inventario." << endl;
}
void modificar()/*usa el mismo principio de la funcion buscar pero se le añaden
cins para modificar los datos*/
{
       int code;
    if (count==0)
    {
       cout<<"primero ingrese los datos"<<endl;
       return;
    }
    
    cout << "Ingrese el código del medicamento a Modificar: ";
    cin >> code;
    for (int i = 0; i < count; i++) {
      if (medicinas[i].codigo == code) {
            cout << "Medicamento encontrado: " << endl<<endl;
            cout << "Nombre: " << medicinas[i].nombre << endl;
            cout << "ingrese nueva Cantidad: ";
            cin>>medicinas[i].cantidad;
            cout << "ingrese nuevo Costo unitario: ";
            cin>>medicinas[i].costo;
            cout<<"Modificacion exitosa"<<endl<<endl;
            return;
        }
    }
    cout << "Medicamento no encontrado en el inventario." << endl<<endl;
}
void menu() {
    int option;
      for (int i = 0; i < 500; i++) {
        medicinas[i].nombre = "";
        medicinas[i].codigo = 0;
        medicinas[i].cantidad = 0;
        medicinas[i].costo = 0.0;
    }
    do {
        cout << "--- Menú de opciones ---" << endl;
        cout << "1. Agregar medicamento" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Buscar medicamento" << endl;
        cout << "4. Modificar medicamento" << endl;
        cout << "5. Salir"<<endl;
        cout << "Seleccione una opción: ";
        cin >> option;
        switch (option) {
            case 1:
                añamedicina();
                break;
            case 2:
                inventario();
                break;
            case 3:
                buscarmedicina();
                break;
            case 4:
                modificar();
                break;
            case 5:
            break;
            default:
                cout << "Opción inválida, por favor seleccione una opción válida." << endl;
                break;
        }
    } while (option != 5);
}

