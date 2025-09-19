/*
  Organizador de tareas pendientes
  Descripción: Permite agregar, marcar como completadas y eliminar
  tareas de una lista.
  Resultado esperado: Tras completar “Estudiar”, esta se marca
  como hecha.
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Task
{
public:
  string title;
  bool taskCompleted;
};

vector<Task> tasks;

Task createTask()
{
  string title;
  cout << "Ingrese el título de la nueva tarea: ";
  getline(cin, title);

  return {title, false};
}

void addTasks(vector<Task> &tasks)
{
  int numberTask;
  cout << "Ingrese la cantidad de tareas que quiere agregar a la lista de tareas: ";
  cin >> numberTask;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t = 0; t < numberTask; t++)
  {
    Task newTask = createTask();
    tasks.push_back(newTask);
  }

  cout << "\n";
}

void displayTasks(vector<Task> &tasks, int index)
{
  if (tasks.size() == 0)
  {
    cout << "No hay tareas agregadas a la lista.\n";
    return;
  }

  // Caso Base
  if (index == tasks.size())
  {
    // Se detiene la función cuando el índice alcanze el tamaño del arreglo
    return;
  }

  cout << "Tittle: " << tasks[index].title << "\n";
  cout << "Completed: " << (tasks[index].taskCompleted ? "True" : "False") << "\n\n";

  displayTasks(tasks, index + 1);
}

void deleteTask(vector<Task> &tasks)
{
  string taskDelete;
  cout << "Ingrese el nombre ó título de la tarea que quiere eliminar: ";
  getline(cin, taskDelete);

  bool taskExists = false;

  for (int t = 0; t < tasks.size(); t++)
  {
    if (tasks[t].title == taskDelete)
    {
      tasks.erase(tasks.begin() + t);
      taskExists = true;
      break;
    }
  }

  if (!taskExists)
  {
    cout << "No existe el nombre de la tarea que ingresaste.\n";
  }

  cout << "\n";
}

void updateTask(vector<Task> &tasks)
{
  string taskUpdate;
  cout << "Ingrese el nombre ó título de la tarea que quiere actualizar como [Completada]: ";
  getline(cin, taskUpdate);

  bool taskExists = false;

  for (int t = 0; t < tasks.size(); t++)
  {
    if (tasks[t].title == taskUpdate)
    {
      tasks[t].taskCompleted = true;
      taskExists = true;
      break;
    }
  }

  if (!taskExists)
  {
    cout << "No existe el nombre de la tarea que ingresaste.\n";
  }
}

char menu()
{
  cout << "\n";
  char opcion;
  cout << "1. Agregar tareas.\n";
  cout << "2. Mostrar tareas.\n";
  cout << "3. Eliminar tareas.\n";
  cout << "4. Actualizar tareas.\n";
  cout << "5. Salir...\n";
  cout << "Ingrese una opción: ";
  cin >> opcion;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "\n";

  return opcion;
}

void taskOperation()
{
  char opcion;
  do
  {
    opcion = menu();
    switch (opcion)
    {
    case '1':
      addTasks(tasks);
      break;

    case '2':
      displayTasks(tasks, 0);
      break;

    case '3':
      deleteTask(tasks);
      break;

    case '4':
      updateTask(tasks);
      break;

    case '5':
      cout << "Saliendo...\n";
      break;

    default:
      cout << "Opción no valida.";
      break;
    }
  } while (opcion != '5');
}

int main()
{
  taskOperation();
  return 0;
}
