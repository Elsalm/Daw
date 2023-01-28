#include "iostream"
using namespace std;
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
float divicion(float a, float b);
int div_rest(int a, int b);
int main()
{
    int num1, num2, op, i;
    string menu[6]{"Suma", "Resta", "Multiplicacion", "Divicion", "Resto", "Salir"};
    do
    {
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
        cout << "-------------------------------------------------" << menu[op-1] << "-------------------------------------------------"<< endl;
            cout << "introducir numeros:"<<endl;
            cout << "Numero 1:";
            cin >> num1;
            cout << "Numero 2:";
            cin >> num2;
            cout << "resultado: " << suma(num1, num2) << endl;
            break;
        case 2:
        cout << "-------------------------------------------------" << menu[op-1] << "-------------------------------------------------"<< endl;
            cout << "introducir numeros:"<<endl;
            cout << "Numero 1:";
            cin >> num1;
            cout << "Numero 2:";
            cin >> num2;
            cout << "resultado: " << resta(num1, num2) << endl;
            break;
        case 3:
        cout << "-------------------------------------------------" << menu[op-1] << "-------------------------------------------------"<< endl;
            cout << "introducir numeros:"<<endl;
            cout << "Numero 1:";
            cin >> num1;
            cout << "Numero 2:";
            cin >> num2;
            cout << "resultado: " << multiplicacion(num1, num2) << endl;
            break;
        case 4:
        cout << "-------------------------------------------------" << menu[op-1] << "-------------------------------------------------"<< endl;
            cout << "introducir numeros:"<<endl;
            cout << "Numero 1:";
            cin >> num1;
            cout << "Numero 2:";
            cin >> num2;
            cout << "resultado: " << divicion(num1, num2) << endl;
            break;
        case 5:
        cout << "-------------------------------------------------" << menu[op-1] << "-------------------------------------------------"<< endl;
            cout << "introducir numeros:"<<endl;
            cout << "Numero 1:";
            cin >> num1;
            cout << "Numero 2:";
            cin >> num2;
            cout << "resultado: " << div_rest(num1, num2) << endl;
            break;
        default:
            break;
        }
    } while (op != 6);
    cout << "has salido del programa";
    return 0;
}
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