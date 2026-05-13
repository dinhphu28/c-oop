#include "cat.h"
#include <stdlib.h>
#include <string.h>

struct Cat {
  char name[50];
  int age;
};

struct Cat *create_cat(const char *name, int age) {
  struct Cat *cat = (struct Cat *)malloc(sizeof(struct Cat));
  if (cat != NULL) {
    strncpy(cat->name, name, sizeof(cat->name) - 1);
    cat->name[sizeof(cat->name) - 1] = '\0'; // Ensure null-termination
    cat->age = age;
  }
  return cat;
}

void set_name(struct Cat *cat, const char *name) {
  if (cat != NULL) {
    strncpy(cat->name, name, sizeof(cat->name) - 1);
    cat->name[sizeof(cat->name) - 1] = '\0'; // Ensure null-termination
  }
}

void set_age(struct Cat *cat, int age) {
  if (cat != NULL) {
    cat->age = age;
  }
}

char *get_name(struct Cat *cat) {
  if (cat != NULL) {
    return cat->name;
  }
  return NULL;
}

int get_age(struct Cat *cat) {
  if (cat != NULL) {
    return cat->age;
  }
  return -1; // Return -1 to indicate an error
}
