/*
  Calculadora de propinas
  Descripción: Solicita el valor de una cuenta y el porcentaje de
  propina deseado para calcular el total a pagar.
*/

#include <iostream>
using namespace std;

void calculadorPropinas(int cuenta)
{
  int porcentajePropina = ((cuenta * 5) / 100);
  int valorTotal = cuenta + porcentajePropina;

  cout << "El valor total de la cuenta más el 5% de propina son: " << valorTotal << " pesos";
}

int main()
{
  int cuenta;
  cout << "Ingrese el valor parcial de la cuenta a pagar: ";
  cin >> cuenta;

  calculadorPropinas(cuenta);
  return 0;
}
