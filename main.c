#include <stdio.h>
#include <stdlib.h>

#include "GenArrayList.h"

int main() {

    galInitialize(5, 5);

    struct a {
        int x;
        int y;
    };

    struct a *aa = malloc(sizeof(struct a));
    struct a *bb = NULL;
    struct a *a1 = malloc(sizeof(struct a));
    struct a *a2 = malloc(sizeof(struct a));
    struct a *a3 = malloc(sizeof(struct a));
    struct a *a4 = malloc(sizeof(struct a));
    struct a *a5 = malloc(sizeof(struct a));

    struct b {
        float x;
        float y;
    };

    struct b *cc = malloc(sizeof(struct b));
    struct b *dd = NULL;

    aa->x = 10;
    aa->y = 20;

    cc->x = 1.5f;
    cc->y = 2.6f;

    a2->x = 7;
    a2->y = 14;

    //galAdd(aa);
    galAdd(cc);
    galInsert(0, aa);
    galAdd(a1);
    galAdd(a2);
    galAdd(a3);
    galAdd(a4);
    galAdd(a5);

    printf("Tamanho: %d\n", galSize());

    ERROR error;

    bb = galGet(0, &error);
    dd = galGet(1, &error);

    printf("bb -> %d, %d\n", bb->x, bb->y);
    printf("dd -> %f, %f\n", dd->x, dd->y);

    if(galContains(aa))
    {
        printf("Encontrei\n");
        printf("Posicao: %d\n", galIndexOf(aa));
    }
    else
    {
        printf("Nao encontrei\n");
        printf("Posicao: %d\n", galIndexOf(aa));
    }

    printf("Last index: %d\n", galLastIndexOf(aa));

    if(galIsEmpty())
    {
        printf("Vazia\n");
    }
    else
    {
        printf("Tem elementos\n");
    }

    galEnsureCapacity(50);

    printf("Last index: %d\n", galLastIndexOf(aa));

    printf("Removing...\n");
    galRemoveE(a2);
    if(galContains(a2))
    {
        printf("Não removeu\n");
    }
    else
    {
        printf("Removeu\n");
    }
    galSet(3, a2);
    if(galContains(a2))
    {
        printf("Não removeu\n");
    }
    else
    {
        printf("Removeu\n");
    }

    galClear();

    if(galIsEmpty())
    {
        printf("Vazia\n");
    }
    else
    {
        printf("Tem elementos\n");
    }

    if(galContains(aa))
    {
        printf("Encontrei\n");
        printf("Posicao: %d\n", galIndexOf(aa));
    }
    else
    {
        printf("Nao encontrei\n");
        printf("Posicao: %d\n", galIndexOf(aa));
    }

    printf("Last index: %d\n", galLastIndexOf(aa));

    galLvDestroy();

    free(aa);
    free(cc);

    return 0;
}
