#include <stdlib.h>
#include <stdio.h>
int vowel(char my_str[100])
{
    char *my_p = my_str[0];
    if (*my_p == '\0')
    {
        return 0;
    }
    else if (*my_p == 'a' || *my_p == 'e' || *my_p == 'i' || *my_p == 'o' || *my_p == 'u')
    {
        return 1 + vowel(my_p++);
    }
    else
    {
        return vowel(my_p++);
    }
}
int main(void)
{
    char my_str[100];
    scanf("%99s", my_str);
    printf("%d", vowel(my_str));
    return 0;
}