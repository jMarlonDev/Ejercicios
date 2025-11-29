/*
Ejercicio 1.2: Clase Producto
Crea una clase `Producto` para una tienda con:
- `codigo` (string)
- `nombre` (string)
- `precio` (double)
- `cantidad` (int)

**Requisitos:**
- ✅ Constructor inicializador
- ✅ Getters y Setters con validaciones:
  - Precio no puede ser negativo
  - Cantidad no puede ser negativa
- ✅ Método `calcularValorTotal()` que retorne precio × cantidad
- ✅ Método `aplicarDescuento(double porcentaje)` que reduzca el precio
- ✅ Método `mostrarInfo()` que muestre todos los datos

**Ejemplo de uso:**
Producto laptop("001", "Laptop HP", 850.00, 5);
laptop.mostrarInfo();
cout << "Valor total: $" << laptop.calcularValorTotal() << endl;
laptop.aplicarDescuento(10); // 10% de descuento
laptop.mostrarInfo();
*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Product
{
private:
  string productCode_;
  string name_;
  int price_;
  int productQuantity_;

public:
  Product() = default;
  Product(string code, string name, int price, int quantity) : productCode_(code), name_(name), price_(price), productQuantity_(quantity) {};

  // Getters
  string getProductCode()
  {
    return productCode_;
  }

  string getName()
  {
    return name_;
  }

  int getPrice()
  {
    return price_;
  }

  int getProductQuantity()
  {
    return productQuantity_;
  }

  // Setters
  void setProductCode()
  {
    cout << "Ingrese el código del producto: ";
    getline(cin, productCode_);
  }

  void setName()
  {
    cout << "Ingrese el nombre del producto: ";
    getline(cin, name_);
  }

  void setPrice()
  {
    cout << "Ingrese el precio del producto: ";
    cin >> price_;
    cin.ignore();

    if (price_ < 0)
    {
      cout << "El precio ingresado NO es valido por que es un valor negativo lo sentimos\n";
      return;
    }
  }

  void setproductQuantity()
  {
    cout << "Ingrese la cantidad que quiere comprar del producto: ";
    cin >> productQuantity_;
    cin.ignore();

    if (productQuantity_ < 0)
    {
      cout << "Lo sentimos no puedes llevar cantidades negativas del producto\n";
      return;
    }
  }

  int calculateProductQuantity()
  {

    return price_ *= productQuantity_;
  }

  int calculateTotalValue()
  {

    int discount = price_ * 10 / 100;
    return price_ -= discount;
  }

  void showInfo()
  {
    cout << "Código del producto: " << getProductCode() << "\n";
    cout << "Nombre del producto: " << getName() << "\n";
    cout << "Precio parcial del producto: " << getPrice() << "\n";
    cout << "Precio basado en la cantidad del producto: " << calculateProductQuantity() << "\n";
    cout << "Precio total con el 10% de descuento aplicado: " << calculateTotalValue() << "\n";
  }
};

Product addValues()
{
  Product product;
  product.setProductCode();
  product.setName();
  product.setPrice();
  product.setproductQuantity();

  cout << "\n";
  return product;
}

void information()
{
  Product productTemp = addValues();
  unique_ptr<Product> product = make_unique<Product>(
      productTemp.getProductCode(),
      productTemp.getName(),
      productTemp.getPrice(),
      productTemp.getProductQuantity());

  product->showInfo();
}

int main(int argc, char const *argv[])
{
  information();
  return 0;
}
