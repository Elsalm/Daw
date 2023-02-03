#include <iostream>
#include <string>
using namespace std;
/*aqui se crean los objetos*/
class temperatura
{
private:
    float grados;

public:
    temperatura(float a);

    ~temperatura();
    void fa();
    void kelvin();
};
temperatura::temperatura(float a)
{
    grados = a;
}
temperatura::~temperatura()
{
}
/*aqui se calculan los grados fahrenheit*/
void temperatura::fa()
{
    float fah;
    fah = grados * (9.0 / 5) + 32;
    cout << "La temperatura en grados fahrenheit es : " << fah << endl;
}
/*aqui los kelvin*/
void temperatura::kelvin()
{
    float kel;
    kel = grados + 273.15;
    cout << "La temperatura en Kelvin es : " << kel << endl;
}
int main()
{
    char op;
    float g;
    do
    {   
        cout<<"introduce los grados a calcular: ";
        cin>>g;
        temperatura temp(g);
        temp.fa();
        temp.kelvin();
        cout << "Te gustaria seguir calculando grados?:";
        cin.sync();
        cin >> op;
        /*este es el control de mi bucle*/
        while (op != 'S' && op != 's' && op != 'N' && op != 'n')
        {
            cout << "opcion incorrecta" << endl;
            cout << "Te gustaria seguir calculando grados?:" << endl;
            cin.sync();
            cin >> op;
        }
        
    } while (op == 'S' || op == 's');

    return 0;
}