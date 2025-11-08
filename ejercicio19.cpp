/*
Planificador de estudio semanal
Descripción: Permite ingresar las horas de estudio por día,
calcula el promedio y determina si se alcanzó un objetivo (por
ejemplo, 20 horas).
Resultado esperado: Horas [3, 2, 4, 3, 3, 2, 4] → total 21,
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> studyHours;

void addStudyHours(vector<int> &studyHours)
{
  for (int i = 0; i < 7; i++)
  {
    int hours;
    cout << "Ingrese la cantidad de horas de estudio que realizaste este día: ";
    cin >> hours;

    studyHours.push_back(hours);
  }

  cout << "\n";
}

void goal(vector<int> &studyHours, int objective)
{
  int total = 0;

  for (int i = 0; i < studyHours.size(); i++)
  {
    total += studyHours[i];
  }

  if (total >= objective)
  {
    cout << "Felicidades completaste " << total << " horas de estudio, superaste el objetivo que era de: " << total << " horas\n";
    return;
  }

  cout << "Up's te falto muy poco para alcanzar tu objetivo de estudio, intentémoslo de nuevo";
}

int main()
{
  int objective;
  cout << "Traza una meta de estudio, ingresa la cantidad de horas que quieres estudiar está semana: ";
  cin >> objective;

  addStudyHours(studyHours);

  goal(studyHours, objective);
  return 0;
}
