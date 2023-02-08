#include <iostream>
#include <math.h>

using namespace std;

class Rectangulo
{
private:
    float largo;
    float ancho;

public:
    Rectangulo();
    ~Rectangulo();
    void perimetro();
    void area();
};

Rectangulo::Rectangulo()
{
         cout << "introduce la altura:";
        cin.sync();
        cin >> largo;
        cout << "introduce la base:";
        cin.sync();
        cin >> ancho;
    
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
    char op;
    do
    {
        Rectangulo cal;
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