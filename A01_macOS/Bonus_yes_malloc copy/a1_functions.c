/********* a1_functions.c ********

	Student Name 	= James Gohl
	Student Number	= 101299043
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "a1_functions.h"
#include <math.h>
#include <assert.h>

unsigned short int get_input_usi(void)
{
	int return_value;
	unsigned short int bool_value = 1;
	do
	{
		scanf("%d", &return_value);
		if (return_value <= 0 || return_value > 65535)
		{
			printf("The input is invalid please try again\n");
		}
		else
		{
			bool_value = 0;
		}
	} while (bool_value);
	return (unsigned short int)return_value;
}

float get_input_f(void)
{
	float return_value = 0;
	do
	{
		scanf("%f", &return_value);
		if (return_value <= 0)
		{
			printf("The input is invalid, please input a number greator than zero");
		}
	} while (return_value <= 0);
	return return_value;
}
_Bool check_unique_id(unsigned short int id_to_check, const unsigned short int *activity_id_list, int check_up_to) // checks if a value is already in an array
{
	for (int i = 0; i < check_up_to; i++)
	{
		if (id_to_check == *(activity_id_list + i))
		{
			return false;
		}
	}
	return true;
}

void init_milestone(milestone_t *milestone_array, unsigned short int num_milestones)
{
	// used to track the number of initalized values in the array excluding garbage values
	int activity_id_list_position = 0;
	int milestone_id_list_position = 0;
	int total_activities = 0;
	unsigned short int *milestone_id_list = malloc(num_milestones * sizeof(unsigned short int));
	assert(milestone_id_list != NULL);
	for (int i = 0; i < num_milestones; i++)
	{
		bool run_bool = true;
		do
		{
			unsigned short int milestone_id_to_check;
			printf("Please enter the ID of the milestone #%d ", i + 1);
			milestone_id_to_check = get_input_usi();
			// unsigned short int milestone_id_list[num_milestones];
			*(milestone_id_list + milestone_id_list_position) = milestone_id_to_check;
			if (check_unique_id(milestone_id_to_check, milestone_id_list, milestone_id_list_position) == false)
			{
				printf("The milestone id just entered already exists. Please try again \n");
			}
			else
			{
				milestone_id_list_position++;
				(milestone_array + i)->id = milestone_id_to_check;
				run_bool = false;
			}
		} while (run_bool);

		printf("Please enter the name of milestone just entered with id: %hu ", (milestone_array + i)->id);
		scanf("%s", (milestone_array + i)->name);
		unsigned short int num_activites = 0;
		printf("Please enter the number of activities in milestone %s ", (milestone_array + i)->name);
		num_activites = get_input_usi();
		total_activities += num_activites;

		activity_t *activity_array = malloc(num_activites * sizeof(activity_t));
		(milestone_array + i)->activity_list = activity_array;
		(milestone_array + i)->capacity = num_activites;
		assert(activity_array != NULL);
		(milestone_array + i)->completed = false;
		(milestone_array + i)->actual_cost = 0;
		(milestone_array + i)->actual_duration = 0;
	}
	unsigned short int *activity_id_list = malloc(total_activities * sizeof(unsigned short int));
	assert(activity_id_list != NULL);
	for (int i = 0; i < num_milestones; i++)
	{
		printf("You are now going to initializes all the activies in milestone ID: %hu\n", (milestone_array + i)->id);

		for (int k = 0; k < (milestone_array + i)->capacity; k++)
		{
			printf("Please enter the id of activity %d ", k + 1);
			unsigned short int activity_id_to_check = get_input_usi();
			*(activity_id_list + activity_id_list_position) = activity_id_to_check;
			// printf("list [0] %hu", activity_id_list[0]);
			if (check_unique_id(activity_id_to_check, activity_id_list, activity_id_list_position) == false)
			{
				k--; // removes one from k so when the loop goes again it will try again since the entered id was wrong
				printf("The id just entered already exists. Please try again.\n");
			}
			else
			{
				activity_id_list_position++;
				((milestone_array + i)->activity_list + k)->id = activity_id_to_check;
				init_activity((milestone_array + i)->activity_list + k);
			}
		}
		activity_id_list_position++;
	}
	free(activity_id_list);
}

void init_activity(activity_t *activity)
{
	printf("Please enter the name of activity with milestone id: %hu\n", (activity)->id);
	scanf("%s", (activity)->name);
	printf("Please enter the planned durration (hours) of the activity %s, ID: %hu: ", activity->name, activity->id);
	activity->planned_duration = get_input_usi();
	activity->planned_cost = activity->planned_duration * AVERAGE_SALARY;
	activity->actual_duration = 0;
	activity->actual_cost = 0;
	activity->completed = false;
	activity->actual_cost = 0;
}

project_t init_project(char name[], milestone_t *milestone_list, int number_milestones, const int *number_activities)
{
	float planned_cost = 0;
	unsigned short int total_hours = 0;
	for (int i = 0; i < number_milestones; i++)
	{
		for (int j = 0; j < *number_activities; j++)
		{
			planned_cost += (((milestone_list + i)->activity_list) + j)->planned_cost;
			total_hours += (((milestone_list + i)->activity_list) + j)->planned_duration;
		}
	}
	project_t return_project;
	return_project.planned_cost = planned_cost;
	return_project.actual_cost = 0;
	return_project.planned_duration = ceil(total_hours / 8.0);
	return_project.actual_duration = 0;
	return_project.completed = false;
	strcpy(return_project.name, name);
	return return_project;
}

void print_main_menu()
{
	printf("Please select one of the following options:\n1. Update activity\n2. Print stats\n3. Exit\nEnter selection: ");
}
void print_sub_menu(milestone_t *milestone_array, unsigned short int num_milestones)
{
	printf("List of all IDs of actvivties:\n");
	for (int i = 0; i < num_milestones; i++)
	{
		for (int j = 0; j < (milestone_array + i)->capacity; j++)
		{
			if (((((milestone_array + i)->activity_list) + j)->completed) == false)
			{
				printf("Incomplete activity name: %s, ID: %hu\n", ((((milestone_array + i)->activity_list) + j)->name), ((((milestone_array + i)->activity_list) + j)->id));
			}
			else if (((((milestone_array + i)->activity_list) + j)->completed) == true)
			{
				printf("Complete activity name: %s, ID: %hu\n", ((((milestone_array + i)->activity_list) + j)->name), ((((milestone_array + i)->activity_list) + j)->id));
			}
		}
	}
}
void update_function(milestone_t *milestone_array, project_t *project, unsigned short int number_milestones)
{
	unsigned short int incomplete_actvity_id_array[number_milestones * milestone_array->capacity]; // used to check if user input is correct when updatting activity
	int array_size = 0;
	for (int i = 0; i < number_milestones; i++)
	{
		for (int j = 0; j < (milestone_array + i)->capacity; j++)
		{
			if (((((milestone_array + i)->activity_list) + j)->completed) == false)
			{
				array_size++;
				incomplete_actvity_id_array[array_size - 1] = ((((milestone_array + i)->activity_list) + j)->id);
			}
		}
	}
	if (array_size == 0)
	{
		printf("All activities are complete. Nothing can be updated\n");
	}
	else
	{
		unsigned short int user_id_choice;
		printf("Please enter the ID of the incomplete activity you would like to updated: ");
		do
		{
			user_id_choice = get_input_usi();
			if (check_unique_id(user_id_choice, incomplete_actvity_id_array, array_size) == true)
			{
				printf("The ID you have entered is either non-existant or complete. Please enter another ID: ");
			}

		} while (check_unique_id(user_id_choice, incomplete_actvity_id_array, array_size) == true);
		for (int i = 0; i < number_milestones; i++)
		{
			for (int j = 0; j < (milestone_array + i)->capacity; j++)
			{
				if (((((milestone_array + i)->activity_list) + j)->id) == user_id_choice)
				{
					update_activity(((milestone_array + i)->activity_list) + j);
					update_milestone((milestone_array + i), milestone_array->capacity);
				}
			}
		}
		// since the ids of the array are initialized in the function and not in main and we aren't allowed gllobal varriables this is need to call the function update_project
		update_project(milestone_array, number_milestones, project);
	}
}
void update_activity(activity_t *activity_to_update)
{
	printf("Please enter the actual duration (hours) of activity with  Id: %hu ", activity_to_update->id);
	activity_to_update->actual_duration = get_input_usi();
	printf("Please enter the actual cost ($) of activity with  Id: %hu ", activity_to_update->id);
	activity_to_update->actual_cost = get_input_f();
	printf("Please enter if the activity with Id: %hu is completed. 1 for completed, 2 for incompleted ", activity_to_update->id);
	unsigned short int user_complete = 0;
	bool run_bool = true;
	do
	{
		user_complete = get_input_usi();
		if (user_complete == 1 || user_complete == 2)
		{
			run_bool = false;
		}
		else
		{
			printf("You must enter 1 or 2. Try again: ");
		}
	} while (run_bool);
	if (user_complete == 1)
	{
		activity_to_update->completed = true;
	}
}
void update_milestone(milestone_t *milestone_to_update, int activities_in_milestone)
{
	int num_activities = 0;
	bool completed = true;
	float actual_cost = 0;
	unsigned short int actual_duration = 0;
	for (int i = 0; i < milestone_to_update->capacity; i++)
	{
		actual_cost += (milestone_to_update->activity_list + i)->actual_cost;
		actual_duration += (milestone_to_update->activity_list + i)->actual_duration;
		if (((milestone_to_update->activity_list + i)->completed) == false)
		{
			// mielstone is still in progress
			completed = false;
			break;
		}
	}
	if (completed == true)
	{
		milestone_to_update->completed = true;
		milestone_to_update->actual_cost = actual_cost;
		milestone_to_update->actual_duration = actual_duration;
	}
}
void update_project(const milestone_t *milestone_array, int num_milestones, project_t *project)
{
	float actual_cost = 0;
	unsigned short int actual_duration = 0;
	bool completed = true;
	for (int i = 0; i < num_milestones; i++)
	{
		actual_duration += (milestone_array + i)->actual_duration;
		actual_cost += (milestone_array + i)->actual_cost;
		if ((milestone_array + i)->completed == false)
		{
			completed = false;
			break;
		}
	}
	if (completed == true)
	{
		project->completed = true;
		project->actual_cost = actual_cost;
		project->actual_duration = ceil(actual_duration / 8.0);
	}
}
void print_project_stats(project_t project, const milestone_t *list_milestones, int num_milestones, const int *number_activities)
{
	char copy_string[100];
	int days_early_late = 0;
	float over_under_budget = 0;
	printf("%s\n", project.name);
	if (project.completed == false)
	{
		printf("Project is incomplete\n");
		print_milestone_stats(list_milestones, num_milestones, number_activities);
	}
	else
	{
		printf("Project is completed\n");
		// dollars over budged
		over_under_budget = project.actual_cost - project.planned_cost;
		if (over_under_budget > 0)
		{
			printf("Your project %s was completed over budget by %.2f$\n", project.name, over_under_budget);
		}
		else if (over_under_budget == 0)
		{
			printf("Your project %s was completed exactly to the budget.\n", project.name);
		}
		else if (over_under_budget < 0)
		{
			printf("Your project %s was completed under budget by %.2f$\n", project.name, over_under_budget * -1);
		}
		// days early / delayed
		days_early_late = project.actual_duration - project.planned_duration;
		if (days_early_late > 0)
		{
			printf("Your project %s was completed late to the schedule by %d days\n", project.name, days_early_late);
		}
		else if (days_early_late == 0)
		{
			printf("Your project %s was completed exactly on time.\n", project.name);
		}
		else if (days_early_late < 0)
		{
			printf("Your project %s was completed ahead of schedule by %d days\n", project.name, abs(days_early_late));
		}
	}
}
void print_milestone_stats(const milestone_t *list_milestones, int num_milestones, const int *number_activities)
{
	int days_early_late = 0;
	float over_under_budget = 0;
	for (int i = 0; i < num_milestones; i++)
	{
		int planned_duration = 0;
		float planned_cost = 0;
		if ((list_milestones + i)->completed == true)
		{
			printf("Completed milestone %s:\n", (list_milestones + i)->name);
			for (int j = 0; j < (list_milestones + i)->capacity; j++)
			{
				planned_duration += (((list_milestones + i)->activity_list) + j)->planned_duration;
				planned_cost += (((list_milestones + i)->activity_list) + j)->planned_cost;
			}
			days_early_late = (list_milestones + i)->actual_duration - planned_duration;
			if (days_early_late > 0)
			{
				printf("- Your milestone %s was completed late to the schedule by %d days\n", (list_milestones + i)->name, days_early_late);
			}
			else if (days_early_late == 0)
			{
				printf("- Your milestone %s was completed exactly on time.\n", (list_milestones + i)->name);
			}
			else if (days_early_late < 0)
			{
				printf("- Your milestone %s was completed ahead of schedule by %d days\n", (list_milestones + i)->name, abs(days_early_late));
			}
			// dollars over budged
			over_under_budget = (list_milestones + i)->actual_cost - planned_cost;
			if (over_under_budget > 0)
			{
				printf("- Your milestone %s was completed over budget by %.2f$\n", (list_milestones + i)->name, over_under_budget * -1);
			}
			else if (over_under_budget == 0)
			{
				printf("- Your milestone %s was completed exactly to the budget.\n", (list_milestones + i)->name);
			}
			else if (over_under_budget < 0)
			{
				printf("- Your mielstone %s was completed under budget by %.2f$\n", (list_milestones + i)->name, over_under_budget);
			}
		}
		else
		{
			int incomplete_activities = 0;
			planned_duration = 0;
			planned_cost = 0;
			printf("Incomplete milestone %s:\n", (list_milestones + i)->name);
			for (int j = 0; j < (list_milestones + i)->capacity; j++)
			{
				planned_duration += (((list_milestones + i)->activity_list) + j)->planned_duration;
				planned_cost += (((list_milestones + i)->activity_list) + j)->planned_cost;
				if ((((list_milestones + i)->activity_list) + j)->completed == true)
				{
					incomplete_activities++;
				}
			}
			printf("- number of activities complete is %d out of %d\n", incomplete_activities, (list_milestones + i)->capacity);
			printf("- the planned duration of this milestone is %d\n", planned_duration);
			printf("- the planned cost of this milestone is $%.2f\n", planned_cost);
		}
	}
}
