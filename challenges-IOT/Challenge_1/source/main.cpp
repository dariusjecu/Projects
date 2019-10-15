/**
 * File: main.cpp
 * Author: Darius Jecu
 * Date: 08-02-2019
 * Desc: Challenge 1
 * Copyright: University of West of England 2017
 */
#include "MicroBit.h"

MicroBit uBit;

struct point {
    int x;
    int y;
};

  int projectiles = 13;
  int quit = 0;
  point player;

void onButtonA(MicroBitEvent){   //Shoot the leds
        if(uBit.display.image.getPixelValue(player.x,1) == uBit.display.image.getPixelValue(player.x,player.y)){     // Finds first the led which is the closest one for player
          quit +=1;
          uBit.display.image.setPixelValue(player.x,3,255);       //If is on coordinates x = player.x, y = 1, then the player will "shoot" and turn off the led
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,3,0);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,2,255);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,2,0);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,1,0);
        }
        else if(uBit.display.image.getPixelValue(player.x,0) == uBit.display.image.getPixelValue(player.x,player.y)) {  // If the led on the coordinate y = 1 is turned off then
                                                                                                                        // it goes on the next one which is y = 0
          quit +=1;
          uBit.display.image.setPixelValue(player.x,3,255);       // If is on coordinates x = player.x, y = 0, then the player will "shoot" and turn off the led
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,3,0);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,2,255);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,2,0);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,1,255);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,1,0);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,0,0);
        }
        else
        {
          uBit.display.image.setPixelValue(player.x,3,255);     // Just the animation for the "laser" when no led reamains on that column
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,3,0);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,2,255);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,2,0);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,1,255);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,1,0);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,0,255);
          uBit.sleep(50);
          uBit.display.image.setPixelValue(player.x,0,0);
        }
        projectiles -= 1;
}

void onButtonB(MicroBitEvent){  //Move the player
      if(player.x == 4){       // If the player is situated on the coordinate x = 4, he can not go further so he need to go back on coordinate x = 0;
        uBit.display.image.setPixelValue(player.x,player.y,0);
        player.x = 0;
        uBit.display.image.setPixelValue(player.x,player.y,255);
      }
      else {        // Else it goes to the right
        uBit.display.image.setPixelValue(player.x,player.y,0);
        player.x += 1;
        uBit.display.image.setPixelValue(player.x,player.y,255);
      }
}

void initialization() {

  uBit.display.scroll("HELLO");
  uBit.display.scroll("YOU HAVE");
  uBit.display.scroll(projectiles);
  uBit.display.scroll("PROJECTILES");

  // Turn on the first 2 rows of leds

  for(int i = 0; i <= 4; i++){
    for(int j = 0; j <= 1; j++){
      uBit.display.image.setPixelValue(i,j,255);
    }
  }

  // Turn on the first 2 rows of leds
}

void game_over(){        //finish the game
    if(quit == 10){          //if all the leds were turned off except the player, win the game
      uBit.display.scroll("YOU WIN");
    }
    else{            //else lose the game
      uBit.display.scroll("YOU LOSE");
    }
}

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    initialization();



    // Set the position of the player

    player.x = 2;
    player.y = 4;
    uBit.display.image.setPixelValue(player.x,player.y,255);

    // Set the position of the player


    // Game begins
    // Button B moves the player on the right everytime when the button is pressed
    // Button A shoots "lasers" to switch off the leds

    while(quit != 10 && projectiles > 0){
        if(uBit.buttonB.isPressed()){
          uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);   // When the Button B is pressed it will call onButtonB function
        }
        if(uBit.buttonA.isPressed()){
          uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);   // When the Button A is pressed it will call onButtonA function
        }
        uBit.sleep(100);     // Set a delay time between 2 buttons pressed
    }

    game_over();

    // If main exits, there may still be other fibers running or
    // registered event handlers etc.
    // Simply release this fiber, which will mean we enter the
    // scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
