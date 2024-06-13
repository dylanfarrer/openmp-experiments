#include <stdio.h>
#include <omp.h>

/*
    Parallelises a sum increment between a number of threads, and then reduces the partial sums into the final sum variable.
    Note, a more explicit way of programming this is:

    int partial_Sum, total_Sum;

    #pragma omp parallel private(partial_Sum) shared(total_Sum)
    {
        partial_Sum = 0;
        total_Sum = 0;

        #pragma omp for
        {
            for(int i = 1; i <= 1000; i++){
                partial_Sum += i;
            }
        }

        #pragma omp critical
        {
                total_Sum += partial_Sum;
        }
    }
    printf("Total Sum: %d\n", total_Sum);
    return 0;

    Where each thread has a partial sum, and these partial sums are added to the shared total sum in a critical section of the code.
    This is effectively the same as the below code, but the below is simpler, and does not require explicit critical zoning.
*/

int main() {
    int n = 1000;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
