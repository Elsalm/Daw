#include <iostream>
#include <math.h>

using namespace std;

class Rectangulo
{
private:
    float largo;
    float ancho;

public:
    Rectangulo(float ancho, float largo);
    ~Rectangulo();
    void perimetro();
    void area();
};

Rectangulo::Rectangulo(float valor1, float valor2)
{
    largo = valor2;
    ancho = valor1;
}
void Rectangulo::perimetro()
{
    float peri = 2 * (ancho + largo);
    cout << "el perimetro es:" << peri << endl;
}
void Rectangulo::area()
{
    float are = ancho * largo;
    cout << "el area es: " << are << endl;
}
Rectangulo::~Rectangulo()
{
}
int main()
{
    float h = 0;
    float b = 0;
    char op;
    do
    {
        cout << "introduce la altura:";
        cin.sync();
        cin >> h;
        cout << "introduce la base:";
        cin.sync();
        cin >> b;
        Rectangulo cal(b, h);
        cal.perimetro();
        cal.area();

        cout << "Quieres segir calculando el area y el perimetro(s/n): ";
        cin.sync();
        cin >> op;
        while (op != 's' && op != 'S' && op != 'N' && op != 'n')
        {
            cout << "valor incorrecto";
            cout << "Quieres segir calculando el area y el perimetro(s/n): ";
            cin.sync();
            cin >> op;
        }
        if (op == 'n' || op == 'N')
        {
            break;
        }

    } while (op == 's' || op == 'S');
    return 0;
}