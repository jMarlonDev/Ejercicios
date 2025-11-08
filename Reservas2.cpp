/*
 * EJERCICIO DE PRÁCTICA: SISTEMA DE GESTIÓN DE RESERVAS DE HOTEL
 *
 * INSTRUCCIONES:
 * Completa este ejercicio siguiendo la metodología OOP:
 *

 * 1. Identifica los objetos necesarios
 * 2. Define sus atributos y métodos
 * 3. Establece las relaciones entre objetos
 * 4. Implementa las clases
 *

 * PROBLEMA:
 * Crear un sistema para gestionar las reservas de un hotel.
 * - El hotel tiene habitaciones de diferentes tipos (simple, doble, suite)
 * - Los clientes pueden hacer reservas
 * - Cada reserva incluye: cliente, habitación, fecha de entrada, fecha de salida
 * - Las habitaciones tienen un precio por noche y pueden estar disponibles o ocupadas
 * - Los clientes tienen información personal (nombre, email, teléfono)

 *
 * FUNCIONALIDADES REQUERIDAS:
 * - Registrar habitaciones en el hotel
 * - Registrar clientes
 * - Hacer reservas (verificando disponibilidad)
 * - Cancelar reservas
 * - Mostrar información de habitaciones disponibles
 * - Calcular el costo total de una reserva
 */

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Client
{
private:
  string name_;
  string email_;
  string phone_;

public:
  Client() = default;
  // Constructor
  Client(string name, string email, string phone) : name_(name), email_(email), phone_(phone) {}

  // Métodos setters para la clase de tipo cliente
  void setName()
  {
    cout << "Ingrese su nombre: ";
    getline(cin, name_);
  }

  void setEmail()
  {
    cout << "Ingrese su Correo Eléctronico: ";
    getline(cin, email_);
  }

  void setPhone()
  {
    cout << "Ingrese su número de telefono: ";
    getline(cin, phone_);
  }

  void setClient()
  {
    setName();
    setEmail();
    setPhone();
  }

  void informationClient()
  {
    cout << "Información del cliente que realizó la reserva de la habitación: \n";
    cout << "Nombre: " << name_ << "\n";
    cout << "Correo: " << email_ << "\n";
    cout << "Telefono: " << phone_ << "\n\n";
  }
};

/* Interface de la Habitación */
class Room
{
public:
  virtual void reserve() = 0;
  virtual void total() = 0;
  virtual void showRooms() = 0;
  virtual void priceRoom() = 0;

  virtual ~Room() {}
};

vector<bool> roomsAvailable(12, false);

class SingleRoom : public Room
{
private:
  int roomPrice = 500000;
  int total_ = 0;

public:
  void priceRoom() override
  {
    cout << "Precio de la habitación: " << roomPrice;
  }

  void showRooms() override
  {
    cout << "Habitaciones disponibles: \n\n";
    for (int i = 0; i < roomsAvailable.size(); i++)
    {
      if (roomsAvailable[i])
      {
        cout << "Habitación número: " << i << " Ocupada\n";
      }
      else
      {
        cout << "Habitación número: " << i << " Disponible\n";
      }
    }
  }

  void reserve() override
  {
    int roomNumber;
    Client client;

    // Mostrar las habitaciones disponibles
    showRooms();
    cout << "\nTipo: Habitación Simple...\n";
    cout << "Ingrese los siguientes datos para registrar la reserva de la habitación: \n";
    client.setClient();

    do
    {
      cout << "Ingrese el número de la habitación que quiere reservar números de habitación de (0 a 11): ";
      cin >> roomNumber;
      cin.ignore();

      if (roomNumber < 0 || roomNumber >= 12)
      {
        cout << "Número de la habitación NO es válido. Intentelo de nuevo\n";
      }

      if (roomsAvailable[roomNumber])
      {
        cout << "La habitación esta ocupada \n";
        roomNumber = -1; // continúa el bucle al cumplir la condición de < 0
      }

    } while (roomNumber < 0 || roomNumber >= 12);

    roomsAvailable[roomNumber] = true;

    cout << "\n";
    client.informationClient();
  }

  void total() override
  {
    int days;
    cout << "Ingrese: ¿Por cuántos días vas a reservar la habitación ?: ";
    cin >> days;
    cin.ignore();

    total_ = roomPrice * days;
    cout << "El total a pagar por la cantidad de días que vas a reservar la habitación son: $ " << total_ << " pesos\n";
  }
};

class DoubleRoom : public Room
{
private:
  int roomPrice = 895000;
  int total_ = 0;

public:
  void priceRoom() override
  {
    cout << "Precio de la habitación: " << roomPrice << "\n\n";
  }

  void showRooms() override
  {
    cout << "Habitaciones disponibles: \n\n";
    for (int i = 0; i < roomsAvailable.size(); i++)
    {
      if (roomsAvailable[i])
      {
        cout << "Habitación número: " << i << " Ocupada\n";
      }
      else
      {
        cout << "Habitación número: " << i << " Disponible\n";
      }
    }
  }

