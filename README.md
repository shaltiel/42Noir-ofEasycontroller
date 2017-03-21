# Easycontroller
Application for using midi-controllers in a convinient way across max/msp and openframework (Only for Mac users). Allows also easy communication between Max and Openframework. 

# Instrouction for using it with openframework:

   1. Download the application in
 <a href="http://www.42noir.com/es">http://www.42noir.com/es</a>
   2. Follow the guide of how to install and assigne your midi-controller for the use, and also whatch how you can use it with Max/MSP. 
   3. Download the dependant class files: escon.h and escon.cpp and add them to your openframework target files or use it next to a specific programm. 
   4. Download all files to run an example ofapp, to see how to call values (easy.rec("s1")), and to label your knob in the application from the controller. Otherwise, in your ofapp.h include the "escon.h" and create an object member of escon (e.g. escon easy). Then use the member functions label, rec, snd, to recieve parameters from the controller.
   

# Functionality
* Easymapping of the controller.
* Labeling knobs and pads.
* Re-mapping values.
* Applying Presets.
* Control both Max and OF together.

<a href="url"><img src="http://42noir.com/wp-content/uploads/2016/12/3-screenshot@2x-1.png" align="left" height="200" width="300" ></a>






