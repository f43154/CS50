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
        printf("Use: ./resize n input output\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    if (n < 1 || n > 100) {
        printf("Please enter an integer between 1 and 100\n");
        return 1;
    }
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
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
        return 4;
    }

    // Change height and width of original bmp
    int biWidthOriginal = bi.biWidth;
    bi.biWidth = bi.biWidth*n;
    int biHeightOriginal = bi.biHeight;
    bi.biHeight = bi.biHeight*n;

    // determine padding for scanlines
    int paddingOriginal =  (4 - (biWidthOriginal * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // write and update outfile's BITMAPFILEHEADER
    bf.bfSize = 54 + (bi.biWidth * sizeof(RGBTRIPLE) + padding) * abs(bi.biHeight);
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write and update outfile's BITMAPINFOHEADER
    /* Use biSizeImage here because we just want to size of the image
    and not the entire BMP file (with bi and bf included)*/
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding) * abs(bi.biHeight);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < abs(biHeightOriginal); i++)
    {
        // Repeat the rows vertically
        for (int v = 0; v < n; v++) {
        
            // iterate over pixels in scanline
            for (int j = 0; j < biWidthOriginal; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for (int h = 0; h < n; h++) {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // add back padding to output file
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
            
            // return to start of current row in input file to repeat vertically
            // fseek(from what, offset how much, from where);
            fseek(inptr, -(biWidthOriginal * sizeof(RGBTRIPLE)), SEEK_CUR);
            
        }
        
        // Go to the end of the current row in input file, not including padding
        fseek(inptr, biWidthOriginal * sizeof(RGBTRIPLE), SEEK_CUR);
        // Skip over the adding of input file
        fseek(inptr, paddingOriginal, SEEK_CUR);
        
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
