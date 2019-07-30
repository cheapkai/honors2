#include <bits/stdc++.h>

using namespace std;

int main()
{

	int t;cin >> t;
	while(t--)
	{
		//vector<int> v;
int n;cin >> n;int a=0;int b=0;int c = 0;
for(int y=0;y<n;y++)
{
int uh;cin >> uh;int uu = uh % 3;
if(uu == 0)a++;
else {if(uu == 1)b++; else c++;}
}
int d = ((b<c)?b:c);
b = b - d; c = c - d;
d += (b/3) + (c/3);
d += a;

cout << d << endl;

	}

return 0;
}
