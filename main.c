/* # KlogClear
 * Overwrites the kernel message buffer with crash dumps to hide previous contents
 *
 * # DISCLAIMER
 * I wrote this for fun. It is not my responsibility what you do with it. Goodbye.
 */

#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE (524288) // A 512 KB Buffer
#define CRASH_SIZE (89) // Worst case crash dump size

int main(void) {
    for (int so_far = 0;so_far < BUFFER_SIZE;so_far+=CRASH_SIZE) {
        if (fork()==0) {
            // ReSharper disable once CppDFANullDereference
            return *(int*)NULL;
        }
        printf("Filled up %i/%i bytes so far (%lf%%)\n",so_far, BUFFER_SIZE, (double)so_far/(double)BUFFER_SIZE*100);
    }
    // Just to end it on 100.
    printf("Filled up %i/%i bytes so far (100%%)\n",BUFFER_SIZE, BUFFER_SIZE);
    return 0;
}
