#include "iostream"

using namespace std;
int main()
{
	// Nota practica 30%, Teorica 60%, Participacion 10;
	float prac;
	float Teo;
	float Part;
	float Not_final;

	cout << "Vamos a Calcular La nota de alumno" << endl;
	cout << "Nota de Practica: ";
	cin >> prac;
	if (prac >= 0 and prac <= 10)
	{
		cout << "Nota de Teoria: ";
		cin >> Teo;
		if (Teo >= 0 and Teo <= 10)
		{
			cout << "Nota de Participacion: ";
			cin >> Part;
			if (Part >= 0 and Part <= 10)
			{
				// Nota practica 30%, Teorica 60%, Participacion 10;
				Not_final = (prac * 0.3) + (Teo * 0.6) + (Part * 0.1);
				cout << "La nota final es: " << Not_final;
			}
			else
			{
				cout << "Nota de Participacion Incorrecta";
			}
		}
		else
		{
			cout << "Nota de Teoria Incorrecta";
		}
	}
	else
	{
		cout << "Nota de Practica Incorrecta";
	}
	return 0;
}