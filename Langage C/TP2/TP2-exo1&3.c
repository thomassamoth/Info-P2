#include <stdio.h>

float maximum(float a, float b);
float max_de_3(float a, float b, float c);

int main()
{
    float x, y, z;
    printf("Entrez 3 nombres : ");
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);
    printf("Le maximum est : %f\n", max_de_3(x, y, z));
    return 0;
}



float maximum(float a, float b)
{
    if(a>b)
        return a;
    else
        return b;

}

float max_de_3(float a, float b, float c)
{
    return maximum(maximum(a, b), c);

}
