#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "Union.h"
using namespace std;
int solution(int n, int m, vector<vector<int>>& vec){
int result = -1;
set<int> fatherpoint;
Union temp(n);
for(int i = 0; i < m; i++)
{
int x = vec[i][0] - 1;
int y = vec[i][1] - 1;
temp.union_build(x, y);
}
for(int i = 0; i < n; i++)
{
if(fatherpoint.find(temp.find(i)) == fatherpoint.end())
{
fatherpoint.insert(temp.find(i));
result++;
}
}
return result;
}
int main() {
int n;
int m;
vector<vector<int>> vec;
cin>>n;
cin>>m;
string line, token;
for (int i = 0; i < m; i++){
vector<int> vvec;
int temp;
cin >> temp;
vvec.push_back(temp);
cin >> temp;
vvec.push_back(temp);
vec.push_back(vvec);
}
int result = solution(n, m,vec);
cout<<result<<endl;
return 0;
}