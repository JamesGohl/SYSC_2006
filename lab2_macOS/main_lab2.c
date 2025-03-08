// SYSC 2006 - Lab 2 Template

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the necessary header for _Bool
#include "lab2.h"

/* Replace these lines with your information */
const char *author_main = "James Gohl";
const char *student_number_main = "101299043";

int main(void)
{
  // Tests exercise 1 - Complete for a comprehensive test harness
  int expected_week_non_vac = 7;
  for (int day = 1; day <= 5; day++)
  {
    int alarm_time = alarm_clock(day, false);
    if (alarm_time == expected_week_non_vac)
    {
      printf("Day %d, Non vacation: TEST PASS.\n", day);
    }
    else
    {
      printf("Day %d, Non vacation: TEST FAIL.\n", day);
    }
  }
  // weekend non vacation
  int expected_weekend_non_vac = 10;
  for (int day = 0; day <= 6; day += 6)
  {
    int alarm_time = alarm_clock(day, false);
    if (alarm_time == expected_weekend_non_vac)
    {
      printf("Day %d, Non vacation: TEST PASS.\n", day);
    }
    else
    {
      printf("Day %d, Non vacation: TEST FAIL.\n", day);
    }
  }
  // week day vacation
  expected_week_non_vac = 10;
  for (int day = 1; day <= 5; day++)
  {
    int alarm_time = alarm_clock(day, true);
    if (alarm_time == expected_week_non_vac)
    {
      printf("Day %d, vacation: TEST PASS.\n", day);
    }
    else
    {
      printf("Day %d, vacation: TEST FAIL.\n", day);
    }
  }
  // weekend  vacation
  expected_weekend_non_vac = -1;
  for (int day = 0; day <= 6; day += 6)
  {
    int alarm_time = alarm_clock(day, true);
    if (alarm_time == expected_weekend_non_vac)
    {
      printf("Day %d, vacation: TEST PASS.\n", day);
    }
    else
    {
      printf("Day %d, vacation: TEST FAIL.\n", day);
    }
  }

  // Type your test cases for exercise 2. Make sure to include border line cases
  printf("Expected Output: 1\nActual output:\n");
  count_replace(1); // should output: 1
  printf("Expected Output: 1 2\nActual output:\n");
  count_replace(2); // should output: 1 2
  printf("Expected Output: 1 2 Fizz\nActual output:\n");
  count_replace(3); // should output: 1 2 Fizz
  printf("Expected Output: 1 2 Fizz 4 Buzz\nActual output:\n");
  count_replace(5); // should output: 1 2 Fizz 4 Buzz
  printf("Expected Output: 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz\nActual output:\n");
  count_replace(15); // should output: 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz
  printf("Expected Output: 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz\nActual output:\n");
  count_replace(30); // should output:1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz Buzz 26 Fizz 28 29 FizzBuzz
  printf("Expected Output: 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz Buzz 26 Fizz 28 29 FizzBuzz\nActual output:\n");
  // Type your test cases for exercise 3. Make sure to include border line cases
  // Tests all numbers 1 to 50
  int test_passed = 0;
  for (int i = 0; i <= 50; i++)
  {
    _Bool correct_answer;
    _Bool function_result;
    // hard codes the prime numbers 0-50
    if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11 || i == 13 || i == 17 || i == 19 || i == 23 || i == 29 || i == 31 || i == 37 || i == 41 || i == 43 || i == 47)
    {
      correct_answer = true;
      _Bool function_result = is_prime(i);
      if (function_result == correct_answer)
      {
        test_passed++;
      }
    }
    else
    {
      correct_answer = false;
      _Bool function_result = is_prime(i);
      if (function_result == correct_answer)
      {
        test_passed++;
      }
    }
  }
  printf("%d tests out of 51 passed for is_prime \n", test_passed);

  // Type your test cases for exercise 4. Make sure to include border line cases
  test_passed = 0;
  if (sum_even(1) == 0)
  {
    test_passed++;
  }
  if (sum_even(2) == 2)
  {
    test_passed++;
  }
  if (sum_even(3) == 2)
  {
    test_passed++;
  }
  if (sum_even(4) == 6)
  {
    test_passed++;
  }
  if (sum_even(10) == 30)
  {
    test_passed++;
  }
  if (sum_even(50) == 650)
  {
    test_passed++;
  }
  if (sum_even(75) == 1406)
  {
    test_passed++;
  }
  if (sum_even(100) == 2550)
  {
    test_passed++;
  }
  printf("%d tests out of 8 passed for sum_even \n", test_passed);

  printf("Test harness finished\n");
  return EXIT_SUCCESS;
}
