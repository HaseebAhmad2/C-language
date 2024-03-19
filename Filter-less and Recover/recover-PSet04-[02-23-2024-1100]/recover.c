#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int JPEG_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    } // opening the raw file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 1;
    }
    // Declaring buffer size,image count image name and output file
    BYTE buffer[JPEG_SIZE];
    int image_count = 0;
    char image_name[8];
    FILE *output = NULL;
    //for loop to read the file
    while (fread(&buffer, 1, JPEG_SIZE, file) == JPEG_SIZE)
    { // checking 1st ,2nd 3rd and 4th byte (Header)
        if ((buffer[0] == 0xff )&& (buffer[1] == 0xd8) && (buffer[2] = 0xff )&& (buffer[3] & 0xf0) == 0xe0)
        {
            // if condition is true then give name to the file
            if (image_count == 0)
            {
                sprintf(image_name, "%03i.jpg", image_count);
                output = fopen(image_name, "w");
                fwrite(buffer, 1, JPEG_SIZE, output);
                image_count++;
            }
            else
            { // close the previous file and open the next file and give name to it
                fclose(output);
                sprintf(image_name, "%03i.jpg", image_count);
                output = fopen(image_name, "w");
                fwrite(buffer, 1, JPEG_SIZE, output);
                image_count++;
            }
        }
        else
        {
            // if the image count >0 or next image occurs
            if (image_count > 0)

            { // write the next file to buffer size that is 512
                fwrite(buffer, 1, JPEG_SIZE, output);
            }
        }
    }//closing all files
    fclose(file);
    fclose(output);

}
