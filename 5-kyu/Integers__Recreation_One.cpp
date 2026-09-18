#include <utility>
#include <vector>
#include <cmath>

class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n);
    static std::vector <long long> Divisiors(long long n);

};

std::vector<std::pair<long long, long long>> SumSquaredDivisors::listSquared(long long m, long long n){
  
  std::vector<std::pair<long long, long long>> v1;
  std::vector<long long> v2;
  std::pair<long long, long long> p1;
  
  long long sum = 0;
  long long sq;
  
  if(m == 1){
    p1.first = 1;
    p1.second = 1;
    v1.push_back(p1);
    m++;
  } 
  
  for(long long i = m; i <= n; i++){
    v2 = Divisiors(i);
    for(long long j = 0; j < v2.size(); j++){
      sum += pow(v2.at(j),2);
    }
    sq = sqrt(sum);
    if(sq * sq == sum){
      p1.first = i;
      p1.second = sum;
      v1.push_back(p1);
    }
    sum = 0;
  }
              
  return v1;
}


std::vector <long long> SumSquaredDivisors::Divisiors(long long n){
  
  std::vector <long long> v1;
  
  for(long long i = 1; i <= n / 2; i++){
    if(n % i == 0) v1.push_back(i);
    else continue;
  }
  
  v1.push_back(n);
  
  return v1;
}