#include "MicroBit.h"
#include <string>
#include <map>

MicroBit uBit;
MicroBitDisplay display;
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);

uint64_t delta =0;
uint64_t temp =0;
char long_msg[20][6];
char msg[6];
int lmsg_id=0;
int msg_id=0;
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
//clearMsg function
//using it to reset array for char or array for word
//e.g. array msg[] contains the morse code - clear it for the new char moresecode when past is submitted
//array long_msg[] contains chars - that are forming word
void clearMsg(int m){
	if(m==1){
		for(int i=0;i<6;i++)
			msg[i]=NULL;
		msg_id=0;
	}else{
		for(int i=0;i<20;i++)
			for(int j=0;j<6;j++)
				long_msg[i][j]=NULL;
		lmsg_id=0;
	}
}
//function ifExist
//using it to check if the morse code inputted from the user exist
bool ifExist(char code[6]){
	//if(MORSE_CODE_LOOKUP.find(code)->first.size()>0 && MORSE_CODE_LOOKUP.find(code)->first.size()<6)
	if(MORSE_CODE_LOOKUP.find(code) != MORSE_CODE_LOOKUP.end())
		return true;
	else{
		uBit.display.scroll("Wrong");
		clearMsg(1);
		return false;
	}
}
//function decode
//uing this function to decode the actual morsecode
char decode(char code[6]){
		return MORSE_CODE_LOOKUP.find(code)->second;
}

//function send()
//using it to send the impulses (times) to the other Microbit
void send(){
	for(int i=0;i<lmsg_id;i++){//chars loop
		int a = MORSE_CODE_LOOKUP.find(long_msg[i])->first.size();
		for(int j=0;j<a;j++){//morse code loop
			uBit.io.P1.setDigitalValue(1);
			if(long_msg[i][j]=='.')
				uBit.sleep(50);
			else
				uBit.sleep(100);
			uBit.io.P1.setDigitalValue(0);
			uBit.sleep(200);

		}
		uBit.sleep(400);
	}
}
//addToLong function
//this function is a feature
//when char is successfully submited Im adding it to array of chars to form a word
void addToLong(char code[6]){
	for(int i=0;i<MORSE_CODE_LOOKUP.find(code)->first.size();i++)
		long_msg[lmsg_id][i]=msg[i];
	lmsg_id++;
}

//lengthCode
//this function is a feature
//helping the user by visualising how ong he get with the morse code
//first line of the LED matrix inform user how many "dots" or "dashes" already input
void lengthCode(int id){
	for(int i=0;i<id;i++)
		uBit.display.image.setPixelValue(i,0,255);
}


int main(){

uBit.init();
bool pressedA = false;
bool pressedB = false;


	//Initialization of Display
	uBit.init();
	uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);
      while (1) {
	//starting a timer
        temp = system_timer_current_time();
	//using while loop, so detect the actual holding
	while(uBit.buttonA.isPressed())
	{
		pressedA = true;
	}
 	if(pressedA)
	{	//getting the difference and find out the holding time
		delta = system_timer_current_time() - temp;
		if(delta<=250){
			uBit.display.image.setPixelValue(2,2,255);
			lengthCode(msg_id);
			msg[msg_id]='.';
		}
		else{
			if(delta>250 && delta<500){
				uBit.display.print("-");
				msg[msg_id]='-';
			}
		}


		if(delta<500){
			msg_id++;
			uBit.sleep(100);
			uBit.display.clear();
			lengthCode(msg_id);

		}
	}
	pressedA = false;
	//--------------------------------------------------------------

	//using while loop, so detect the actual holding
	while(uBit.buttonB.isPressed())
	{
		pressedB = true;
	}
 	if(pressedB)
	{
		//getting the difference and find out the holding time
		delta = system_timer_current_time() - temp;
		if(delta<=250){
			if(lmsg_id<5){
				if(ifExist(msg)){
					addToLong(msg);
					uBit.display.scroll(decode(msg));

					clearMsg(1);
				}
			}
			else{
				uBit.display.scroll("Max 5");

				msg_id=0;
			}
		}
		else{
			if(delta>250 && delta<500){
				send();
				for(int i=0;i<lmsg_id;i++){
					uBit.display.scroll(decode(long_msg[i]));
				}
				clearMsg(2);

			}
		}
		if(delta<500){
			uBit.sleep(100);
			uBit.display.clear();
		}
	}
	pressedB = false;
      }

}
