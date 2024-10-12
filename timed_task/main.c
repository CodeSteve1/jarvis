#include "sched_cnf.h"
#include <stdio.h>
#include <time.h>

int main()
{
    int elapsed_time = 0;
    clock_t start_time = clock();
    void (*Rnd_rbn[])(void) = {R1, R2, R3, R4};
    int time_interval[]={10,20,40,50};
    

    for (int i = 0; i < 4; i++)
    {
        while(((clock() - elapsed_time) * 1000 / CLOCKS_PER_SEC)<=time_interval[i]){

        }
        printf("time:%ld\n",((clock() - elapsed_time) * 1000 / CLOCKS_PER_SEC));
        Rnd_rbn[i]();
    }
    return 0;
}