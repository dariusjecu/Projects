/**
 * File: main.cpp
 * Author: Darius Jecu
 * Date: 20-10-2017
 * Desc:
 * Copyright: University of West of England 2017
 */
 #include <stdio.h>
 #include <cstring>
 #include <unistd.h>
 #include <crypt.h>
 // include the UFCFGL301's standard library
#include <ufcfgl-30-1.h>

// uncomment if you want to use the graphics library
//#include <graphics.h>

using namespace uwe;

/**
 * main routine, implements ...
 * @return      success
 */

void crackPassword(char * password,char * salt);

const char alpha[]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int main(int argt, char ** argv) {

   if(argt!=3){
    printf("Usage: %s hash\n", argv[0]);
    return 1;
    }
  crackPassword(argv[1],argv[2]);
  return 0;
 }

void crackPassword(char * hash,char * salt){

  char passGuess[5]={'\0'};
  size_t length=strlen(alpha);
  for(size_t a=0; a<length; a++){
    passGuess[0]=alpha[a];
    for(size_t b=0; b<length; b++){
      passGuess[1]=alpha[b];
      for(size_t c=0; c<length; c++){
        passGuess[2]=alpha[c];
        for(size_t d=0; d<length; d++){
          passGuess[3]=alpha[d];
          char * newHash=crypt (passGuess,salt);
          if(strcmp(hash,newHash)==0){
              printf("Cracked: %s\n",passGuess);
              return;
            }
        }
      }
    }
  }
}
