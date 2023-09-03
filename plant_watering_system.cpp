# include "mbed.h"


//   define the port of MCU to use for water pump
DigitalOut motor(D4);
//   define the interval you want to water the plant
int wait_time = 24 * 60 * 60;   //one day


int main(){
    /*   turn on the motor for a short time so that water can reach the end of the tube
         because we don't need too much water for our plant so after that each time the motor 
         will pump water again he doesn't need to carry the water for the entire tube
         
         This depends on the length of your tube (i use 1 meter)*/
    motor = 0;
    wait_ms(500);
    motor = 1;

    while(1) {
        /* set the time in ms depending on the quantity of water you want for the plant
        ex: if my motor pumps 1.2 l/minute that means 1200 ml / 60 seconds
        => 20 ml / second
        I want only 5 ml so for me the time when motor is on = 250ms */

        motor = 0;
        wait_ms(250);
        motor = 1; 

        //   wait for one day
        wait(wait_time);     
        
    }
}