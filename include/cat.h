struct Cat;

struct Cat *create_cat(const char *name, int age);

void set_name(struct Cat *cat, const char *name);
void set_age(struct Cat *cat, int age);

char *get_name(struct Cat *cat);
int get_age(struct Cat *cat);
