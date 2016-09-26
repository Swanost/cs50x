#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    char* menu = malloc(sizeof(char) * 256);
    // Output the restaurant's welcome message:
    printf("Welcome to Better Burger, way better than Good Burger!\n");
    printf("MENU:\n");

    // PUT YOUR CODE HERE: Open the file, based on the file name supplied in the command line
    FILE *file = fopen(argv[1], "r");
    
    if (file == NULL)
    return 1;
    
    // PUT YOUR CODE HERE:
    // loop through each line in the input file
    int item = 0;
    while(fgets(menu, 256, file) != NULL)
{
    printf("Item %i) %s\n", item, menu);
    item++;
}
    
    
    // For each item, output its item number and value

    // PUT YOUR CODE HERE: Close the file
    free(menu);
    fclose(file);
}