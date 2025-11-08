/*
Control de ahorro personal
Descripción: Permite registrar ahorros semanales y muestra
cuánto se ha ahorrado al final del mes.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> ahorros;

void registrarAhorros(vector<int> &ahorros)
{
  int cantidadAhorro;
  for (int i = 0; i < 7; i++)
  {
    cout << "Ingrese la cantidad que ahorro para este día: ";
    cin >> cantidadAhorro;

    ahorros.push_back(cantidadAhorro);
  }
}

void mostrarAhorros(vector<int> &ahorros, int index = 0)
{
  if (index == ahorros.size())
    return;

  cout << "Ahorro: " << ahorros[index] << " pesos\n";
  mostrarAhorros(ahorros, index + 1);
}

int sumarAhorros(vector<int> &ahorros)
{
  int totalAhorrado = 0;
  for (int i = 0; i < ahorros.size(); i++)
  {
    totalAhorrado += ahorros[i];
  }

  return totalAhorrado;
}

int main()
{
  cout << "Registro de ahorros, ingresa la cantidad ahorrada para cada dia de la semana [lunes - domingo ]: \n";
  registrarAhorros(ahorros);
  mostrarAhorros(ahorros);

  int totalAhorrado = sumarAhorros(ahorros);
  cout << "La cantidad total ahorrada en esta semana fueron: " << totalAhorrado << " pesos.";
  return 0;
}
