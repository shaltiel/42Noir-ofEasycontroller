//EasyController - 42%noir, 2017.

#include <sys/msg.h>
#include "escon.h"

    
escon::escon()
    {
        key = 4458;//recieve to this key
        keys=4456; //send back using this key
        msgid = msgget(key, 0666);
        msgids= msgget(keys, 0666);
        msgflg= IPC_CREAT | 0666;
        sbuf.mtype = 1;
        this->snd("activate",1);//send activation on to easycontroller.
        //
    }
    escon::~escon()
    {
        this->snd("activate",0);
        msgsnd(msgids, &sbuf,  sbuf_length, IPC_NOWAIT);//disconnect easycontroller.
    }
    
    char * escon::rec()//receiving raw messages.
    {
        msg.text[0]='\0';
        int getting=msgrcv(msgid, &msg, sizeof(msg)-sizeof(msgtyp), msgtyp, MSG_NOERROR | IPC_NOWAIT);
        return msg.text;
    }
    
    //main function for updating all channels.
    int   escon::rec(int index)
    {
        msg.text[0]='\0';
        char buf[MSZ];//would be the buffer who reads
        char seps[] = " ";//for choping the string
        buf[0]='\0';
        int var; char vars[BSZ];
        int input[2]={-1,-1};//intial
        
        int i = 0;
        int getting=msgrcv(msgid, &msg, sizeof(msg)-sizeof(msgtyp), msgtyp, MSG_NOERROR | IPC_NOWAIT);
        
        (void) strcpy(buf,msg.text);
        char *token=strtok(buf, seps);//first token
        
        while (token != NULL)
        {
            sscanf (token, "%s", vars);//Reads data from string
            if(isdigit(vars[0])||vars[0]=='-')
            {
                sscanf (token, "%d", &var);//Reads number data from string
                input[i] = var;//save data into array and then promote it
            }
            i++;
            token = strtok (NULL, seps);//next token
        }
        
        indexin[hash(input[0])]=input[1]; //updating channel
        
        return indexin[hash(index)];
    }
    
    //same as before but now overloaded for a range
    float  escon::rec(int index, float l, float u)
    {
        int input=rec(index);
        return (float)input*(u-l)/127 + l;//(d-c)*[(n-a)/(b-a)]+c 0-127 to a-b
    }
    
    
    //from input string to an integer index
    float escon::rec(string c_inputs, float l, float u)
    {
        int index=table(c_inputs);
        return rec(index, l, u);
    }
    //from input string to an integer index
    int escon::rec(string c_inputs)
    {
        int index=table(c_inputs);
        return rec(index);
    }
    
    //send functions************************************************
    void escon::snd(string c_inputs, int val)
    {
        int channel=table(c_inputs);
        char  ch[BSZ];
        sprintf(ch,"%d",channel);
        char  ch2[8];
        sprintf(ch2, "%d",val);
        strcat(ch," "); strcat(ch,ch2);
        char out0[BSZ]="\0";
        strcpy(out0,ch);
        (void) strcpy(sbuf.mtext, out0);
        sbuf_length = strlen(sbuf.mtext) + 1 ;
        msgsnd(msgids, &sbuf,  sbuf_length, IPC_NOWAIT);
    }
    void escon::snd(string c_inputs, float val)
    {
        int channel=table(c_inputs);
        
        
        char  ch[BSZ];
        sprintf(ch,"%d",channel);
        char  ch2[8];
        sprintf(ch2, "%3.*f", 6,val);
        strcat(ch," "); strcat(ch,ch2);
        char out0[BSZ]="\0";
        strcpy(out0,ch);
        (void) strcpy(sbuf.mtext, out0);
        sbuf_length = strlen(sbuf.mtext) + 1 ;
        msgsnd(msgids, &sbuf,  sbuf_length, IPC_NOWAIT);
    }
    void escon::snd(int channel, int val)
    {
        char  ch[BSZ];
        sprintf(ch,"%d",channel);
        char  ch2[8];
        sprintf(ch2, "%d",val);
        strcat(ch," "); strcat(ch,ch2);
        char out0[BSZ]="\0";
        strcpy(out0,ch);
        (void) strcpy(sbuf.mtext, out0);
        sbuf_length = strlen(sbuf.mtext) + 1 ;
        msgsnd(msgids, &sbuf,  sbuf_length, IPC_NOWAIT);    }

    void escon::label(string c_inputs, string name)
    {
        int channel=table(c_inputs);
        char * ch2= &name[0];
        
        char  ch[BSZ];
        sprintf(ch,"%d",channel);
        strcat(ch," "); strcat(ch,ch2);
        char out0[BSZ]="\0";
        strcpy(out0,ch);
        (void) strcpy(sbuf.mtext, out0);
        sbuf_length = strlen(sbuf.mtext) + 1 ;
        msgsnd(msgids, &sbuf,  sbuf_length, IPC_NOWAIT);
        //*********************************************************************
    }

