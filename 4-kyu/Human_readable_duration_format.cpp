#include <string>
#include <iostream>

#define year 31536000
#define day 86400
#define hour 3600
#define minute 60

std::string format_duration(int seconds){
  
  int count = 0, temp = 0;
  
  std::string sol = "", temp_s = "";
  
  char vr = ',';
  
  if(seconds == 0){
    return "now";
  }
  
  
  if(seconds < 60){
    temp_s = std:: to_string(seconds);
    sol += temp_s;
    sol += " ";
    sol += "seconds";
    if(seconds == 1){
      sol.erase(sol.begin() + sol.size()- 1);
    }
    
    return sol;
  }
  
  
  
  if(seconds >= year){
    count = seconds / year;
    temp = count*year;
    seconds -= temp;
    temp_s = std::to_string(count);
    sol += temp_s;
    sol += " ";
    sol += "years";
    if(count == 1){
      sol.erase(sol.begin() + sol.size()- 1);
    }
    sol += ",";
    sol += " ";
    if(seconds == 0){
      sol.erase(sol.begin() + sol.size()- 1);
      sol.erase(sol.begin() + sol.size()- 1);
    }
  }
  
  
  
  if(seconds >= day){
    count = seconds / day;
    temp = count*day;
    seconds -= temp;
    temp_s = std::to_string(count);
    if(seconds == 0 && (sol.size() > 0)){
      sol.erase(sol.begin() + sol.size()- 1);
      sol.erase(sol.begin() + sol.size()- 1);
      sol += " ";
      sol += "and";
    }
    sol += temp_s;
    sol += " ";
    sol += "days";
    if(count == 1){
      sol.erase(sol.begin() + sol.size()- 1);
    }
    sol += ",";
    sol += " ";
    if(seconds == 0){
      sol.erase(sol.begin() + sol.size()- 1);
      sol.erase(sol.begin() + sol.size()- 1);
    }
  }
  
  
  if(seconds >= hour){
    count = seconds / hour;
    temp = count * hour;
    seconds -= temp;
    temp_s = std::to_string(count);
    if(seconds == 0 && (sol.size() > 0)){
      sol.erase(sol.begin() + sol.size()- 1);
      sol.erase(sol.begin() + sol.size()- 1);
      sol += " ";
      sol += "and";
    }  
    sol += temp_s;
    sol += " ";
    sol += "hours";
    if(count == 1){
      sol.erase(sol.begin() + sol.size()- 1);
    }
    sol += ",";
    sol += " ";
    if(seconds == 0){
      sol.erase(sol.begin() + sol.size()- 1);
      sol.erase(sol.begin() + sol.size()- 1);
    }
  }
  
  
  if(seconds >= minute){
    count = seconds / minute;
    temp = count * minute;
    seconds -= temp;
    temp_s = std::to_string(count);
    if(seconds == 0 && (sol.size() > 0)){
      sol.erase(sol.begin() + sol.size()- 1);
      sol.erase(sol.begin() + sol.size()- 1);
      sol += " ";
      sol += "and";
      sol += " ";
    }
    sol += temp_s;
    sol += " ";
    sol += "minutes";
    if(count == 1){
      sol.erase(sol.begin() + sol.size()- 1);
    }
    if(seconds == 0){
      return sol;
    }
  }
  
  
  if(seconds < 60){
    temp_s = std::to_string(seconds);
    if(sol.at(sol.size() - 2) == ','){
      sol.erase(sol.begin() + sol.size()- 1);
      sol.erase(sol.begin() + sol.size()- 1);
    }
    sol += " ";
    sol += "and";
    sol += " ";
    sol += temp_s;
    sol += " ";
    sol += "seconds";
    if(seconds == 1){
      sol.erase(sol.begin() + sol.size()- 1);
    }
  }
  
  return sol;
}