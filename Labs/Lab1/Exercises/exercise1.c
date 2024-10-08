#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel num_threads(7)
    {
       int th = omp_get_thread_num();
        if(th%2 == 0) {
            printf("Fizz %d\n", th);
        }else{
            printf("Buzz %d\n", th);
        }
    }
    return 0;
}