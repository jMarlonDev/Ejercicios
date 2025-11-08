/*
Seguimiento de consumo eléctrico
Descripción: Registra el consumo diario de electricidad en kWh y
calcula el total mensual y el día de mayor consumo.
Resultado esperado: Consumos [5, 7, 4] → total 16, día mayor
consumo: 2 (7 kWh).
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Dia
{
  string nombre;
  int consumoKWH;
};

vector<Dia> consumoDias;

void registrarConsumoDiario(vector<Dia> &consumoDias)
{
  cout << "Registro de consumo de energía para los días de la semana [lunes-domingo]\n";
  Dia diaSemana;

  for (int i = 0; i < 7; i++)
  {
    cout << "Que día es hoy: ";
    getline(cin, diaSemana.nombre);

    cout << "Cuanto fue el total de Kilowats consumidos por hora: ";
    cin >> diaSemana.consumoKWH;
    cin.ignore();

    consumoDias.push_back(diaSemana);
  }
}

void mostrarElementos(vector<Dia> &consumoDias, int index = 0)
{
  if (index == consumoDias.size())
  {
    return;
  }

  cout << "Dia: " << consumoDias[index].nombre << "\n";
  cout << "Consumo de Kw/h: " << consumoDias[index].consumoKWH << "\n";

  mostrarElementos(consumoDias, index + 1);
}

void diaMayorConsumo(vector<Dia> &consumoDias)
{
  // Primer elemento
  int mayor = consumoDias[0].consumoKWH;
  string nombre = consumoDias[0].nombre;

  for (int i = 0; i < consumoDias.size(); i++)
  {
    if (consumoDias[i].consumoKWH > mayor)
    {
      mayor = consumoDias[i].consumoKWH;
      nombre = consumoDias[i].nombre;
    }
  }

  cout << "\nEl día de mayor consumo de energía fue: " << nombre << "\n";
  cout << "\nCon un total de kw/h consumidos: " << mayor << "\n";
}

int main(int argc, char const *argv[])
{
  registrarConsumoDiario(consumoDias);
  mostrarElementos(consumoDias);
  diaMayorConsumo(consumoDias);
  return 0;
}
