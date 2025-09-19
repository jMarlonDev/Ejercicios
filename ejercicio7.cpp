/*
Seguimiento de lectura de libros:
Descripción: Guarda libros leídos con su número de páginas y

calcula el total de páginas leídas en el mes.
Resultado esperado: Libros con [200,150] páginas, total 350.
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Libro
{
public:
  string name;
  int pages;
};

vector<Libro> books;

Libro createBook()
{
  string name;
  int pagesBook;

  cout << "Ingresa el nombre del libro: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar la entrada de \n para la nueva salida
  getline(cin, name);

  cout << "Ingresa la cantidad de paginas del libro: ";
  cin >> pagesBook;

  Libro book = {name, pagesBook};

  cout << "\n";
  return book;
}

void addBooks(vector<Libro> &readBooks, int index, int quantity)
{

  if (index == quantity)
  {
    return;
  }

  Libro book = createBook();
  readBooks.push_back(book);
  addBooks(readBooks, index + 1, quantity);
}

int addPages(vector<Libro> &readBooks)
{
  int result = 0;

  for (int b = 0; b < readBooks.size(); b++)
  {
    result += readBooks[b].pages;
  }

  cout << "Total de paginas leídas: " << result << "\n\n";
  return result;
}

void displayBooks(vector<Libro> &readBooks, int index)
{
  if (index == readBooks.size())
  {
    return;
  }

  cout << "Booke Title: " << readBooks[index].name << "\n";
  cout << "Number Pages: " << readBooks[index].pages << "\n";

  displayBooks(readBooks, index + 1);
}

int main()
{

  cout << "Seguimiento de lectura de libros...\n";
  cout << "Ingresa la cantidad de libros que has leído en el mes o en meses anteriores: ";
  int quantity;
  cin >> quantity;

  addBooks(books, 0, quantity);

  cout << "Libros: \n";
  displayBooks(books, 0);
  addPages(books);

  return 0;
}
