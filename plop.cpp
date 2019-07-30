#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;cin >> t;
while(t--)
{
int n;int k;cin >> n;cin >> k;

vector<int> v;

for(int y=0;y<n;y++)
{
int x;cin >> x;v.push_back(x);
}

sort(v.begin(),v.end());
int g = v[0] + k;int flg=1;
for(int y=1;y<n;y++)
{
if(abs(g - v[y])>k){flg=0;break;}
}
if(flg==0)cout << "-1" << endl;
else cout << g << endl;
}

return 0;
}
