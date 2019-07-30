#include <bits/stdc++.h>

using namespace std;

int main()
{
int n;cin >> n;

queue<int> q4;queue<int> q8;queue<int> q15;queue<int> q16;queue<int> q23;queue<int> q42;
for(int y=1;y<=n;y++)
{
int op;cin >> op;
switch(op)
{
	case 4 : q4.push(op);break;
	case 8 : q8.push(op);break;
	case 15 : q15.push(op);break;
	case 16 : q16.push(op);break;
	case 23 : q23.push(op);break;
	case 42 : q42.push(op);break;
	default : break;	  
}
}
int flg = 1;
int cl=0;
while(flg)
{
	if(q4.empty()){flg=0;cl=0;continue;}
int pr = q4.front();q4.pop();
while(!q8.empty() && (q8.front()<=pr))q8.pop();
if(q8.empty()){flg=0;cl=1;continue;}
pr = q8.front();q8.pop();
while(!q15.empty() && (q15.front()<=pr))q15.pop();
if(q15.empty()){flg=0;cl=2;continue;}
pr = q15.front();q15.pop();
while(!q16.empty() && (q16.front()<=pr))q16.pop();
if(q16.empty()){flg=0;cl=3;continue;}
pr = q16.front();q16.pop();
while(!q23.empty() && (q23.front()<=pr))q23.pop();
if(q23.empty()){flg=0;cl=4;continue;}
pr = q23.front();q23.pop();
while(!q42.empty() && (q42.front()<=pr))q42.pop();
if(q42.empty()){flg=0;cl=5;continue;}
pr = q42.front();q42.pop();
}

int ans = q4.size() + q8.size() + q15.size() + q16.size() + q23.size() + q42.size() + cl;
cout << ans << endl;
return 0;
}
