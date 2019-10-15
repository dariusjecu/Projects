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

    char * const cypher = "UNIVERSITYABCDFGHJKLMOPQWX";
    printf("Message: ");
    char * message=getString();

    for(int i=0;i<strlen(message);i++)
    {
        if(message[i]>='a'&&message[i]<='z')
          message[i]=cypher[message[i]-32-'A'];
        else
          if(message[i]>='A'&&message[i]<='Z')
            message[i]=cypher[message[i]-'A'];
    }

    printf("Cipher: %s\n",message);

    return 0;
}
