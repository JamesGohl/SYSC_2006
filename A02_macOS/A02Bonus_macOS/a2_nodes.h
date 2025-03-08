/********* nodes.h ********
    Student Name 	= James Gohl
    Student Number	= 101299043
*/

/********** DON'T MODIFY **********/
// Structure to represent a linked list of users

#ifndef __A2_NODES_H__
#define __A2_NODES_H__
#define MAX_POST_LENGTH 250
#define MAX_USERNAME 30
#define MAX_PASSWORD 15
#define MIN_PASSWORD 8
#define NUM_POSTS 3

typedef struct user
{
    char username[30];
    char password[15];
    struct friend *friends;
    struct post *posts;
    struct user *next;
} user_t;

// Structure to represent linked list of a user's posts
typedef struct friend
{
    char username[30];
    struct post **posts;
    struct friend *next;
}
friend_t;

// Structure to represent linked list of a user's posts
typedef struct post
{
    char content[250];
    struct post *next;
} post_t;
#endif
