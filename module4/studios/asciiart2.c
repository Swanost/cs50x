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
    string rfileName;
    string wfileName;
    //Prompt the user for an input file
    do {
        printf("What is the name of the file I should read from? ");
        rfileName = GetString();
    } while (rfileName == NULL);
    //Prompt the user for an output file
    
    //Open the file to read from
    FILE* rFile = fopen(rfileName, "r");
    
    if (rFile == NULL) {
        return 1;
    }
    //Open the file you're writing to
    do {
        printf("What is the name of the file I should write to? ");
        wfileName = GetString();
    } while (wfileName == NULL);

    FILE* wFile = fopen(wfileName, "w");
    
    if (wFile == NULL) {
        return 1;
    }
    
    char* line = malloc(sizeof(char) * 256);
    csvLine array = {};
    //For each line being read in from the input file:
    while (fgets(line, 256, rFile) != NULL) {
        array = extractNumbers(line);
        
        for (int i = 1, j = 0; i < 128; i++) {
            if (i == array.hashLocations[j]) {
                fputs("#", wFile);
                if (j < array.length) {
                    j++;
                }
            } else {
                fputs(" ", wFile);
            }
        }
        fputs("\n", wFile);
    }
    
    //Close both files
    fclose(wFile);
    fclose(rFile);

    //Insert the name of the output file in the print statement below
    printf("Done! If you open up <output file name> you should now see a cool image!\n");
    free(line);
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