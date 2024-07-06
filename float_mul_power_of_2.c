#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float float_mul_power_of_2(float x, int e)
{
    int a = *((int*)&x);
    int b = *((int*)&x);
    a = (a & 0x7F800000) >> 23;
    a += e;
    b = (b & 0x807FFFFF) | (a << 23);
    return *((float*)&b);
}
int main(){
    srand(time(NULL));
    int e;
    scanf("%d", &e);
    for(int i = 0; i < 3; i++){
        float x = (float)rand()/RAND_MAX;
        printf("x = %f\n", x);
        printf("2x = %f\n",float_mul_power_of_2(x, e));
    }
    return 0;
}
