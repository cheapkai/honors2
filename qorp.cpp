#include <bits/stdc++.h>

using namespace std;

int L(int k,int n,int a,int b)
{
	if(k==0)return -1;
if(n==0 && k > 0)return 0;

if((n>0) && ((k<=a)&&(k<=b)))return -1;

if(k>a){

	int y = L((k-a),(n-1),a,b);
	if(y==-1){
	y = L((k-b),(n-1),a,b);

if(y==-1){return y;}
else return (y);
	}

	else {
	return (y+1);
	}

}
else if(k>b){
 int y = L((k-b),(n-1),a,b);

if(y==-1){return y;}
else return (y);
}
return 0;
}
int main()
{

int t;cin >> t;
while(t--)
{
int k;int n;int a;int b;
cin >> k;cin >> n;cin >> a;cin >> b;

int m = L(k,n,a,b);
cout << m << endl;
}


return 0;
}
