# Easycontroller (beta)
Application for using midi-controllers in an easy and convinient way across max/msp and Openframeworks (Only for Mac users). The idea is to be able to master your midi-controller in live music and visual, independently of the platform used. Initially,  map your midi-controller by touching the knobs and click on the desired knob in th panel. Then you set to work with the  paramters directly in your OF app or Max patch (all can be found in the video here <a href="https://www.youtube.com/watch?v=en2tB_PJq-0">User Guide -Easycontroller</a>). Your knobs can be labeled for each program/song/visualization and you can easily re-map the values, and finally create presets to update your midi-controller for each chapter of your performance. We perform with this tool at 42Noir, we've tested it mostely for Novation and Yamaha controllers, but if your controller has unique midi formating (:/) contact us and we would try to sort it out for you.   

# Instruction for Openframeworks

1. Download the application in
 <a href="http://www.42noir.com/es">http://www.42noir.com/es</a>

2. Follow the guide in the page to see how to install and assigne your midi-controller, and also watch how to use Easycontroller with Max/MSP.

 3. Download the dependant class files: escon.h and escon.cpp and add them to your openframework target files or use it next to a specific programm. In your ofapp.h include the "escon.h" and create an object member of escon (e.g. escon easy). Then use the member functions label, rec, snd, to recieve/send parameters from/to the controller.
    
    Alternatively, download all files and run the example ofapp to see how to call values (easy.rec("s1")), and to label your knob in the application. 
   
<a href="url"><img src="https://github.com/shaltiel/ofEasycontroller/blob/master/Hanging.gif" align="center" height="270" width="480" ></a>
# Functionality
* Easymapping of midi-controllers.
* Labeling knobs and pads.
* Re-mapping values.
* Applying Presets.
* Control both Max and OF together.




<a href="url"><img src="http://42noir.com/wp-content/uploads/2016/12/3-screenshot@2x-1.png" align="left" height="200" width="300" ></a>

 char * rec();//receive raw string message
    int rec(int); //give value in index of the controller, see table function.
    float rec(int,float,float);//return remapped value from index
    float rec(string,float, float);//return with a new range from string index
    int rec(string);
    void snd(string,int);
    void snd_wait(int,int);
    void snd(int,int);
    void label(string,string); //send label to controller
    void set_to_preset(string,int);// set a knob  with string name to control a preset number (in update function only)
    void call_preset(int); // call a preset (use in setup function)
    int table(string); //int index to string index
    int hash(int);
    int re_hash(int);
    void all_s(int);//set all slides to value use in setup function.
    void all_p(int);//set all pads to value use in setup function.
};






