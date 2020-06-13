Gradient-Options-Git
Probably useful to know that I'm an absolute beginner to opencv
Language used and other: C++, opencv
Aim: Program that converts images to grayscale, creates borders in the image
        and then labels the area within each individual border with the kind of graphite 
        pencil to be used.
Progress update:
    1. 6/12/2020
     Program can convert images to gray scale and creates borders. Borders are incorrect as of now.
For use:
    I use Xming to display the image. It has to be running before running this program. 
    I'm also running this on ubuntu so for compilation:
    g++ gradient.cpp -o grad `pkg-config --cflags --libs opencv`
    to run: ./grad
Other information about the program:
    It is not written to take in command line arguments, that will be worked on at a later date.
    The image I'm using is called 'Deku_2.png', that can be replaced with the name of the image you like 
    until I rewrite the program to accept command line arguments or something more user friendly.
