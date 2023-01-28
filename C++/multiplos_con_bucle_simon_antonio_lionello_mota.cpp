#include "iostream"
// porgrama que diga si es multiplo de 3,4,5
using namespace std;

int main()
{
    int num;
    int i;
    int mod;
 cout <<"introducir un numero: ";
 cin >> num;

 for ( i = 3; i <= 5; i++)
 { mod=num%i;
    if (mod == 0)
    {
        cout << num <<" es multiplo de " << i<<endl;
    }
    else
    {
        cout << num <<" no es multiplo de " << i<< endl;
    }
    
    
 }
 
    
}