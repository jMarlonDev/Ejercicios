/*
### Ejercicio 3.1: Jerarquía de Animales

Crea la siguiente jerarquía:

```
        Животное (Animal)
           /        \
       Mamífero    Ave
        /   \       / \
     Perro Gato  Loro Aguila
```

**Clase base `Animal`:**

- `nombre` (string)
- `edad` (int)
- `peso` (double)

Métodos virtuales:

- `hacerSonido()` virtual
- `mostrarInfo()` virtual
- Getters y Setters

**Clase intermedia `Mamífero` hereda de `Animal`:**

- Atributo: `tieneColaMamífero` (bool)
- Sobrescribir métodos

**Clase intermedia `Ave` hereda de `Animal`:**

- Atributo: `envergaduraAlas` (double)
- Sobrescribir métodos

**Clases finales:**

- `Perro`, `Gato`, `Loro`, `Aguila` heredan de sus respectivas clases intermedias
*/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Interface de animal
class Animal
{
protected:
  string nombre_;
  int edad_;
  double peso_;

public:
  Animal(string nombre = "", int edad = 0, double peso = 0.0)
      : nombre_(nombre), edad_(edad), peso_(peso) {}

  virtual ~Animal() {}

  // Getters
  virtual string getNombre() const { return nombre_; }
  virtual int getEdad() const { return edad_; }
  virtual double getPeso() const { return peso_; }

  // Setters
  virtual void setNombre() = 0;
  virtual void setEdad() = 0;
  virtual void setPeso() = 0;

  // Métodos virtuales de hacer sonido y mostrar información
  virtual void hacerSonido() = 0;
  virtual void mostrarInfo() = 0;
};

// Clase hija Mamífero que hereda de la interfaz animal
class Mamifero : public Animal
{
private:
  bool tieneColaMamifero_;

public:
  Mamifero(string nombre = "", int edad = 0, double peso = 0.0, bool tieneColaMamifero = false)
      : Animal(nombre, edad, peso), tieneColaMamifero_(tieneColaMamifero) {}

  // Getters
  string getNombre() const override { return nombre_; }
  int getEdad() const override { return edad_; }
  double getPeso() const override { return peso_; }
  bool getTtieneCola() { return tieneColaMamifero_; }

  void setNombre() override
  {
    cout << "Ingrese el nombre del mamífero: ";
    cin.ignore();
    getline(cin, nombre_);
  }

  void setEdad() override
  {
    cout << "Ingrese la edad del mamífero: ";
    cin >> edad_;
    cin.ignore();
  }

  void setPeso() override
  {
    cout << "Ingrese el peso del mamífero (kg): ";
    cin >> peso_;
    cin.ignore();
  }

  void setTieneCola()
  {
    char respuesta;
    cout << "¿El mamífero tiene cola? (s/n): ";
    cin >> respuesta;
    tieneColaMamifero_ = (respuesta == 's' || respuesta == 'S');
  }

  void hacerSonido() override
  {
    cout << "El mamífero hace un sonido genérico...\n";
  }

  void mostrarInfo() override
  {
    cout << "Nombre del mamífero: " << getNombre() << "\n";
    cout << "Edad del mamífero: " << getEdad() << "\n";
    cout << "Peso del mamífero: " << getPeso() << "\n";
    cout << "El mamífero tiene cola: " << (getTtieneCola() ? "Sí" : "No") << "\n";
  }
};

// Clase hija Ave que hereda de la interfaz animal
class Ave : public Animal
{
private:
  double envergaduraAlas_;

public:
  Ave(string nombre = "", int edad = 0, double peso = 0.0, double envergaduraAlas = 0.0)
      : Animal(nombre, edad, peso), envergaduraAlas_(envergaduraAlas) {}

  // Getters
  string getNombre() const override { return nombre_; }
  int getEdad() const override { return edad_; }
  double getPeso() const override { return peso_; }
  double getEnvergaduraAlas() { return envergaduraAlas_; }

  void setNombre() override
  {
    cout << "Ingrese el nombre del Ave: ";
    cin.ignore();
    getline(cin, nombre_);
  }

  void setEdad() override
  {
    cout << "Ingrese la edad del Ave: ";
    cin >> edad_;
  }

  void setPeso() override
  {
    cout << "Ingrese el peso del Ave (kg): ";
    cin >> peso_;
  }

  void setEnvergaduraAlas()
  {
    cout << "Ingrese la medida en cm de la envergadura del Ave: ";
    cin >> envergaduraAlas_;
  }

  void hacerSonido() override
  {
    cout << "Haciendo sonido del Ave...\n";
  }

  void mostrarInfo() override
  {
    cout << "Nombre del Ave: " << getNombre() << "\n";
    cout << "Edad del Ave: " << getEdad() << "\n";
    cout << "Peso del Ave: " << getPeso() << "\n";
    cout << "Medida envergadura de alas (cm): " << getEnvergaduraAlas() << "\n";
  }
};

// Clase hija Perro que hereda de mamífero
class Perro : public Mamifero
{
public:
  Perro(string nombre = "", int edad = 0, double peso = 0.0,
        bool tieneColaMamifero = true)
      : Mamifero(nombre, edad, peso, tieneColaMamifero) {}

  void hacerSonido() override
  {
    cout << "Ladrando Guau! Guau!...\n";
  }

