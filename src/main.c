#include "animal.h"
#include "car.h"
#include "cat.h"
#include <stdio.h>
#include <stdlib.h>

#include "bmw_bike.h"
#include "ducati_bike.h"
#include "motorbike.h"

int ride_bmw_bike() {
  printf("Starting the BMW bike...\n");

  // Create a BMW bike and use its functions through the Motorbike interface
  struct Motorbike *my_bike = create_bmw_bike("BMW R1250 GSA", 1);
  if (my_bike == NULL) {
    return EXIT_FAILURE; // Handle memory allocation failure
  }

  // Use the Motorbike interface to interact with the BMW bike
  printf("Current fuel level: %d liters.\n", my_bike->get_fuel_level(my_bike));

  my_bike->fill_gas(my_bike, 20);
  printf("Current fuel level after filling gas: %d liters.\n",
         my_bike->get_fuel_level(my_bike));

  my_bike->start_engine(my_bike);

  free(my_bike);

  return EXIT_SUCCESS;
}

int ride_ducati_bike() {
  printf("Starting the Ducati bike...\n");

  struct Motorbike *ducati_bike = create_ducati_bike("Ducati Panigale V4S", 5);
  if (ducati_bike == NULL) {
    return EXIT_FAILURE; // Handle memory allocation failure
  }

  printf("Current fuel level: %d liters.\n",
         ducati_bike->get_fuel_level(ducati_bike));
  ducati_bike->fill_gas(ducati_bike, 15);
  printf("Current fuel level after filling gas: %d liters.\n",
         ducati_bike->get_fuel_level(ducati_bike));
  ducati_bike->start_engine(ducati_bike);

  free(ducati_bike);

  return EXIT_SUCCESS;
}

int main() {
  struct Animal *my_animal = create_animal("Buddy", 5);
  say_hello(my_animal);

  /*
   NOTE: Below lines will cause compilation error because the struct definition
   is hidden in the .c file. This is ENCAPSULATION in C
  */
  // printf("My animal's name is %s and it is %d years old.\n", my_animal->name,
  // my_animal->age);

  struct Cat *my_cat = create_cat("Whiskers", 3);
  printf("My cat's name is %s and it is %d years old.\n", get_name(my_cat),
         get_age(my_cat));

  // NOTE: INHERITANCE in C is achieved by embedding one struct inside another
  say_hello((struct Animal *)
                my_cat); // Treat cat as an animal, this is INHERITANCE in C

  // NOTE: POLYMORPHISM in C is achieved through function pointers in the struct
  // definition.
  extern struct Car
      bmw; // Declare the external Car instance defined in bmw_car.c
  bmw.start_engine();

  ride_bmw_bike();
  ride_ducati_bike();

  free(my_cat);
  free(my_animal);
  return EXIT_SUCCESS;
}
