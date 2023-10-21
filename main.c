#include <stdio.h>
#include <stdlib.h>

int main() {

    void **lista;
    lista = malloc(10 * sizeof(void *));

    struct a {
        int x;
        int y;
    } aa, bb;

    struct b {
        float x;
        float y;
    } cc, dd;

    aa.x = 10;
    aa.y = 20;

    cc.x = 1.5f;
    cc.y = 2.6f;

    lista[0] = &aa;
    lista[1] = &cc;

    bb = *(struct a*)lista[0];
    dd = *(struct b*)lista[1];

    printf("bb -> %d, %d", bb.x, bb.y);
    printf("cc -> %f, %f", dd.x, dd.y);


    return 0;
}
