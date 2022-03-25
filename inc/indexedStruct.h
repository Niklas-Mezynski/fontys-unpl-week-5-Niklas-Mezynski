#ifndef __INDEXED__STRUCT
#define __INDEXED__STRUCT

#define INDEX_SIZE 10
#define BUCKET_SIZE 10
#define OVERFLOW_SIZE 10

struct Person {
    int id;
    char* name;
    char* address;
};

typedef struct Person person;

void init();

void create(person* person);

person* read(int id);

void delete(int id);

void printPerson(person* person);

int saveToFile();

#endif