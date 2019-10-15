struct Stack {
    int * stack;
    int size;
    int top = -1;

    Stack (int s);
    void push (int v);
    int pop();

};
