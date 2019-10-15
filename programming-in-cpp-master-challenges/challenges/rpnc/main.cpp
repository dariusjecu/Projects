/**
 * File: main.cpp
 * Author: Darius Jecu
 * Date: 12-11-2017
 * Desc:
 * Copyright: University of West of England 2017
 */
 #include <stdio.h>
 #include "stack.h"
 #include <unistd.h>
 #include <string.h>
 // include the UFCFGL301's standard library
 #include <ufcfgl-30-1.h>

 // uncoment if you want to use the graphics library
 //#include <graphics.h>

 using namespace uwe;




 int main (int argc, char **argv) {


   int stackSize = 10;
   char temp;
   char *fileLocation = NULL;
   int errorCheck = 0;
   while((temp = getopt(argc, argv, "f:s:")) != -1)  {
     switch(temp)
     {
       case 'f':
         fileLocation = optarg;
         break;
       case 's':
           stackSize = atoi(optarg);
           break;
       case ':':
               printf("argument not found\n");
               errorCheck=1;
               break;
       case '?':
         printf("Unrecognished Input\n");
         errorCheck=1;
         break;

       default :
           errorCheck=1;
           break;


     }
   }
   if(errorCheck != 0)
   {
     printf("error found, exiting");
     return 0;
   }

   Stack stack (stackSize);


   char * str;
   if(!fileLocation)
   {
     printf("enter an expression:");
     str = getString();
   }
   else
   {
     str = const_cast<char *>(readFile(fileLocation).c_str());
   }
   while (*str != '\0') {
     if (isdigit(*str)){
       int temp =getInt(str);
       while(*str!=' '){
         str++;
       }
       stack.push(temp);

     }
     else {
       if (*str == '+') {
         int b = stack.pop();
         int a = stack.pop();
         stack.push(a+b);
       }
       if (*str == '*') {
         int b = stack.pop();
         int a = stack.pop();
         stack.push(a*b);
       }
       if (*str == '/') {
         int b = stack.pop();
         int a = stack.pop();
         stack.push(a/b);
       }
       if (*str == '-') {
         int b = stack.pop();
         int a = stack.pop();
         stack.push(a-b);
       }
       str++;
     }
   }
   printf("result: %d\n",stack.pop());
   return 0;
 }
