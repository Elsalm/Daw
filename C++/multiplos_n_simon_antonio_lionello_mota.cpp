#include "iostream"
// porgrama que diga si es multiplo de 3,4,5
using namespace std;

int main()
{
    int num;
    int i;
    int mod;
    int cont;
    int c;

    cout << "cuantos numeros quiere saber si son multiplo de 3,4,5: ";
    cin >> cont;
    if (cont > 0)
    {
        for (c = 0; c <= cont; c++)
        {
            cout << "introducir un numero: ";
            cin >> num;
            for (i = 3; i <= 5; i++)
            {
                mod = num % i;
                if (mod == 0)
                {
                    cout << num << " es multiplo de " << i << endl;
                }
                else
                {
                    cout << num << " no es multiplo de " << i << endl;
                }
            }
        }
    }
    else
    {
        cout << "error, por favor solo introducir numeros positivos";
    }
}