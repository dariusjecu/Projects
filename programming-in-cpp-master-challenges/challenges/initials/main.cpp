/**
 * File: main.cpp
 * Author: Darius Jecu
 * Date: 19-10-2017
 * Desc:
 * Copyright: University of West of England 2017
 */
#include <stdio.h>
#include <cstring>
// include the UFCFGL301's standard library
#include <ufcfgl-30-1.h>

// uncomment if you want to use the graphics library
//#include <graphics.h>

using namespace uwe;

/**
 * main routine, implements ...
 * @return      success
 */
int main(void) {
    // your  code begins here

    printf("Enter your name: ");
    char * name=getString();
    int i=0;
    if(name[i]!=' ')
      printf("%c",name[i]);

    for(int i=0;i<strlen(name)-1;i++)
      {
        if(name[i]==' ' && name[i+1]!=' ')
        printf("%c", name[i+1]);
      }
      printf("\n\n");

    return 0;
}
