/**
 * File: main.cpp
 * Author: Darius Jecu
 * Date: 26-10-2017
 * Desc:
 * Copyright: University of West of England 2017
 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>

// include the UFCFGL301's standard library
#include <ufcfgl-30-1.h>

// uncomment if you want to use the graphics library
#include <graphics.h>

using namespace uwe;

const uint32 WINDOW_WIDTH = 1200;
const uint32 WINDOW_HEIGHT = 800;

struct Circle
{
  int x;
  int y;
  int radius;
  int deltaX;
  int deltaY;
  int speed;
};


void newCircle(Circle &circle,int rad)
{
  circle.radius=rad;
  circle.x=random()%(WINDOW_WIDTH-rad);
  circle.y=random()%(WINDOW_HEIGHT-rad);
  circle.deltaX=1;
  circle.deltaY=1;
  circle.speed=5;
}


void move(Circle &circle,int color)
{
  circle.x=circle.x+circle.deltaX*circle.speed;
  if(circle.x-circle.radius<0||circle.x+circle.radius>WINDOW_WIDTH)
      {
    circle.deltaX=circle.deltaX*-1;
      }

  circle.y=circle.y+circle.deltaY*circle.speed;
  if(circle.y-circle.radius<0||circle.y+circle.radius>WINDOW_HEIGHT)
      {
    circle.deltaY=circle.deltaY*-1;
      }
  if(color==1)
  setColour(255,0,0);
  else
  if(color==2)
  setColour(0,0,255);
  drawFilledCircle(circle.x,circle.y,circle.radius);
}


void balls(Circle &circle1,Circle &circle2)
{
    if(((circle1.x+circle1.radius>circle2.x-circle2.radius && circle1.x<circle2.x) && (circle1.y+circle1.radius>circle2.y-circle2.radius && circle1.y<circle2.y))
    || ((circle1.x-circle1.radius<circle2.x+circle2.radius && circle1.x>circle2.x) && (circle1.y-circle1.radius<circle2.y+circle2.radius && circle1.y>circle2.y)))
      {
      circle1.deltaX*=-1;
      circle2.deltaX*=-1;
      circle1.deltaY*=-1;
      circle2.deltaY*=-1;
      }
}


int main(void) {

    initialiseGraphics(WINDOW_WIDTH,WINDOW_HEIGHT);

    int color=0;
    Circle circle1;
    Circle circle2;
    Circle circle3;
    newCircle(circle1,35);
    newCircle(circle2,35);
    newCircle(circle3,35);

    loop(
      [&](){

        move(circle1,color);
        move(circle2,color);
        move(circle3,color);
        balls(circle1,circle2);
        balls(circle1,circle3);
        balls(circle2,circle3);

      },
      [&](KeyPress g){
        if(g.getTextCharacter()=='q')
         return true;
        else
        if(g.getTextCharacter()=='r')
         {
           color=1;
           return false;
         }
        else
        if(g.getTextCharacter()=='b')
        {
          color=2;
          return false;
        }
        else
        if(g.getTextCharacter()=='+'&& circle1.radius+10<=120 && circle2.radius+10<=120 && circle2.radius+10<=120)
        {
          circle1.radius+=10;
          circle2.radius+=10;
          circle3.radius+=10;
          return false;
        }
        else
        if(g.getTextCharacter()=='-' && circle1.radius-10>=10 && circle2.radius-10>=10 && circle2.radius-10>=10)
        {
          circle1.radius-=10;
          circle2.radius-=10;
          circle3.radius-=10;
          return false;
        }
        return false;
        }
    );

    return 0;
}
