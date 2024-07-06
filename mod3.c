#include <stdio.h>


int mod3(unsigned n)
{
    n = __builtin_popcount(n ^ 0xAAAAAAAA) + 23;
    n = __builtin_popcount(n ^ 0x2A) - 3;
    return n + (((n >> 31) | (n >> 30))& 3);
}


int main()
{
    printf("%d\n", mod3(8));
    return 0;
}
