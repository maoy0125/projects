// ============================================
// The Hardware class file
//
// Copyright 2023 Georgia Tech. All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must NOT be made publicly available anywhere.
//==================================================================


#include "globals.h"
#include "hardware.h"

// We need to actually instantiate some of the globals for hardwares 
// (i.e. declare them once without the extern keyword).
// That's what this file does!

// Hardware initialization: Instantiate all the things!
uLCD_4DGL uLCD(p9,p10,p11);                 // LCD Screen (tx, rx, reset)
Serial pc(USBTX,USBRX);                     // USB Console (tx, rx)
MMA8452 acc(p28, p27, 100000);              // Accelerometer (sda, sdc, rate)
DigitalIn button1(p21);                     // Pushbuttons (pin)
DigitalIn button2(p22);
DigitalIn button3(p23);
AnalogOut DACout(p18);                      // Speaker (pin)
PwmOut speaker(p26);
wave_player waver(&DACout);
Nav_Switch navs(p12,p15,p14,p16,p13);       // Nav Switch
BusOut mbedleds(LED1,LED2,LED3,LED4);
//SDFileSystem sd(p5, p6, p7, p8, "sd");    // SD Card(mosi, miso, sck, cs)


// Some hardware also needs to have functions called before it will set up
// properly. Do that here.

/*
 * This initializes the hardware by calling some functions to set them up.
 */
int hardware_init()
{
    // Crank up the speed
    uLCD.baudrate(3000000);
    pc.baud(115200);
    
    //Initialize pushbuttons to pullups (not needed for NavSwitch)
    button1.mode(PullUp);
    button2.mode(PullUp);
    button3.mode(PullUp);
    
    return ERROR_NONE;
}


/*
 * This handles reading inputs from all possible devices - pushbuttons, nav_switch
 */
GameInputs read_inputs() 
{
    GameInputs in;
    
    in.b1 = button1;
    in.b2 = button2;
    in.b3 = button3;
    
    in.ns_up = navs.up();
    in.ns_down = navs.down();
    in.ns_left = navs.left();
    in.ns_right = navs.right();
    in.ns_center = navs.center();
    //*****************
    // TODO: Implement
    //*****************
    
    //Buttons Read
    //1. Read the three action buttons from GameInputs in 
    //   Hint: Low voltage means "pressed"
    
    //NavSwitch Read
    //2. Read navigation switch buttons from GameInputs in
    //   (up,down,left,right,center)
    


    //For debugging inputs
    #ifdef F_DEBUG
        pc.printf("Inputs: %d %d %d | %f %f %f | %d %d %d %d %d \r\n", in.b1, 
                                                                    in.b2, 
                                                                    in.b3, 
                                                                    in.ax, 
                                                                    in.ay, 
                                                                    in.az, 
                                                                    in.ns_up, 
                                                                    in.ns_down, 
                                                                    in.ns_left, 
                                                                    in.ns_right, 
                                                                    in.ns_center);
    #endif


    wait(0.02); //For simple debouncing
    return in;
}
