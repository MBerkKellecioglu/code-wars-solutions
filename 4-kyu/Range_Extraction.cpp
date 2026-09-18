#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args){
  
  std::string sol = "", temp_s;
  
  int index = 0, s_index = 0, end_index = 0, i = 0;
  
  for(index = 0; index < args.size(); index++){
    if(abs(args[index] - args[index + 1]) != 1){
      temp_s = std::to_string(args[index]);
      sol += temp_s;
      sol += ","; 
    }
    else{
      if(abs(args[index + 1] - args[index + 2]) != 1){
        temp_s = std::to_string(args[index]);
        sol += temp_s;
        sol += ",";
      }
      else{
        s_index = index;
        for(i = index; i < args.size(); i++){
          if(abs(args[i] - args[i + 1]) != 1){
            break;
          }
        }
        end_index = i;
        index = i;
        temp_s = std::to_string(args[s_index]);
        sol += temp_s;
        sol += "-";
        temp_s = std::to_string(args[end_index]);
        sol += temp_s;
        sol += ",";
      }
    }
  }
  
  sol.erase(sol.begin() + sol.size() - 1);
  
  return sol;
}