#include "motorbike_factory.h"
#include "bmw_bike.h"
#include "ducati_bike.h"
#include "motorbike.h"
#include <stdlib.h>

struct Motorbike *create_motorbike(struct MotorbikeFactory *self,
                                   enum Manifacturer manifacturer,
                                   const char *model) {
  switch (manifacturer) {
  case DUCATI:
    return create_ducati_bike(
        model, 0); // Create a Ducati bike with initial fuel level 0
    break;
  case BMW:
    return create_bmw_bike(model,
                           0); // Create a BMW bike with initial fuel level 0
    break;
  default:
    return NULL; // Handle unknown manufacturer case
    break;
  }
}

struct MotorbikeFactory motorbike_factory = {create_motorbike};
