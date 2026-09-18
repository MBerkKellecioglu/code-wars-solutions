#include <iostream>
#include <string>

using namespace std;

bool path_finder(string m){
  
  vector<vector<int>> maze;
  vector<int> tmp;
  
  // 0 is wall, 1 is empty //
  
  for(int i = 0; i < m.size(); i++){
    if(m[i] == '.') tmp.push_back(1);
    else if(m[i] == 'W') tmp.push_back(0);
    else{
      maze.push_back(tmp);
      tmp.clear();
    }
  }
  
  maze.push_back(tmp);

  stack<pair<int,int>> cache;
  
  cache.push({0,0});
    
  maze[0][0] = 0;
  
  while(!cache.empty()){
    auto top_pair = cache.top();
    
    int x = top_pair.first;
    int y = top_pair.second;
    
    
    if(x == maze.size() - 1 && y == maze[0].size() - 1) return true;
    
    
    if(x + 1 < maze.size() && maze[x + 1][y]){
      maze[x + 1][y] = 0;
      cache.push({x + 1, y});
    }
    else if(x - 1 > -1 && maze[x - 1][y]){
      maze[x - 1][y] = 0;
      cache.push({x - 1, y});
    }
    else if(y + 1 < maze[0].size() && maze[x][y + 1]){
      maze[x][y + 1] = 0;
      cache.push({x, y + 1});
    }
    else if(y - 1 > -1 && maze[x][y - 1]){
      maze[x][y - 1] = 0;
      cache.push({x, y - 1});
    }
    else cache.pop();
  }
  
  return false;
  
}