/*****************
    Student Name 	= James Gohl
    Student Number	= 101299043
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include "a2_nodes.h"
#include "a2_functions.h"

// Your solution goes here

/*
   ******** DONT MODIFY THIS FUNCTION ********
   Function that reads users from the text file.
   IMPORTANT: This function shouldn't be modified and used as is
   ******** DONT MODIFY THIS FUNCTION ********
*/
user_t *read_CSV_and_create_users(FILE *file, int num_users)
{
    srand(time(NULL));
    user_t *users = NULL;
    char buffer[500];
    fgets(buffer, sizeof(buffer), file); // Read and discard the header line
    int count = 0;
    for (int i = 0; i < num_users; i++)
    {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline characters

        char *token = strtok(buffer, ",");
        char *token2 = strtok(NULL, ",");
        users = add_user(users, token, token2);
        char *username = token;

        token = strtok(NULL, ",");

        user_t *current_user = users;
        for (; current_user != NULL && strcmp(current_user->username, username) != 0; current_user = current_user->next)
            ;

        while (token != NULL && strcmp(token, ",") != 0 && count < 3)
        {
            if (strcmp(token, " ") != 0)
            {
                add_friend(current_user, token);
            }
            token = strtok(NULL, ",");
            count++;
        }
        count = 0;

        // token = strtok(NULL, ",");
        while (token != NULL && strcmp(token, ",") != 0)
        {
            add_post(current_user, token);
            token = strtok(NULL, ",");
        }
    }
    return users;
}
void print_menu()
{
    printf("***********************************************\n"
           "\tWelcome to Text-Based Facebook\n"
           "***********************************************\n\n\n"
           "***********************************************\n"
           "\t\tMAIN MENU:\n"
           "***********************************************\n"
           "1. Register a new user\n"
           "2. Login with exitising user's information\n"
           "3. Exit\n"
           "Enter Your choice: ");
}
user_t *add_user(user_t *users, const char *username, const char *password)
{
    user_t *new_user = malloc(sizeof(user_t));
    assert(new_user != NULL);
    strcpy(new_user->username, username);
    strcpy(new_user->password, password);
    new_user->next = NULL;
    new_user->posts = NULL;
    new_user->friends = NULL;
    if (users == NULL)
    {
        return new_user;
    }

    /*
    This will now put the new user in the correct position
    */

    user_t *current, *previous;
    for (previous = NULL, current = users; current != NULL && strcmp(current->username, new_user->username) < 0; previous = current, current = current->next)
    {
        // does nothing in for loop just used to increase current and previous until the new username is greater in list
    }
    // insert before current
    new_user->next = current;
    // insert after pervious or at beginning
    if (previous == NULL)
        users = new_user;
    else
        previous->next = new_user;
    return users;
}
void get_input_password(char *password)
{
    while (true)
    {
        if (scanf("%s", password) == 1 && strlen(password) >= MIN_PASSWORD && strlen(password) < MAX_PASSWORD)
        {
            break;
        }
        printf("Your password is invalid. It must be between 8 and 14 characters. Please try again: ");
    }
}
void get_input_username(char *username)
{
    while (true)
    {
        if (scanf("%s", username) == 1 && strlen(username) < MAX_USERNAME)
        {
            for (int i = 0; i < strlen(username); i++)
            {
                username[i] = tolower(username[i]);
            }
            *username = tolower(*username);
            break;
        }
        printf("Your username is invalid. It must be less than 30 characters. Please try again: ");
    }
}
user_t *find_user(user_t *users, const char *username)
{
    user_t *current;
    for (current = users; current != NULL && strcmp(current->username, username) != 0; current = current->next)
    {
    }
    return current;
}
void print_post_menu(user_t *user)
{
    printf("------------------------------------------------\n"
           "\t\tManaging %s's posts\n"
           "------------------------------------------------\n",
           user->username);
    if (user->posts == NULL)
        printf("Note: No posts available for %s\n", user->username);
    printf("1. Add a new post\n"
           "2. Remove a post\n"
           "3. Return to main menu\n"
           "Enter your choice: ");
}
void add_post(user_t *user, const char *text)
{

    post_t *new_post = create_post(text);
    new_post->next = user->posts;
    user->posts = new_post;
}

