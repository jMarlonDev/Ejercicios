/*
Gestor de notas escolares
Descripción: Registra las notas de diferentes materias y
determina si el estudiante aprueba cada una y el promedio
general.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<float> notas;

void ingresarNotas(vector<float> &notas, int index = 0)
{
  int cantidadNotas;
  float nota;

  cout << "Cuantas notas vas a agregar a la lista: ";
  cin >> cantidadNotas;

  for (int n = 0; n < cantidadNotas; n++)
  {
    cout << "Ingrese el valor de la nota: ";
    cin >> nota;
    notas.push_back(nota);
    cout << "\n";
  }
}

float sumarNotas(vector<float> &notas)
{
  float suma = 0.0;
  for (int i = 0; i < notas.size(); i++)
  {
    suma += notas[i];
  }

  return suma;
}

void mostrarNotas(vector<float> &notas, int index = 0)
{
  if (index == notas.size())
    return;

  cout << "Nota: " << notas[index] << "\n";
  mostrarNotas(notas, index + 1);

  cout << "\n";
}

void promedio(vector<float> &notas)
{
  int totalNotas = notas.size();
  float suma = sumarNotas(notas);

  float promedio = suma / totalNotas;

  if (promedio >= 3.0)
  {
    cout << "Felicidades aprobaste el curso con un promedio general de: " << promedio << "\n";
    return;
  }

  cout << "Lo sentimos reprobaste el promedio debe ser mayor o igual que 3.0 para aprobar y tu promedio es: " << promedio << "\n";
}

int main()
{
  float suma;
  ingresarNotas(notas);
  promedio(notas);

  return 0;
}
