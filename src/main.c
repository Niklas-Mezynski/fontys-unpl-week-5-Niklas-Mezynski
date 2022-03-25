#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexedStruct.h"

person *createPerson(int id, char *name, char *address);

int main()
{
    init();
    char name[25];
    char address[50];
    strcpy(name, "Snens");
    strcpy(address, "Am Hoterhof 1");

    person *p1 = createPerson(1, name, address);
    create(p1);
    person *p1read = read(p1->id);
    if (p1read != NULL)
        printf("P1 name:  %s\n", p1read->name);

    strcpy(name, "Felix");
    strcpy(address, "Pullerweg 15");
    person *p2 = createPerson(10, name, address);
    create(p2);
    person *p2read = read(p2->id);
    if (p2read != NULL)
        printf("P2 name:  %s\n", p2read->name);

    strcpy(name, "Daniel");
    strcpy(address, "Am Lindchen 21");
    person *p3 = createPerson(19, name, address);
    create(p3);
    person *p3read = read(p3->id);
    if (p3read != NULL)
        printf("P3 address:  %s\n", p3read->address);

    delete(p2->id);
    p2read = read(p2->id);
    if (p2read != NULL) {
        printf("P2 name:  %s\n", p2read->name);
    } else {printf("P2 not found\n");}


    saveToFile();

}

person *createPerson(int id, char *name, char *address)
{
    person *p = (person *)malloc(sizeof(person));
    p->id = id;
    p->name = (char *)malloc(strlen(name) + 1);
    p->address = (char *)malloc(strlen(address) + 1);
    strcpy(p->name, name);
    strcpy(p->address, address);
    return p;
}