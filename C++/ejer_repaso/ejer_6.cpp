#include <iostream>
#include <math.h>
#include <string>
#include <wchar.h>
#include <locale.h>
#include <cctype> //es para controlar si ingresan una letra o un numero
using namespace std;
string convertidor(int n);
char filtroop(char &letra);
int main()
{
    setlocale(LC_ALL, "");
    int nb;
    char pro;
    do
    {
        cout << "Programa que convierte un número del sistema decimal al binario!" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Digite un número decimal natural:        ";
        cin >> nb;
        cout << "Número digitado en el sitema decimal:    " << nb << endl;
        cout << "Número convertido en binario:             " << convertidor(nb) << endl;
        cout << "Desea convertir otro numero: S o N: ";
        cin >> pro;

        if (int(pro) == 110 || int(pro) == 78)
        {
            cout << "has salido del programa" << endl;
            break;
        }
    } while (int(pro) == 115 || int(pro) == 115);
    return 0;
}
char filtroop(char &letra)
{
    while (int(letra) != 115 && int(letra) != 83 && int(letra) != 110 && int(letra) != 78)
    {
        cout << "parametro incorrecto!" << endl;
        cout << "Desea convertir otro numero: S o N:  ";
        cin >> letra;
    }
    return letra;
}
string convertidor(int n)
{
    string binario = "";
    /*
     *- para convertir numero decimal a binario es necesario sacar el resto al al numero(esto hace el primer digito)
     *luego dividimos entre dos el numero decimal y hacemos lo mismo que hicimos antes con el numero original(sacarle el resto)
     *
     */
    while (n > 0)
    { /*
       *  "to string(valor)" funciona para convertir cualquiel valor a estring
       *   lo que hago aqui (binario = to_string(n % 2) + binario;) es realizar la operacion convertirla a string
       *   y concatenarla de tal modo que todos los resultados nuevos van al inicio del string
       */
        binario = to_string(n % 2) + binario;
        n /= 2;
    }

    return binario;
}
