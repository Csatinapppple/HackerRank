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
