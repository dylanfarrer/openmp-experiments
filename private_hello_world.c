#include <stdio.h>
#include <omp.h>

/*
    This hello world program uses a private variable.
    Each thread takes thread_id as a private variable (not globally shared).
    Each thread can then assign and use the variable.
*/

int main(){
    int thread_id;
    
    #pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();
        printf("Hello from process: %d\n", thread_id);
    }
    return 0;
}
