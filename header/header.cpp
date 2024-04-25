#include <iostream>
#include <fstream>
#include "header.h"

int FILESIZE = 10;

struct Animal
{
  std::string name;
  std::string species;
  int age;
  std::string color;
};

void readFile(std::string path, Animal *animals)
{
  // állat index
  int index = 0;

  std::string line; // jelenlegi sor
  std::ifstream file(path);
  while (getline(file, line))
  {
    int lineLength = line.size(); // jelenlegi sor hossza

    // attribútumok
    std::string name = "";
    std::string species = "";
    std::string age = "";
    std::string color = "";

    int col = 0; // oszlopindex
    for (int i = 0; i < lineLength; i++)
    {
      // új oszlop kezdődik minden szóköz mentén
      if (line[i] == ' ')
      {
        col += 1;
        continue;
      }

      // karakterenként hozzáfűzöm
      if (col == 0)
        name += line[i];
      else if (col == 1)
        species += line[i];
      else if (col == 2)
        age += line[i];
      else
        color += line[i];

      // resetelem az oszlopindexet a végén
      if (i == lineLength - 1)
        col = 0;
    }

    // létrehozok egy állat struct-ot
    Animal currentAnimal;
    currentAnimal.name = name;
    currentAnimal.species = species;
    currentAnimal.age = std::stoi(age);
    currentAnimal.color = color;

    // hozzáfűzöm a tömbhöz
    animals[index] = currentAnimal;
    index++;
  }

  file.close();
}

void searchByAttribute(Animal *animals, Animal *filteredAnimals)
{
  // bekérem az attribútumot
  std::string chosenAttribute;
  std::cout << "Adja meg a szamot, hogy melyik attributum alapjan keresne!\n"
            << "Lehetseges attributumok:\n"
            << "   1 - allat neve\n"
            << "   2 - allat faja\n"
            << "   3 - allat eletkora\n"
            << "   4 - allat szorenek szine\n"
            << "\nAttributum: ";
  std::cin >> chosenAttribute;

  std::string value;
  std::cout << "Ertek: ";
  std::cin >> value;

  // kereses:
  for (int i = 0; i < FILESIZE; i++)
  {
    if (chosenAttribute == "1" && animals[i].name == value)
      filteredAnimals[i] = animals[i];
    else if (chosenAttribute == "2" && animals[i].species == value)
      filteredAnimals[i] = animals[i];
    else if (chosenAttribute == "3" && animals[i].age == std::stoi(value))
      filteredAnimals[i] = animals[i];
    else if (chosenAttribute == "4" && animals[i].color == value)
      filteredAnimals[i] = animals[i];
  }
}

void printAnimals(Animal *animals)
{
  for (int i = 0; i < FILESIZE; i++)
  {
    if (animals[i].name != "")
    {
      std::cout << i + 1 << ". allat:\n"
                << "- Nev: " << animals[i].name << '\n'
                << "- Faj: " << animals[i].species << '\n'
                << "- Kor: " << animals[i].age << '\n'
                << "- Szorszin: " << animals[i].color << "\n\n";
    }
  }
}