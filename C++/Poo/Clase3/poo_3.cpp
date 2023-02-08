#include <iostream>
#include <cstdlib>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:
    Persona(string, int);
    ~Persona();
    void mostrarpersona();
};

Persona::Persona(string _nombre, int _edad)
{
    nombre = _nombre;
    edad = _edad;
}
Persona::~Persona()
{
}
void Persona::mostrarpersona()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}
class Alumno : public Persona
{
private:
    string codalumno;
    float nota;

public:
    Alumno(string, int, string, float);
    ~Alumno();
    void mostraralumno();
};
Alumno::Alumno(string _nombre, int _edad, string _codalumno, float _nota):Persona(_nombre , _edad)
{
    codalumno= _codalumno;
    nota= _nota;
}
Alumno::~Alumno()
{}
void Alumno::mostraralumno()
{
    mostrarpersona();
    cout<<"Cpdigo Alumno: "<<codalumno<<endl;
    cout<<"Nota: "<<nota<<endl;
}
int main()
{
    Alumno alumno1("pablo",20,"0015",5);
    alumno1.mostraralumno();
}
