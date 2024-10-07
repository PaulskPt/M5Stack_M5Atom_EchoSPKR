M5Stack M5Atom Echo new C++ class ATOMECHOSPKR and Arduino beep test sketch.

Important credit:

I was only able to create and successfully finish this project with the great help of Microsoft AI assistant CoPilot.
CoPilot helped me correcting wrong C++ code fragments. It suggested C++ code fragments. CoPilot gave me, in one Q&A session, a "workaround" 
for certain limitation that the Arduino IDE has with the standard C++ specification. And CoPilot gave it's answers at great speed of response.
There were no delays. The answers were instantaneous! Thank you CoPilot. Thank you Microsoft for this exciting new tool!

The reason for this project is that M5Stack doesn't have available, as far as I know, a C++ class for the Atom Echo to produce simple beeps.
For the M5 Atom Echo M5Stack has examples as: EchoRest, PlayMusic and RecordPlay. In the available Github repositories from M5Stack I found a usable C++ class ATOMSPK,
intended for the M5 EchoSPK device.
I copied the files into a new Arduino IDE sketch project. I renamed the C++ files more suitable for the M5 Atom Echo device.
I ported the contents of the C++ files to be used with the M5 Atom Echo. 
The Arduino sketch example ```PlayMusic``` was suitable for me to modify for use with the created ATOMECHOSPKR class.
I also added functionality to use the builtin RGB Led of the Atom Echo. 

Hardware used:

1. M5Stack M5 Atom Echo;


Sound:

After applying power to the M5 Echo Atom device, the sketch will wait for a button press.
Upon pressing the button on top of the Atom Echo, a double tone sound will be produced and the RGB Led wil be set to GREEN at the start of the beeps. After the beeps have finished, the RGB Led will be set to RED.

Docs:

Monitor_output.txt


Images: 

Images taken during the sketch was running are in the folder ```images```.

Link to product page of the hardware used:

- M5Stack M5Echo [info](https://shop.m5stack.com/products/atom-echo-smart-speaker-dev-kit);
