#include <stdio.h>
#include <omp.h>

/*
    This incrememnt program uses the critical directive.
    This directive ensures that only one thread can execute the block
    of code at a time. Which results in a neat increment and print flow.
*/

int main(){
    int i = 0;
    #pragma omp parallel
    {
        #pragma omp critical
        {
            printf("The value of i is %d\n", i++);
        }
    }
    return 0;
}
