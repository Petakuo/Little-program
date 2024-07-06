#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

uint32_t randnum()
{
    uint32_t ran = 0;
    ran |= (uint32_t)(rand() & 0xFFFF) << 16;
    ran |= (uint32_t)rand() & 0xFFFF;
    return ran;
}

void divmod_9(uint32_t in, uint32_t *div, uint32_t *mod)
{
    uint32_t x = in - (in >> 3);  /*in = (in*8/9)/8  8/9 = 7/8 + 7/512 */
    uint32_t q = (x >> 6) + x;
    x = q;
    q = (q >> 12) + x;
    q = (q >> 12) + x;
    q = (q >> 12) + x;
    q = (q >> 12) + x;
    
    *div = (q >> 3);
    *mod = in - (q & ~0x7) - *div;
    if(*mod == 10 || *mod == 9)
    {
        (*div)++;
        *mod -= 9;
    }
}

int main()
{
    uint32_t div, mod;
    int correct = 0;
    for(int i = 0; i < 1000000; i++){
        uint32_t ran = randnum();
        uint32_t a = ran/9;
        uint32_t b = ran%9;
        divmod_9(ran, &div, &mod);
        if(a == div && b == mod)
        {
            correct++;
        }
    }
    printf("%d/1000000\n", correct);
    return 0;
}
