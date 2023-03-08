#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
S = split   ; C = Class
C = combine ; V = Variable
            ; M = Method    
*/

enum Flags1{
  COMBINE = 'C',
  SPLIT = 'S', 
};

enum Flags2{
  CLASS = 'C',
  VARIABLE = 'V',
  METHOD = 'M',
};

string split(string input){
  string ret="";
  for(size_t i = 0;i<input.size();i++){
    if(i!=0 && isupper(input[i]))
      ret+=' ';
    ret+=tolower(input[i]);
  }
  return ret;
}

string combine(string input){
  string ret="";
  for(size_t i = 0;i<input.size();i++){
    if(input[i]==' ')
      ret+=toupper(input[++i]),i++;
    ret+=input[i];
  }
  return ret;
}

bool isMethod(string ret){
  if(ret.length()>=3 && ret[ret.length()-2]=='(' && ret[ret.length()-1]==')')
    return true;
  return false;
}

string convert(string input){
  string ret=input.substr(4,input.length()-1);
  char flag1=input[0],flag2=input[2];

  switch(flag1){
    case COMBINE:
      ret = combine(ret);
      break;
    case SPLIT:
      ret = split(ret);
      if(isMethod(ret))
        ret.pop_back(),ret.pop_back();
      return ret;
  }

  switch(flag2){
    case CLASS:
      ret[0]=toupper(ret[0]);
      if(isMethod(ret))
        ret.pop_back(),ret.pop_back();
      break;
    case VARIABLE:
      ret[0]=tolower(ret[0]);
      if(isMethod(ret))
        ret.pop_back(),ret.pop_back();
      break;
    case METHOD:
      ret[0]=tolower(ret[0]);
      if(!isMethod(ret))
        ret+="()";
  } 

  return ret;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  //cout << convert("C;C;coffee machine");
  #if 1
  for(string input;getline(cin,input);){
    cout << convert(input) << endl;
  }
  #endif
  return 0;
}

//does not work for some reason

/*
Extra c code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum Flags1{
  COMBINE = 'C',
  SPLIT = 'S', 
};

enum Flags2{
  CLASS = 'C',
  VARIABLE = 'V',
  METHOD = 'M',
};


char *split(const char *input){
  int spaces=0;
  for(size_t i=0;input[i]!=0;i++){
      if(isupper(input[i])){
          spaces++;
      }
  }
  char *ret = malloc((strlen(input)+spaces+1)*(sizeof(char)));
  size_t j = 0;
  for(size_t i=0;input[i]!=0;i++){
      if(i!=0 && isupper(input[i])){
          ret[j]=' ',j++;
      }
      ret[j++]=tolower(input[i]);
  }
  ret[j]=0;
  return ret;
}

char *combine(const char *input){
  int spaces=0;
  for(size_t i=0;input[i]!=0;i++){
      if(isupper(input[i])){
          spaces++;
      }
  }
  char *ret = malloc((strlen(input)-spaces+1)*(sizeof(char)));
    size_t j=0;
    for(size_t i=0;input[i]!=0;i++){
      if(input[i]!=' '){
          ret[j++]=input[i];
      } else ret[j++]=toupper(input[++i]);
  }
  ret[j]=0;
  return ret;
}

char *slice_str(const char * str, size_t start, size_t end)
{
  char *buffer = malloc((strlen(str)+1)*(sizeof(char)));
  size_t j = 0;
  for ( size_t i = start; i < end; ++i ) {
      buffer[j++] = str[i];
  }
  buffer[j] = 0;
  return buffer;
}

bool isMethod(const char* input){
  size_t len = strlen(input);
  
  if(len>=3 && input[len-2]=='('&& input[len-1]==')')
    return true;
  
  return false;
}

char *convert(char *input){
  char f1=input[0],f2=input[2];
  char *hold = slice_str(input,4,strlen(input));
  char *ret;
  size_t len;

  switch(f1){
    case SPLIT:
      ret = split(hold);
      len = strlen(ret);
      free(hold);
      if(isMethod(ret)){
        ret = realloc(ret,(len-2)*sizeof(char)),len-=2;
        ret[len]=0;
      }
      return ret;
    case COMBINE:
      ret = combine(hold);
      free(hold);
      len=strlen(ret);
      break;
  }

  switch(f2){
    case METHOD:
      if(!isMethod(ret)){
        ret = realloc(ret,(len+2)*(sizeof(char))),len+=2;
        ret[len]=0,ret[len-1]=')',ret[len-2]='(';
      }
      break;
    case CLASS:
      if(isMethod(ret)){
        ret = realloc(ret,(len-2)*(sizeof(char))),len-=2;
        ret[len]=0;
      }
      ret[0]=toupper(ret[0]);
      break;
    case VARIABLE:
      if(isMethod(ret)){
        ret = realloc(ret,(len-2)*(sizeof(char))),len-=2;
        ret[len]=0;
      }
      break;
  }

  return ret;
}

does not accept
*/
