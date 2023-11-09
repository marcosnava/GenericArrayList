#include <stdio.h>
#include <stdlib.h>

#include "GenArrayList.h"
struct a {
    int x;
    int y;
};

BOOLEAN crescente(void *a, void *b);

int main() {

    galInitialize(5, 5);

    struct a *aa = malloc(sizeof(struct a));
    struct a *a1 = malloc(sizeof(struct a));
    struct a *a2 = malloc(sizeof(struct a));
    struct a *a3 = malloc(sizeof(struct a));
    struct a *a4 = malloc(sizeof(struct a));
    struct a *a5 = malloc(sizeof(struct a));

    struct a *aux;

    aa->x = 10;
    aa->y = 20;
    a1->x = 7;
    a1->y = 20;
    a2->x = 1;
    a2->y = 20;
    a2->x = 5;
    a2->y = 20;
    a3->x = 2;
    a3->y = 20;
    a4->x = 25;
    a4->y = 20;
    a5->x = 13;
    a5->y = 20;

    //galAdd(aa);
    galAdd(aa);
    galAdd(a1);
    galAdd(a2);
    galAdd(a3);
    galAdd(a4);
    galAdd(a5);

    galSort(crescente);

    ERROR error;

    for(size_t i = 0; i < galSize(); i++)
    {
        aux = galGet(i, &error);
        printf("Element %d -> %d\n", i, aux->x);
    }

    galEnsureCapacity(50);

    printf("Tamanho geral: %d\n", galLvSize);

    galTrimToSize();

    printf("Tamanho geral: %d\n", galLvSize);

    galDestroy();

    return 0;
}

BOOLEAN crescente(void *a, void *b)
{
    struct a* a1;
    struct a* b1;

    a1 = a;
    b1 = b;

    if(a1->x > b1->x)
    {
        return TRUE;
    }

    return FALSE;
}