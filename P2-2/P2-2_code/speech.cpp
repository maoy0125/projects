//=================================================================
// The speech class file.
//
// Copyright 2023 Georgia Tech. All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must NOT be made publicly available anywhere.
//==================================================================

#include "speech.h"

#include "globals.h"
#include "hardware.h"

///////////////////////////////
//Static function declarations
///////////////////////////////
/**
 * Draw the speech bubble background.
 */
static void draw_speech_bubble();

/**
 * Erase the speech bubble.
 */
static void erase_speech_bubble();

/**
 * Draw a single line of the speech bubble.
 * @param line The text to display
 * @param which If TOP, the first line; if BOTTOM, the second line.
 */
#define TOP    0
#define BOTTOM 1
static void draw_speech_line(const char* line, int which);


///////////////////////////////
//Drawing function declarations
///////////////////////////////


//***
// HINT: for this function and below: Check out the ULCD demo in the docs to see what
// uLCD methods you can use to draw graphics 

//Link: https://os.mbed.com/users/4180_1/notebook/ulcd-144-g2-128-by-128-color-lcd/
//***


void draw_speech_bubble()
{
    //****************
    // TODO: Implement
    //****************
    uLCD.filled_rectangle(0, 100, 127, 120, 0xFF0000);
    //1. Draw a speech bubble at the bottom of the screen 
    // Hint: You can stack ULCD rectangles to make a border
    
}

void erase_speech_bubble()
{
    //****************
    // TODO: Implement
    //****************
    uLCD.filled_rectangle(0, 100, 127, 120, 0x000000);
    //1. Erase the speech bubble at the bottom of the screen
    // Hint: You can overwrite the bubble with a empty (black) one
}

void draw_speech_line(const char* line, int which)
{
    //****************
    // TODO: Implement
    //****************
    //1. Set the location which line of text will go the uLCD
    // Hint: Change the y coordinate based on which line (top or bottom)

    //2. For each character in the text, write it to uLCD
    for (int i = 0; line[i] && i < 17; i++) //We can simplify by limiting each line to 17 char
    {
        // uLCD.text_width(0.2); // set text width to 2
        // uLCD.text_height(0.2); // set text height to 2
        //uLCD.locate(33, 90+which*10);
        uLCD.locate(i, 13+which);
        uLCD.printf("%c", line[i], WHITE);
        //TODO: Write the character
        wait_ms(30); 
    }
}

void speech_bubble_wait()
{
    //****************
    // TODO: Implement
    //****************
    GameInputs input = read_inputs();

    while (input.b1) {
        input = read_inputs();
        wait(0.1);
    }
    // 1. Keep waiting until the action button is pressed 
    //   Hint: What type of loop can we use to stay until a condition is met?


}

void speech(const char* line1, const char* line2)
{
    //****************
    // TODO: Implement
    //****************
    const char* lines[] = {line1, line2};
    long_speech(lines, 2);
    // 1. Place the two lines into an array of lines
    // 2. Pass in to long_speech with the corresponding number of lines
}

void long_speech(const char* lines[], int n)
{

    //****************
    // TODO: Implement
    //****************

    //1. Create a speech bubble
    draw_speech_bubble();
    //2. For each lines, display only two lines at a time
    //   If two lines are displayed, make sure to wait (call the wait function)
    for (int i = 0; i < n - 1; i++) {
        draw_speech_line(lines[i], 0);
        if(i+1<n) {
            draw_speech_line(lines[i+1], 1);
        }
        speech_bubble_wait();
    }
    speech_bubble_wait();
    erase_speech_bubble();

    //3. Erase the speech bubble when you are done

}

