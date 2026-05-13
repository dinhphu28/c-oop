#include "animal.h"
#include <stdlib.h>
#include <string.h>

struct Animal {
    char name[50];
    int age;
};

struct Animal* create_animal(const char* name, int age) {
    struct Animal* animal = (struct Animal*)malloc(sizeof(struct Animal));
    if (animal != NULL) {
        strncpy(animal->name, name, sizeof(animal->name) - 1);
        animal->name[sizeof(animal->name) - 1] = '\0'; // Ensure null-termination
        animal->age = age;
    }
    return animal;
}
