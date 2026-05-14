#ifndef MOTORBIKE_H
#define MOTORBIKE_H

struct Motorbike {
  void (*start_engine)(struct Motorbike *self);
  void (*fill_gas)(struct Motorbike *self, int amount);
  int (*get_fuel_level)(struct Motorbike *self);
};

#endif
