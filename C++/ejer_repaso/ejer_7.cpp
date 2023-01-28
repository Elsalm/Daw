#include "iostream"
#include "wchar.h"
#include "locale.h"
#include "vector"
#include "cmath"

using namespace std;

constexpr double G = 9.8; // aceleración de la gravedad en metros/segundos^2
int main()
{
  setlocale(LC_ALL, "spanish");
  vector<double> altitudes; // vector para almacenar las alturas
  vector<double> times;     // vector para almacenar los tiempos de caída
  int cont;
  char c;
  do
  {
    cout << "Program calcula el tiempo en caída libre" << endl;
    cout << "----------------------------------------" << endl
         << endl;
    cout << "Digite la altura en caida libre: ";
    cin >> cont;
    cout << "imprimir alctura y timepo en caida libre" << endl;
    cout << "----------------------------------------" << endl
         << endl;

    for (double h = 1; h <= cont; h++)
    {
      altitudes.push_back(h);        // agregamos la altura al vector
      double time = sqrt(2 * h / G); // cálculo del tiempo de caída
      times.push_back(time);         // agregamos el tiempo de caída al vector
    }

    // imprimimos la altura y el tiempo de caída para cada una de las alturas
    cout << "Altura(m)                        Tiempo de caída(s)" << endl;
    cout << "---------                        ------------------" << endl;

    for (int i = altitudes.size(); i > 0; i--)
    {
      cout << " " << altitudes[i - 1] << "                            " << times[i - 1] << endl;
    }
cout<<endl<<endl;
cout<<"desea realizar otro cálculo: S o N:";
cin >> c;
    if (int(c) == 110 || int(c) == 78)
    {
      cout << "has salido del programa" << endl;
      break;
    }
  } while (int(c) == 115 || int(c) == 115);
  return 0;
}
