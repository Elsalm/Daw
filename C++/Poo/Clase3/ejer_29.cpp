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
    void mostrarPersona();
};

Persona::Persona(string _nombre, int _edad)
{ nombre = _nombre;
edad = _edad;
}
void Persona::mostrarPersona()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}
Persona::~Persona()
{
}

class Empleado : public Persona
{
private:
    float salario;

public:
    Empleado(float, string, int);
    ~Empleado();
    void mostrarEmpleado();
};

Empleado::Empleado(float _salario, string _nombre, int _edad):Persona(_nombre, _edad)
{ salario = _salario;
}
void Empleado::mostrarEmpleado()
{
    mostrarPersona();
    cout << "Salario: " << salario << endl;
}
Empleado::~Empleado()
{
}

class Estudiante : public Persona
{
private:
    float notafinal;

public:
    Estudiante(float, string, int);
    ~Estudiante();
    void mostrarEstudiante();
};

Estudiante::Estudiante(float _notafinal, string _nombre, int _edad):Persona(_nombre, _edad)
{notafinal = _notafinal;
}
void Estudiante::mostrarEstudiante()
{
    mostrarPersona();
    cout << "Nota final: " << notafinal << endl;
}
Estudiante::~Estudiante()
{
}
class Universitario : public Estudiante
{
private:
    string carrera;

public:
    Universitario(string, float, string, int);
    ~Universitario();
    void mostrarUniversitario();
};

Universitario::Universitario(string _carrera, float _notafinal, string _nombre, int _edad):Estudiante(_notafinal, _nombre, _edad)
{carrera = _carrera;
}
void Universitario::mostrarUniversitario()
{
    mostrarEstudiante();
    cout << "Carrera: " << carrera << endl;
}
Universitario::~Universitario()
{
}
int main()
{   
    Empleado Empleado1(12.000,"pedro", 27);
    Universitario Universitario1("matematicas", 9, "juan",21);
    Empleado1.mostrarEmpleado();
    Universitario1.mostrarUniversitario();
    return 0;
}