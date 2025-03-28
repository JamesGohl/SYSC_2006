/********* a1_functions.h ********
	
	Student Name 	= James Gohl
	Student Number	= 101299043
*/

#ifndef __A1_FUNCTIONS_H__
#define __A1_FUNCTIONS_H__

#include "a1_data_structures.h"

#endif




/********** DON'T MODIFY - FROM HERE **********/
/* 
   Get unsigned short integer user input.
   The value entered by the user must be positive.
   If the user enters a negative value, the function asks user to re-enter a positive value.
*/
unsigned short int get_input_usi(void);

/*
   Get float user input. The value must be positive.
   The value entered by the user must be positive.
   If the user enters a negative value, the function asks user to re-enter a positive value.
*/
float get_input_f(void);

/* 
   Initialize all fields in an activity as per the instructions (3)
*/
void init_activity(activity_t * activity_to_int);
/* 
   Initialize all fields in the milestone as per the instructions (3)
   The implementation of your function MUST call the function init_activity.
*/
void init_milestone(milestone_t * milestone_to_int, unsigned short int num_activities);


/* 
   Initialize all fields in the project as per the instructions (4)
   number_activities contains the number of activities per milestone
*/
project_t init_project(char name[], milestone_t *milestone_list, int number_milestones, const int * number_activities);


/* 
   Print the main menu as per the instructions (5)
*/
void print_main_menu(void);

/*
   Print out milestone stats as per the instructions (6)
   number_activities contains the number of activities per milestone
*/
void print_milestone_stats(const milestone_t * list_milestones, int num_milestones, const int * number_activities);

/*
   Print out project stats as per the instructions (6)
   number_activities contains the number of activities per milestone
   The implementation MUST call print_stats_milestone
*/
void print_project_stats(project_t details, const milestone_t * list_milestones, int num_milestones, const int * number_activities);

/*
   Update activity per the instructions (6)
*/
void update_activity(activity_t * activity_to_update);
/*
   Update milestone per the instructions (6)
*/
void update_milestone(milestone_t * milestone_to_update, int activities_in_milestone);

/*
   Update project per the instructions (6)
   number_activities contains the number of activities per milestone
*/
void update_project(const milestone_t * milestone_array, int num_milestones, const int * number_activities, project_t * my_project);

/********** DON'T MODIFY - UNTIL HERE **********/


// Extra function prototypes/declarations go here
_Bool check_unique_id(unsigned short int id_to_check, unsigned short int *activity_id_list, int check_up_to); // checks if an activity id already existis in a milestone


/* 
   Print the sub menu as per the instructions (6)
*/
void print_sub_menu(milestone_t *milestone_array, unsigned short int num_milestones);

/*
Gets the user input for which activity they want to update and checks if it is incompleted and exists
*/
void update_function(milestone_t *milestone_array, project_t *project, unsigned short int num_milestones);
