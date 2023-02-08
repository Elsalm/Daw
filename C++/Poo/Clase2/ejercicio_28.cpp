#include <iostream>

using namespace std;

class Tiempo
{
private:
    int horas;
    int minutos;
    int segundos;

public:
    Tiempo(int h, int m, int s);
    Tiempo(int s);
    ~Tiempo();
};
Tiempo::Tiempo(int h, int m, int s)
{
  
    horas = h;
    minutos = m;
    segundos = s;
    cout << horas << " horas " << minutos << " minutos " << segundos << " segundos" << endl;
}
Tiempo::Tiempo(int s)
{
  
    horas = (s / 3600);
    segundos = s % 3600;
    minutos = (segundos / 60);
    segundos %=60;
    cout << horas << " horas " << minutos << " minutos " << segundos << " segundos" << endl;
}

Tiempo::~Tiempo()
{
}
int main()
{   
    int h = 2;
    int m = 50;
    int s = 10;
    Tiempo time(h,m,s);
      s = 2587;
      Tiempo times(s); 
    return 0;
}
