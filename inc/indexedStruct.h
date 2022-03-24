#ifndef __INDEXED__STRUCT
#define __INDEXED__STRUCT

struct Person {
    int id;
    char* name;
    char* address;
};

void init();

void create(struct Person* person);

struct Person* read(int id);

void delete(int id);

#endif