  void reserve() override
  {
    int roomNumber;
    Client client;

    // Mostrar las habitaciones disponibles
    showRooms();
    cout << "\nTipo: Habitación Doble...\n";
    cout << "Ingrese los siguientes datos para registrar la reserva de la habitación: \n";
    client.setClient();

    do
    {
      cout << "Ingrese el número de la habitación que quiere reservar números de habitación de (0 a 11): ";
      cin >> roomNumber;
      cin.ignore();

      if (roomNumber < 0 || roomNumber >= 12)
      {
        cout << "Número de la habitación NO es válido. Intentelo de nuevo\n";
      }

      if (roomsAvailable[roomNumber])
      {
        cout << "La habitación esta ocupada \n";
        roomNumber = -1; // continúa el bucle al cumplir la condición de < 0
      }

    } while (roomNumber < 0 || roomNumber >= 12);

    roomsAvailable[roomNumber] = true;

    cout << "\n";
    client.informationClient();
  }

  void total() override
  {
    int days;
    cout << "Ingrese: ¿Por cuántos días vas a reservar la habitación ?: ";
    cin >> days;
    cin.ignore();

    total_ = roomPrice * days;
    cout << "El total a pagar por la cantidad de días que vas a reservar la habitación son: $ " << total_ << " pesos\n";
  }
};

class Suite : public Room
{
private:
  int roomPrice = 1200000;
  int total_ = 0;

public:
  void priceRoom() override
  {
    cout << "Precio de la habitación: " << roomPrice << "\n\n";
  }

  void showRooms() override
  {
    cout << "Habitaciones disponibles: \n\n";
    for (int i = 0; i < roomsAvailable.size(); i++)
    {
      if (roomsAvailable[i])
      {
        cout << "Habitación número: " << i << " Ocupada\n";
      }
      else
      {
        cout << "Habitación número: " << i << " Disponible\n";
      }
    }
  }

  void reserve() override
  {
    int roomNumber;
    Client client;

    // Mostrar las habitaciones disponibles
    showRooms();
    cout << "\nTipo: Suite...\n";
    cout << "Ingrese los siguientes datos para registrar la reserva de la habitación: \n";
    client.setClient();

    do
    {
      cout << "Ingrese el número de la habitación que quiere reservar números de habitación de (0 a 11): ";
      cin >> roomNumber;
      cin.ignore();

      if (roomNumber < 0 || roomNumber >= 12)
      {
        cout << "Número de la habitación NO es válido. Intentelo de nuevo\n";
      }

      if (roomsAvailable[roomNumber])
      {
        cout << "La habitación esta ocupada \n";
        roomNumber = -1; // continúa el bucle al cumplir la condición de < 0
      }

    } while (roomNumber < 0 || roomNumber >= 12);

    roomsAvailable[roomNumber] = true;

    cout << "\n";
    client.informationClient();
  }

  void total() override
  {
    int days;
    cout << "Ingrese: ¿Por cuántos días vas a reservar la habitación ?: ";
    cin >> days;
    cin.ignore();

    total_ = roomPrice * days;
    cout << "El total a pagar por la cantidad de días que vas a reservar la habitación son: $ " << total_ << " pesos\n";
  }
};

void roomTypes()
{
  cout << "\n";
  cout << "Tipo de habitaciones: \n";
  cout << "Habitación Simple...\n";
  cout << "Habitación Doble...\n";
  cout << "Suite...\n";
  cout << "\n";
}

char menu()
{
  char option;
  cout << "\nMenú de opciones del Hotel...\n";
  cout << "[1]. Mostrar los tipos de habitaciones.\n";
  cout << "[2]. Mostrar habitaciones disponibles.\n";
  cout << "[3]. Mostrar precios de las habitaciones.\n";
  cout << "[4]. Reservar una habitación simple.\n";
  cout << "[5]. Reservar una habitación doble.\n";
  cout << "[6]. Reservar una suite.\n";
  cout << "[7]. Salir del sistema...\n";
  cout << "Ingrese una opción: ";
  cin >> option;
  cin.ignore();

  return option;
}

void operations()
{
  unique_ptr<Room> singleRoom = make_unique<SingleRoom>();
  unique_ptr<Room> doubleRoom = make_unique<DoubleRoom>();
  unique_ptr<Room> suiteRoom = make_unique<Suite>();
  char option;

  do
  {
    option = menu();

    switch (option)
    {
    case '1':
      roomTypes();
      break;

    case '2':
      singleRoom->showRooms();
      break;

    case '3':
      cout << "Precios de las habitaciones: \n";
      singleRoom->priceRoom();
      doubleRoom->priceRoom();
      suiteRoom->priceRoom();
      break;

    case '4':
      singleRoom->reserve();
      singleRoom->total();
      break;

    case '5':
      doubleRoom->reserve();
      doubleRoom->total();
      break;

    case '6':
      suiteRoom->reserve();
      suiteRoom->total();
      break;

    case '7':
      cout << "Saliendo...\n";
      break;

    default:
      cout << "Opcioón no valida...\n";
      break;
    }
  } while (option != '7');
}

int main(int argc, char const *argv[])
{

  operations();
  return 0;
}
