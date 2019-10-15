/**
 * File: pairing.cpp
 * Author: Darius Jecu
 * Date: 25-03-2019
 */

#include "MicroBit.h"
#include "pairing.h"

PairingClass::PairingClass() {
  //Constructor
}

int PairingClass::randomInt(int min, int max, uint64_t sysTime) {
 srand(sysTime); //Use current system up time as random seed
 int returnVar = rand() % max + min; //Generate random number
 return returnVar;
}

ManagedString PairingClass::dataString(int newGroup, int newFrequency, const char* delimiter) {
  //Convert variables to correct types
  ManagedString newGroupStr = newGroup;
  ManagedString newFrequencyStr = newFrequency;
  ManagedString delimiterStr = delimiter;
  //Concatenate variables
  ManagedString returnVar = newGroupStr + delimiterStr + newFrequencyStr + delimiterStr;
  return returnVar;
}
