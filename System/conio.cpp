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

#pragma mark The UART 1 - UART 6

#define PIC32MZ_U5MODE   0xBF822800 // UARTx Mode Register
#define PIC32MZ_U5STA    0xBF822810 // UARTx Status and Control Register
#define PIC32MZ_U5STACLR 0xBF822814
#define PIC32MZ_U5TXREG  0xBF822820 // UARTx Transmit Register
#define PIC32MZ_U5RXREG  0xBF822830 // UARTx Receive Register
#define PIC32MZ_U5BRG    0xBF822840 // UARTx Baud Rate Register

BITMASK (uint32_t) { // UxMODE
    UxMODE_SLPEN    = 0b100000000000000000000000, // Run During Sleep Enable bit
    UxMODE_ACTIVE   = 0b010000000000000000000000, // UARTx Module Running Status bit
    UxMODE_CLKSEL_2 = 0b000001100000000000000000, // UARTx Module Clock Selection bits
    UxMODE_RUNOVF   = 0b000000010000000000000000, // Run During Overflow Condition Mode bit
    UxMODE_ON       = 0b000000001000000000000000, // UARTx Enable bit
    UxMODE_SIDL     = 0b000000000010000000000000, // Stop in Idle Mode
    UxMODE_IREN     = 0b000000000001000000000000, // IrDA Encoder and Decoder Enable
    UxMODE_RTSMD    = 0b000000000000100000000000, // Mode Selection for UxRTS Pin bit
    UxMODE_UEN_2    = 0b000000000000001100000000, // UARTx Enable
    UxMODE_WAKE     = 0b000000000000000010000000, // Enable Wake-up on Start bit Detect During Sleep Mode
    UxMODE_LPBACK   = 0b000000000000000001000000, // UARTx Loopback Mode Select
    UxMODE_ABAUD    = 0b000000000000000000100000, // Auto-Baud Enable
    UxMODE_RXINV    = 0b000000000000000000010000, // Receive Polarity Inversion
    UxMODE_BRGH     = 0b000000000000000000001000, // High Baud Rate Enable
    UxMODE_PDSEL_2  = 0b000000000000000000000110, // Parity and Data Selection. E.g 00 = 8-bit data, no parity
    UxMODE_STSEL    = 0b000000000000000000000001  // Stop Selection. 1 = 2 Stop bits. 0 = 1 Stopbit
};

BITMASK (uint32_t) { // UxSTA
    UxSTA_ADM_MASK  = 0b11111111000000000000000000000000, // Automatic Address Detect Mode Enable
    UxSTA_ADDR_8    = 0b00000000111111110000000000000000, // Automatic Address Mask
    UxSTA_UTXISEL_2 = 0b00000000000000001100000000000000, // TX Interrupt Mode Selection
    UxSTA_UTXINV    = 0b00000000000000000010000000000000, // Transmit Polarity Inversion
    UxSTA_URXEN     = 0b00000000000000000001000000000000, // Receiver Enable
    UxSTA_UTXBRK    = 0b00000000000000000000100000000000, // Transmit Break
    UxSTA_UTXEN     = 0b00000000000000000000010000000000, // Transmit Enable
    UxSTA_UTXBF     = 0b00000000000000000000001000000000, // Transmit Buffer Full Status
    UxSTA_TRMT      = 0b00000000000000000000000100000000, // Transmit Shift Register is Empty
    UxSTA_URXISEL_2 = 0b00000000000000000000000011000000, // Receive Interrupt Mode Selection
    UxSTA_ADDEN     = 0b00000000000000000000000000100000, // Address Character Detect
    UxSTA_RIDLE     = 0b00000000000000000000000000010000, // Receiver Idle
    UxSTA_PERR      = 0b00000000000000000000000000001000, // Parity Error Status
    UxSTA_FERR      = 0b00000000000000000000000000000100, // Framing Error Status
    UxSTA_OERR      = 0b00000000000000000000000000000010, // Receive Buffer Overrun Error Status
    UxSTA_URXDA     = 0b00000000000000000000000000000001  // Receive Buffer Data Available
};

BITMASK (uint32_t) { // UxTXREG
    UxRXREG_TX8   = 0b100000000,
    UxTXREG_TX_8  = 0b011111111 // Transmit register
};

BITMASK (uint32_t) { // UxRXREG
    UxRXREG_RX8   = 0b100000000,
    UxTXREG_RX_8  = 0b011111111 // Receive Register
};

BITMASK (uint32_t) { // UxBRG
    UxBRG_BRG_16 = 0b1111111111111111 // Baud Rate Division
};

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
