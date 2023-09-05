// ============================================
// The globals header file
//
// Copyright 2023 Georgia Tech. All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must NOT be made publicly available anywhere.
//==================================================================

#ifndef GLOBAL_H
#define GLOBAL_H

// Include all the hardware libraries
#include "mbed.h"
#include "wave_player.h"
#include "MMA8452.h"
#include "uLCD_4DGL.h"
#include "Nav_Switch.h"
// #include "SDFileSystem.h"



/////////////////////////////////////////
// Declare the hardware interface objects
/////////////////////////////////////////

/*
This file holds all the global variables that are accessable from all the 
different files in this project. You see below most of it looks like hardware.
That's because it is hardware! The uLCD object is how you interact with the LCD
screen. The navigation switch variable is how you interact with the nav switch 
and so on for all the other variables. "extern" means "this is instantiated somewhere, 
but here's what the name means.
*/

extern uLCD_4DGL uLCD;      // LCD Screen
extern Serial pc;           // USB Console output
extern MMA8452 acc;         // Accelerometer
extern DigitalIn button1;   // Pushbuttons
extern DigitalIn button2;
extern DigitalIn button3;
extern AnalogOut DACout;    // Speaker
extern PwmOut speaker;
extern wave_player waver;
extern Nav_Switch navs;     // Nav Switch
// extern SDFileSystem sd;     // SD Card


/////////////////////////////////////////
// Global settings
/////////////////////////////////////////

#define F_DEBUG   1                     // Debug flag
#define BACKGROUND_COLOR 0x000000       // Black Background
#define LANDSCAPE_HEIGHT 4              // Number of pixel on the screen
#define MAX_BUILDING_HEIGHT 10          // Number of pixel on the screen


/////////////////////////////////////////
// Global Variables
/////////////////////////////////////////

//  Feel free to define any global variables here



/////////////////////////////////////////
// Error Handler
/////////////////////////////////////////

// === [define the macro of error heandle function] ===
// when the condition (c) is not true, assert the program and show error code
#define ASSERT_P(c,e) do { \
    if(!(c)){ \
        pc.printf("\nERROR:%d\n",e); \
        while(1); \
    } \
} while (0)

// === [error code] ===
#define ERROR_NONE 0 // All good in the hood
#define ERROR_MEH -1 // This is how errors are done

#endif //GLOBAL_H
