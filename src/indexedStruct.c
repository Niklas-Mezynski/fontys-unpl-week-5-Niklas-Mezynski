#include "indexedStruct.h"

#define INDEX_SIZE 10
#define BUCKET_SIZE 10
#define OVERFLOW_SIZE 10

struct Person *indexes[INDEX_SIZE];

void init()
{
    struct Person overflow[BUCKET_SIZE];
    indexes[0] = overflow;
    for (int i = 1; i < INDEX_SIZE; i++)
    {
        struct Person persons[BUCKET_SIZE];
        indexes[i] = persons;
    }
}

void create(struct Person* person) {

}

struct Person* read(int id) {

}

void delete(int id) {

}