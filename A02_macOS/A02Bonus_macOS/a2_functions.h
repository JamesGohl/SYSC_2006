/********* functions.h ********
   Student Name 	= James Gohl
   Student Number	= 101299043
*/
#ifndef __A2_FUNCTIONS_H__
#define __A2_FUNCTIONS_H__

#include "a2_nodes.h"

/********** DON'T MODIFY **********/
/*
   Function that creates a new user and adds it to a sorted (ascending order) linked list at
   the proper sorted location. Return the head of the list.
*/
user_t *add_user(user_t *users, const char *username, const char *password);

/*
   Function that searches if the user is available in the database
   Return a pointer to the user if found and NULL if not found.
*/
user_t *find_user(user_t *users, const char *username);

/*
   Function that creates a new friend's node.
   Return the newly created node.
*/
friend_t *create_friend(user_t *users, const char *username);

/*
   Function that links a friend to a user. The friend's name should be added into
   a sorted (ascending order) linked list.
*/
void add_friend(user_t *user,user_t *users, const char *friend);

/*
   Function that removes a friend from a user's friend list.
   Return true of the friend was deleted and false otherwise.
*/
_Bool delete_friend(user_t *user, char *friend_name);

/*
   Function that creates a new user's post.
   Return the newly created post.
*/
post_t *create_post(const char *text);

/*
   Function that adds a post to a user's timeline following a stack.
*/
void add_post(user_t *user, const char *text);

/*
   Function that removes a post from a user's list of posts.
   Return true if the post was deleted and false otherwise.
*/
_Bool delete_post(user_t *user);

/*
   Function that  displays a specific user's posts (All posts)
*/
void display_all_user_posts(user_t *user);

/*
   Function that displays a specific user's friends (All friends)
*/
void display_user_friends(user_t *user);

/*
   Function that displays "number" of posts for a given friend.
   After displaying "number" posts, it prompts if you want to display
   more posts.
   If there are no more post or the user types “n” or “N”, the function returns.
*/
void display_posts_by_n(friend_t *friend, int number);

/*
   Function that free all users from the database before quitting the application.
*/
void teardown(user_t *users);

/*
   Function that prints the main menu with a list of options for the user to choose from
*/
void print_menu();

/*
   ******** DONT MODIFY THIS FUNCTION ********
   Function that reads users from the text file.
   IMPORTANT: This function shouldn't be modified and used as is
   ******** DONT MODIFY THIS FUNCTION ********
*/
user_t *read_CSV_and_create_users(FILE *file, int num_users);

/********** DON'T MODIFY **********/

// Extra functions' Prototypes/Declarations go here

/*
   Function that prints the secondary menu with a list of options for the user to choose from
*/
void print_menu2(user_t *user);
/*
If the user logs in in goes to this list of options 
*/
void menu2_func(user_t *user, user_t *users);

/*
If the entered username and password is correct the user is logged in and the options
are displayed
*/
void login(user_t *users);


/*
   Function that searches if the username is a friend of the user
   Return a pointer to the user if found and NULL if not found.
*/
friend_t *find_friend(user_t *user, char *username);



void get_input_password(char *password);
void get_input_username(char *username);
void print_post_menu(user_t *user);
void print_friend_menu(user_t *user);
void manage_friends(user_t *user, user_t *users);
void free_friends(friend_t *friends);
void free_posts(post_t *friends);
void display_friend_posts(user_t *users);
user_t *register_user(user_t *users);
void manage_profile(user_t *user);
void manage_posts(user_t *user);
#endif