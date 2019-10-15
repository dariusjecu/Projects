
class Board { // initialize all variables and all functions for the game board

   static const int WIDTH = 4;
   static const int HEIGHT = 4;
   static const int EMPTY = 0;

   int board[WIDTH][HEIGHT],board_bool[WIDTH][HEIGHT];

 public:

   int Score;
   void Begin();
   int Guess();
   void Bool();
   void Empty(int guess);
   void Flow();
   void Print();
   void Print_Bool();
   void BoardEmpty();
   void Display();
   int Full();
   void Display_Win();
   void Display_Lose();

};
