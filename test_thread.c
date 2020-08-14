#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

void *myThread(void *args) {
    printf("%s\n", (char *)args); 
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2;
    int rc;
    printf("main_begin: \n");
    rc = pthread_create(&p1, NULL, myThread, "A"); assert(rc == 0);
    rc = pthread_create(&p2, NULL, myThread, "B"); assert(rc == 0);

    rc = pthread_join(p1, NULL); assert(rc == 0);
    rc = pthread_join(p2, NULL); assert(rc == 0);

    printf("main: end \n");
    return 0;

}