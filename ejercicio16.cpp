/*
Control de gastos de un evento
Descripción: Permite ingresar los gastos de diferentes áreas
(comida, decoración, sonido) de un evento social y devuelve el
total y el área con mayor gasto.
Resultado esperado: Comida 200, Decoración 150, Sonido 250 →
total 600, mayor gasto: Sonido.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Estructura para definir cada gasto del evento
en diferentes áreas
*/

struct Gasto
{
  string nombre;
  int precio;
};

vector<Gasto> gastos;

void agregarGastosEvento(vector<Gasto> &gastos)
{
  Gasto area;

  for (int i = 0; i < 3; i++)
  {
    cout << "Ingrese el nombre del área del evento: ";
    getline(cin, area.nombre);

    cout << "Ingrese el precio del área del evento ingresada: ";
    cin >> area.precio;
    cin.ignore();
    gastos.push_back(area);
  }

  cout << "\n";
}

void mostrarElementosEvento(vector<Gasto> &gastos, int index = 0)
{
  if (index == gastos.size())
  {
    return;
  }

  cout << "Área del evento: " << gastos[index].nombre << "\n";
  cout << "Precio de esta área: " << gastos[index].precio << "\n";

  mostrarElementosEvento(gastos, index + 1);
}

void calcularMayor(vector<Gasto> &gastos)
{
  // Se asume que el primer elemento es el mayor para hacer la comparación
  int precioMayor = gastos[0].precio;
  string nombre = gastos[0].nombre;

  for (int i = 0; i < gastos.size(); i++)
  {
    if (gastos[i].precio > precioMayor)
    {
      precioMayor = gastos[i].precio;
      nombre = gastos[i].nombre;
    }
  }

  cout << "\nEl área con mayor gasto es: " << nombre << "\n";
  cout << "Con un valor de: " << precioMayor << "\n";
}

int main(int argc, char const *argv[])
{
  agregarGastosEvento(gastos);
  mostrarElementosEvento(gastos);
  calcularMayor(gastos);

  return 0;
}
