#include <vector>
#include <iostream>

bool CheckSurroundings(std::vector< std::vector<int> > field, int x, int y);
int FollowPath(std::vector < std::vector<int> > &field, int x, int y);

bool validate_battlefield(std::vector< std::vector<int> > field){
  
  std::vector <std::vector<int> > big_field;
  
  int ship_style = 0, battleship = 0, cruiser = 0, destroyer = 0, submarine = 0;
  
  std::vector <int> field_parts (12,0);
  
  for(int i = 0 ; i < 12; i++) big_field.push_back(field_parts);
  
  for(int i = 1; i < 11; i++){
    for(int j = 1; j < 11; j++) big_field.at(i).at(j) = field.at(i - 1).at(j-  1);
  }
  
  
  for(int i = 1; i < 11; i++){
    for(int j = 1; j < 11; j++){
      if(big_field.at(i).at(j) == 0) continue;
      if(CheckSurroundings(big_field, i, j)) continue;
      else return false;
    }
  }
  
  for(int i = 1; i < 11; i++){
    for(int j = 1; j < 11; j++){
      if(big_field.at(i).at(j) == 0 || big_field.at(i).at(j) == 2) continue;
      else{
        ship_style = FollowPath(big_field, i, j);
        if(ship_style == 4) battleship++;
        else if(ship_style == 3) cruiser++;
        else if(ship_style == 2) destroyer++;
        else submarine++;
      }
    }
  }
  
  if((battleship != 1) || (cruiser != 2) || (destroyer != 3) || submarine != 4) return false;
  else return true;
  
}

bool CheckSurroundings(std::vector< std::vector<int> > field, int x, int y){
  
  int one_count = 0;
  
  if(field.at(x - 1).at(y - 1) == 1 || field.at(x - 1).at(y + 1) || field.at(x + 1).at(y - 1) || field.at(x + 1).at(y + 1)) return false;
  
  for(int i = x - 1; i < x + 2; i++){
    for(int j = y - 1; j < y + 2; j++){
      if(i == x && j == y) continue;
      if(field.at(i).at(j) == 1) one_count++;
      if(one_count > 2) return false;
    }
  }
  
  return true;
}

int FollowPath(std::vector < std::vector<int> >&field, int x, int y){
  
  // 1 means submarine || 2 means destroyer || 3 means cruiser || 4 means battleship //
  
  int ship_type = 0, dir = 0;
  
  if(field.at(x).at(y + 1) == 1) dir = 1;
  else if(field.at(x + 1).at(y) == 1) dir = 2;
  else return 1;
  
  if(dir == 1){
    for(int i = y; i < y + 4; i++){
      if(field.at(x).at(i) == 0) break;
      ship_type++;
      field.at(x).at(i) = 2;
    }
  }
  
  if(dir == 2){
    for(int i = x; i < x + 4; i++){
      if(field.at(i).at(y) == 0) break;
      ship_type++;
      field.at(i).at(y) = 2;
    }
  }
  
  return ship_type;
}