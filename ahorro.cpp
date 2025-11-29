/*
Hacer un sistema que implemente la regla
del 50/30/20 ingresando el salario base
mostrar cuanta plata basado en el porcentaje de 50 debe en gastos necesarios
30 es la cantidad de plata que se destina para otros o gastos personales
y el 20 es la cantidad de plata que se debe ahorrar cada mes y luego mostrar
cuanto se ha ahorrado durante el año
*/

#include <iostream>
using namespace std;

// Función para calcular del salario base el 50%
// del dinero que se debe gastar en cosas necesarios si o si
int basicExpenses(int salary)
{
  // Salario multiplicado por el 50%
  return salary * 0.5;
}

int otherExpenses(int salary)
{
  return salary * 0.3;
}

int savings(int salary)
{
  return salary * 0.2;
}

int main()
{
  int salary;
  cout << "Ingrese su salario neto de cada mes: ";
  cin >> salary;

  int necessary = basicExpenses(salary);
  cout << "Gastos necesarios del 50% de su salario son: " << necessary << " pesos al mes.\n";

  int other = otherExpenses(salary);
  cout << "Otros gastos del 30% de su salario que puede gasta en lo que quiera son: " << other << " pesos al mes.\n";

  int save = savings(salary);
  cout << "Dinero para ahorro del 20% de su salario que solo se puede destinar para ahorrar son: " << save << " pesos al mes.\n";

  // Mostrar la cantidad de ahorro total si se cumple con el requisito todos los meses
  int totalSaved = save * 12;
  cout << "Si cumple con el 20% de su salario para ahorrar en un lapso de 12 meses o un año tendra: " << totalSaved << " pesos ahorrados.\n";
  return 0;
}