  void mostrarInfo() override
  {
    cout << "Información de los datos del Perro: \n";
    cout << "Nombre: " << getNombre() << "\n";
    cout << "Edad: " << getEdad() << " años\n";
    cout << "Peso: " << getPeso() << " (kg) \n";
    cout << "Tiene cola: " << (getTtieneCola() ? "Sí" : "No") << "\n";
  }
};

// Clase hija Gato que hereda de mamífero
class Gato : public Mamifero
{
public:
  Gato(string nombre = "", int edad = 0, double peso = 0.0,
       bool tieneColaMamifero = true)
      : Mamifero(nombre, edad, peso, tieneColaMamifero) {}

  void hacerSonido() override
  {
    cout << "Miau! Miau!...\n";
  }

  void mostrarInfo() override
  {
    cout << "Información de los datos del Gato: \n";
    cout << "Nombre: " << getNombre() << "\n";
    cout << "Edad: " << getEdad() << " años\n";
    cout << "Peso: " << getPeso() << " (kg) \n";
    cout << "Tiene cola: " << (getTtieneCola() ? "Sí" : "No") << "\n";
  }
};

// Clase hija Loro que hereda de Ave
class Loro : public Ave
{
public:
  Loro(string nombre = "", int edad = 0, double peso = 0.0, double envergaduraAlas = 0.0)
      : Ave(nombre, edad, peso, envergaduraAlas) {}

  void hacerSonido() override
  {
    cout << "Cacatua rou rou...\n";
  }

  void mostrarInfo() override
  {
    cout << "Información de los datos del Loro: \n";
    cout << "Nombre: " << getNombre() << "\n";
    cout << "Edad: " << getEdad() << " años\n";
    cout << "Peso: " << getPeso() << " (kg) \n";
    cout << "Envergadura de las alas (cm): " << getEnvergaduraAlas() << "\n";
  }
};

// Clase Hija Aguila que hereda de Ave
class Aguila : public Ave
{
public:
  Aguila(string nombre = "", int edad = 0, double peso = 0.0, double envergaduraAlas = 0.0)
      : Ave(nombre, edad, peso, envergaduraAlas) {}

  void hacerSonido() override
  {
    cout << "¡Screeech! \n";
  }

  void mostrarInfo() override
  {
    cout << "Información de los datos del Aguila: \n";
    cout << "Nombre: " << getNombre() << "\n";
    cout << "Edad: " << getEdad() << " años\n";
    cout << "Peso: " << getPeso() << " (kg) \n";
    cout << "Envergadura de las alas (cm): " << getEnvergaduraAlas() << "\n";
  }
};

// Funciones para darle valores a las clases Perro, Gato, Loro, Aguila
Perro dogValues()
{
  Perro dog;
  cout << "\n=== Valores para la clase hija Perro ===\n";

  dog.setNombre();
  dog.setEdad();
  dog.setPeso();
  dog.setTieneCola();

  return dog;
}

Gato catValues()
{
  Gato cat;
  cout << "\n=== Valores para la clase hija Gato ===\n";

  cat.setNombre();
  cat.setEdad();
  cat.setPeso();
  cat.setTieneCola();

  return cat;
}

Loro loroValues()
{
  Loro loro;
  cout << "\n=== Valores para la clase hija Loro ===\n";

  loro.setNombre();
  loro.setEdad();
  loro.setPeso();
  loro.setEnvergaduraAlas();

  return loro;
}

Aguila aguilaValues()
{
  Aguila aguila;
  cout << "\n=== Valores para la clase hija Aguila ===\n";

  aguila.setNombre();
  aguila.setEdad();
  aguila.setPeso();
  aguila.setEnvergaduraAlas();

  return aguila;
}

/*
Funciones para mostrar los valores y la información de cada clase
y creación de punteros inteligentes para que se destruyan automáticamente
*/

void createDog()
{
  Perro tempDog = dogValues();
  unique_ptr<Perro> dog = make_unique<Perro>(
      tempDog.getNombre(),
      tempDog.getEdad(),
      tempDog.getPeso(),
      tempDog.getTtieneCola());

  dog->mostrarInfo();
  dog->hacerSonido();
  cout << "\n";
}

void createCat()
{
  Gato tempCat = catValues();
  unique_ptr<Gato> gato = make_unique<Gato>(
      tempCat.getNombre(),
      tempCat.getEdad(),
      tempCat.getPeso(),
      tempCat.getTtieneCola());

  gato->mostrarInfo();
  gato->hacerSonido();
  cout << "\n";
}

void createLoro()
{
  Loro tempLoro = loroValues();
  unique_ptr<Loro> loro = make_unique<Loro>(
      tempLoro.getNombre(),
      tempLoro.getEdad(),
      tempLoro.getPeso(),
      tempLoro.getEnvergaduraAlas());

  loro->mostrarInfo();
  loro->hacerSonido();
  cout << "\n";
}

void createAguila()
{
  Aguila tempAguila = aguilaValues();
  unique_ptr<Aguila> aguila = make_unique<Aguila>(
      tempAguila.getNombre(),
      tempAguila.getEdad(),
      tempAguila.getPeso(),
      tempAguila.getEnvergaduraAlas());

  aguila->mostrarInfo();
  aguila->hacerSonido();
  cout << "\n";
}

int main(int argc, char const *argv[])
{
  createDog();
  createCat();
  createLoro();
  createAguila();
  return 0;
}
