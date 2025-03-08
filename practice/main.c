#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    /*
    double i = 0;
    int n = 3;
    {
        for (int a = 1; a < n + 1; a++)
        {
            for (int b = 1; b < a + 1; b++)
            {
                for (int c = 1; c < b + 1; c++, i ++)
                {
                    i++;
                }
                printf("%f\n", i);
            }

        }
        printf("%f\n", i); */
    double i = 0;
    int n = 2383;
    {
        for (int a = 366; a < n; a++)
        {
            i += 74*a;   
            printf("%f\n", i);
        }
        printf("%f\n", i);
        return 0;
    }
}