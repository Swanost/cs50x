/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    int n = atoi(argv[1]);
    
    if ((n < 1) || (n > 100))
    {
        printf("N must be between 1 and 100.\n");
        return 2;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // save original file specs
    int originalheight = bi.biHeight;
    int originalwidth = bi.biWidth;
    
    // new file specs
    int newheight = bi.biHeight * n;
    int newwidth = bi.biWidth * n;
    
    // find padding
    int originalpadding = (4 - (originalwidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newpadding = (4 - (newwidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // calculate new sizes
    int originallength = (originalwidth * 3) + originalpadding;
    
    bi.biSizeImage = abs(newheight) * (newwidth * sizeof(RGBTRIPLE) + newpadding);
   
    bf.bfSize = bi.biSizeImage + bf.bfOffBits;
   
    bi.biWidth = newwidth;
    bi.biHeight = newheight;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < abs(originalheight); i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < n; j++)
        {
            fseek(inptr, 54 + originallength * i, SEEK_SET);
            
            for (int k = 0; k < originalwidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int l = 0; l < n; l++)
                {    
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
        

            // skip over padding, if any
            // fseek(inptr, newpadding, SEEK_CUR);
        
            // then add it back (to demonstrate how)
            for (int m = 0; m < newpadding; m++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}