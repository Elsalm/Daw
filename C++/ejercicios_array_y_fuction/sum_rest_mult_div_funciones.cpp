#include "iostream"
using namespace std;
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
float divicion(float a, float b);
int div_rest(int a, int b);
int main()
{
    int num1, num2;
    cout << "introducir numeros ";
    cin >> num1 >> num2;
    cout << "suma: " << suma(num1, num2) << endl;
    cout << "resta: " << resta(num1, num2) << endl;
    cout << "multiplicacion: " << multiplicacion(num1, num2)<< endl;
    cout << "divicion: " << divicion(num1, num2)<< endl;
    cout << "resto: " << div_rest(num1, num2)<< endl;
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