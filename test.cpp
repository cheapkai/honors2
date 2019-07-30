#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
unordered_map<int, int> umap;
umap[1]=2;

cout << umap[1] << endl;

cout << umap[50] << endl;

return 0;
}
