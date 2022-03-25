#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexedStruct.h"

person *createPerson(int id, char *name, char *address);

int main()
{
    printf("-1\n");
    init();
    printf("-0.5\n");
    char* name;
    char* address;
    strcpy(name, "Snens");
    strcpy(address, "Am Hoterhof 1");

    printf("0\n");
    person *p1 = createPerson(1, name, address);
    printf("1\n");
    create(p1);
    printf("2\n");
    person *p1read = read(p1->id);
    printf("3\n");
    if (p1read != NULL)
        printf("P1 name:  %s\n", p1read->name);


    printf("3.5\n");
    strcpy(name, "Felix Pralle");
    strcpy(address, "Pullerweg 15");
    person *p2 = createPerson(1, name, address);
    printf("4\n");
    create(p2);
    printf("5\n");
    person *p2read = read(p2->id);
    if (p2read != NULL)
        printf("P2 name:  %s", p2read->name);
}

person* createPerson(int id, char *name, char *address)
{
    person *p;
    p->id = id;
    p->name = (char *)malloc(strlen(name) + 1);
    p->address = (char *)malloc(strlen(address) + 1);
    strcpy(p->name, name);
    strcpy(p->address, address);
    return p;
}