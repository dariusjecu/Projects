/**
 * File: main.cpp
 * Author: Darius Jecu
 * Date: 26-11-2017
 * Desc:
 * Copyright: University of West of England 2017
 */
 #include <stdio.h>
 #include "Board.h"

 // include the UFCFGL301's standard library
 #include <ufcfgl-30-1.h>

 // uncomment if you want to use the graphics library
 //#include <graphics.h>

 using namespace uwe;

 int main(void) {

     Board gameBoard;

     gameBoard.Score = 0;
     gameBoard.Begin(); //initialize each value in the board with 0
     gameBoard.Bool(); //initialize each value in the bool array with 0
     int nrGuess;
     nrGuess=gameBoard.Guess(); //put 2 or 4 into the variable nrGuess
     gameBoard.Empty(nrGuess); //put the first value on the bord
     nrGuess=gameBoard.Guess();
     gameBoard.Empty(nrGuess);//put the second value on the bord
     gameBoard.Display(); //print the board;
     printf("\n");

     while(1) //use a loop to do more than 1 move
       if(gameBoard.Full()==1) //verify if there are any empty place to put the next value on the board
     {
         if(gameBoard.Score<2048)
         {
           gameBoard.Flow(); //moves the values inside the board by pressing  arrow keys
           nrGuess=gameBoard.Guess();
           gameBoard.Empty(nrGuess); //introduce a new value on the board
           gameBoard.Display(); //print the board after every arrow key press
         }
         else
           {
             gameBoard.Display_Win(); //display win screen if the score is higher than 2048 or equal
             break;
           }
     }
       else
     {
       gameBoard.Display_Lose(); //display win screen if there are no space for another value to put on board
       break;
     }

     return 0;
 }