_Bool delete_post(user_t *user)
{
    // no posts
    if (user->posts == NULL)
        return false;
    post_t *to_remove = user->posts;
    user->posts = to_remove->next;
    free(to_remove);
    return true;
}
void display_all_user_posts(user_t *user)
{
    printf("------------------------------------------------\n"
           "\t\t%s's posts\n",
           user->username);
    post_t *current;
    int i = 1;
    for (current = user->posts; current != NULL; current = current->next, i++)
    {
        printf("%d - %s\n", i, current->content);
    }
    printf("------------------------------------------------\n");
}
void print_friend_menu(user_t *user)
{
    printf("------------------------------------------------\n"
           "\t\tManaging %s's friends\n"
           "------------------------------------------------\n",
           user->username);
    printf("1. Add a new friend\n"
           "2. Remove a friend\n"
           "3. Return to main menu\n"
           "Enter your choice: ");
}
void add_friend(user_t *user, const char *friend)
{
    friend_t *new_friend = create_friend(friend);

    friend_t *current, *previous;
    previous = NULL;
    current = user->friends;
    for (; current != NULL && strcmp(current->username, new_friend->username) < 0; previous = current, current = current->next)
    {
        // does nothing in for loop just used to increase current and previous until the new username is greater in list
    }
    // insert before current
    new_friend->next = current;
    // insert at beginning
    if (previous == NULL)
        user->friends = new_friend;
    // insert after previous
    else
        previous->next = new_friend;
}
friend_t *create_friend(const char *username)
{
    friend_t *new_friend = malloc(sizeof(friend_t));
    assert(new_friend != NULL);
    strcpy(new_friend->username, username);
    new_friend->next = NULL;
    return new_friend;
}
void display_user_friends(user_t *user)
{
    friend_t *current;
    int i = 1;
    for (current = user->friends; current != NULL; current = current->next, i++)
    {
        printf("%d-  %s\n", i, current->username);
    }
}
void manage_friends(user_t *users)
{
    char username[MAX_USERNAME];
    unsigned short int user_choice = 0;
    printf("Enter a username to update their friends: ");
    get_input_username(username);
    user_t *user_friend_manage;
    user_friend_manage = (find_user(users, username));
    if (user_friend_manage == NULL)
    {
        printf("------------------------------------------------\n"
               "\t\tUser not found.\n"
               "------------------------------------------------\n");
    }
    else
    {
        while (true)
        {
            print_friend_menu(user_friend_manage);
            char friend[MAX_USERNAME];
            while (true)
            {
                if (scanf("%hu", &user_choice) == 1 && user_choice > 0 && user_choice < 4)
                {
                    break;
                }
                printf("Your input is invalid. Enter a value between 1 and 3 please try again: ");
            }
            if (user_choice == 1)
            {
                printf("Enter a new friends name: ");
                get_input_username(friend);
                add_friend(user_friend_manage, friend);
                printf("Friend added to the list.\n");
            }
            if (user_choice == 2)
            {
                printf("List of %s's friends:\n", user_friend_manage->username);
                display_user_friends(user_friend_manage);
                printf("Enter a friend's name to delete: ");
                get_input_username(friend);
                if (delete_friend(user_friend_manage, friend) == true)
                {
                    printf("Updated list of %s's friends\n", user_friend_manage->username);
                    display_user_friends(user_friend_manage);
                    break;
                }
                else
                    printf("Invalid friend's name\n");
            }
            if (user_choice == 3)
                break;
        }
    }
}
_Bool delete_friend(user_t *user, char *friend_name)
{
    friend_t *current, *previous;
    previous = NULL;
    current = user->friends;
    for (; current != NULL && strcmp(current->username, friend_name) != 0; previous = current, current = current->next)
    {
        // does nothing in for loop just used to increase current and previous until friend name is found
    }
    if (current == NULL)
    {
        return false;
    }

    // insert after pervious or at beginning
    if (previous == NULL)
        user->friends = current->next;
    else
        previous->next = current->next;
    free(current);
    return true;
}
post_t *create_post(const char *text)
{
    post_t *new_post = malloc(sizeof(post_t));
    assert(new_post != NULL);
    strcpy(new_post->content, text);
    new_post->next = NULL;
    return new_post;
}
void teardown(user_t *users)
{
    user_t *current = users;
    while (users != NULL)
    {
        current = users->next;
        free_friends(users->friends);
        free_posts(users->posts);
        free(users);
        users = current;
    }
}
void free_friends(friend_t *friends)
{
    friend_t *current = friends;
    while (friends != NULL)
    {
        current = friends->next;
        free(friends);
        friends = current;
    }
}
void free_posts(post_t *posts)
{
    post_t *current = posts;
    while (posts != NULL)
    {
        current = posts->next;
        free(posts);
        posts = current;
    }
}
void display_posts(user_t *users)
{
    printf("Enter a username for which you would like to display their posts: ");
    char username[MAX_USERNAME];
    get_input_username(username);
    user_t *user = find_user(users, username);
    if (user == NULL)
    {
        printf("------------------------------------------------\n"
               "\t\tUser not found.\n"
               "------------------------------------------------\n");
    }
    else
    {
        display_posts_by_n(user, NUM_POSTS);
    }
}
void display_posts_by_n(user_t *user, int number)
{
    if (user->posts == NULL)
    {
        printf("%s has no posts \n", user->username);
        return;
    }
    printf("------------------------------------------------\n"
           "\t\t%s's posts\n",
           user->username);
    post_t *current;
    int i = 1;

    for (current = user->posts; current != NULL && i <= number; current = current->next, i++)
    {
        printf("- %s\n", current->content);
        if (current->next == NULL)
        {
            printf("------------------------------------------------\n");
            printf("All posts have been displayed. Returning to main menu\n");
        }
        else if (i == number)
        {
            printf("------------------------------------------------\n");
            printf("Would you like to display more post. Please input 'y' or 'Y' for yes and 'n' or 'N' for no: ");
            char user_choice;
            while (true)
            {
                if (scanf("%c", &user_choice) == 1)
                {
                    if (user_choice == 'y' || user_choice == 'Y' || user_choice == 'n' || user_choice == 'N')
                        break;
                }
                else
                    printf("Try again. Please enter either 'y' or 'Y' for yes and 'n' or 'N' for no: ");
            }

            if (user_choice == 'y' || user_choice == 'Y')
            {
                number += NUM_POSTS;
                printf("------------------------------------------------\n"
                       "\t\t%s's posts\n",
                       user->username);
            }
        }
    }
}
void register_user(user_t *users)
{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    printf("Enter a username: ");
    get_input_username(username);
    user_t *new_user = find_user(users, username);
    if (new_user != NULL)
    {
        printf("The username just entered already exists. Returning to main menu.\n");
    }
    else
    {
        printf("Enter an up to 15 character password of at least 8 characters: ");
        get_input_password(password);
        users = add_user(users, username, password);
    }
}

