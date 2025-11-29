/*
Nivel 2️⃣: Herencia Simple
Ejercicio 2.1: Vehículos (Auto y Motocicleta)

Partiendo de la clase `Vehículo` del Ejercicio 1.1, crea dos clases derivadas:

#### Clase `Auto` hereda de `Vehículo`

Atributos adicionales:

- `numeroPuertas` (int)
- `tipoCombustible` (string)

Métodos:

- Constructor
- Getters y Setters
- `mostrarInfo()` sobrescrito (override)

#### Clase `Motocicleta` hereda de `Vehículo`

Atributos adicionales:

- `tieneAlarón` (bool)
- `cilindrada` (int)

Métodos:

- Constructor
- Getters y Setters
- `mostrarInfo()` sobrescrito (override)

**Ejemplo de uso:**

```
Auto miAuto("Ford", "Mustang", 2023, 220, 4, "Gasolina");
Motocicleta miMoto("Harley-Davidson", "Sportster", 2023, 200, true, 1200);

miAuto.mostrarInfo();
miMoto.mostrarInfo();
*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

/* Interfaz de la clase Vehículo */
class InterfaceVehicle
{
protected:
  string brand_;
  string model_;
  int year_;
  int maximumSpeed_;

public:
  InterfaceVehicle(string brand = "", string model = "", int year = 0, int maximumSpeed = 0)
      : brand_(brand), model_(model), year_(year), maximumSpeed_(maximumSpeed) {}

  virtual ~InterfaceVehicle() {}

  // Getters virtuales puros
  virtual string getBrand() const = 0;
  virtual string getModel() const = 0;
  virtual int getYear() const = 0;
  virtual int getMaximumSpeed() const = 0;

  // Setters virtuales puros
  virtual void setBrand() = 0;
  virtual void setModel() = 0;
  virtual void setYear() = 0;
  virtual void setMaximumSpeed() = 0;

  // Método virtual para mostrar información
  virtual void showInfo() const = 0;
};

/* Clase base Vehicle que implementa la interfaz */
class Vehicle : public InterfaceVehicle
{
public:
  Vehicle(string brand = "", string model = "", int year = 0, int maximumSpeed = 0)
      : InterfaceVehicle(brand, model, year, maximumSpeed) {}

  // Implementación de getters
  string getBrand() const override { return brand_; }
  string getModel() const override { return model_; }
  int getYear() const override { return year_; }
  int getMaximumSpeed() const override { return maximumSpeed_; }

  // Implementación de setters
  void setBrand() override
  {
    cout << "Ingrese la marca del vehículo: ";
    getline(cin, brand_);
  }

  void setModel() override
  {
    cout << "Ingrese el modelo del vehículo: ";
    getline(cin, model_);
  }

  void setYear() override
  {
    cout << "Ingrese el año del vehículo: ";
    cin >> year_;
    cin.ignore();

    if (year_ < 1886)
    {
      cout << "El año del vehículo no es válido. El primer vehículo motorizado se construyo en 1886.\n";
      year_ = 0;
      return;
    }

    cout << "Año válido registrado.\n";
  }

  void setMaximumSpeed() override
  {
    cout << "Ingrese la velocidad máxima del vehículo (km/h): ";
    cin >> maximumSpeed_;
    cin.ignore();

    if (maximumSpeed_ < 0)
    {
      cout << "La velocidad máxima NO puede ser negativa.\n";
      maximumSpeed_ = 0;
      return;
    }

    cout << "Velocidad máxima registrada correctamente.\n";
  }

  void showInfo() const override
  {
    cout << "Información del Vehículo \n";
    cout << "Marca del vehículo: " << brand_ << "\n";
    cout << "Modelo del vehículo: " << model_ << "\n";
    cout << "Año de creación del vehículo: " << year_ << "\n";
    cout << "Velocidad Máxima del vehículo: " << maximumSpeed_ << " km/h\n\n";
  }
};

class Car : public Vehicle
{
private:
  int numberDoors_;
  string typeFuel_;

public:
  Car(string brand = "", string model = "", int year = 0, int maximumSpeed = 0, int doors = 0, string typeFuel = "")
      : Vehicle(brand, model, year, maximumSpeed), numberDoors_(doors), typeFuel_(typeFuel) {}

  // Getters
  int getDoors() const { return numberDoors_; }
  string getTypeFuel() const { return typeFuel_; }

  // Setters
  void setNumberDoors()
  {
    cout << "Ingrese la cantidad de puertas que tiene el Auto: ";
    cin >> numberDoors_;
    cin.ignore();
  }

  void setFuelType()
  {
    cout << "Ingrese el tipo de gasolina que tiene el Auto: ";
    getline(cin, typeFuel_);
  }

  void showInfo()
  {
    Vehicle::showInfo();
    cout << "Número de puertas del vehículo: " << getDoors() << "\n";
    cout << "Tipo de combustible del vehículo: " << getTypeFuel() << "\n";
  }
};

class Motorcycle : public Vehicle
{
private:
  bool aileron_;
  int cylinder_;

public:
  Motorcycle(string brand = "", string model = "", int year = 0, int maximumSpeed = 0, bool aileron = false, int cylinder = 0)
      : Vehicle(brand, model, year, maximumSpeed), aileron_(aileron), cylinder_(cylinder) {}

  // Getters
  bool getAileron() const { return aileron_; }
  int getCylinder() const { return cylinder_; }

  // Setters
  void setAileron()
  {
    cout << "Ingrese 1: si la motocicleta tiene un alerón\n 0: si NO lo tiene: ";
    cin >> aileron_;
    cin.ignore();
  }

  void setCylinder()
  {
    cout << "Ingrese el cilindraje de la motocicleta: ";
    cin >> cylinder_;
    cin.ignore();
  }

  void showInfo()
  {
    Vehicle::showInfo();
    cout << "¿La motocicleta tiene alerón?: " << getAileron() << "\n";
    cout << "Cilindraje de la motocicleta: " << getCylinder() << "\n";
  }
};

Car carValues()
{
  Car car;
  cout << "Valores para la clase hija Auto: \n";
  car.setBrand();
  car.setModel();
  car.setYear();
  car.setMaximumSpeed();
  car.setNumberDoors();
  car.setFuelType();

  return car;
}

Motorcycle motorCycleValues()
{
  Motorcycle motorcycle;
  cout << "Valores para la clase hija Motocicleta: \n";
  motorcycle.setBrand();
  motorcycle.setModel();
  motorcycle.setYear();
  motorcycle.setMaximumSpeed();
  motorcycle.setAileron();
  motorcycle.setCylinder();

  return motorcycle;
}

void createCar()
{
  Car tempCar = carValues();
  unique_ptr<Car> car = make_unique<Car>(
      tempCar.getBrand(),
      tempCar.getModel(),
      tempCar.getYear(),
      tempCar.getMaximumSpeed(),
      tempCar.getDoors(),
      tempCar.getTypeFuel());

  cout << "\n";
  car->showInfo();
}

void createMotorcycle()
{
  Motorcycle tempMototorcycle = motorCycleValues();
  unique_ptr<Motorcycle> motorcycle = make_unique<Motorcycle>(
      tempMototorcycle.getBrand(),
      tempMototorcycle.getModel(),
      tempMototorcycle.getYear(),
      tempMototorcycle.getMaximumSpeed(),
      tempMototorcycle.getAileron(),
      tempMototorcycle.getCylinder());

  cout << "\n";
  motorcycle->showInfo();
}

int main(int argc, char const *argv[])
{
  createCar();
  createMotorcycle();
  return 0;
}
