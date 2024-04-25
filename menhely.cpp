#include <iostream>
#include "header/header.h"
#include "header/header.cpp"

int main()
{
  Animal animals[FILESIZE];
  readFile("menhely.txt", animals);

  printAnimals(animals);

  Animal filteredAnimals[FILESIZE];
  searchByAttribute(animals, filteredAnimals);

  std::cout << "\nTalalt allatok:\n";
  printAnimals(filteredAnimals);

  return 0;
}