/*
Ejercicio 1.1: Clase Vehículo
Crea una clase `Vehículo` con los siguientes atributos **privados**:
- `marca` (string)
- `modelo` (string)
- `año` (int)
- `velocidadMaxima` (double)

**Requisitos:**
- ✅ Constructor que inicialice todos los atributos
- ✅ Getters para todos los atributos
- ✅ Setters para todos los atributos con validaciones:
  - El año debe ser mayor a 1886 (primer vehículo motorizado)
  - La velocidad máxima debe ser positiva
- ✅ Método `mostrarInfo()` que imprima todos los datos
- ✅ Método `acelerar(double incremento)` que aumente la velocidad máxima

**Ejemplo de uso esperado:**
```
Vehículo auto("Toyota", "Corolla", 2023, 180);
auto.mostrarInfo();
auto.acelerar(20);
auto.mostrarInfo();
*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Vehicle
{
private:
  string brand_;
  string model_;
  int year_;
  int maximumSpeed_;

public:
  Vehicle() = default;
  Vehicle(string brand, string model, int year, int maximunSpeed)
      : brand_(brand), model_(model), year_(year), maximumSpeed_(maximunSpeed) {}

  // Getters
  string getBrand()
  {
    return brand_;
  }

  string getModel()
  {
    return model_;
  }

  int getYear()
  {
    return year_;
  }

  int getMaximunSpeed()
  {
    return maximumSpeed_;
  }

  // Setters
  void setBrand()
  {
    cout << "Ingrese el modelo del vehículo: ";
    getline(cin, brand_);
  }

  void setModel()
  {
    cout << "Ingrese el modelo del vehículo: ";
    getline(cin, model_);
  }

  void setYear()
  {
    cout << "Ingrese el año del vehículo: ";
    cin >> year_;
    cin.ignore();

    if (year_ < 1886)
    {
      cout << "El año del vehículo no es valido. Por que el primer vehículo motorizado empezó a partir del año 1886 en adelante\n";
      return;
    }

    cout << "El año del vehículo es mayor o igual a 1886 por ende si es un vehículo motorizado\n";
  }

  void setMaximunSpeed()
  {
    cout << "Ingrese la velocidad máxima del vehículo: ";
    cin >> maximumSpeed_;
    cin.ignore();

    if (maximumSpeed_ < 0)
    {
      cout << "La velocidad del máxima del vehículo NO puede ser negativa\n";
      return;
    }

    cout << "La velocidad máxima del vehículo es correcta por que tiene un valor positivo\n";
  }

  void showInfo()
  {
    cout << "Marca del vehículo: " << getBrand() << "\n";
    cout << "Modelo del vehículo: " << getModel() << "\n";
    cout << "Año de creación del vehículo: " << getYear() << "\n";
    cout << "Velocidad máxima que puede alcanzar el vehículo: " << getMaximunSpeed() << " Km/h \n";
  }

  void accelerate(int increase)
  {
    maximumSpeed_ += increase;
    cout << "Acelerando el vehículo hasta llegar a la velocidad máxima de: " << maximumSpeed_ << "km/h";
  }
};

Vehicle addValue()
{
  Vehicle vehicle;
  vehicle.setBrand();
  vehicle.setModel();
  vehicle.setYear();
  vehicle.setMaximunSpeed();

  cout << "\n";
  return vehicle;
}

void information()
{
  // Creación de un objeto de tipo vehículo temporal para ingresarle los valores
  Vehicle temporaryVehicle = addValue();

  // Creación de un puntero inteligente basado en el objeto anterior para eliminación de memoria automatica
  unique_ptr<Vehicle> vehicle = make_unique<Vehicle>(
      temporaryVehicle.getBrand(),
      temporaryVehicle.getModel(),
      temporaryVehicle.getYear(),
      temporaryVehicle.getMaximunSpeed());

  // Ejemplo del readme para mostrar y incrementar los valores de velocidad en el objeto
  vehicle->showInfo();
  cout << "\n";
  vehicle->accelerate(20);
  cout << "\n\n";
  vehicle->showInfo();
}

int main(int argc, char const *argv[])
{
  information();
  return 0;
}
