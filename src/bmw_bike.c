#include "motorbike.h"
#include <stdio.h>
#include <stdlib.h>

struct BMWBike {
  struct Motorbike base; // Inherit from Motorbike
  int fuel_level;        // Additional property specific to BMWBike
  const char *model;     // Additional property specific to BMWBike
};

static void bmw_bike_start_engine(struct Motorbike *self) {
  struct BMWBike *bmw_bike = (struct BMWBike *)self; // Cast to derived type
  printf("%s Engine started!\n", bmw_bike->model);
}

static void bmw_bike_fill_gas(struct Motorbike *self, int amount) {
  struct BMWBike *bmw_bike = (struct BMWBike *)self; // Cast to derived type
  bmw_bike->fuel_level += amount;
  printf("%s filled %d liters of gas. Current fuel level: %d liters.\n",
         bmw_bike->model, amount, bmw_bike->fuel_level);
}

static int bmw_bike_get_fuel_level(struct Motorbike *self) {
  struct BMWBike *bmw_bike = (struct BMWBike *)self; // Cast to derived type
  return bmw_bike->fuel_level;
}

struct Motorbike *create_bmw_bike(const char *model, int initial_fuel_level) {
  struct BMWBike *bmw_bike = (struct BMWBike *)malloc(sizeof(struct BMWBike));
  if (bmw_bike != NULL) {
    bmw_bike->base.start_engine = bmw_bike_start_engine;
    bmw_bike->base.fill_gas = bmw_bike_fill_gas;
    bmw_bike->base.get_fuel_level = bmw_bike_get_fuel_level;
    bmw_bike->fuel_level = initial_fuel_level; // Initial fuel level
    bmw_bike->model = model;  // Set the model name
  }
  return (struct Motorbike *)bmw_bike; // Return as base type
}
