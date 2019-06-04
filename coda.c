#define DEBUG 1
#include"prelude.h"
#include"v.h"
const int FUNCS_SZ=sizeof(Funcs)/sizeof(func);
jmp_buf _jb, *JB=0; int _x = -1, _debug = DEBUG;
def nil__ = &nil__, tru__ = &tru__, _, __,
  _r, _1, _2, _3, _4, _5, _6, _7, _8, _9;
void init(){_=__=_r=_1=_2=_3=_4=_5=_6=_7=_8=_9=0;}
int main(int c,char**v){
  if(_debug)Funcs[0]=Fdebug;
  init();while(_debug)CALL(&_jb)();}
