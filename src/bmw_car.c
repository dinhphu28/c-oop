#include "car.h"
#include <stdio.h>

void start_engine() { printf("BMW Engine started!\n"); }
void fill_gas(int amount) { printf("BMW filled %d liters of gas.\n", amount); }
int get_fuel_level() {
  return 50; // Just a dummy value for demonstration
}

struct Car bmw = {start_engine, fill_gas, get_fuel_level};
