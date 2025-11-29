/*
  Control de inventario de una tienda pequeña
  Descripción: Permite registrar productos con su cantidad,
  agregar o retirar existencias y consultar el stock total.
  Resultado esperado: Tras agregar 10 manzanas y retirar 3, quedan 7
*/

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Producto
{
public:
  string nombre;
  int cantidad = 0;
};

vector<Producto> tienda;

void agregarProductos(vector<Producto> &tienda)
{
  Producto productoTienda = {};
  string nombre;
  int cantidad;

  int inventarioElementos;
  cout << "Ingrese la cantidad de elementos que va a agregar al inventario: ";
  cin >> inventarioElementos;

  cout << "\n";

  for (int i = 0; i < inventarioElementos; i++)
  {
    cout << "Ingresa el nombre del producto: ";
    cin >> nombre;
    cout << "Ingresa la cantidad del producto: ";
    cin >> cantidad;

    cout << "\n";

    productoTienda = {nombre, cantidad};
    tienda.push_back(productoTienda);
  }

  cout << "\n";
}

void mostrarElementos(vector<Producto> &tienda)
{
  if (tienda.size() == 0)
  {
    cout << "NO hay elementos agregados en el inventario. \n\n";
    return;
  }

  for (int i = 0; i < tienda.size(); i++)
  {
    cout << "Nombre: " << tienda[i].nombre << "\n";
    cout << "Cantidad: " << tienda[i].cantidad << "\n\n";
  }
}

void agregarCantidad(vector<Producto> &tienda)
{
  string nombre;
  int nuevaCantidad;
  cout << "Ingrese el nombre del elemento en el inventario\n";
  cout << "al cuál quiere agregar la cantidad [nombre]:  ";
  cin >> nombre;

  cout << "\n";

  for (int i = 0; i < tienda.size(); i++)
  {
    if (nombre == tienda[i].nombre)
    {
      cout << "Cuánta cantidad quiere agregar: ";
      cin >> nuevaCantidad;

      cout << "\n\n";

      tienda[i].cantidad += nuevaCantidad;
      cout << "Producto actualizado: \n";
      cout << "Nombre: " << tienda[i].nombre << "\n";
      cout << "Cantidad: " << tienda[i].cantidad << "\n\n";
      return;
    }
  }

  cout << "\n";
  cout << "El nombre no corresponde a ningún elemento dentro del inventario \n\n";
  cout << "Ingresa los siguientes datos para agregar el elemento que buscas a el inventario: \n\n";
  agregarProductos(tienda);
}

void retirarCantidad(vector<Producto> &tienda)
{
  string nombre;
  int nuevaCantidad;
  cout << "Ingrese el nombre del elemento en el inventario\n";
  cout << "para retirar la cantidad [nombre]: ";
  cin >> nombre;

  cout << "\n";

  for (int i = 0; i < tienda.size(); i++)
  {
    if (nombre == tienda[i].nombre)
    {
      cout << "Cuánta cantidad quiere retirar: ";
      cin >> nuevaCantidad;

      cout << "\n\n";
      cout << "Producto actualizado: \n";
      cout << "Nombre: " << tienda[i].nombre << "\n";
      cout << "Cantidad: " << tienda[i].cantidad << "\n\n";
      return;
    }
  }

  cout << "El nombre no corresponde a ningún elemento dentro del inventario\n";
  cout << "Ingresa los siguientes datos para agregar el elemento que buscas a el inventario: \n";
  agregarProductos(tienda);
}

char menuInventario()
{
  char opcion;
  cout << "1. Agregar productos al inventario.\n";
  cout << "2. Mostrar elementos del inventario.\n";
  cout << "3. Agregar cantidad a un producto\n";
  cout << "4. Retirar cantidad a un producto.\n";
  cout << "5. Salir..\n";
  cout << "Ingrese la opcion a realizar [1 - 5]:  ";
  cin >> opcion;

  cout << "\n";

  return opcion;
}

void operacionInventario()
{
  char opcion;
  do
  {
    opcion = menuInventario();

    switch (opcion)
    {
    case '1':
      agregarProductos(tienda);
      break;

    case '2':
      mostrarElementos(tienda);
      break;

    case '3':
      agregarCantidad(tienda);
      break;

    case '4':
      retirarCantidad(tienda);
      break;

    case '5':
      cout << "saliendo..";
      break;

    default:
      cout << "Opcion no valida: ";
      break;
    }
  } while (opcion != '5');
}

int main()
{
  operacionInventario();
  return 0;
}