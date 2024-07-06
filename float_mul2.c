#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

float float_mul2(float x)
{
    // using bitwise operation, no mul
    int a = *((int*)&x);
    int b = a;
    a = (a & 0x7F800000) >> 23;
    a++;
    b = (b & 0x807FFFFF) | (a << 23);
    return *((float*)&b);
}
int main(){
    srand(time(NULL));
    printf("pid: %d\n", getpid());
    sleep(10);
    for(int i = 0; i < 100; i++){
        float x = (float)rand()/RAND_MAX;
        printf("x = %f\n", x);
        printf("2x = %f\n",float_mul2(x));
    }
    return 0;
}
