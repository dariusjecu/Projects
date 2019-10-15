int delta =0;
int delta_no =0;
int temp =0;
int temp_no =0;

vector<short> a;
vector<short> b;

char long_msg[20][6];
int ch=0;
int mc=0;

//map holding chars morse code
//using it to decode and find chars
map<string,char> MORSE_CODE_LOOKUP{
   {".-",'A'},
   {"-...",'B'},
   {"-.-.",'C'},
   {"-..",'D'},
   {".",'E'},
   {"..-.",'F'},
   {"--.",'G'},
   {"....",'H'},
   {"..",'I'},
   {".---",'J'},
   {"-.-",'K'},
   {".-..",'L'},
   {"--",'M'},
   {"-.",'N'},
   {"---",'O'},
   {".--.",'P'},
   {"--.-",'Q'},
   {".-.",'R'},
   {"...",'S'},
   {"-",'T'},
   {"..-",'U'},
   {"...-",'V'},
   {".--",'W'},
   {"-..-",'X'},
   {"-.--",'Y'},
   {"--..",'Z'},
   {".----",'1'},
   {"..---",'2'},
   {"...--",'3'},
   {"....-",'4'},
   {".....",'5'},
   {"-....",'6'},
   {"--...",'7'},
   {"---..",'8'},
   {"----.",'9'},
   {"-----",'0'}
};

char decode(char code[6]);

void prints();

void receive()

void clearMsg(int m);

bool ifExist(char code[6]);

char decode(char code[6]);

void send();

void addToLong(char code[6]);

void lengthCode(int id);
