#include "stack.h"
#include "expression.h"
#include <stdio.h>

Stack::Stack (int s) {
stack =new int(s);
size =s;
}
void Stack ::push (int v){
  top+=1;
  stack [top] =v;
}

int Stack::pop(){
  top-=1;
return stack[top+1];
}
