#include"prelude.h"

def Fmain(){
  printf("Fmain1\n");
  return VPC(3);
  return NULL;}

def Flookup_underflow(){
  printf("Flookup underflow\n");
  exit(1);
  return NULL;}

def Flookup_overflow(){
  printf("Flookup overflow\n");
  exit(1);
  return NULL;}

def Fxit(){
  printf("Fxit\n");
  printf("MESSAGE IS %s\n", (char*)_1);
  exit(1);
  return NULL;}

def Fbye(){
  fputs("\nBye!!\n", stderr);
  return exit(0), NULL;}

char*getbuf(char *b, unsigned sz){
  do{
    fputs(" $ ", stderr);
    char*s = fgets(b, sz, stdin);
    if(!s) return s;
    while(isspace(*s)) ++s;
    if(*s) return s;
  }while(1);}

def menu(){
  int i=0;
  for(char **n=Names; *n; i++,n++)
    if(i) printf(" %d %s\n", i, *n);
  return nil;}

def Fdebug(){
  printf(" == DEBUG ==\n");
  menu();
  char b[1024],*s;
  if(!(s=getbuf(b,sizeof(b))))
    fputs("\neof!!!\n", stderr),
      exit(0);
  unsigned n = atoi(s);
  if(n<=0){
    printf("bad number\n");
    return NULL;}
  return Funcs[_ndx(n)]();}

def Fhello(){
  printf("hello!\n");
  return NULL;}
