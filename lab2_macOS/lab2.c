// SYSC 2006 - Lab 2 Solution template

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the necessary header for _Bool
#include "lab2.h"

/* Replace these lines with your information */
const char *author = "James Gohl";
const char *student_number = "101299043";

// Type your solution to exercise 1 inside the body of the function. You need to update the return statement
int alarm_clock(int day, _Bool vacation)
{
  /* This is a function that lets you know what time to wake up based on the day of the week and if is a vaction day or not
  Preconditons: the day value must be an int between 0 and 6 0 for sunday and 6 for saturday and the vaction parameter is a bool value
  */
  if (vacation == false)
  {
    if ((day == 0) || (day == 6))
    {
      return 10;
    }
    else
    {
      return 7;
    }
  }
  else
  {
    if ((day == 0) || (day == 6))
    {
      return -1;
    }
    else
    {
      return 10;
    }
  }
}
// Type your solution to exercise 2 inside the body of the function.
void count_replace(int value)
{
  /* This is a function that plays the fame FizzBuzz it takes a value which must be an int and counts up by one to the value
  starting at 1 if the number is at a multiple of 3 it outputs Fizz, a multiple of 5 it outputs Buzz and if it is a multiple
  of 3 and 5 it outputs FIzzBuzz. Otherwise it just outputs the number.
  Preconditons: the int value must be an int
  */
  for (int i = 1; i <= value; i++)
  {
    if (i % 3 == 0 && i % 5 == 0)
    {
      printf("FizzBuzz ");
    }
    else if (i % 3 == 0)
    {
      printf("Fizz ");
    }
    else if (i % 5 == 0)
    {
      printf("Buzz ");
    }
    else
    {
      printf("%d ", i);
    }
  }
  printf("\n");
  return;
}
// Type your solution to exercise 3 inside the body of the function. You need to update the return statement
_Bool is_prime(int value)
{
  /*
  The function takes an integer and returens whether it is a prime number (true) or not a prime number (false)
  Precondtions: the value passed the fuction must be an int
  */
  if (value > 1)
  {
    for (int i = 2; i <= value - 1; i++)
    {
      if (value % i == 0)
      {
        return false;
      }
    }
  }
  else // if value 1 or less
  {
    return false;
  }
  return true;
}
// Type your solution to exercise 4 inside the body of the function. You need to update the return statement

int sum_even(int value)
{
  /*
  Takes an int and sums all the even numbers from 1 to the value of the int and returns the sum
  Precondtion: value must be an int
  */
  int sum_even;
  if (value > 0)
  {
    // cacluates how many even numbers are in the range
    value = value / 2;
    // formula for summing consecuitive even numbers
    sum_even = value * (value + 1);
  }

  return sum_even;
}