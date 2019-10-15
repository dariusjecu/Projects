/**
 * File: main.cpp
 * Author: Darius Jecu
 * Date: 17-10-2017
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

static const char alpha[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/**
 * main routine, implements ...
 * @return      success
 */
int main(int argc,char **argv) {
    // your  code begins here

    if(argc!=2)
    {
      printf("usage:%s rotation\n", argv[0]);
      exit(1);
    }
    int rotation= atoi(argv[1]);
    if(rotation>26||rotation<1)
    {
      printf("usage:%s rotation\n", argv[0]);
      exit(1);
    }
    printf("Normal: ");
    char * message=getString();
    for(int i = 0; i < strlen(message); i++)
    {
      if(message[i]>='a'&&message[i]<='z')
        message[i]=message[i]-32;
      if(message[i]>='A'&&message[i]<='Z')
        {
          message[i] = message[i] + rotation%26;
          if(message[i]>'Z')
            message[i]=message[i]-26;
        }
      else
        message[i] = ' ';
    }

    printf("%s\n", message);


    return 0;
}
