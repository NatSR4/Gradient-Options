# Gradient-Options readme
Probably useful to know that I'm an absolute beginner to opencv
## Language used and other: C++, opencv
 Program that converts images to grayscale, creates borders in the image
        and then labels the area within each individual border with the kind of graphite 
        pencil to be used.
## Progress update:
    1. 6/12/2020
      - Program can convert images to gray scale and creates borders. Borders are incorrect as of now.
      2. 8/12/2020
         - Program uses Sobel operator for edge detection
## For use:
    I use Xming to display the image. It has to be running before running this program. 
    I'm also running this on ubuntu so for compilation:
   g++ gradient.cpp -o grad \`pkg-config --cflags --libs opencv\` 
    to run: ./grad [image name]
## Other information about the program:
    Although it accepts command line arguments now, a few more changes need to be made. 
    The image I'm using is called 'Deku_2.png', that can be replaced with the name of the image you like 
    until this is worked out.
