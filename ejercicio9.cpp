/*
Organizador de tareas pendientes
Descripción: Permite agregar, marcar como completadas y eliminar
tareas de una lista.
Resultado esperado: Tras completar “Estudiar”, esta se marca
como hecha.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> numeros;

int main()
{
  int cantidadNumeros;
  int numero;
  cout << "Ingrese la cantidad de números que quieres agregar";
  cin >> cantidadNumeros;

  for (int i = 0; i < cantidadNumeros; i++)
  {
    cout << "Ingrese el numero: ";
    cin >> numero;

    numeros[i] = numero;
  }

  return 0;
}
