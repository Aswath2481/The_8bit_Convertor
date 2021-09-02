/*
This program demostrates the conversion capability of this library.
Feel free to play with it :P 

Even though the current program is written in CPP, the library
can still work fine with C compilers.
*/
#include <iostream>
#include "Convertor.h"
using namespace std;

int main()
{
  uint32_t var32 {0xabcdef98};
  uint16_t var16 {0xfedc};
  uint8_t var8 {255};
  uint8_t uint8_tArray[4];
  
  // Converts 16bit number to 2*8 bit array
  IntoUint8_t(var16,uint8_tArray);
  //Display
  for(uint8_t i; i<sizeof(var16);i++)
  {
    cout<<"Array ["<<(int)i<< "] => ";
    cout<<hex<<(int)uint8_tArray[i]<<endl;
  }

  //Converts 2*8 bit array to 16bit number
  // One need to mannually typecast it to 16bit as the
  // return type is 32bit.
  uint16_t new16bit{static_cast<uint16_t>(Reconstruct(uint8_tArray))};
  //display
  cout<<endl<<"Reconstructed value is "<<new16bit<<" with size "<< sizeof(new16bit)<<" bytes";
  return 0; 
}