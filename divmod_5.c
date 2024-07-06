#include <stdio.h>
#include <stdint.h>

void divmod_5(uint32_t in, uint32_t *div, uint32_t *mod)
{
    uint32_t x = in - (in >> 2);  /*in = (in*4/5)/4  4/5 = 3/4 + 3/64 */
    uint32_t q = (x >> 4) + x;
    x = q;
    q = (q >> 8) + x;
    q = (q >> 8) + x;
    q = (q >> 8) + x;
    q = (q >> 8) + x;

    *div = (q >> 2);
    *mod = in - (q & ~0x3) - *div;
}


int main()
{
    uint32_t div, mod;
    divmod_5(58, &div, &mod);
    printf("div = %u\nmod = %u\n", div, mod);
    return 0;
}
