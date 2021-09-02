/*
Author: Aswath S

Descrption:
This library is intended to facilitate the conversion of 
any type to array of unit_8 and vice versa. This aims at
converting big numbers to be transported via interfaces 
which can transmit data in only EIGHT bits i.e., a byte.

Written in C, supports both C and CPP;

Example usage: 
1.  A 4 byte wide data is packed in an array single byte 
    with size FOUR. 
2.  An array of single byte data with size two is
    reconstructed as 2 byte wide data.
(Also check example.cpp)
Note: 1. Currently the project supports only unsigned numbers.
      2. Only 32 bit is supported so far.
*/

#ifndef CONVERTOR
#define CONVERTOR
#include <iostream>
using namespace std;
#ifdef __cplusplus
extern "C" {
#endif

/*
@brief : This function converts any unsigned integer to an
         array of single byte values
@return: None
@parms : 1. Copy of the variable to get converted.
         2. Address of the uint8_t array.
*/
void IntoUint8_t(const uint32_t bigVariable,  uint8_t *const ptr)
{
    // You cannot change the pointer ptr, but can change the value pointed by ptr.
    uint8_t bigVarSize=sizeof(bigVariable);
    for(uint8_t i=0;i<bigVarSize;i++)
    {
        ptr[i]=(bigVariable>>i*8)&0xff;
    }
}

/*
@brief : This function converts an array of uint8_t to
         uint32_t. Capture the bytes properly in the 
         calling statement.
@return: Copy of the reconstructed value in uint32_t type.
@parms : 1. Address of the uint8_t array.
*/
uint32_t Reconstruct(const uint8_t *const ptr)
{   
    //You can neither change the value pointed by ptr nor the pointer ptr.
    uint32_t bigVariable;
    uint8_t bigVarSize=sizeof(bigVariable);
    bigVariable=0;
    for(uint8_t i=0;i<bigVarSize;i++)
    {
       bigVariable|=ptr[i]<<i*8;
    }
    return bigVariable;
}
#ifdef __cplusplus
}
#endif

#endif