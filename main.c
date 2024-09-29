
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 524288 // A 512 KB Buffer
#define CRASH_SIZE 89 // Worst case crash dump size

int main(void) {
    for (int so_far = 0;so_far < BUFFER_SIZE;so_far+=CRASH_SIZE) {
        if (fork()==0) {
            return *(int*)NULL;
        }
        printf("Filles up %d bytes so far\n",so_far);
    }
    return 0;
}