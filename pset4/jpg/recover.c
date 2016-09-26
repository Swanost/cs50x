/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    // open card file
    FILE* infile = fopen("card.raw", "r");
    if (infile == NULL)
    {
        return 1;
    }
    // initialize placeholder variables
    typedef uint8_t BYTE;
    BYTE block[512]; // JPG block
    int count = 0; // counter
    char title[8]; // title of JPG
    
    FILE *outfile;
    outfile = NULL;
    
    while (fread(&block, 1, 512, infile))
    {
    
        // check for start of JPG
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] == 0xe0 || block[3] == 0xe1))
        {
            if (outfile == NULL)
            {
                sprintf(title, "%03d.jpg", count);
                outfile = fopen(title, "w");
                fwrite(block, 1, 512, outfile);
                count++;
            }
        
            else
            {
                fclose(outfile);
                sprintf(title, "%03d.jpg", count);
                outfile = fopen(title, "w");
                fwrite(block, 1, 512, outfile);
                count++;
            }
        }

        else
        {
            if (count != 0)
                fwrite(block, 1, 512, outfile);
        }
    }
    // fwrite(block, 1, 512, outfile);
    fclose(outfile);
    fclose(infile);
    return 0;
}
