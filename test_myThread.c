#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <stdio.h>

typedef struct myarg_t{
    int a;
    int b;
} myarg_t;

typedef struct myret_t{
    int x;
    int y;
} myret_t;

void * myThread(void *args) {
    myarg_t *m = (myarg_t *) args;
    printf("%d %d\n", m->a, m->b);
    myret_t * r = malloc(sizeof(myret_t));
    r->x = 1;
    r->y = 2;

    return (void *)r;
}

int main(int argc, char *argv[]) {
    int rc;
    pthread_t p;
    myret_t *m;
    myarg_t args;
    args.a = 10;
    args.b = 20;
    pthread_create(&p, NULL, myThread, &args);
    pthread_join(p, (void **) &m);
    printf("return %d %d\n", m->x, m->y);
    return 0;
}