#include "animal.h"
#include "cat.h"
#include <stdio.h>
// #include "animal.c"

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

  say_hello((struct Animal *)
                my_cat); // Treat cat as an animal, this is INHERITANCE in C

  return 0;
}
