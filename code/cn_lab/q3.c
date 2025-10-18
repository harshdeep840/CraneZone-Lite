#include <stdio.h>

int main() {
    unsigned int number = 0x12345678;
    unsigned char byte1, byte2, byte3, byte4;

    byte1 = (number >> 24) & 0xFF;
    byte2 = (number >> 16) & 0xFF;
    byte3 = (number >> 8) & 0xFF;
    byte4 = number & 0xFF;

    printf("Original number: 0x%08X\n", number);

    printf("Byte 1 (MSB): 0x%02X\n", byte1);
    printf("Byte 2: 0x%02X\n", byte2);
    printf("Byte 3: 0x%02X\n", byte3);
    printf("Byte 4 (LSB): 0x%02X\n", byte4);

    return 0;
}