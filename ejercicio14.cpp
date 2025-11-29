/*
Gestión de pedidos en un café
Descripción: Registra pedidos de clientes con productos y
precios, calcula la cuenta total por cliente.

pendientje
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Cliente
{
public:
  string name;
  int precio;
};

Cliente crearPedido()
{
  string nombreProducto;
  int precioProducto;

  cout << "Ingrese el nombre del producto: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar salto pendiente
  getline(cin, nombreProducto);

  cout << "Ingrese el precio del producto: ";
  cin >> precioProducto;

  return {nombreProducto, precioProducto};
}

void agregarPedidos(vector<vector<Cliente>> &pedidosClientes, int mesas, int productos)
{
  for (int m = 0; m < mesas; m++)
  {
    for (int p = 0; p < productos; p++)
    {
      pedidosClientes[m][p] = crearPedido();
      cout << "\n";
    }
  }
}

void mostrarPedidos(vector<vector<Cliente>> &pedidosClientes, int mesas, int productos)
{
  for (int i = 0; i < mesas; i++)
  {
    cout << "Mesa: " << i << "\n";
    for (int j = 0; j < productos; j++)
    {
      cout << "Producto: " << pedidosClientes[i][j].name << "\n";
      cout << "Precio: " << pedidosClientes[i][j].precio << "\n";
    }

    cout << "\n";
  }

  cout << "\n";
}

void calcularTotalPagar(vector<vector<Cliente>> &pedidosClientes, int mesas, int productos)
{
  int total = 0;
  int totalMesa = 0;

  for (int i = 0; i < mesas; i++)
  {
    for (int j = 0; j < productos; j++)
    {
      total += pedidosClientes[i][j].precio;
    }
  }

  cout << "Total por todas las mesas: " << total << " pesos." << "\n";

  totalMesa = total / 2;

  cout << "Total a pagar por mesa: " << totalMesa << " pesos." << "\n";
}

int main()
{
  int mesas, productos;
  cout << "Ingrese cuantas mesas hay en la cafetería: ";
  cin >> mesas;

  cout << "Ingrese la cantidad de productos por cada mesa: ";
  cin >> productos;

  // Crear la matriz
  vector<vector<Cliente>> pedidosClientes(mesas, vector<Cliente>(productos));

  agregarPedidos(pedidosClientes, mesas, productos);
  cout << "\n";
  mostrarPedidos(pedidosClientes, mesas, productos);

  calcularTotalPagar(pedidosClientes, mesas, productos);

  return 0;
}
