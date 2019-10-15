/**
 * File: main.cpp
 * Author: Darius Jecu
 * Date: 12-10-2017
 * Desc:
 * Copyright: University of West of England 2017
 */
#include <stdio.h>

// include the UFCFGL301's standard library
#include <ufcfgl-30-1.h>

// uncomment if you want to use the graphics library
//#include <graphics.h>

using namespace uwe;

/**
 * main routine, implements ...
 * @return      success
 */

int prime(int x)
{

  if(x<2 || x>2 && x%2==0)
    return 0;
  else
    for(int d=3;d*d<=x;d=d+2)
      if(x%d==0)
        return 0;
  return 1;

}

int main(void) {
    // your  code begins here

    printf("\n");
    printf("I want to know if X is a prime number\n");
    int x=13;
    printf("X=%d\n", x);
    if(prime(x)==1)
    {
      printf("%d ", x);
      printf("is a prime number\n");
    }
    else
    {
      printf("%d ", x);
      printf("is not a prime number\n\n");
    }
    printf("Hello world\n\n");

    return 0;
}
