//
//  conio.cpp
//  Pinecone
//

#include <Pinecone.h>

#ifdef __x86_64__

#include <stdio.h>

uint8_t getch() { return (uint8_t)getc(stdin); }
void putch(uint8_t data) { putchar(data); }
void initUART() {}

#elif __mips__

//#include<PIC32MXCPU.h>
#include<PIC32MZCPU.h>

void
initUART()
{
    // TODO: Fine-tune oscillator
    🔧(PIC32MZ_U5MODESET) = UxMODE_ON; // UART5 is enabled
    🔧(PIC32MZ_U5STASET)  = UxSTA_UTXEN; // UART5 transmitter is enabled
}

void
putch(
    uint8_t c
)
{
    while (UxSTA_UTXBF & 🔎(PIC32MZ_U5STA)); // Wait while buffer is full
    🔧(PIC32MZ_U5TXREG) = c; // Transmit character
}

uint8_t getch()
{
    if (UxSTA_OERR & 🔎(PIC32MZ_U5STA)) { 🔧(PIC32MZ_U5STACLR) = UxSTA_OERR; }
    while (UxSTA_URXDA & 🔎(PIC32MZ_U5STA) == 0);
    uint8_t result = 🔎(PIC32MZ_U5RXREG);
    🔧(PIC32MZ_U5STACLR) = UxSTA_OERR;
    return result;
}

#endif
