#include "struct_string.h"
#include <stdlib.h> // abs(x)
#include <stdio.h>  // printf

// Exercise 1
/* Print fraction pointed to by pf in the form a/b. */
void print_fraction(const fraction_t *pf)
{
   printf("%d/%d", pf->num, pf->den);
}

/* Return the greatest common divisor of integers a and b;
   i.e., return the largest positive integer that evenly divides
   both values.  Copy this function from Lab 6.  No changes are needed.
*/
int gcd(int a, int b)
{
   /* Euclid's algorithm, using iteration and calculation of remainders. */
   int q, p, r;
   q = abs(a);
   p = abs(b);
   r = q % p;
   while (r != 0)
   {
      q = p;
      p = r;
      r = q % p;
   }
   return p;
}

/* Updates the fraction pointed to by pf to its reduced form.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
      positive, and the numerator and denominator have no common
      divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
      are made positive, or if the numerator is positive and the
      denominator is negative, the numerator is made negative and the
      denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
      common divisor.
*/
void reduce(fraction_t *pf)
{
   if (pf->num == 0) // makes fraation 0/1
   {
      pf->den = 1;
   }
   else
   {
      int g_c_d = gcd(pf->den, pf->num);
      pf->num = pf->num / g_c_d;
      pf->den = pf->den / g_c_d;
      if (pf->den < 0) // if den is negative
      {
         pf->den = abs(pf->den);
         if (pf->num < 0) // if num is also negative (i.e. -9/-15)
         {
            pf->num = abs(pf->num);
         }
         else
         {
         pf->num *= -1;
         }
      }
   }  
  
}

/* Returns a pointer to a fraction (by reference) with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form.
*/
void make_fraction(int a, int b, fraction_t *pf)
{
   if (b == 0)
   {
      printf("Zero in demoninator error");
      exit(1);
   }
   pf->num = a;
   pf->den = b;
   reduce(pf);
}

/* Returns by reference a pointer to the sum of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void add_fractions(const fraction_t *pf1, const fraction_t *pf2, fraction_t *psum)
{
   make_fraction(((pf1->num * pf2->den) + (pf2->num * pf1->den)), (pf1->den * pf2->den), psum);

}

/* Returns by reference a pointer to the product of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void multiply_fractions(const fraction_t *pf1, const fraction_t *pf2, fraction_t *pprod)
{
   make_fraction((pf1->num * pf2->num), (pf1->den * pf2->den), pprod);
}

// Exercise 2

/* Update the GPA of the student pointed to by studentp, assuming the student has numGrades.	Note that update_gpa must call calc_gpa for each student. */
void update_gpa(student_t *studentp, int numGrades)
{
   studentp->gpa = calc_gpa(studentp->grades, numGrades);
}

/* Calculate the GPA associated with the numGrades pointed to by gradesp.
   The implementation must use a walking pointer.
   If the total weight of all courses is 0, a GPA of 0 is returned. */
float calc_gpa(const grade_t *gradesp, int numGrades)
{
   float total_gp = 0;
   float total_credits = 0;
   for (const grade_t *i = gradesp; i < gradesp + numGrades; i++)
   {
     total_gp += i->gp * i->weight;
     total_credits += i->weight;
   }
   if (total_credits == 0)
   {
      return 0;
   }
   return total_gp / total_credits;
}

// Exercise 3

/* Calculate how many time the target character appears in string my_str
For example:
count_char("Hello world ",'l') return 3
count_char("Hello world ",'a') return 0
Your implementation must use array-indexing.
*/

int count_char(const char *my_str, char target)
{
   int count = 0;
   int index = 0;
   while (my_str[index] != 0) 
   {
      if (my_str[index] == target)
      {
         count++;
      }
      index++;
   }
   return count;
}

// Exercise 4

/* Calculate how many time the target character appears in string my_str
For example:
count_char("Hello world ",'l') return 3
count_char("Hello world ",'a') return 0
Your implementation must use walking pointer.
*/

int count_char_wp(const char *my_str, char target)
{
   int count = 0;
   int index = 0;
   while (*my_str != 0) 
   {
      if (*my_str == target)
      {
         count++;
      }
      my_str++;
   }
   return count;
}