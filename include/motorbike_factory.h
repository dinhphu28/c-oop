#ifndef MOTORBIKE_FACTORY_H
#define MOTORBIKE_FACTORY_H

#include "motorbike.h"
enum Manifacturer { DUCATI, BMW };

struct MotorbikeFactory {
  struct Motorbike *(*create_motorbike)(struct MotorbikeFactory *self,
                                        enum Manifacturer manifacturer,
                                        const char *model);
};

#endif
