#include <stdio.h>
#include <cs50.h>

int main(void)
{
  string menuItems[] = {"Water", "Soda", "Cheeseburger", "Fries"};

  // Display menu:
  printf("Welcome to Good Burger! Can I take your order?\n");
  printf("MENU:\n");
  for (int i = 0; i < 4; i++)
  {
    printf("Item %i: %s\n", i, menuItems[i]);
  }
  printf("\nHow many items?\n");

  int numItems = GetInt();

  // PUT YOUR CODE HERE: open a file to write
  FILE *file = fopen("order.txt", "w");

  // PUT YOUR CODE HERE: before continuing, make sure the file pointer is not NULL
  // if it is NULL, then quit the program (return 1) instead of continuing
  if (file == NULL)
    return 1;

  for (int i = 0; i < numItems; i++)
  {
    printf("Which menu item would you like?\n");
    // PUT YOUR CODE HERE: Take the order number, translate it into an item, and write the item to the file
    int order = GetInt();
    fputs(menuItems[order], file);
    // PUT YOUR CODE HERE: Write a new line ("\n") to the file
    fputs("\n", file);
    // free(order);
  }

  // PUT YOUR CODE HERE: close the file
    fclose(file);
}