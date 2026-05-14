struct Car {
  void (*start_engine)();
  void (*fill_gas)(int amount);
  int (*get_fuel_level)();
};
