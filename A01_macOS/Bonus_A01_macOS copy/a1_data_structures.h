/********* a1_data_structures.h ********
	
	Student Name 	= James Gohl
	Student Number	= 101299043
*/
#include <stdbool.h>

#ifndef __A1_DATA_STRUCTURES_H__
#define __A1_DATA_STRUCTURES_H__
#define NUM_ACTIVITIES 3
#define NUM_MILESTONES 5
#define AVERAGE_SALARY 30
#define UNINITIALIZED_NAME "This activity has not be initialized"
#endif


/********** DON'T MODIFY FROM HERE **********/

typedef struct activity {
    unsigned short int id;
    char name[100];
    float planned_cost, actual_cost;
    unsigned short int planned_duration, actual_duration;
    _Bool completed;
}activity_t;

typedef struct milestone {
    unsigned short int id;
    char name[100];
    unsigned short int  activity_capacity;  // Maximum number of elements in the list.
    activity_t *activity_list;
    _Bool completed;
    float actual_cost;
    short int actual_duration;
}milestone_t;

typedef struct project {
    char name[100]; 
    float planned_cost, actual_cost;
    unsigned short int planned_duration, actual_duration;
    _Bool completed;
}project_t;

/********** DON'T MODIFY UNTIL HERE **********/