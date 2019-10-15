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
  int red;
  int green;
  int blue;
};


struct Rect
{
  int x;
  int y;
  int width;
  int height;
  int red;
  int green;
  int blue;
};


union Shape
{
  Circle circle;
  Rect rect;
};


int randomize(int x)
{
  return rand()%x;
}


void DrawShape(int draw,Shape shape)
{
    if(draw==2)
  {
    setColour(shape.rect.red,shape.rect.green,shape.rect.blue);
    drawFilledRect(shape.rect.x,shape.rect.y,shape.rect.width,shape.rect.height);
  }
  else if(draw==1)
  {
    setColour(shape.circle.red,shape.circle.green,shape.circle.blue);
    drawFilledCircle(shape.circle.x,shape.circle.y,shape.circle.radius);
  }
}


bool paused=false;

int main(void) {

    initialiseGraphics(WINDOW_WIDTH,WINDOW_HEIGHT);
    int draw=0;
    Shape previouShape[99999];
    int top=0;
    loop(
      [&](){
        for(int i=0;i<top;i++)
        {
          Shape shape=previouShape[i];
          DrawShape(draw,shape);
        }

        Shape newShape;
        if(paused){
          setColour(255,255,255);
          setFontSize(72);
          drawText("Paused",2,2,800,72);
        }
        else if(draw==1)
        {
        newShape.circle.x=randomize(WINDOW_WIDTH);
        newShape.circle.y=randomize(WINDOW_HEIGHT);
        newShape.circle.radius=randomize(150);
        newShape.circle.red=randomize(255);
        newShape.circle.green=randomize(255);
        newShape.circle.blue=randomize(255);
        }
        else if(draw==2)
        {
        newShape.rect.x=randomize(WINDOW_WIDTH);
        newShape.rect.y=randomize(WINDOW_HEIGHT);
        newShape.rect.width=randomize(200);
        newShape.rect.height=randomize(200);
        newShape.rect.red=randomize(255);
        newShape.rect.green=randomize(255);
        newShape.rect.blue=randomize(255);
        }
        previouShape[top++]=newShape;
      },
      [&](KeyPress g){
        if(g.getTextCharacter()=='c'){
              draw=1;
            }
        else if(g.getTextCharacter()=='r'){
              draw=2;
          }
        else if(g.getTextCharacter()=='p'){
          paused = !paused;
        }
        else if(g.getTextCharacter()=='q'){
          return true;
          }
          return false;
        }
    );

    return 0;
}
