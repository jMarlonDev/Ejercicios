/*
Ejercicio 3.2: Sistema Bancario

Crea una jerarquía:

```
        Cuenta
       /      \
   CuentaAhorro CuentaCorriente
```

**Clase base `Cuenta`:**

- `numeroCuenta` (string)
- `propietario` (string)
- `saldo` (double)

Métodos:

- `depositar(double monto)` virtual
- `retirar(double monto)` virtual
- `mostrarInfo()` virtual
- Getters y Setters con validaciones

**Clase `CuentaAhorro` hereda de `Cuenta`:**

- Atributo: `tasaInteres` (double)
- Método: `generarInteres()` que calcule y agregue interés
- Sobrescribir `depositar()` y `retirar()`

**Clase `CuentaCorriente` hereda de `Cuenta`:**

- Atributo: `limiteDescubierto` (double)
- Método: `solicitarDescubierto(double monto)`
- Sobrescribir `depositar()` y `retirar()`
*/

#include <iostream>
#include <memory>
#include <string>
#include <iomanip>
using namespace std;

class Account
{
protected:
  string accountNumber_;
  string owner_;
  double balance_;

public:
  Account(string accountNumber = "", string owner = "", double balance = 0.0)
      : accountNumber_(accountNumber), owner_(owner), balance_(balance) {}

  virtual ~Account() {}

  virtual string getAccountNumber() const { return accountNumber_; }
  virtual string getOwner() const { return owner_; }
  virtual double getBalance() const { return balance_; }

  virtual void setAccountNumber() = 0;
  virtual void setOwner() = 0;
  virtual void setBalance() = 0;

  virtual void deposit() = 0;
  virtual void withdraw() = 0;
  virtual void showInfo() = 0;
};

class SavingsAccount : public Account
{
private:
  double interestRate_;

public:
  SavingsAccount(string accountNumber = "", string owner = "", int balance = 0, double interestRate = 0.02)
      : Account(accountNumber, owner, balance), interestRate_(interestRate) {}

  // Getters
  string getAccountNumber() const override { return accountNumber_; }
  string getOwner() const override { return owner_; }
  double getBalance() const override { return balance_; }

  double getInterestRate() const { return interestRate_; }

  void setAccountNumber() override
  {
    cout << "Ingrese el código de la cuenta: ";
    getline(cin, accountNumber_);
  }

  void setOwner() override
  {
    cout << "Ingrese el nombre del propietario de la cuenta: ";
    getline(cin, owner_);
  }

  void setBalance() override
  {
    cout << "Ingrese el saldo base inicial para depositarlo en la cuenta: ";
    cin >> balance_;
    cin.ignore();
  }

  void deposit() override
  {
    int tempBalance;
    cout << "Ingrese la cantidad de dinero que va a depositar en la cuenta: ";
    cin >> tempBalance;
    cin.ignore();

    if (tempBalance <= 0)
    {
      cout << "Lo sentimos No se puede ingresar saldos negativos o saldo 0 de dinero en la cuenta vuelve a intentarlo\n";
      return;
    }

    balance_ += tempBalance;
    cout << fixed << setprecision(2);
    cout << "Depósito exitoso. Nuevo saldo: $" << balance_ << "\n";
  }

  void withdraw() override
  {
    double tempBalance;
    cout << "\nSaldo disponible: $" << fixed << setprecision(2) << balance_ << "\n";
    cout << "Ingrese la cantidad de dinero que va a retirar de la cuenta: ";
    cin >> tempBalance;
    cin.ignore();

    if (tempBalance <= 0)
    {
      cout << "Lo sentimos no puedes retirar dinero de saldo negativo o 0 de la cuenta\n";
      return;
    }

    if (tempBalance > balance_)
    {
      cout << "Lo sentimos, fondos insuficientes. Tu saldo actual es: $"
           << fixed << setprecision(2) << balance_ << "\n";
      return;
    }

    balance_ -= tempBalance;
    cout << "Retiro exitoso. Nuevo saldo: $" << fixed << setprecision(2) << balance_ << "\n";
  }

  double calculateMonthlyInterest()
  {
    return balance_ * (interestRate_ / 12.0);
  }

  double applyMonthlyInterest()
  {
    double interest = calculateMonthlyInterest();
    balance_ += interest;
    cout << fixed << setprecision(2);

    return balance_;
  }

  void showInfo() override
  {
    cout << fixed << setprecision(2);
    cout << "\nINFORMACIÓN DE LA CUENTA\n";
    cout << "Código de la cuenta: " << getAccountNumber() << "\n";
    cout << "Propietario de la cuenta: " << getOwner() << "\n";
    cout << "Tasa de interés anual: " << (interestRate_ * 100) << "%\n";
    cout << "Interés mensual estimado: $" << calculateMonthlyInterest() << "\n";
    cout << "Interés aplicado: " << applyMonthlyInterest() << "\n";
    cout << "Saldo actual en la cuenta: $" << getBalance() << "\n";
  }
};

SavingsAccount savingAccountValues()
{
  SavingsAccount account;
  account.setAccountNumber();
  account.setOwner();
  account.setBalance();

  return account;
}

void createSavingsAccount()
{
  SavingsAccount tempAccount = savingAccountValues();

  unique_ptr<SavingsAccount> account = make_unique<SavingsAccount>(
      tempAccount.getAccountNumber(),
      tempAccount.getOwner(),
      tempAccount.getBalance(),
      tempAccount.getInterestRate());

  account->deposit();
  account->showInfo();
  account->withdraw();
}

int main(int argc, char const *argv[])
{
  createSavingsAccount();
  return 0;
}
