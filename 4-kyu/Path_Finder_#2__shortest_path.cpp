#include <iostream>
#include <string>
#include <queue>

using namespace std;

int shortestPath(vector<vector<int>> maze, int dist, int& min_dist, int x, int y, int&);

int path_finder(string m) {
  
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
  
  queue<pair<pair<int,int>, int>> cache;
  
  cache.push({{0,0}, 0});
  
  maze[0][0] = 0;
  
  int min_dist = maze.size() * maze.size();
  
  while(!cache.empty()){
    int x = cache.front().first.first;
    int y = cache.front().first.second;
    int dist = cache.front().second;
    
    
    if(x == maze.size() - 1 && y == maze[0].size() - 1) return cache.front().second;
    
    cache.pop();
    
    if(x + 1 < maze.size() && maze[x + 1][y]){
      maze[x + 1][y] = 0;
      cache.push({{x + 1, y}, dist + 1});
    }
    if(x - 1 > -1 && maze[x - 1][y]){
      maze[x - 1][y] = 0;
      cache.push({{x - 1, y}, dist + 1});
    }
    if(y + 1 < maze[0].size() && maze[x][y + 1]){
      maze[x][y + 1] = 0;
      cache.push({{x, y + 1}, dist + 1});
    }
    if(y - 1 > -1 && maze[x][y - 1]){
      maze[x][y - 1] = 0;
      cache.push({{x, y - 1}, dist + 1});
    }
  }
  return -1;
}