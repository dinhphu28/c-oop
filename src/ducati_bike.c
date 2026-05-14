#include "motorbike.h"
#include <stdio.h>
#include <stdlib.h>

struct DucatiBike {
  struct Motorbike base; // Inherit from Motorbike
  int fuel_level;        // Additional property specific to DucatiBike
  const char *model;     // Additional property specific to DucatiBike
};

static void ducati_bike_start_engine(struct Motorbike *self) {
  struct DucatiBike *ducati_bike =
      (struct DucatiBike *)self; // Cast to derived type
  printf("%s Engine started!\n", ducati_bike->model);
}

static void ducati_bike_fill_gas(struct Motorbike *self, int amount) {
  struct DucatiBike *ducati_bike =
      (struct DucatiBike *)self; // Cast to derived type
  ducati_bike->fuel_level += amount;
  printf("%s filled %d liters of gas. Current fuel level: %d liters.\n",
         ducati_bike->model, amount, ducati_bike->fuel_level);
}

static int ducati_bike_get_fuel_level(struct Motorbike *self) {
  struct DucatiBike *ducati_bike =
      (struct DucatiBike *)self; // Cast to derived type
  return ducati_bike->fuel_level;
}

struct Motorbike *create_ducati_bike(const char *model, int initial_fuel_level) {
  struct DucatiBike *ducati_bike =
      (struct DucatiBike *)malloc(sizeof(struct DucatiBike));
  if (ducati_bike != NULL) {
    ducati_bike->base.start_engine = ducati_bike_start_engine;
    ducati_bike->base.fill_gas = ducati_bike_fill_gas;
    ducati_bike->base.get_fuel_level = ducati_bike_get_fuel_level;
    ducati_bike->fuel_level = initial_fuel_level; // Initial fuel level
    ducati_bike->model = model;  // Set the model name
  }
  return (struct Motorbike *)ducati_bike; // Return as base type
}
