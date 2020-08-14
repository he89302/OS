#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

static volatile int counter = 0;

void* myThread(void *args) {
    printf("%s: begin\n", (char *)args); 
    int i;
    for (i = 0; i < 1e7; i++) {
        counter = counter + 1;
    }
    printf("%s: done\n", (char *) args);
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2;

    printf("main: begin (counter = %d) \n", counter);
    pthread_create(&p1, NULL, myThread, "A");
    pthread_create(&p2, NULL, myThread, "B");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("main: done with both (counter = %d) \n", counter);

    return 0;
}