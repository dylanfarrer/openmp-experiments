#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int sum = 0;

    // Parallelize the following block using OpenMP
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
