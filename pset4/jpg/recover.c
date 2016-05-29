/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
 #include <stdio.h>
 #include <stdint.h> // To use uint8_t
 #include <stdlib.h> // To use malloc()
 
 #define CARD_FILENAME "card.raw"
 
// Integer with an exact specified width
// 8-bit unsigned type character
// Recall 8 Bits = 1 Byte
// Found in stdint.h Standard Integer Types
// Using uint8_t documents intent on storing small numbers instead of characters
// Also nicer if I'm complimenting it with other typedefs like uint16_t*/
typedef uint8_t BYTE; // Defines 1 Byte as 8 Bits

int main(void)
{
    
    // Open input file
    FILE* INPUT_FILE = fopen(CARD_FILENAME, "r");
    // Open output file
    FILE* OUTPUT_FILE = NULL;
    
    // Create INDEX as counter for number of JPEGS
    // Useful for naming the JPEGS
    int INDEX = 0;
    
    // Check for successful open
    if (INPUT_FILE == NULL) {
        printf("Could not open card.raw\n");
        fclose(INPUT_FILE);
        return 1;
    }
    
    // Each file size block is 512 Bytes in size, regardless of image quality/size
    // Therefore need to read each file by the block, by 512 bytes
    // So I need to declare a BLOCK array of 512 bytes
    // This BLOCK array will hold information on jpgs that I will recover
    // Except it's not permanent, I'll get rid of it after I'm done each file
    BYTE BLOCK[512];
    
    // While BLOCK[512] is not the end of the file
    // Use fread to read the data in buffer to make sure each block is 512
    // As long as each block is 512, do the stuff inside while loop
    // Otherwise close the file with fclose
    // fread takes on four arguments:
    //      fread( pointer to memory, size in bytes, number of elements, pointer to input)
    while(fread(BLOCK, 512, 1, INPUT_FILE)) {
        
        // If it's JPEG header 
        // The first three bytes of JPEGS are
        // 0xff 0xd8 0xff
        // With the fourth byte either 0xe0 or 0xe1 
        // (There are much more but it seems there are only these two in card.raw)
        if((BLOCK[0] == 0xff && BLOCK[1] == 0xd8 && BLOCK[2] == 0xff && BLOCK[3] == 0xe0) || (BLOCK[0] == 0xff && BLOCK[1] == 0xd8 && BLOCK[2] == 0xff && BLOCK[3] == 0xe1)) {
            
            // If old file exists then close the old file
            if(OUTPUT_FILE != NULL)
                fclose(OUTPUT_FILE);
            
            // Create a character array for title 
            // Because title must be in xxx.jpg format
            char FILE_NAME[8];
                
            // Then open a new writable file
            // write the bytes into a new file
            // Use sprintf( type of data, output format, data to output)
            // The "%03d" means print as a decimal integer with a width of at least 3 wide and with leading zeros
            sprintf(FILE_NAME, "%03d.jpg", INDEX);
            INDEX++; // Increment INDEX to name next JPEG
            OUTPUT_FILE = fopen(FILE_NAME, "w"); // a for append
        }
        if(OUTPUT_FILE != NULL) // If OUTPUT is still open
            fwrite(BLOCK, 512, 1, OUTPUT_FILE); // Write what's stored in BLOCK into OUTPUT_FILE
    }
    
    fclose(INPUT_FILE); // Close card.raw after going through while loop
    fclose(OUTPUT_FILE); // Close output after done with it
}
