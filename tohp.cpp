#include <iostream>
using namespace std;
#define M 101
void dfs(int arr[][M],int arf[][M],int n,int i,vector<int>& v)
{
    v[i]=1;
    for(int y=0;y<n;y++)
    if((arr[i][y]==1) && (v[y]==0))
    {
        dfs(arr,arf,n,y,v);
        for(int df=0;df<n;df++)
        arf[i][df] += arf[y][df];
    }
    
}

int main() {
    int t;cin >> t;
    while(t--)
    {
        
        int arr[101][101];int n;cin >> n; int arf[101][101];
        for(int y=0;y<n;y++)
        for(int j=0;j<n;j++)
        {cin >> arr[y][j];arf[y][j]=arr[y][j];}    
        //int arf[101][101];
        //arf = arr;
            vector<int> v(n,0);
            for(int i=0;i<n;i++)
            {
                if(v[i]==0)dfs(arr,arf,n,i,v);
            }
        
for(int gh=0;gh<n;gh++)
for(int tg=0;tg<n;tg++)
{
    if(arf[gh][tg]>0)cout << 1 << " ";
    else cout << 0 << " ";
}
        cout << endl;
    }
	//code
	return 0;
}