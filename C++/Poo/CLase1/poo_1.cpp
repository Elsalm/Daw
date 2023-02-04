#include<iostream>

using namespace std;

class Automovil
{
    public:
    int combustible;
    int valocidad_max;
    string color;
private:
int cv;
void pintar();

    public:
    Automovil();
    void arrancar();
    void acelerar();
    void acelerar(int a);
    void apagar();
    ~Automovil();
};

//CONSTRUCTOR INICIALIZA LAS VARIABLES TIENE QUE LLAMARSE IGUAL QUE LA CLASE; NADA MAS LLAMAR A LA CLASE SE EJECUTA
Automovil::Automovil()
{
    cout<<"Se ha creado un oobjeto de tipo automovil"<<endl;
    cv=15;
    cout<<cv<<endl;
}
void Automovil::arrancar(){
    cout<<"El Automovil se esta arrancando"<<endl;
}
void Automovil::acelerar()
{
    cout<<"El Automovil se esta acelerando"<<endl;
}
void Automovil::acelerar(int a)
{
     cout<<"El Automovil se esta acelerando "<<a<< "km/h"<<endl;
}
void Automovil::apagar()
{
    cout<<"El Automovil se esta apagando"<<endl;
}
void Automovil::pintar()
{
    cout<<"El Automovil se ha pintando"<<endl;
}

Automovil::~Automovil()
{
    cout<<"Se ha destruido un objeto de tipo Automovil"<<endl;
}
int main()
{
    Automovil seat;
    seat.color="Rojo";
    cout<<"Mi coche es "<<seat.color<<endl;
    seat.acelerar(5);
    seat.apagar();
    
    return 0;
}