void manage_profile(user_t *users)
{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    printf("Enter a username to update their password: ");
    get_input_username(username);
    user_t *user_to_be_changed;
    user_to_be_changed = (find_user(users, username));
    if (user_to_be_changed != NULL)
    {
        printf("Enter the old password: ");
        scanf("%s", password);
        if (strcmp(user_to_be_changed->password, password) == 0)
        {
            printf("Enter a new password up to 14 characters: ");
            get_input_password(password);
            strcpy(user_to_be_changed->password, password);
            printf("**** Password Changed! ****\n");
        }
        else
            printf("Passwords do not match. Returning to main menu.\n");
    }
    else
        printf("Username does not exist returning to main menu.\n");
}
void manage_posts(user_t *users)
{
    char username[MAX_USERNAME];
    unsigned short int user_choice = 0;
    printf("Enter a username to manage their posts: ");
    get_input_username(username);
    user_t *user_post_manage;
    user_post_manage = (find_user(users, username));
    if (user_post_manage == NULL)
    {
        printf("------------------------------------------------\n"
               "\t\tUser not found.\n"
               "------------------------------------------------\n");
    }
    else
    {
        char username[MAX_USERNAME];
        print_post_menu(user_post_manage);
        while (true)
        {
            if (scanf("%hu", &user_choice) == 1 && user_choice > 0 && user_choice < 4)
            {
                break;
            }
            printf("user_choice is %hu", user_choice);
            printf("Your input is invalid. Enter a value between 1 and 3 please try again: ");
        }
        if (user_choice == 1)
        {
            printf("Please enter a post of up to 249 characters: ");
            char post[MAX_POST_LENGTH];
            scanf(" %[^\n]s", post);
            add_post(user_post_manage, post);
        }
        if (user_choice == 2)
        {
            if (delete_post(user_post_manage) == false)
                printf("No posts to be deleted. Returning to main menu\n");
            else
            {
                printf("Post successfully deleted\n");
                display_all_user_posts(user_post_manage);
            }
        }
    }
}
void print_menu2()
{
    printf("***********************************************\n"
           "\t\tMAIN MENU:\n"
           "***********************************************\n"
           "1. Register a new user\n"
           "2. Manage a user's profile (change profile)\n"
           "3. Manage a user's posts (add/remove)\n"
           "4. Manage a user's friends (add/remove)\n"
           "5. Display a user's posts\n"
           "6. Exit\n\n"
           "Enter Your choice ");
}
void login(user_t *users)
{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    printf("Enter a username: ");
    get_input_username(username);
    printf("Enter the password: ");
    // doesn't use get input password cause they can try any length might just be wrong
    scanf("%s", password);
    user_t *login_user = find_user(users, username);
    if (strcmp(login_user->password, password) == 0)
    {
        printf("You are now logged in\n");
    }
    else
    { 
        printf("")
    }
}