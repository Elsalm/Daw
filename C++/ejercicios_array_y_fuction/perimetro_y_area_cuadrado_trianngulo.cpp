#include <iostream>
#include <math.h>
using namespace std;
// Prototipo de funciones
float perim_tri(float lado_a, float lado_b, float lado_c);
float area_tri(float lado_a, float lado_b, float lado_c);
float perim_rec(float base, float altura);
float area_rec(float base, float altura);
// variables
float a, b, c, d, f;
// funcion principal
int main()
{
    a = 3;
    b = 4;
    c = 5;
    d = 12;
    f = 18;
    cout << perim_tri(a, b, c) << endl;
    cout << area_tri(a, b, c) << endl;
    cout << perim_rec(d, f) << endl;
    cout << area_rec(d, f);
    return 0;
}
// definicion de fuciones
float perim_tri(float a, float b, float c)
{
    float perimetro = 0;
    perimetro = a + b + c;
    return perimetro;
}
float area_tri(float a, float b, float c)
{
    float s = 0, A = 0;
    s = perim_tri(a, b, c) / 2;
    A = sqrt(s * (s - a) * (s - b) * (s - c));
    return A;
}
float perim_rec(float base, float altura)
{
    float p;
    p = (2 * base) + (2 * altura);
    return p;
}
float area_rec(float base, float altura)
{
    float A;
    A = base * altura;
    return A;
}
