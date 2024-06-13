#include <stdio.h>
#include <omp.h>

/*
    This hello world program uses the omp barrier statement as a sync tool.
    All threads must reach this point before any thread can continue.
    This forces the threads to print out in order of their thread count.
*/

int main(){
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        for(int i = 0; i < num_threads; i++){
            if(i == thread_id){
                printf("Hello from process: %d\n", thread_id);
            }
            #pragma omp barrier
        }
    }
    return 0;
}
