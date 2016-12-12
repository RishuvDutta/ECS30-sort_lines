
/*
 * Demonstrates malloc usage.
 *  * Prints the first n numbers,
 *   * where n is obtained from stdin 
 *    
 */
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 2

void n_letters(int* A, int n);
void print_array(int* A, int n);

int main() {
    int i = 0, n = INITIAL_BUFFER_SIZE, x, status;
    int* A = (int*) malloc(n * sizeof(int));
    /* Read integers until user stops, i.e. ctrl-D (EOF) entered */
    printf("Please enter integers to read: ");
    /* get x before entering loop */
    status = scanf("%d", &x);
    while (status == 1) {
        /* scanf was successful (statues == 1) so read into array */
        A[i++] = x;
        /* if A fills up, double its size */
        if (i == n) {
            printf("A is too small! Doubling size..\n");
            n *= 2;
            int* temp = realloc(A, n * sizeof(int));
            /* if realloc succeeded, update where A points to */
            if (temp != NULL) { 
                A = temp;
            } else {
                /* in this case temp == NULL */
                /* realloc failed, print error & quit */
                printf("Error: No more memory\n");
                exit(EXIT_FAILURE);
            }
        } 
        status = scanf("%d", &x);
    }
    /* At this stage, i is the length of A */
    print_array(A, i);    
    printf("Cleaning up A by calling free..\n");
    /* Clean up heap, free memory used by A since we are done with it */
    free(A);

    return EXIT_SUCCESS;
}

/*
 *  * Input: char array A, int n
 *   * Summary: Prints first n characters of A
 *    */
void print_array(int* A, int n) {
    int i;
    /* n tells us where to stop - normally we use '\0' as a sentinel */
    for (i = 0; i < n; i++) {
        printf("%d", A[i]);
    }
    printf("\n");
    return;
}
