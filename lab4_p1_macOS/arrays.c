/* SYSC 2006 Lab 4.

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "arrays.h"

/* Exercise 1. */

/* Return the average magnitude of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], int n)
{
    double return_value = 0;
    for (int i = 0; i < n; i++)
    {
        return_value += fabs(x[i]);
    }
    return return_value / n;
}

/* Exercise 2. */

/* Return the average power of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], int n)
{
    double return_value = 0;
    for (int i = 0; i < n; i++)
    {
        return_value += x[i] * x[i];
    }
    return return_value / n;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double maxi(double arr[], int n)
{
    double max_value = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max_value < arr[i])
        {
            max_value = arr[i];
        }
    }
    return max_value;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double mini(double arr[], int n)
{
    double min_value = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min_value > arr[i])
        {
            min_value = arr[i];
        }
    }
    return min_value;
}

/* Exercise 5. */

/* Normalize the n doubles in x[].
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{
    double max_value = maxi(x, n);
    double min_value = mini(x, n);

    for (int i = 0; i < n; i++)
    {
        x[i] = (x[i] - min_value) / (max_value - min_value);
    }
}
