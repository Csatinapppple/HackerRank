import java.io.*;
import java.util.*;

public class Solution {

    public static String split(String input){
    String ret ="";
    boolean first=true;
    for(char ch : input.toCharArray()){
      if(first != true && ch>='A' && ch<='Z')
        ret+=' ';
      
      ret += Character.toLowerCase(ch);
      first=false;
    }
    return ret;
  }

  public static String combine(String input){
    String ret = "";
    boolean spaceFound=false;
    for(char ch : input.toCharArray()){
      if(ch!=' ' && spaceFound){
        ret+=Character.toUpperCase(ch);
        spaceFound=false;
      }else if(ch!=' '){
        ret+=ch; 
      }else{
        spaceFound=true;
      }
    }
    return ret;
  }

  public static boolean isMethod(String input){
    if(input.length()>=3 && 
    input.charAt(input.length()-2) == '(' && 
    input.charAt(input.length()-1)==')')
      return true;
    return false;
  }

  public static String convert(String input){
    char f1 = input.charAt(0);
    char f2 = input.charAt(2);
    String ret = input.substring(4,input.length()); 
    
    switch(f1){
      case 'S':
        ret = split(ret);
        if(isMethod(ret))
          ret = ret.substring(0,ret.length()-2);
        return ret;

      case 'C':
        ret = combine(ret);
        break;
    }
  
    char manipulate[] = ret.toCharArray();
    
    switch(f2){
      case 'C':
        manipulate[0] = Character.toUpperCase(manipulate[0]);
        ret = String.valueOf(manipulate);
        if(isMethod(ret))
          ret = ret.substring(0,ret.length()-2);
        break;
      
      case 'M':
        if(!isMethod(ret))
          ret+="()";
        break;
      case 'V':
        if(isMethod(ret))
          ret = ret.substring(0,ret.length()-2);
        break;
    }

    return ret;
  }

  public static void main(String[]args){
    Scanner s = new Scanner(System.in);
    String input[] = {
      "S;M;plasticCup()",
      "C;V;mobile phone",
      "C;C;coffee machine",
      "S;C;LargeSoftwareBook",
      "C;M;white sheet of paper",
      "S;V;pictureFrame"
    };
    //System.out.println(convert(input[5]));
    while(s.hasNextLine()){
      String in = s.nextLine();
      System.out.println(convert(in));
    }
    s.close();
  }
 
}
