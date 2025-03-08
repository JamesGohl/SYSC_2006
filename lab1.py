# SYSC 2006 - Lab 1 Solution template

__author__ = "James Gohl"
__student_number__ = "101299043"

# Type your solution to exercise 1 after this line


def alarm_clock(day: int, vaction: bool) -> str:
    """
   This function determines when you should wake up on the weekend or weekday weather it is a holday or not

   Precondtions: day must be an int between 0 and 6 inclusive.

   >>> alarm_clock(1, True)
   10:00

   >>> alarm_clock(1, False)
   07:00

   >>> alarm_clock(0, True)
   off

    """
    if vaction == False:
        if day == 0 or day == 6:
            return "10:00"
        else:
            return "07:00"
    else:
        if day == 0 or day == 6:
            return "off"
        else:
            return "10:00"


# Type your solution to exercise 2 after this line


def count_replace() -> None:
    """
    This function plays the game fizz buzz where it counts up to a nubmer inputed by the
    user but replaces multiples of 3 with Fizzand multiples of 5 with buzz and multiplies of 3 and 5 with FizzBuzz

       Precondtions: user must input an int.

       >>> count_replace()
       5
       1 2 Fizz 4 Buzz

       >>> count_replace()
       15
       1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz
       >>> count_replace()
       12
       1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz




    """

    n = int(input("Enter a positive intger "))
    for i in range(1, n + 1):
        if (i % 3 == 0) & (i % 5 == 0):
            print("FizzBuzz", end=" ")
        elif i % 3 == 0:
            print("Fizz", end=" ")
        elif i % 5 == 0:
            print("Buzz", end=" ")
        else:
            print(i, end=" ")


# Type your solution to exercise 3 after this line


def is_prime(n: int) -> bool:
    """
    This function program determines if a number is prime or not

       Precondtions: n must be an int

       >>> is_prime(7)
       True

       >>> is_prime(8)
       False

       is_prime(1)
       False

    """
    if n > 1:
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True
    return False


# Type your solution to exercise 4 after this line
def divisors(n: int) -> list:
    """
    This function returns a list wirhall the divisors of an integer

       Precondtions: n must be a positive int

       >>> divisors(7)
       [1, 7]

       >>> divisors(8)
       [1, 2, 4, 8]

       divisors(15)
       [1, 3, 5, 15]
    """
    divisor_list = []
    for i in range(1, n + 1):
        if n % i == 0:
            divisor_list.append(i)
    return divisor_list
