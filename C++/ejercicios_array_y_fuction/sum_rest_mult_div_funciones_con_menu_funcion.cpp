#include "iostream"
using namespace std;
//----variables universales----
int num1, num2, op, i;
//----Prototipo_funcion----
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
float divicion(float a, float b);
int div_rest(int a, int b);
void men();
void control();
void pedir_nm();
//----funcion_Principal----
int main()
{
    do
    {
        men();
        control();
    } while (op != 6);
    cout << "has salido del programa";
    return 0;
}
//----Funciones----
int suma(int a, int b)
{
    int res;
    res = a + b;
    return res;
}
int resta(int a, int b)
{
    int res;
    res = a - b;
    return res;
}
int multiplicacion(int a, int b)
{
    int res;
    res = a * b;
    return res;
}
float divicion(float a, float b)
{
    float res;
    res = a / b;
    return res;
}
int div_rest(int a, int b)
{
    int res;
    res = a % b;
    return res;
}
void control()//Esta funcion revisa si los parametros initroducidos son correctos
{
    if (op < 1 or op > 5)
    {
        cout << "el parametro ingresado es incorrecto(1-5)" << endl;
    }
}
void pedir_nm()//esta funcion pide los numeros que vamos a calcular
{
    cout << "introducir numeros:" << endl;
    cout << "Numero 1:";
    cin >> num1;
    cout << "Numero 2:";
    cin >> num2;
}
void men()//este es el menu
{
    string menu[6]{"Suma", "Resta", "Multiplicacion", "Divicion", "Resto", "Salir"};
    cout << "Por favor, selecione una opcion: " << endl;
    for (i = 0; i < 6; i++)
    {
        cout << i + 1 << ". " << menu[i] << endl;
    }
    cout << "Opcion: ";
    cin >> op;

    switch (op)
    {

    case 1:
        cout << "-------------------------------------------------" << menu[op - 1] << "-------------------------------------------------" << endl;
        pedir_nm();
        cout << "resultado: " << suma(num1, num2) << endl;
        break;
    case 2:
        cout << "-------------------------------------------------" << menu[op - 1] << "-------------------------------------------------" << endl;
        pedir_nm();
        cout << "resultado: " << resta(num1, num2) << endl;
        break;
    case 3:
        cout << "-------------------------------------------------" << menu[op - 1] << "-------------------------------------------------" << endl;
        pedir_nm();
        cout << "resultado: " << multiplicacion(num1, num2) << endl;
        break;
    case 4:
        cout << "-------------------------------------------------" << menu[op - 1] << "-------------------------------------------------" << endl;
        pedir_nm();
        cout << "resultado: " << divicion(num1, num2) << endl;
        break;
    case 5:
        cout << "-------------------------------------------------" << menu[op - 1] << "-------------------------------------------------" << endl;
        pedir_nm();

        cout << "resultado: " << div_rest(num1, num2) << endl;
        break;
    default:
        break;
    }
}