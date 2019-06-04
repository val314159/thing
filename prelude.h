#ifndef __PRELUDE_H__
#define __PRELUDE_H__
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<strings.h>
#include<string.h>
#include<setjmp.h>
typedef void*def;
typedef def(*func)();
#define VPC(x) ((def)(long long)(x))
#define LLC(x) ((long long)(def)(x))
#define SI static inline
#define nil ((def)&nil__)
#define _T_ ((def)&tru__)
extern def nil__,tru__,_1,_2,_3,_4,_5,_6,_7,_8,_9;
extern int _x;
extern jmp_buf*JB;
extern func Funcs[];
extern char*Names[];
extern const int FUNCS_SZ;
#define eprintf(fmt,...)			\
  fprintf(stderr,fmt,##__VA_ARGS__)
#define _say(ts) \
  eprintf("\n ** %s **: %s\n",ts,(char*)_1);
#define CALL(jb) (Funcs[_ndx(_x=setjmp(*(JB=(jb))))])
#define rcall0(fn)({				\
      (fn)();})
#define rcall1(fn,a1)({				\
      _1 = VPC(a1);				\
      (fn)();})
#define rcall2(fn,a1,a2)({			\
      _1 = VPC(a1);				\
      _2 = VPC(a2);				\
      (fn)();})
#define rcall3(fn,a1,a2,a3)({			\
      _1 = VPC(a1);				\
      _2 = VPC(a2);				\
      _3 = VPC(a3);				\
      (fn)();})
#define rcall4(fn,a1,a2,a3,a4)({\
      _1 = VPC(a1);				\
      _2 = VPC(a2);				\
      _3 = VPC(a3);				\
      _4 = VPC(a4);				\
      (fn)();})
SI void die() {_say("FAIL");exit(0);}
SI void warn(){_say("WARN");}
SI unsigned _ndx(unsigned n){return(n<FUNCS_SZ-1)?n:2;}
SI func _condByKey(char*key){
  for(char **n=Names; *n; n++)
    if(!strcmp(key, *n)) return Funcs[_ndx(n-Names)];
  return nil;}
#endif//__PRELUDE_H__
