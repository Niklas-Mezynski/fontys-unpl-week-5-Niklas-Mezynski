#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexedStruct.h"

person ***indexes;

int hashPersonId(int id);

void init()
{
    indexes = malloc(OVERFLOW_SIZE * sizeof(person *) + ((INDEX_SIZE - 1) * BUCKET_SIZE * sizeof(person *)));

    person **overflow;
    overflow = malloc(OVERFLOW_SIZE * sizeof(person *));
    for (int i = 0; i < OVERFLOW_SIZE; i++)
    {
        overflow[i] = NULL;
    }

    indexes[0] = overflow;

    for (int i = 1; i < INDEX_SIZE; i++)
    {
        // person* persons[BUCKET_SIZE];
        person **bucket;
        bucket = malloc(BUCKET_SIZE * sizeof(person *));
        for (int j = 0; j < BUCKET_SIZE; j++)
        {
            bucket[j] = NULL;
        }
        indexes[i] = bucket;
    }
}

void create(person *person)
{
    int hashIndex = hashPersonId(person->id);

    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        // printf("Pointer = %p\n", indexes[hashIndex][i]);
        // printf("Size = %d\n", sizeof(indexes[hashIndex][i]));
        if (indexes[hashIndex][i] == NULL)
        {
            indexes[hashIndex][i] = person;
            return;
        }
    }

    // If for loop ends, try storing the object in the overflow container
    for (int i = 0; i < OVERFLOW_SIZE; i++)
    {
        if (indexes[0][i] == NULL)
        {
            indexes[0][i] = person;
            return;
        }
    }
    printf("Overflow bucket is full!\n");
}

person *read(int id)
{
    int hashIndex = hashPersonId(id);
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        if (indexes[hashIndex][i] != NULL)
        {
            if (indexes[hashIndex][i]->id == id)
            {
                return indexes[hashIndex][i];
            }
        }
    }
    return NULL;
}

void delete (int id)
{
    int hashIndex = hashPersonId(id);
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        if (indexes[hashIndex][i] != NULL)
        {
            if (indexes[hashIndex][i]->id == id)
            {
                person *p = indexes[hashIndex][i];
                free(p->name);
                free(p->address);
                indexes[hashIndex][i] = NULL;
            }
        }
    }
}

int hashPersonId(int id)
{
    return (id % (INDEX_SIZE - 1) + 1);
}

void printPerson(person *person)
{
    printf("Person id: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
}

int saveToFile()
{
    char *filename = "persistence.txt";

    FILE *filepath = fopen(filename, "w");

    if (filepath == NULL)
    {
        printf("Error opening the file %s", filename);
        return -1;
    }

    for (int i = 0; i < 420; i++)
        fprintf(filepath, "This is the line #%d\n", i + 1);


    fclose(filepath);
    return 0;
}