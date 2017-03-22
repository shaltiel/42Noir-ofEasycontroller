#pragma once
#include <sys/msg.h>
#include <string>
#define BSZ 16
#define MSZ 64
using namespace std;
class escon
{
//message queue structures
private:
    struct message {
        long type;
        char text[MSZ];
    } msg;
    long msgtyp = 1;
    typedef struct masgbuf {
        long    mtype;
        char    mtext[MSZ];
    } message_buf;
    int msgid;
    int msgids;
    key_t key;
    key_t keys;
    int msgflg;
    message_buf sbuf;
    size_t buf_length,sbuf_length;
    int indexin[42];
    
public:
    escon();
    ~escon();
    char * rec();//receive raw string message
    int rec(int); //give value in index of the controller, see table function.
    float rec(int,float,float);//return remapped value from index
    float rec(string,float, float);//return remapped value from  string index
    int rec(string);
    void snd(string,int);
    void snd(string,float);
    void snd(int,int);
    void label(string,string); //send label to controller
    void press_preset(string,int);
    int table(string); //int index to string index
    int hash(int);
    int re_hash(int);
    void all_s(int); void all_p(int);
};

