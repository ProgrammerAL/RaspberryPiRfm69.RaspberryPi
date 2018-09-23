
// ****************************************************************************
// Driver definition for HopeRF RFM69W/RFM69HW, Semtech SX1231/1231H
// ****************************************************************************
// Creative Commons Attrib Share-Alike License
// You are free to use/extend this library but please abide with the CCSA license:
// http://creativecommons.org/licenses/by-sa/3.0/
// Original from: http://rdepablos.merlitec.com/mixed/rfm69-library-for-raspberry-pi
//	Created by: Raul Pablos at raul.pablos@merlitec.com
// ****************************************************************************

#include <stdint.h>

#ifndef RFM69_h
#define RFM69_h

#define MAX_DATA_LEN         61 // to take advantage of the built in AES/CRC we want to limit the frame size to the internal FIFO size (66 bytes - 3 bytes overhead)
#define SPI_CS               SS // SS is the SPI slave select pin, for instance D10 on atmega328
#define RF69_IRQ_PIN          2 // INT0 on AVRs should be connected to DIO0 (ex on Atmega328 it's D2)
#define CSMA_LIMIT          -80 // upper RX signal sensitivity threshold in dBm for carrier sense access
#define RF69_MODE_SLEEP       0 // XTAL OFF
#define	RF69_MODE_STANDBY     1 // XTAL ON
#define RF69_MODE_SYNTH	      2 // PLL ON
#define RF69_MODE_RX          3 // RX MODE
#define RF69_MODE_TX		  4 // TX MODE

//available frequency bands
#define RF69_315MHZ     31  // non trivial values to avoid misconfiguration
#define RF69_433MHZ     43
#define RF69_868MHZ     86
#define RF69_915MHZ     91

#define null                  0
#define COURSE_TEMP_COEF    -90 // puts the temperature reading in the ballpark, user can fine tune the returned value
#define RF69_BROADCAST_ADDR 255
typedef uint8_t             BOOL;

int rfm69_initialize(uint16_t freqBand, uint8_t nodeID, uint8_t networkID);
void rfm69_writeReg(char addr, char value);
char rfm69_readReg(char addr);
void rfm69_readAllRegs(void);
int rfm69_readRSSI(char forceTrigger);
void rfm69_encrypt(const char* key);
void rfm69_setMode(char newMode);
void rfm69_sleep(void);
void rfm69_setAddress(char addr);
void rfm69_setPowerLevel(char powerLevel);
char rfm69_canSend(void);
void rfm69_receive(void);
char rfm69_getDataLen(void);
char rfm69_getTargetId(void);
int rfm69_getRssi(void);
void rfm69_getData(char *data);
char rfm69_getSenderId(void);
void rfm69_send(uint8_t toAddress, const void* buffer, uint8_t bufferSize, BOOL requestACK);
void rfm69_sendFrame(uint8_t toAddress, const void* buffer, uint8_t bufferSize, BOOL requestACK, BOOL sendACK);

#endif
