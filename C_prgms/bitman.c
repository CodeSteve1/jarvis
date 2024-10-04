#include <stdio.h>
#define reg '3';               //initialising variable 
#define set_bit(x,y) x|=(1<<y); // macro function to set the y+1th bit to 1
#define clear_bit(x,y) x&= ~(1<<y); // macro function to clear the y+1th bit to 0
int main()
{
    char arbit = reg; //setting a arbitary variable 
    set_bit(arbit,2);  //calling macro function to set variable arbit's 3rd bit value
    printf("After setting 3rd bit: %c\n", arbit);//printing arbit after setting


    clear_bit(arbit,3); //calling macro function to clear the 4th bit of arbit
    printf("After clearing 4th bit: %c\n", arbit);//printing arbit after clearing the 4th bit

    if (arbit & (1 << 4))      //checking if the 5th bit is set or not
    {
        printf("5th bit is set.\n");
    }
    else
    {
        printf("5th bit is not set.\n");
    }

    return 0;
}