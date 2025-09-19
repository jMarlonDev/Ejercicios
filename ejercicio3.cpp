/*
Agenda de contactos
Descripción: Guarda nombres y números de teléfono, permite
buscar un contacto por nombre y mostrar su número.
Resultado esperado: Buscar “Ana” devuelve su número registrado.
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Contact
{
public:
  string name;
  int phone;
};

vector<Contact> contactList;

void addContact(vector<Contact> &contactList)

{
  Contact newContact = {};
  string name;
  int phone;
  int numberContacts;

  cout << "Ingrese en numeros la cantidad de contactos que quiere agregar: ";
  cin >> numberContacts;
  cout << "\n";

  for (int i = 0; i < numberContacts; i++)
  {
    cout << "Ingrese el nombre del nuevo contacto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar la entrada de \n para la nueva salida
    getline(cin, name);

    cout << "Ingrese el telefono del nuevo contacto: ";
    cin >> phone;

    newContact = {name, phone};

    contactList.push_back(newContact);
  }
}

void displayContacts(vector<Contact> &contactList, int i)
{
  if (i == contactList.size())
  {
    return; // para la funcion
  }

  cout << "Name: " << contactList[i].name << "\n";
  cout << "Phone: " << contactList[i].phone << "\n";
  displayContacts(contactList, i + 1);
}

vector<Contact> deleteContact(vector<Contact> &contactList)
{

  vector<Contact> filter;
  string nameRemove;

  cout << "Ingrese el nombre del contacto que quiere eliminar: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar la entrada de \n para la nueva salida
  getline(cin, nameRemove);

  if (contactList.size() != 0)
  {
    for (int i = 0; i < contactList.size(); i++)
    {
      if (nameRemove != contactList[i].name)
      {
        filter.push_back(contactList[i]);
        break;
      }
    }
  }

  cout << "El contacto No existe";

  return filter;
}

void filterContact(vector<Contact> &contactList)
{
  string nameFilter;
  cout << "Ingresa el nombre del contacto que quieres buscar: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar la entrada de \n para la nueva salida
  getline(cin, nameFilter);

  for (int i = 0; i < contactList.size(); i++)
  {
    if (nameFilter == contactList[i].name)
    {
      cout << "Contact: \n";
      cout << "Name: " << contactList[i].name << "\n";
      cout << "Phone: " << contactList[i].phone << "\n";
      return;
    }
  }

  cout << "El contacto no se encuentra registrado en la agenda";
}

char menu()
{
  char option;
  cout << "Contact List: ";
  cout << "1. Add Contacts.\n";
  cout << "2. Display Contacts.\n";
  cout << "3. Delete Contact.\n";
  cout << "4. Find Contact.\n";
  cout << "5. Salir\n";
  cout << "Ingresa una opción entre [1 - 5]: ";
  cin >> option;

  return option;
}

void agendaOperations()
{
  char option;
  vector<Contact> filter = deleteContact(contactList);

  do
  {
    option = menu();

    switch (option)
    {
    case '1':
      addContact(contactList);
      break;

    case '2':
      displayContacts(contactList, 0);
      break;

    case '3':
      deleteContact(contactList);
      displayContacts(filter);

      break;

    case '4':
      filterContact(contactList);
      break;

    case '5':
      cout << "Saliendo...";
      break;

    default:
      cout << "Opción no valida.";
      break;
    }
  } while (option != '5');
}

int main()
{
  agendaOperations();

  return 0;
}
