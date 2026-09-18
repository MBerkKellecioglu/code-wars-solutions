#include <vector>

using namespace std; 

int findSmallest(vector <int> list){
  
  int ans = list[0];
  
  for(int i = 1; i < list.size(); i++){
    
    ans = min(ans, list[i]);
  }
  
  return ans;
}