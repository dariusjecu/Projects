#include "MicroBit.h"
#include <map>
#include <vector>

MicroBit uBit;

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

//function decode
//uing this function to decode the actual morsecode
char decode(char code[6]){
		return MORSE_CODE_LOOKUP.find(code)->second;
}
//function prints
//printing the message
void prints(){
	for(int i=0;i<ch+1;i++){
		uBit.display.scroll(decode(long_msg[i]));
	}
	fill(a.begin(), a.end(), 0);
	fill(b.begin(), b.end(), 0);

	memset(long_msg, 0, 120);

}
//function receive
//working out the times and sort the "dots" and "dashes" in arrays forming a morse code and chars
void receive(){
	for(int i=0;i<a.size();i++){
		if(b.at(i) >= 100 && b.at(i) <= 250){//new "dot" or "dash" is comming
			mc++;
			if(a.at(i)>=50 && a.at(i) <= 60){
				long_msg[ch][mc]='.';
			}else
				long_msg[ch][mc]='-';
		}else
		if((b.at(i) >= 251) && b.at(i) <= 999){//new char is comming
			ch++;
			mc=0;
			if(a.at(i)>=50 && a.at(i) <= 60){
				long_msg[ch][mc]='.';
			}else
				long_msg[ch][mc]='-';
		}else{
		//reset - new word is coming
			memset(long_msg, 0, 120);
			ch=0;
			mc=0;
			if(a.at(i)>=50 && a.at(i) <= 60){
				long_msg[ch][mc]='.';
			}else
				long_msg[ch][mc]='-';
		}

	}
	prints();
}

int main(){
	//Initialization of Display
	uBit.init();
	uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);

	int i = 1;
	bool signal = false;
	bool once = true;
	bool finished = false;
	while (1) {
		if(once){
			//start a timer in the begining - one time only (not affected by while1)
			//using this temp timer later to find the time that the signal was off
			temp_no = system_timer_current_time();
			once = false;
		}
		//start a timer in the begining - evry time
		//using this temp timer later to find the time that the signal was on
		temp = system_timer_current_time();
		while(uBit.io.P1.getDigitalValue()==1){
			if(!once){
				//When signal detected get the time that signal was off
				delta_no = system_timer_current_time() - temp_no;
				if(delta_no >= 251 && delta_no <= 999)
					i++;//countint how many chars are in the message
				once=true;
			}
			signal = true;

		}
		if(signal){
			//When signal stops again - get the time while the signal was on
			delta = system_timer_current_time() - temp;
			//now I have both times - while signal was ON and while signal was OFF
			//add them to vectors
			a.push_back(delta);
			b.push_back(delta_no);
			signal = false;
			finished = true;
		}else{
			int hold = system_timer_current_time() - temp_no;
			if(hold > 1000*i){//1sec * the number of chars in the message (need more time for sending if more chars)
				if(finished){
					receive();
					a.clear();
					b.clear();
					finished = false;
					i = 1;
				}
			}
		}
	}

}
