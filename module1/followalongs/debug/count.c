/**
  * Filename: count.c
  * Save in Folder: ~/workspace/module1/followalongs/count
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method
  * (Hint: Don't forget to add curly braces { })
  *    Print "Please enter a number: "
  *    Declare a variable called num of type int and assign the user input to it.
  *    Assign the expression num / 2 to the variable num
  *    Print "Your halved number is: %i\n" using num as the value for the placeholder %i
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  * 
  */

#include <cs50.h>
#include <stdio.h>

int main(void)

{
    printf("Please enter a number: ");
    int num = GetInt();
    num = num / 2;
    printf("Your halved number is: %i\n", num);
}