
#include <stdio.h>
#include "Board.h"
#include <cmath>
#include <ufcfgl-30-1.h>

void Board::Begin() // initialize an empty array which is the board
{
  for(int x=0;x<WIDTH;x++)
  for(int y=0;y<HEIGHT;y++)
    board[x][y]=EMPTY;
}

void Board::Bool() // initialize an empty bool array with 0
{
  for(int x=0;x<WIDTH;x++)
  for(int y=0;y<HEIGHT;y++)
    board_bool[x][y]=false;
}

int Board::Guess() //this function will return 2 or 4
{
  int x=rand()%100;
  if(x<90)
  return 2;
  else
  return 4;
}

int Board::Full() //verify if there are any empty place to put the next value on the board
{
  int k=0;
  for(int x=0;x<WIDTH;x++)
  for(int y=0;y<HEIGHT;y++)
   if(board[x][y]==0)
    {
      k=1;
      break;
    }
  return k;
}

void Board::Empty(int guess) //put the number into an empty position in array
{
  int x,y,numberFound;
  numberFound=false;
  while(!numberFound)
  {
    x=rand()%4;
    y=rand()%4;
    if(board[x][y]==0)
    {
      board[x][y]=guess;
      numberFound=true;
    }
  }
}

void Board::Flow(){ //move the values inside the game board by pressing arrow keys
    Bool();
    if (uwe::getch() == '\033') {
        {
        uwe::getch();
        switch(uwe::getch()) {
          case 'A':   // move up
            for(int x=0;x<4;x++)
              for (int r = 0; r < 3; r++) {
                for(int y=0;y<3;y++)
                {
                  if ((board_bool[y][x] == false) && (board_bool[y+1][x] == false) && (board[y+1][x] != 0) &&
                      (board[y][x] == board[y+1][x] || board[y][x] == 0)) {
                    if (board[y][x] == board[y+1][x]) {
                      board_bool[y][x]=true;
                      Score += board[y][x]+board[y+1][x];
                    }
                    board_bool[y+1][x]=false;
                    board[y][x] += board[y+1][x];
                    board[y+1][x]=0;
                  }
              }
            }break;
          case 'B':   // move down
            for(int x=0;x<4;x++)
              for (int r = 0; r < 3; r++){
                for(int y=3;y>0;y--)
              {
                  if ((board_bool[y][x] == false) && (board_bool[y-1][x] == false) && (board[y-1][x] != 0) &&
                    (board[y][x] == board[y-1][x] || board[y][x] == 0)) {
                  if (board[y][x] == board[y-1][x]) {
                    board_bool[y][x]=true;
                    Score += board[y][x]+board[y-1][x];
                  }
                  board_bool[y-1][x]=false;
                  board[y][x] += board[y-1][x];
                  board[y-1][x]=0;
                }
              }
            }break;
          case 'C':   // move right
            for(int x=0;x<4;x++)
              for (int r = 0; r < 3; r++){
   						     for(int y=3;y>0;y--)
   						{
                  if ((board_bool[x][y] == false) && (board_bool[x][y-1] == false) && (board[x][y-1] != 0) &&
                    (board[x][y] == board[x][y-1] || board[x][y] == 0)) {
                  if (board[x][y] == board[x][y-1]) {
                    board_bool[x][y]=true;
                    Score += board[x][y]+board[x][y-1];
                  }
                  board_bool[x][y-1]=false;
                  board[x][y] += board[x][y-1];
                  board[x][y-1]=0;
                  }
   						}
            }break;
          case 'D':   // move left
            for(int x=0;x<4;x++)
            for (int r = 0; r < 3; r++){
              for(int y=0;y<3;y++)
              {
                  if ((board_bool[x][y] == false) && (board_bool[x][y+1] == false) && (board[x][y+1] != 0) &&
                    (board[x][y] == board[x][y+1] || board[x][y] == 0)) {
                  if (board[x][y] == board[x][y+1]) {
                    board_bool[x][y]=true;
                    Score += board[x][y]+board[x][y+1];
                  }
                  board_bool[x][y+1]=false;
                  board[x][y] += board[x][y+1];
                  board[x][y+1]=0;
                }
              }
            }break;
         }
       }
     }
}

void Board::Display() //print the game board
{
	system("clear");

		printf("\n    <[  The 2048 Game  ]>\t\t\t\t\n\n\t");
		printf("\t\t\t\t\t\tSCORE::");
    printf("%i", Score);
    printf(" \n\n\n\n");

				for(int i=0;i<4;i++)
				{
				printf("\t\t     |");

					for(int j=0;j<4;j++)
					{
						if(board[i][j])
							printf("%4d    |",board[i][j]);
						else
							printf("%4c    |",' ');
					}

				printf("\n\n");
				}

		printf("\n\n Controls: \t\t\t\t\t\n\n\t^\t\t\t\t\n\t\t\t\t\t\t\t\t");
		printf(" \n   <    v    >\t\t");
		printf(" \n\t\t\t\t ");

}

void Board::Display_Win() //print the win screen
{
	system("clear");

	printf("\n\n");
	printf("\n\n\n\n\n\n\t\t\t  :: [ YOU WON THE GAME ] :: \n\n\n\n");

}

void Board::Display_Lose() //print the lose screen
{
	system("clear");

	printf("\n\n");
	printf("\n\n\n\n\n\n\t\t\t  :: [ GAME OVER ] :: \n\n\n\n");

}

void Board::Print_Bool()
{
  for(int x=0;x<4;x++)
    {
      for(int y=0;y<4;y++)
      printf("%i",board_bool[x][y]);
      printf("\n");
    }
}
