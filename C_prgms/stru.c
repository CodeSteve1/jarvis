#include <stdio.h>


struct Example
{
    //
    __uint32_t a_uint32;   
    __uint8_t b_uint8;    
    __uint32_t c_uint32;
    __uint16_t d_uint16;

};

struct Example2
{
    __uint32_t a_uint32;
    __uint16_t b_uint16;
    __uint8_t c_uint8;
    /* data */
};


int main()
{
    struct Example ex;
    printf("Address of 'a': %p\n", (void *)&ex.a_uint32);
    printf("Address of 'b': %p\n", (void *)&ex.b_uint8);
    printf("Address of 'c': %p\n", (void *)&ex.c_uint32);
    printf("Address of 'd': %p\n", (void *)&ex.d_uint16);

    printf("Size of structure: %zu bytes\n", sizeof(struct Example));
    printf("Size of a 32: %zu bytes\n", sizeof(ex.a_uint32));
    printf("Size of b 8: %zu bytes\n", sizeof(ex.b_uint8));
    printf("Size of c 32: %zu bytes\n", sizeof(ex.c_uint32));
    printf("Size of d 16: %zu bytes\n", sizeof(ex.d_uint16));

    struct Example2 ex2;
    printf("Address of 'a2'32: %p\n", (void *)&ex2.a_uint32);
    printf("Address of 'b2'16: %p\n", (void *)&ex2.b_uint16);
    printf("Address of 'c2'8: %p\n", (void *)&ex2.c_uint8);

    printf("Size of a 32: %zu bytes\n", sizeof(ex2.a_uint32));
    printf("Size of b 16: %zu bytes\n", sizeof(ex2.b_uint16));
    printf("Size of c 8: %zu bytes\n", sizeof(ex2.c_uint8));
    

    return 0;
}