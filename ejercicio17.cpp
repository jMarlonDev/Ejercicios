/*
Sistema de puntuación de un torneo
Descripción: Registra los puntos obtenidos por cada equipo en
varios partidos y determina el ganador con mayor puntaje total.
Resultado esperado: Equipos: A=12, B=15, C=10 → ganador B.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Equipo
{
  string nombre;
  int puntaje;
};

vector<Equipo> equipos;

void registrarEquipos(vector<Equipo> &equipos)
{
  int cantidadEquipos;

  Equipo equipoParticipante;

  cout << "Cuantos equipos vas a registrar: ";
  cin >> cantidadEquipos;

  cin.ignore(); // Ignorar salto de linea

  for (int i = 0; i < cantidadEquipos; i++)
  {
    cout << "Ingrese el nombre del equipo participante: ";
    getline(cin, equipoParticipante.nombre);

    cout << "Ingrese el puntaje total que obtuvo el equipo: ";
    cin >> equipoParticipante.puntaje;
    cin.ignore(); // Ignorar salto de linea

    equipos.push_back(equipoParticipante);
  }
}

void mostrarElementos(vector<Equipo> &equipos, int index = 0)
{
  if (index == equipos.size())
  {
    return;
  }

  cout << "Nombre del equipo: " << equipos[index].nombre << "\n";
  cout << "puntaje del equipo: " << equipos[index].puntaje << "\n";
  mostrarElementos(equipos, index + 1);
}

void mayorPuntaje(vector<Equipo> &equipos)
{
  // Se asume que el primer elemento es el mayor
  int mayor = equipos[0].puntaje;
  string nombre = equipos[0].nombre;

  for (int i = 0; i < equipos.size(); i++)
  {
    if (equipos[i].puntaje > mayor)
    {
      mayor = equipos[i].puntaje;
      nombre = equipos[i].nombre;
    }
  }

  cout << "\nEl equipo de mayor puntaje es: " << nombre << "\n";
  cout << "\nCon un puntaje total de: " << mayor << "\n";
}

int main(int argc, char const *argv[])
{
  registrarEquipos(equipos);
  mostrarElementos(equipos);
  mayorPuntaje(equipos);
  return 0;
}
