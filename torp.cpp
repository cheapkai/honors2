#include <bits/stdc++.h>
using namespace std;
int main()
{

int n;cin >> n;

unordered_map<int , int> m;

int flg=1;
m.insert({n,1});
int k = 1;
while(flg)
{
n = n + 1;

while(n%10==0)
{
n=n/10;
}
if(m.find(n)==m.end()){
k++;m.insert({n,1});
}
else {
flg=0;continue;
}
}
cout << k << endl;

return 0;
}
