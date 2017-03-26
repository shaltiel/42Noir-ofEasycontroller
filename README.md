# Easycontroller (beta)
Application for using midi-controllers in an easy and convinient way across max/msp and Openframeworks (Only for Mac users). The idea is to be able to master your midi-controller in live music and visual, independently of the platform used. Initially,  map your midi-controller by touching the knobs and click on the desired knob in th panel. Then you set to work with the  paramters directly in your OF app and Max patch (all can be found in the video here <a href="https://www.youtube.com/watch?v=en2tB_PJq-0">User Guide -Easycontroller</a>). You can label knobs/pads for each parameter in your program/song/visualization,  assign various value-ranges for each slider, and set presets for your midi-controller in each chapter of your performance. We perform with this tool at 42Noir, we've tested it mostely for Novation and Yamaha controllers, but if your controller has unique midi formating (:/) contact us and we would try to sort it out for you.   

# Instruction for Openframeworks

1. Download the application in
 <a href="http://www.42noir.com/es">http://www.42noir.com/es</a>

2. Follow the guide in the page to see how to install and assigne your midi-controller, and also watch how to use Easycontroller with Max/MSP.

 3. Download the dependant class files: escon.h and escon.cpp and add them to your openframework target files or use it next to a specific programm. In your ofapp.h include the "escon.h" and create an object member of escon (e.g. escon easy). Then use the member functions label, rec, snd, to recieve/send parameters from/to the controller.
    
    Alternatively, download all files and run the example ofapp to see how to call values (easy.rec("s1")), and to label your knob in the application. 
   
<a href="url"><img src="https://github.com/shaltiel/ofEasycontroller/blob/master/Hanging.gif" align="center" height="270" width="480" ></a>
# Usage
* Easymapping of midi-controllers.
* Labeling knobs and pads.
* Re-mapping values.
* Applying Presets.
* Control both Max and OF together.




<a href="url"><img src="http://42noir.com/wp-content/uploads/2016/12/3-screenshot@2x-1.png" align="left" height="200" width="300" ></a>

### In Easycontroller

* To map your midi-controller, choose the instrument from the drop menu, turn on the map midi button, and assign sliders and pads by moving a knob/pad and then pressing the label above the knob/pad in Easycontroller. Press save to use this mapping as defult for next use.

* Press "shift" to store a preset or "alt+shift" to remove a preset.


### Functions in OpenFrameworks

#### Recieve
```c++
    int escon::rec(string); //recieve value from Easycontroller using the string name, e.g. rec("s1"),rec("s4b"), rec("p1b")   for recieving values from slider 1 slider 4 from set b and for pad 1 in set b.
    
    float escon::rec(string,float, float); //recieve with a new range from string index of Easycontroller: rec("s3",-1,4.1)
    
    int escon::rec(int); //recieve value from Easycontroller, see the table function for the mapping
     
    float escon::rec(int,float,float);//recieve new range values from index
   
    int escon::table(string); //get index from string
```
 #### Send / Label 
 ```c++
    void escon::label(string,string); //send a label to controller, e.g. label("s1","of_slid")
  
    void escon::snd(string,int); //send a value to midi-controller and Easycontroller
    
    void escon::snd_wait(int,int); //send a value to midi-controller using index and wait until the queue is empty (for escon::setup, and  presets)
    
    void escon::snd(int,int); //send but do not wait if the queue is full
```
 #### Presets
```c++
    void escon::set_to_preset(string,int);// set a pad  with string name to control a preset number (in escon::update use: set_to_preset("p2",2) to call preset 2 with pad 2)
    
    void escon::call_preset(int); // call a preset (use in escon::setup function)
    
    void escon::all_s(int);//set all slides to a value (use in escon::setup function)
    
    void escon::all_p(int);//set all pads to a value (use in escon::setup function)
    

```








