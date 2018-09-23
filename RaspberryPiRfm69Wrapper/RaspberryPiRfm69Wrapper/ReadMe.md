The purpose of this project is to compile the dynamic library used by the RaspberryPiControl project for controlling a RFM69W Transceived on a Raspberry Pi with .NET. The dynamic library is checked into source control. So you should only have to compile this project if changes happen.


Notes/Steps:
1. Must be built on an ARM Linux device (Raspberry Pi is preferred since this will be running on one)
1. The Linux device must already have wiringPi installed and setup (instructions http://wiringpi.com/download-and-install/)
1. Must compile as a dynamic library because that's how the library loader works on the .NET side
1. gcc -shared -o rfm69.o rfm69.c -lwiringPi

