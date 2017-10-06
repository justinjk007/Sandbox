/*
 * Author : Justin Kaipada
 * Purpose: The script here runs in the audrino IDE
 * and is used to run stepper motors from initial position until
 * STEPS_COVERED is reached and then return back to the original
 * position it started from. This was written to power a camera
 * slider that was made using an audrino.
 **/
#include <Stepper.h>

const int stepsPerRevolution = 200;

// Initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
bool direction = true;
int steps_cw   = 0;
int steps_ccw  = 0;

const int STEPS_COVERED = 10;  // Change this variable to chnage the
                               // number of steps taken by the stepper
                               // motor

void setup()
{
    myStepper.setSpeed(60);  // Set the speed at 60 rpm:
    Serial.begin(9600);      // Initialize the serial port:
}

void loop()
{
    if (direction) {
        // Step clockwise direction
        Serial.println("clockwise");
        myStepper.step(stepsPerRevolution);
        steps_cw++;
        if (steps_cw >= STEPS_COVERED) {
            direction = false;
            steps_ccw = steps_cw;
        }
    } else {
        // Step anti-clockwise direction
        Serial.println("counterclockwise");
        myStepper.step(-stepsPerRevolution);
        steps_ccw--;
        if (steps_ccw <= 0) {
            // Exit when the initial position is reached
            exit(0);
        }
    }
}
