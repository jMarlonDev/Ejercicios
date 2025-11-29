/*
### Ejercicio 2.2: Sistema de Empleados

Crea una clase base `Empleado` con:

- `nombreCompleto` (string)
- `numeroEmpleado` (string)
- `salarioBase` (double)

Crea dos clases derivadas:

#### Clase `EmpleadoTiempoCompleto` hereda de `Empleado`

Atributos:

- `beneficios` (string)
- `bono` (double)

Métodos:

- `calcularSalarioTotal()` → salarioBase + bono
- `mostrarInfo()` sobrescrito

#### Clase `EmpleadoPorHoras` hereda de `Empleado`

Atributos:

- `horasTrabajadas` (int)
- `tarifaPorHora` (double)

Métodos:

- `calcularSalarioTotal()` → horasTrabajadas × tarifaPorHora
- `mostrarInfo()` sobrescrito

*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Employee
{
protected:
  string fullname_;
  string employeeCode_;
  int salary_;

public:
  Employee(string fullname = "", string employeeCode = "", int salary = 0)
      : fullname_(fullname), employeeCode_(employeeCode), salary_(salary) {}

  virtual ~Employee() {}

  // Getters
  virtual string getFullName() const { return fullname_; }
  virtual string getEmployeeCode() const { return employeeCode_; }
  virtual int getSalary() const { return salary_; }

  // Setters
  virtual void setFullName() = 0;
  virtual void setEmployeeCode() = 0;
  virtual void setSalary() = 0;

  // Métodos virtuales para calcular el salario y mostrar la información
  virtual int calculateSalary() = 0;
  virtual void showInfo() = 0;
};

class FullTimeEmployee : public Employee
{
private:
  string advantages_;
  int bond_;

public:
  FullTimeEmployee(string fullname = "", string employeeCode = "", int salary = 0, string advantages = "Seguro Médico", int bond = 250000)
      : Employee(fullname, employeeCode, salary), advantages_(advantages), bond_(bond) {}

  // Implementación Getters de la interfaz de empleado
  string getFullName() const override { return fullname_; }
  string getEmployeeCode() const override { return employeeCode_; }
  int getSalary() const override { return salary_; }

  // Getter de la clase empleado tiempo completo
  string getAdvantages() const { return advantages_; }
  int getBond() const { return bond_; }

  // Implementación de Setters de la interfaz de empleado
  void setFullName() override
  {
    cout << "Ingrese el nombre completo del empleado: ";
    getline(cin, fullname_);
  }

  void setEmployeeCode() override
  {
    cout << "Ingrese el código asignado del empleado: ";
    getline(cin, employeeCode_);
  }

  void setSalary() override
  {
    cout << "Ingrese el salario base del empleado: ";
    cin >> salary_;
    cin.ignore();
  }

  // Métodos para calcular y mostrar información implementados por la interfaz
  int calculateSalary() override
  {
    return salary_ + bond_;
  }

  void showInfo() override
  {
    cout << "Nombre completo del empleado: " << getFullName() << "\n";
    cout << "Código del empleado: " << getEmployeeCode() << "\n";
    cout << "Salario base sin bono: " << getSalary() << "\n";
    cout << "Bono sugerido por la empresa: " << getBond() << "\n";
    cout << "Salario base más el bono mensual: " << calculateSalary() << "\n";
    cout << "Beneficios por parte de la empresa para el empleado: " << getAdvantages() << "\n";
  }
};

class HourlyEmployee : public Employee
{
private:
  int hoursWorked_;
  int hourlyRate_;

public:
  HourlyEmployee(string fullname = "", string employeeCode = "", int salary = 0, int hourWorked = 0, int hourlyRate = 9000)
      : Employee(fullname, employeeCode, salary), hoursWorked_(hourWorked), hourlyRate_(hourlyRate) {}

  // Implementación Getters de la interfaz de empleado
  string getFullName() const override { return fullname_; }
  string getEmployeeCode() const override { return employeeCode_; }
  int getSalary() const override { return salary_; }

  // Getter de la clase empleado por horas
  int getHoursWorked() { return hoursWorked_; }
  int getHourlyRate() { return hourlyRate_; }

  // Implementación de Setters de la interfaz de empleado
  void setFullName() override
  {
    cout << "Ingrese el nombre completo del empleado: ";
    getline(cin, fullname_);
  }

  void setEmployeeCode() override
  {
    cout << "Ingrese el código asignado del empleado: ";
    getline(cin, employeeCode_);
  }

  void setSalary() override
  {
    cout << "Ingrese el salario base del empleado: ";
    cin >> salary_;
    cin.ignore();
  }

  // Setters de la clase empleado por horas
  void setHoursWorked()
  {
    cout << "Ingrese las horas trabajas por día en la semana: ";
    cin >> hoursWorked_;
    cin.ignore();
  }

  // Métodos de calcular salario y mostrar información del empleado de la interfaz
  int calculateSalary() override
  {
    int result = hoursWorked_ * hourlyRate_;
    return salary_ += result;
  }

  void showInfo() override
  {
    cout << "Nombre completo del empleado: " << getFullName() << "\n";
    cout << "Código del empleado: " << getEmployeeCode() << "\n";
    cout << "Salario base sin contar las horas y precio por días de trabajo: " << getSalary() << "\n";
    cout << "Horas de trabajo: " << getHoursWorked() << "\n";
    cout << "Pago por hora de trabajo: " << getHourlyRate() << "\n";
    cout << "Salario total por las horas de trabajo: " << calculateSalary() << "\n";
  }
};

FullTimeEmployee employeeValues()
{
  FullTimeEmployee employeeFullTime;
  cout << "Valores para la clase hija Empleado de tiempo completo: \n";

  employeeFullTime.setFullName();
  employeeFullTime.setEmployeeCode();
  employeeFullTime.setSalary();

  return employeeFullTime;
}

HourlyEmployee employeeHourlyValues()
{
  HourlyEmployee employeeHourly;
  cout << "Valores para la clase hija Empleado de por horas: \n";

  employeeHourly.setFullName();
  employeeHourly.setEmployeeCode();
  employeeHourly.setSalary();
  employeeHourly.setHoursWorked();

  return employeeHourly;
}

void createFullTimeEmployee()
{
  FullTimeEmployee tempEmployee = employeeValues();
  unique_ptr<FullTimeEmployee> employee = make_unique<FullTimeEmployee>(
      tempEmployee.getFullName(),
      tempEmployee.getEmployeeCode(),
      tempEmployee.getSalary(),
      tempEmployee.getAdvantages(),
      tempEmployee.getBond());

  cout << "\n";
  employee->showInfo();
}

void createHourlyEmployee()
{
  HourlyEmployee tempEmployee = employeeHourlyValues();
  unique_ptr<HourlyEmployee> employee = make_unique<HourlyEmployee>(
      tempEmployee.getFullName(),
      tempEmployee.getEmployeeCode(),
      tempEmployee.getSalary(),
      tempEmployee.getHoursWorked(),
      tempEmployee.getHourlyRate());

  cout << "\n";
  employee->showInfo();
}

int main(int argc, char const *argv[])
{
  createFullTimeEmployee();
  createHourlyEmployee();
  return 0;
}
