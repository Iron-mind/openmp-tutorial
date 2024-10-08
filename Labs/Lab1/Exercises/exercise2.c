#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>
#include <time.h> 

#define ARRAY_SIZE 100

int main() {
    int array[ARRAY_SIZE];
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    double avg_val = 0.0;

    // Initialize random number generator
    srand(time(NULL));


    // Calculate max, min, and average using reduction
    #pragma omp parallel reduction(max:max_val) reduction(min:min_val) reduction(+:avg_val) num_threads(ARRAY_SIZE)
    {
        int i = omp_get_thread_num();
        array[i] = rand() % 1000;  // Random number between 0 and 999

        max_val = array[i];
        min_val = array[i];
        avg_val += array[i];
    }

    avg_val /= ARRAY_SIZE;

    // Print results
    printf("Max value: %d\n", max_val);
    printf("Min value: %d\n", min_val);
    printf("Average value: %.2f\n", avg_val);

    return 0;
}
