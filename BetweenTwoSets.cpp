int find_lcd(int x,int y){
  int higher = max(x,y),
      higher_save = higher;
    
  if(x == 0 || y == 0)    return higher;
  
  while(!((higher % x == 0) && (higher % y == 0))){
    higher+=higher_save;
  }
  return higher;
}

int find_lcd_vector(vector<int> a){
  int lcd=a[0];

  for(int i = 1;a.size()>i;i++){
    lcd = find_lcd(lcd,a[i]);
  } 

  return lcd;
}

int find_lowest(vector<int> vec){
  int ret = INT_MAX;
  for(int i = 0; vec.size()>i; i++){
    ret = min(ret,vec[i]);
  }
  return ret;
}

int getTotalX(vector<int> a, vector <int> b){
  int ret = 0,
      lcd = find_lcd_vector(a),
      lcd_save = lcd,
      i=0,
      divisible_on_b=0;

  while(lcd <= find_lowest(b)){
    if(i==b.size()){
      
      i=0;
      if(divisible_on_b == b.size()){
        ret++;
      }
      lcd += lcd_save;
      divisible_on_b = 0;
    }

    if(b[i] % lcd == 0){
      divisible_on_b++;
      
    }
    
    i++;
  }

  return ret;
}
