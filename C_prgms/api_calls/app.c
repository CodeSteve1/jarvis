#include <stdio.h>
#include "addition.h"
#include "multiplication.h"


int APP2()
{   
    int add_val=Addition(5,5);
    printf("Added_value is app 2: %d \n",add_val); 
    int mul_val = Multiplication(5,5); 
    printf("Multiplied Value is  app 2: %d \n",mul_val);
    
    return 0;
}