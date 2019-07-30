#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define M 21
typedef struct T{
   int ds;int x;int y; 
}T;


bool isValid(int x,int y,int n,int m)
{
    if((x>=0) && (x<n) && (y<m) && (y>=0))return true;
    return false;
}

struct cm {
  bool operator()(T const& a,T const& b)
  {
      return (a.ds > b.ds); 
  }
};


void dj(priority_queue<T,vector<T>,cm> pq,int ar1[][M],int ar2[][M],int  arr[][M],int n,int m)
{
    while((!pq.empty()) && (ar1[pq.top().x][pq.top().y]==1))pq.pop();
    
    if(!pq.empty())
    {
        int x = pq.top().x;int y = pq.top().y;
        ar1[x][y]=1;
        cout << "pal" << " ";cout << x << " ";cout << y << " ";
        if(arr[x][y] == 1){cout << "kap" << endl;cout << x << " ";cout << y << " ";cout << endl;
        cout << ar1[x][y] << " ";cout << ar2[x][y] << " ";cout << endl;
        //_Exit(0);
        if(isValid(x+1,y,n,m) && ar1[x+1][y]==-1){if((ar2[x+1][y]>(ar2[x][y]+1)) || (ar2[x+1][y]==-1))ar2[x+1][y]= ar2[x][y]+1;pq.push({ar2[x+1][y],x+1,y});}
        if(isValid(x-1,y,n,m) && ar1[x-1][y]==-1){if((ar2[x-1][y]>(ar2[x][y]+1)) || (ar2[x-1][y]==-1))ar2[x-1][y]=ar2[x][y]+1;pq.push({ar2[x-1][y],x-1,y});}
        if(isValid(x,y+1,n,m) && ar1[x][y+1]==-1){if((ar2[x][y+1]>(ar2[x][y]+1)) || (ar2[x][y-1]==-1))ar2[x][y+1]= ar2[x][y]+1;pq.push({ar2[x][y+1],x,y+1});}
        if(isValid(x,y-1,n,m) && ar1[x][y-1]==-1){if((ar2[x+1][y]>(ar2[x][y]+1)) || (ar2[x][y+1]==-1))ar2[x][y-1]=ar2[x][y]+1;pq.push({ar2[x][y-1],x,y-1});}
        }
    pq.pop();
        dj(pq,ar1,ar2,arr,n,m);
    }
    
}
int main() {
    int t; cin >> t;
    while(t--)
    {
        int n;int m;cin >> n;cin >> m;
        int arr[21][21];
        for(int y=0;y<n;y++)
        for(int j=0;j<m;j++)
        cin >> arr[y][j];
        int x;int y;cin >> x;cin >> y;
        int ar1[21][21]={-1};
        int ar2[21][21]={-1};
        cout << ar2[x][x] << endl;cout << "kott" << endl;
        priority_queue<T,vector<T>,cm> pq;
        ar2[0][0] = 0;
        pq.push({0,0,0});
        dj(pq,ar1,ar2,arr,n,m);
        cout << ar2[x][y] << endl;
        
    }
	//code
	return 0;
}