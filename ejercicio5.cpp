/*
Sistema de reservas de cine
Descripción: Administra asientos de una sala de cine (ocupado o
libre) y permite reservar o cancelar asientos.
Resultado esperado: Reservar asiento 5 cambia su estado a
“ocupado”.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<bool> puestosEnSalaDeCine = {false, false, false, false};

void reservarPuesto(vector<bool> &puestosEnSalaDeCine)
{
  int asiento;
  cout << "En la sala hay asientos disponibles desde [0 hasta 3]\n";
  cout << "ingresa el número del asiento que quieres reservar: ";
  cin >> asiento;

  for (int i = 0; i < puestosEnSalaDeCine.size(); i++)
  {
    if (i == asiento)
    {
      if (puestosEnSalaDeCine[i] != true)
      {
        puestosEnSalaDeCine[i] = true;
        break;
      }

      cout << "Lo sentimos el asiento que quieres reversar esta ocupado.";
    }
  }

  cout << "\n";
}

void cancelarPuesto(vector<bool> &puestosEnSalaDeCine)
{
  int asiento;
  cout << "ingresa el número del asiento que reservaste en la sala y ahoras vas a cancelar: ";
  cin >> asiento;

  for (int i = 0; i < puestosEnSalaDeCine.size(); i++)
  {
    if (i == asiento)
    {
      if (puestosEnSalaDeCine[i] != false)
      {
        puestosEnSalaDeCine[i] = false;
        break;
      }

      cout << "NO puedes cancelar un puesto que no has reservado. \n";
    }
  }

  cout << "\n";
}

void mostrarDisponibles(vector<bool> &puestosEnSalaDeCine)
{

  for (int i = 0; i < puestosEnSalaDeCine.size(); i++)
  {
    if (puestosEnSalaDeCine[i] == 1)
    {
      cout << "[" << i << "]." << " Asiento Ocupado." << "\n";
      continue;
    }
    cout << "[" << i << "]." << " Asiento Libre" << "\n";
  }

  cout << "\n";
}

char menu()
{
  char opcion;
  cout << "Administracion de la sala de cine...\n";
  cout << "1. Mostrar puestos disponibles.\n";
  cout << "2. Reservar puesto en la sala.\n";
  cout << "3. Cancelar puesto en la sala.\n";
  cout << "4. Salir de la sala.\n";

  cout << "Ingresa un opción del [ 1 - 4]: ";
  cin >> opcion;
  cout << "\n";

  return opcion;
}

void administracionDeSala()
{
  char opcion;
  do
  {
    opcion = menu();
    switch (opcion)
    {
    case '1':
      mostrarDisponibles(puestosEnSalaDeCine);
      break;

    case '2':
      reservarPuesto(puestosEnSalaDeCine);
      break;

    case '3':
      cancelarPuesto(puestosEnSalaDeCine);
      break;

    case '4':
      cout << "Saliendo de la sala... \n";
      break;

    default:
      cout << "Opción No valida";
      break;
    }

  } while (opcion != '4');
}

int main()
{
  administracionDeSala();
  return 0;
}
