#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    char name[10];
    void (*print)(void*);
} test;
 
typedef struct {
    char name[128];
} string;
 
void printName(void* t)
{
    printf("%s\n",((test*)t)->name);
}
 
void shell(void)
{
    printf("This is Shell\n");
}
 

test* t1;


int main(void)
{
    /* malloc and free */
    t1 = (test*)malloc(256);
 
    strcpy(t1->name, "DOG");
    auto c =printName;
    t1->print = c;
 
    t1->print(t1);
 
    free(t1);
 
    scanf("%128s",t1->name);
 
    /* use */
    t1->print(t1);
 
    return 0;
}
