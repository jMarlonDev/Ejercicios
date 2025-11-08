/*
Cálculo de consumo de agua
Descripción: Recibe la cantidad de litros usados diariamente y
determina el promedio y si se supera un límite recomendado.
Resultado esperado: Con [50,40,60], promedio 50, si el límite es
55, no se supera.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> literOfWater;

void recordLiters(vector<int> &literOfWater)
{
  int literConsumed;

  for (int i = 0; i < 7; i++)
  {
    cout << "Ingrese la cantidad total de litros \n";
    cout << "Consumidos para cada día de la semana [lunes hasta domingo]: ";
    cin >> literConsumed;

    literOfWater.push_back(literConsumed);
  }
}

void displayLiterConsumed(vector<int> &literOfWater, int index)
{
  if (index == literOfWater.size())
  {
    return;
  }

  cout << literOfWater[index] << " l" << "\n";
  displayLiterConsumed(literOfWater, index + 1);
}

int addLiterConsumed(vector<int> &literOfWater, int index, int result = 0)
{
  if (index == literOfWater.size())
  {
    return 0;
  }

  return literOfWater[index] + addLiterConsumed(literOfWater, index + 1);
  cout << "\n";
}

int averageLiters(int totalLiterConsumed, int vectorSize)
{
  int promedio = (totalLiterConsumed / vectorSize);
  if (promedio <= 700)
  {
    cout << "límite normal: promedio total de litros consumidos por semana: " << promedio;
    return 0;
  }

  cout << "El promedio excedío el límite de litros consumidos por semana que son: 700 litros\n";
  cout << "Y el promedio de litros consumidos durante la semana son: " << promedio << " litros";
  cout << "\n";

  return promedio;
}

int main()
{
  recordLiters(literOfWater);

  displayLiterConsumed(literOfWater, 0);

  int literConsumed = addLiterConsumed(literOfWater, 0);

  cout << "Total litros consumidos: " << literConsumed << " litros";
  cout << "\n";

  averageLiters(literConsumed, literOfWater.size());

  return 0;
}
