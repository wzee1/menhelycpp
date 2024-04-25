#ifndef header
#define header

#include <iostream>

struct Animal;
void readFile(std::string path, Animal *animals);
void searchByAttribute(Animal *animals, Animal *filteredAnimals);
void printAnimals(Animal *animals);

#endif