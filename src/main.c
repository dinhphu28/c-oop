#include "animal.h"
#include "car.h"
#include "cat.h"
#include <stdio.h>
#include <stdlib.h>

#include "motorbike.h"

#include "motorbike_factory.h"

void encapsulation_example();
void inheritance_example();
void polymorphism_example();

int factory_method_example();
int ride_bike(struct Motorbike *bike);

int main() {
  encapsulation_example();
  inheritance_example();
  polymorphism_example();

  return factory_method_example();

  return EXIT_SUCCESS;
}

void encapsulation_example() {
  struct Animal *my_animal = create_animal("Buddy", 5);
  say_hello(my_animal);

  /*
   NOTE: Below lines will cause compilation error because the struct definition
   is hidden in the .c file. This is ENCAPSULATION in C
  */
  // printf("My animal's name is %s and it is %d years old.\n", my_animal->name,
  // my_animal->age);

  free(my_animal);
}

void inheritance_example() {
  struct Cat *my_cat = create_cat("Whiskers", 3);
  printf("My cat's name is %s and it is %d years old.\n", get_name(my_cat),
         get_age(my_cat));

  // NOTE: INHERITANCE in C is achieved by embedding one struct inside another
  say_hello((struct Animal *)
                my_cat); // Treat cat as an animal, this is INHERITANCE in C

  free(my_cat);
}

void polymorphism_example() {
  // NOTE: POLYMORPHISM in C is achieved through function pointers in the struct
  // definition.
  extern struct Car
      bmw; // Declare the external Car instance defined in bmw_car.c
  bmw.start_engine();
}

int factory_method_example() {
  // NOTE: FACTORY PATTERN in C is implemented by defining a factory struct
  extern struct MotorbikeFactory
      motorbike_factory; // Declare the factory instance

  struct Motorbike *bmw_bike = motorbike_factory.create_motorbike(
      &motorbike_factory, BMW, "BMW R1250 GSA");
  if (bmw_bike == NULL) {
    fprintf(stderr, "Failed to create motorbike.\n");
    return EXIT_FAILURE; // Handle factory failure case
  }

  struct Motorbike *ducati_bike = motorbike_factory.create_motorbike(
      &motorbike_factory, DUCATI, "Ducati Panigale V4S");
  if (ducati_bike == NULL) {
    fprintf(stderr, "Failed to create motorbike.\n");
    free(bmw_bike);      // Clean up previously created bike
    return EXIT_FAILURE; // Handle factory failure case
  }

  ride_bike(bmw_bike);
  ride_bike(ducati_bike);

  free(bmw_bike);
  free(ducati_bike);

  return EXIT_SUCCESS;
}

int ride_bike(struct Motorbike *bike) {
  printf("Starting the bike...\n");
  // Use the Motorbike interface to interact with the bike
  printf("Current fuel level: %d liters.\n", bike->get_fuel_level(bike));
  bike->fill_gas(bike, 20);
  printf("Current fuel level after filling gas: %d liters.\n",
         bike->get_fuel_level(bike));
  bike->start_engine(bike);
  return EXIT_SUCCESS;
}
