/*
Gestión de gastos mensuales
    -   Descripción: Crea un programa que permita al usuario ingresar
        sus gastos diarios de un mes, calcule el total gastado y el
        promedio por día.
    -   Resultado esperado: Con gastos [10, 20, 15], el total es 45 y el
        promedio 15.
*/
#include <iostream>
#include <vector>
using namespace std;

void registroDeGastos(vector<int> &gastosDiarios, int dias)
{
  int gastos;
  cout << "Ingrese el valor que gasto para cada día de la semana [lunes-domingo]\n";
  for (int i = 0; i < dias; i++)
  {
    cout << "Ingrese la cantidad gastada: ";
    cin >> gastos;
    gastosDiarios.push_back(gastos);
  }
}

int calcularTotalGastos(vector<int> &gastosDiarios)
{
  int totalGastado = 0;

  for (int i = 0; i < gastosDiarios.size(); i++)
  {
    totalGastado += gastosDiarios[i];
  }

  return totalGastado;
}

int promedioDeGastos(vector<int> &gastosDiarios, int totalGastos)
{
  int promedio = totalGastos / gastosDiarios.size();
  return promedio;
}

int main()
{
  vector<int> gastosDiarios;
  int dias = 7;
  int total, promedio;

  registroDeGastos(gastosDiarios, dias);

  total = calcularTotalGastos(gastosDiarios);
  promedio = promedioDeGastos(gastosDiarios, total);

  cout << "El total de gastos semanal es: " << total << " pesos \n";
  cout << "El promedio de gastos en la semana son: " << promedio << " pesos";

  return 0;
}
