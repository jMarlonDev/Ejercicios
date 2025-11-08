/*
Control de hábitos de ejercicio
Descripción: Registra los minutos de ejercicio por día y muestra
el total semanal y si se alcanzó un objetivo (ej. 150 min).
Resultado esperado: Con [30,20,40,10,50], total 150,
alcanzado.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> minutosEjercicio;

void resgistroDeEjercicio(vector<int> &minutosEjercicio, int i)
{
  int minutosDiarios;
  if (i == 7)
  {
    return;
  }

  cout << "[" << i << "]." << "Ingrese el total de minutos realizados en ejercicio en este día: ";
  cin >> minutosDiarios;

  minutosEjercicio.push_back(minutosDiarios);
  resgistroDeEjercicio(minutosEjercicio, i + 1);
}

int calcularTotalEjercicio(vector<int> &minutosEjercicio)
{
  int resultado = 0;
  for (int i = 0; i < minutosEjercicio.size(); i++)
  {
    resultado += minutosEjercicio[i];
  }

  return resultado;
}

void objetivoSemanal(int total)
{
  int objetivo;
  cout << "Para comparar los minutos de ejercicios realizados semanalmente,\n";
  cout << "Ingrese la cantidad de minutos de ejercicios que vas realizar durante la semana: ";
  cin >> objetivo;

  if (total >= objetivo)
  {
    cout << "Wow felicidades, lograste alcanzar o superar el objetivo de esta semana que fue: " << objetivo << "minutos\n";
    return;
  }

  cout << "Upss te faltó muy poco para alcanzar el objetivo de esta semana que es: " << objetivo << "minutos \n";
  cout << "Sige avanzando un poco más para alcanzarlo :)\n";
}

int main()
{
  cout << "Registro diario de minutos de ejercicio...\n";
  resgistroDeEjercicio(minutosEjercicio, 0);
  cout << "\n";

  int total;
  total = calcularTotalEjercicio(minutosEjercicio);
  cout << "Total de minutos realizados en ejercicio esta semana: " << total;

  cout << "\n";

  objetivoSemanal(total);

  return 0;
}
