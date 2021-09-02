### To clone the repo:
```
https://github.com/the-binaryElf/The_8bit_Convertor.git
```

**Features:**  
* Written in C, supports both C and CPP;
* [Header-Only library.](https://en.wikipedia.org/wiki/Header-only)
    (Just download include the *[Conversion.h](https://raw.githubusercontent.com/the-binaryElf/The_8bit_Convertor/main/Convertor.h)* file and you are ready to go.)
    
**Example usage:**  
    
1.  A 4 byte wide data is packed in an array single byte 
    with size FOUR. 
    ```c++
    uint32_t var32 {0xabcdef98};
    uint8_t uint8_tArray[4];
    IntoUint8_t(var32,
                uint8_tArray);
    ```
2.  An array of uint8_t with size two is
    reconstructed as 2 byte wide data.
      ```c++
      uint16_t new16bit{static_cast<uint16_t>(
          Reconstruct(uint8_tArray))};
      ``` 
   Also check example.cpp and convertor.h file for more detailed usage explanation.  

**Note:**
 * Currently the project supports only __unsigned__ numbers.  
 * Only upto **32 bit** (uint32_t) is supported so far.