void escon::press_preset(string pad,int preset) //making a pad controlling a preset when pressed
    {
        if(rec(pad))//if pad was pressed
            {
                snd("preset",preset); //press preset 2.
                snd(pad,0);    //turn off pad.
            }
    }

    int escon::table(string c_inputs)//maping the indexes to channels as formatted by the app.
    {
        char * c_input= &c_inputs[0];
        int index=0;
        if(strcmp(c_input,"s0")==0) index=0;
        if(strcmp(c_input,"s1")==0) index=1;
        if(strcmp(c_input,"s2")==0) index=2;
        if(strcmp(c_input,"s3")==0) index=3;
        if(strcmp(c_input,"s4")==0) index=4;
        if(strcmp(c_input,"s5")==0) index=5;
        if(strcmp(c_input,"s6")==0) index=6;
        if(strcmp(c_input,"s7")==0) index=7;
        if(strcmp(c_input,"s8")==0) index=8;
        if(strcmp(c_input,"s0b")==0) index=10;
        if(strcmp(c_input,"s1b")==0) index=11;
        if(strcmp(c_input,"s2b")==0) index=12;
        if(strcmp(c_input,"s3b")==0) index=13;
        if(strcmp(c_input,"s4b")==0) index=14;
        if(strcmp(c_input,"s5b")==0) index=15;
        if(strcmp(c_input,"s6b")==0) index=16;
        if(strcmp(c_input,"s7b")==0) index=17;
        if(strcmp(c_input,"s8b")==0) index=18;
        
        if(strcmp(c_input,"p0")==0) index=100;
        if(strcmp(c_input,"p1")==0) index=101;
        if(strcmp(c_input,"p2")==0) index=102;
        if(strcmp(c_input,"p3")==0) index=103;
        if(strcmp(c_input,"p4")==0) index=104;
        if(strcmp(c_input,"p5")==0) index=105;
        if(strcmp(c_input,"p6")==0) index=106;
        if(strcmp(c_input,"p7")==0) index=107;
        if(strcmp(c_input,"p8")==0) index=108;
        if(strcmp(c_input,"p0b")==0) index=110;
        if(strcmp(c_input,"p1b")==0) index=111;
        if(strcmp(c_input,"p2b")==0) index=112;
        if(strcmp(c_input,"p3b")==0) index=113;
        if(strcmp(c_input,"p4b")==0) index=114;
        if(strcmp(c_input,"p5b")==0) index=115;
        if(strcmp(c_input,"p6b")==0) index=116;
        if(strcmp(c_input,"p7b")==0) index=117;
        if(strcmp(c_input,"p8b")==0) index=118;
        if(strcmp(c_input,"activate")==0) index=150;
        if(strcmp(c_input,"preset")==0) index=200;
        return(index);
    }
    int escon::hash(int index)//mapping into array of 41 elements
        {
            if (index>99&&index<150)
                return index-80;
            if (index==150) return 39;
            if (index==200) return 40;
            return index;
        }
    int escon::re_hash(int index)//mapping into array of 41 elements
        {
            if (index>19&&index<39)
                return index+80;
                if (index==39) return 150;
                if (index==40) return 200;
            return index;
        }


    void escon::all_s(int n)
    {
        for (int i=0;i<20;i++)
        snd(i,n);
    }
    void escon::all_p(int n)
    {
    for (int i=100;i<120;i++)
        snd(i,n);
    }
