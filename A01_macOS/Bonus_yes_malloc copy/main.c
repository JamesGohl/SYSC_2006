/********* main.c ********

    Student Name 	= James Gohl
    Student Number	= 101299043
*/

// Complete the includes
#include <stdlib.h>
#include <stdio.h>
#include "a1_functions.h"
#include <string.h>
#include <assert.h>

int main()
{
    /** 1-  Display a welcome message **/
    printf("Welcome to the start of the project managmenet software\n");

    /** 2- Get the project's name and number of milestones **/
    project_t project;
    int num_milestones = 0;
    printf("Please enter the name of the project ");
    scanf("%s", project.name);
    printf("Please enter the number of milestones ");
    num_milestones = get_input_usi();

    /** 3- Initialize all milestones and activities.
     * You need an array of milestones.
     * The capacity of the array must be the max number of milestones the program
     * can handle as per the instructions **/
    // milestone_t milestone_array[num_milestones];
    milestone_t *milestone_array = malloc(num_milestones * sizeof(milestone_t));
    assert(milestone_array != 0);
    init_milestone(milestone_array, num_milestones);

    /** 4- Initialize the project **/
    const int num_activities = 3;
    project = init_project(project.name, milestone_array, num_milestones, &num_activities); // needed as can't modify name in function

    /** 5- Print the main menu **/
    print_main_menu();

    /** 6- Get user choice and handle it as per the instructions**/
    unsigned short int user_choice = 0;
    do
    {
        user_choice = get_input_usi();
        switch (user_choice)
        {
        case 1:
            print_sub_menu(milestone_array, num_milestones);
            update_function(milestone_array, &project, num_milestones);
            print_main_menu();
            break;
        case 2:
            print_project_stats(project, milestone_array, num_milestones, &num_activities);
            print_main_menu();
            break;
        case 3:
            break;
        default:
            printf("You must enter a number between 1 and 3 please try again\n");
            print_main_menu();
        }
    } while (user_choice != 3);
    free(milestone_array->activity_list);
    free(milestone_array);
    milestone_array = NULL;
    return EXIT_SUCCESS;
}