/********* main.c ********
    Student Name 	= James Gohl
    Student Number	= 101299043
*/

// Includes go here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "a2_nodes.h"
#include "a2_functions.h"

int main()
{
    FILE *csv_file = fopen("user_details.csv", "r");
    if (csv_file == NULL)
    {
        perror("Error opening the CSV file");
        return 1;
    }
    // Parse CSV data and create users
    user_t *users = read_CSV_and_create_users(csv_file, 50);

    fclose(csv_file);
    printf("WELCOME TO FACEBOOK\n");

    unsigned short int user_choice = 0;
    while (true)
    {
        print_menu();
        while (true)
        {
            if (scanf("%hu", &user_choice) == 1 && user_choice > 0 && user_choice < 4)
            {
                break;
            }
            printf("Your input is invalid please try again: ");
        }
        switch (user_choice)
        {
        case 1:
            users = register_user(users);
            break;
        case 2:
            login(users);
            printf("hi\n");
            break;
        case 3:
            printf("Goodbye! Thank you for using the program.\n");
            teardown(users);
            exit(0);
            break;
        }
    }

    return 0;
}
