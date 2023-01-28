#include "iostream"
using namespace std;
int main()
{
    int nume[3][3];
    int cont = 0, x, y;
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            nume[x][y] = cont;
            cont++;
        }
    }

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            cout << nume[x][y] << " ";
        }
        cout << endl;
    }
}