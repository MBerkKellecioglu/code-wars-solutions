#include <list>
#include <iostream>
#include <vector>

using namespace std;

int last_digit(list<int> array){
  
  int a_last_dig, sol, i = 0;
  
  if(array.size() == 0) return 1;
  else if(array.size() == 1) return *array.begin() % 10;
  
  vector<int> arr;
  
  for(int const &c : array){
    arr.push_back(c);
    cout << arr[i] << endl;
    i++;
  }
  
  for(int i = arr.size() - 1; i >= 1; i--){ 
    
    if(arr[i] == 0 && arr[i - 1] == 0) arr[i - 1] = 1;
    else if(arr[i] == 0) arr[i - 1] = 1;
  }
  
  if(arr.size() < 3) arr.push_back(1);
  
  int pattern[10][4] = 
  { 
    {0},
    {1},
    {2, 4, 8, 6},
    {3, 9, 7, 1},
    {4, 6},
    {5},
    {6},
    {7, 9, 3, 1},
    {8, 4, 2, 6},
    {9, 1},
  };
  
  a_last_dig = arr[0] % 10;
  
  if(a_last_dig == 1 || a_last_dig == 5 || a_last_dig == 6) return a_last_dig;
  else if (a_last_dig == 0) return 0;
  else if (a_last_dig == 4) sol = arr[1] % 2 ? 4 : 6;
  else if (a_last_dig == 9) sol = arr[1] % 2 ? 9 : 1;
  else{
    if(arr[1] % 4 == 0) return pattern[a_last_dig][3];
    else if(arr[1] % 4 == 1) return pattern[a_last_dig][0];
    else if(arr[1] % 4 == 2){
      if(arr[2] == 2) return pattern[a_last_dig][3];
      else if(arr[2] == 1) return pattern[a_last_dig][1];
      else return pattern[a_last_dig][3];
    }
    else{
      sol = arr[2] % 2 ? pattern[a_last_dig][2] : pattern[a_last_dig][0];
    }
  }
  
  return sol;
  
  
}