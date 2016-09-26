#include <cs50.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int* hashLocations;
    int length;
} csvLine;

csvLine extractNumbers(char* line);

int main(void)
{
    //You need to do the following:
    
    //Prompt the user for an input file
    printf("What is the name of the file that I should read from?\n");
    string input = GetString();
    if (input == NULL)
        return 1;
    
    //Prompt the user for an output file
    printf("What is the name of the file that I should write to?\n");
    string output = GetString();
    if (output == NULL)
        return 1;
    
    //Open the file to read from
    FILE *file_in = fopen(input, "r");
    //Open the file you're writing to
    FILE *file_out = fopen(output, "w");
    //For each line being read in from the input file:
    char* line = malloc(sizeof(char) * 256);
    csvLine array = {};
    while (fgets(line, 256, file_in) != NULL)
    {
        array = extractNumbers(line);
        for (int i = 1, j = 0; i < 128; i++)
            {
                if (i == array.hashLocations[j])
                    fputs("#", file_out);
                if (j < array.length)
                    j++;
                else
                {
                    fputs(" ", file_out);
                }
            }
        fputs("\n", file_out);
    }
    //Close both files
    free(line);
    fclose(file_in);
    fclose(file_out);
    //Insert the name of the output file in the print statement below
    printf("Done! If you open up %s you should now see a cool image!\n", output);
    return 0;
}

csvLine extractNumbers(char* line)
{
    int count = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == ',')
        {
            count++;
        }
    }

    char* token;
    int* hV = malloc(sizeof(int) * (count+1));
    int i = 0;
    token = strtok(line, ",");
    hV[i] = atoi(token);
    i++;
    while ((token = strtok(NULL, ",")) != NULL)
    {
        hV[i] = atoi(token);
        i++;
    }
    csvLine result;
    result.hashLocations = hV;
    result.length = count + 1;
    return result;
}