/*

Simulador de préstamos
Descripción: Calcula la cuota mensual de un préstamo según
monto, interés y plazo en meses.
Resultado esperado: Para 1000 con 5% de interés anual y 12
meses, muestra la cuota aproximada.

Aquí se utiliza la formúla para calcular la couta mensual
que se debe pagar esto se hace a tráves
de calcular una tasa de ínteres del 5% anual
para la cantidad de meses que se disponen para pagar el préstamo
luego se usa la formúla del pretamo amortizado.

*/

#include <iostream>
#include <cmath>

using namespace std;

float annualRate()
{
  // Interes del 5%
  float interest = 0.05;
  return (interest / 12);
}

void monthlyFee()
{
  int capital, months;
  cout << "Ingrese la cantidad de dinero en pesos para el préstamo: ";
  cin >> capital;

  cout << "Ingrese la cantidad de meses para pagar el préstamo: ";
  cin >> months;

  // tasa anual:
  float i = annualRate();

  // Fórmula de cuota de un préstamo amortizado

  float firstOperation = i * (pow(1 + i, months));
  float secondOperation = pow((1 + i), months) - 1;

  // Resultado de la couta mensual basado en la formúla
  int c = capital * (firstOperation / secondOperation);
  cout << "Couta mensual: " << c << " pesos.";
}

int main()
{
  monthlyFee();
  return 0;
}
