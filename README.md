# Raspberry Pi RFM69 Transceiver Wrapper
This repo contains code for using an RFM69 Transceiver on a Raspberry Pi. The original code for this project is from http://rdepablos.merlitec.com/mixed/rfm69-library-for-raspberry-pi. The only changes made was some cleanup so the code is displayed properly when loaded in Visual Studio, and some commented out code was removed. All funcationlity is the same as the original.

## How to Compile
1. Install/Setup WiringPi on your raspberry Pi. You can find instructions online. I used the ones from here: http://wiringpi.com/download-and-install/
2. Get the three code files from this repo into a folder on your Raspberry Pi (rfm69.c, rfm69.h, and rfm69registers.h)
3. Open a command line terminal and navigate to the folder with the code files
4. In the terminal, run the following command: `gcc -shared -o rfm69.o rfm69.c -lwiringPi`
5. The output binary file `rfm69.o` will be created in that same directory. Use it however you would like. 

Note: Even though there is a Visul Studio .sln file in this project, it is not setup to be compiled on a Windows machine. It's just there in case you want to use that editor.
