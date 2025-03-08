#include <stdlib.h>
#include <stdio.h>
int vowel(char my_str[100])
{
    if (my_str == "\0")
    {
        return 0;
    }
    else if (my_str == "a" || my_str == "e" || my_str == "i" || my_str == "o" || my_str == "u")
    {
        return 1 + vowel(my_str++);
    }
    else
    {
        return vowel(my_str++);
    }
}
int main(void)
{
    char my_str[100];
    scanf("%99s", my_str);
    printf("%d", vowel(my_str));
    return 0;
}