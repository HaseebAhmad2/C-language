#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{ // two for loops are used to iterate the pixels as we know that we are moving in 2d array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        { // finding average of pixels rgb value
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // assigning average value to Red green and blue color to each pixel
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{ // two loops for getting pixels rgb as discussed
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        { // farmula for converting image to sepia is given in documentation
            int sepia_red = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepia_green =
                round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepia_blue =
                round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            // if value of sepia red ,sepia blue and sepia green is greater then 255 then give the specific color value to 255
            if (sepia_red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepia_red;
            }
            //if value of sepia green is greater then 255 then give the specific color value to 255
            if (sepia_green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepia_green;
            }
            //if value of sepia blue is greater then 255 then give the specific color value to 255
            if (sepia_blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepia_blue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    { // here loop is iterating to half of the width because we want first half of pixels to swap by the next half pixels .
        for (int j = 0; j < width / 2; j++)
        { // swaping the array . first pixel swap with last
            int tmp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtRed = tmp;

            int tmp1 = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][width - 1 - j].rgbtGreen = tmp1;

            int tmp2 = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][width - 1 - j].rgbtBlue = tmp2;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{ // creating a copy for image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        { // assigning total color values
            float total_red = 0;
            float total_green = 0;
            float total_blue = 0;
            float count = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    { // adding the neigbours pixels RGB value adn updating count
                        total_red += (image[k][l].rgbtRed);
                        total_green += (image[k][l].rgbtGreen);
                        total_blue += (image[k][l].rgbtBlue);
                        count++;
                    }
                }
            }
            // calculating average for red green and blue colors
            int average_red = round(total_red / count);
            int average_green = round(total_green / count);
            int average_blue = round(total_blue / count);
            copy[i][j].rgbtRed = average_red;
            copy[i][j].rgbtGreen = average_green;
            copy[i][j].rgbtBlue = average_blue;
        }
    }
    // swaping copy pixels to image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
