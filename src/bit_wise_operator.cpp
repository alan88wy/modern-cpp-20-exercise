#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

// Bitwise masking
const unsigned char mask_bit_0 {0b00000001};
const unsigned char mask_bit_1 {0b00000010};
const unsigned char mask_bit_2 {0b00000100};
const unsigned char mask_bit_3 {0b00001000};
const unsigned char mask_bit_4 {0b00010000};
const unsigned char mask_bit_5 {0b00100000};
const unsigned char mask_bit_6 {0b01000000};
const unsigned char mask_bit_7 {0b10000000};

// Color mask
const unsigned int red_mask { 0xFF000000 };
const unsigned int green_mask { 0x00FF0000 };
const unsigned int blue_mask { 0x0000FF00 };
const unsigned int alpha_mask { 0x000000FF };


int main(int argc, char  **argv) {

    unsigned short int data {0b11111110};

    cout << "Original value : " << endl;
    cout << "================ " << endl;
    cout << endl;
    cout << "data (dec) : " << showbase << dec << data << endl;
    cout << "data (hex) : " << showbase << hex << data << endl;
    cout << "data (oct) : " << showbase << oct << data << endl;
    cout << "data (bin) : " << bitset<16>(data) << endl;
    cout << endl;

    // shift operator

    cout << "Shift Operator" << endl;
    cout << "============== " << endl;
    cout << endl;

    data = static_cast<unsigned short int>(data >> 1);  // Right shift
    cout << "data (right shift) : " << bitset<16>(data) << ", dec : " << dec << data << endl;

    data = static_cast<unsigned short int>(data << 1);  // Right shift
    cout << "data (left shift) : " << bitset<16>(data) << ", dec : " << dec << data << endl;

    cout << endl;

    // Logical Bitwise Operators

    const int COLUMN_WIDTH {25};

    unsigned char v1 {0x3};  // 0000 0011
    unsigned char v2 {0x5};  // 0000 0101

    cout << "Logical Bitwise Operator" << endl;
    cout << "========================" << endl;
    cout << endl;

    // Original
    cout << setw(COLUMN_WIDTH) << "Original value : " << endl;
    cout << setw(COLUMN_WIDTH) << "v1 : " << setw(COLUMN_WIDTH) << bitset<8>(v1) << endl;
    cout << setw(COLUMN_WIDTH) << "v2 : " << setw(COLUMN_WIDTH) << bitset<8>(v2) << endl;
    cout << endl;

    // AND
    cout << setw(COLUMN_WIDTH) << "Bitwise AND : " << endl;
    cout << setw(COLUMN_WIDTH) << "v1 & v2 : " << setw(COLUMN_WIDTH) << bitset<8>(v1 & v2) << endl;
    cout << endl;

    // OR
    cout << setw(COLUMN_WIDTH) << "Bitwise OR : " << endl;
    // cout << endl;
    cout << setw(COLUMN_WIDTH) << "v1 | v2 : " << setw(COLUMN_WIDTH) << bitset<8>(v1 | v2) << endl;
    cout << endl;

    // NOT
    cout << setw(COLUMN_WIDTH) << "Bitwise NOT : " << endl;
    // cout << endl;
    cout << setw(COLUMN_WIDTH) << "Not v1 : " << setw(COLUMN_WIDTH) << bitset<8>(~v1) << endl;
    cout << setw(COLUMN_WIDTH) << "Not v2 : " << setw(COLUMN_WIDTH) << bitset<8>(~v2) << endl;
    cout << endl;

     // XOR
    cout << setw(COLUMN_WIDTH) << "Bitwise OR : " << endl;
    // cout << endl;
    cout << setw(COLUMN_WIDTH) << "v1 ^ v2 : " << setw(COLUMN_WIDTH) << bitset<8>(v1 ^ v2) << endl;
    cout << endl;

    // Compound Bitwise and Assignment Operators : >>=, <<=, !=, &=, ^=
    cout << "Compound Bitwise and Assignment Operators : >>=, <<=, !|=, &=, ^=" << endl;
    cout << "================================================================" << endl;
    cout << endl;

    // Compound Shift right by 2
    v2 >>=2;
    cout << setw(COLUMN_WIDTH) << "v2 - Shift right by 2 : " << setw(COLUMN_WIDTH) << bitset<8>(v2) << endl;

    //Compound Shift left by 2
    v1 <<=2;
    cout << setw(COLUMN_WIDTH) << "v1 - Shift left by 2 : " << setw(COLUMN_WIDTH) << bitset<8>(v1) << endl;

    unsigned short int mask = 0b01010111;
    cout << setw(COLUMN_WIDTH) << "Mask : " << setw(COLUMN_WIDTH) << bitset<8>(mask) << endl;
    v1 |=mask;
    cout << setw(COLUMN_WIDTH) << "v1 |= 0b00110100 : " << setw(COLUMN_WIDTH) << bitset<8>(v1) << endl;
    v1 &=mask;
    cout << setw(COLUMN_WIDTH) << "v1 &= 0b00110100 : " << setw(COLUMN_WIDTH) << bitset<8>(v1) << endl;
    v1 ^=mask;
    cout << setw(COLUMN_WIDTH) << "v1 ^= 0b00110100 : " << setw(COLUMN_WIDTH) << bitset<8>(v1) << endl;
    cout << endl;

    // Masks
    cout << "Masks" << endl;
    cout << "=====" << endl;
    cout << endl;

    unsigned short int var1 {0b01100001};

    // Set bit position

    cout << setw(COLUMN_WIDTH) << "var1 : " << setw(COLUMN_WIDTH) << bitset<8>(var1) << endl;
    cout << setw(COLUMN_WIDTH) << "Mask (Bit 2) : " << setw(COLUMN_WIDTH) << bitset<8>(mask_bit_2) << endl;
    cout << setw(COLUMN_WIDTH) << "Result (!= mask) : " << setw(COLUMN_WIDTH) << bitset<8>(var1 |= mask_bit_2) << endl;

    cout << setw(COLUMN_WIDTH) << "Mask (Bit 3) : " << setw(COLUMN_WIDTH) << bitset<8>(mask_bit_3) << endl;
    cout << setw(COLUMN_WIDTH) << "Result (!= mask) : " << setw(COLUMN_WIDTH) << bitset<8>(var1 |= mask_bit_3) << endl;

    // Reset bit position

    cout << setw(COLUMN_WIDTH) << "Mask (Bit 0) : " << setw(COLUMN_WIDTH) << bitset<8>(~mask_bit_0) << endl;
    cout << setw(COLUMN_WIDTH) << "Result (&=(~mask)) : " << setw(COLUMN_WIDTH) << bitset<8>(var1 &= (~mask_bit_0)) << endl;

    cout << setw(COLUMN_WIDTH) << "Mask (Bit 5) : " << setw(COLUMN_WIDTH) << bitset<8>(~mask_bit_5) << endl;
    cout << setw(COLUMN_WIDTH) << "Result (&=(~mask)) : " << setw(COLUMN_WIDTH) << bitset<8>(var1 &= (~mask_bit_5)) << endl;

    // Reset multiple bits

    cout << setw(COLUMN_WIDTH) << "Mask (Bit 0,2, 6) : " << setw(COLUMN_WIDTH) << bitset<8>(~(mask_bit_0 | mask_bit_2 | mask_bit_6)) << endl;
    cout << setw(COLUMN_WIDTH) << "Result (&=(~mask)) : " << setw(COLUMN_WIDTH) << bitset<8>(var1 &= ~(mask_bit_0 | mask_bit_2 | mask_bit_6)) << endl;

    // Set all bits
    cout << setw(COLUMN_WIDTH) << "Mask  : " << setw(COLUMN_WIDTH) << bitset<8>(mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 | mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7) << endl;
    cout << setw(COLUMN_WIDTH) << "Result (|=mask)) : " << setw(COLUMN_WIDTH) << bitset<8>(var1 |= (mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 | mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7)) << endl;


    // Check bit position
    // first we check if bit 5 is true by using &
    // Then we move the bit to the right 5 position to push it to the end and we get either 0 or 1 depending on whether pos 5 is 0 or 1
    cout << setw(COLUMN_WIDTH) << "var1 : " << setw(COLUMN_WIDTH) << bitset<8>(var1) << endl;
    cout << setw(COLUMN_WIDTH) << "Mask (Bit 5) : " << setw(COLUMN_WIDTH) << bitset<8>(mask_bit_5) << endl;
    cout << boolalpha;
    // cout << setw(COLUMN_WIDTH) << "Result ((& mask) >> 5) : " << setw(COLUMN_WIDTH) << bitset<8>((var1 & mask_bit_5) >> 5) << endl;
    cout << setw(COLUMN_WIDTH) << "Result ((& mask) >> 5) : " << setw(COLUMN_WIDTH) << static_cast<bool>((var1 & mask_bit_5) >> 5) << endl;
    // position 2
    cout << setw(COLUMN_WIDTH) << "Mask (Bit 2) : " << setw(COLUMN_WIDTH) << bitset<8>(mask_bit_2) << endl;
    // cout << setw(COLUMN_WIDTH) << "Result ((& mask) >> 1) : " << setw(COLUMN_WIDTH) << bitset<8>((var1 & mask_bit_2) >> 2) << endl;
    cout << setw(COLUMN_WIDTH) << "Result ((& mask) >> 2) : " << setw(COLUMN_WIDTH) << static_cast<bool>((var1 & mask_bit_2) >> 2) << endl;

    // Toggle bit position

    cout << setw(COLUMN_WIDTH) << "var1 : " << setw(COLUMN_WIDTH) << bitset<8>(var1) << endl;
    var1 ^=mask_bit_3;
    cout << setw(COLUMN_WIDTH) << "Toggle (Bit 3) : " << setw(COLUMN_WIDTH) << bitset<8>(mask_bit_3) << endl;
    cout << setw(COLUMN_WIDTH) << "Result ((& mask) >> 3) : " << setw(COLUMN_WIDTH) << bitset<8>(var1)  << endl;


    // unsigned int my_color { 0xAABCDE00 };
    unsigned int my_color { 0xbd179ed6 };

    // set format options to show as hexadecimal
    cout << hex << showbase << endl;

    // Shift to make sure color byte is in the lower index position that can be interpreted as an integer between 0 and 255
    // We use this to calculate the RGBA color (red, green, blue, alpha) = (255,255,255,255)

    cout << "Red is : " << ((my_color & red_mask) >> 24) << endl;
    cout << "Green is : " << ((my_color & green_mask) >> 16) << endl;
    cout << "Blue is : " << ((my_color & blue_mask) >> 8) << endl;
    cout << "Alpha is : " << ((my_color & alpha_mask) >> 0) << endl;

    return 0;
}