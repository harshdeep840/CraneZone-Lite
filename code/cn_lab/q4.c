#include <stdio.h>
struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    unsigned int number;
    struct pkt p;

    printf("Enter a number: ");
    scanf("%x", &number);

    p.ch1 = (number >> 24) & 0xFF;
    p.ch2[0] = (number >> 16) & 0xFF;
    p.ch2[1] = (number >> 8) & 0xFF;
    p.ch3 = number & 0xFF;

    printf("Content of each member:\n");
    printf("ch1: 0x%02X\n", p.ch1);
    printf("ch2[0]: 0x%02X\n", p.ch2[0]);
    printf("ch2[1]: 0x%02X\n", p.ch2[1]);
    printf("ch3: 0x%02X\n", p.ch3);

    unsigned int reconstructed_number = (p.ch1 << 24) | (p.ch2[0] << 16) | (p.ch2[1] << 8) | p.ch3;

    printf("\nOriginal number: 0x%08X\n", number);
    printf("Reconstructed number: 0x%08X\n", reconstructed_number);

    return 0;
}