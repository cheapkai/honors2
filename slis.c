// Finding the Longest Increasing Subsequence using  
// Segment Tree 
#include <bits/stdc++.h> 
using namespace std; 
  
// function to compare two pairs 
int compare(pair<int, int> p1, pair<int, int> p2) 
{ 
     /* For same values, element with the higher  
        index appear earlier in the sorted array. 
        This is for strictly increasing subsequence. 
        For increasing subsequence, the lower index  
         appears earlier in the sorted array. */
    if (p1.first == p2.first)  
        return p1.second > p2.second; 
      
    // Sorting the array according to their values. 
    return p1.first < p2.first; 
} 
  
// Building the entire Segment tree, the root of which 
// contains the length of the LIS 
void buildTree(int* tree, int pos, int low, int high,  
                                 int index, int value) 
{ 
    // index is the original index of current element 
    // If the index is not present in the given range,  
    // then simply return 
    if (index < low || index > high) 
        return; 
  
    // If low == high then the current position should  
    // be updated to the value 
    if (low == high) { 
        tree[pos] = value; 
        return; 
    } 
  
    int mid = (high + low) / 2; 
  
    // Recursively call the function on the  
    // child nodes 
    buildTree(tree, 2 * pos + 1, low, mid, index, value); 
    buildTree(tree, 2 * pos + 2, mid + 1, high, index, value); 
  
    // Assign the current position the max of the 2 child  
    // nodes 
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]); 
} 
  
// Function to query the Segment tree and return the 
// value for a given range 
int findMax(int* tree, int pos, int low, int high,  
                               int start, int end) 
{ 
    // Query: Same as the query function of Segment tree 
    // If the current range is totally inside the query  
    // range, return the value of current position 
    if (low >= start && high <= end)  
        return tree[pos]; 
      
    // If it is out of bound, return the minimum which 
    // would be 0 in this case 
    if (start > high || end < low)  
        return 0;     
  
    // Partial overlap 
    int mid = (high + low) / 2; 
  
    // Call findMax on child nodes recursively and  
    // return the maximum of the two 
    return max(findMax(tree, 2 * pos + 1, low, mid,  
                                        start, end),  
               findMax(tree, 2 * pos + 2, mid + 1,  
                                high, start, end)); 
} 
  
int findLIS(int arr[], int n) 
{ 
    // The array of pairs stores the integers and  
    // indices in p[i] 
    pair<int, int> p[n]; 
    for (int i = 0; i < n; i++) { 
        p[i].first = arr[i];  
        p[i].second = i;  
    } 
  
    // Sorting the array in increasing order 
    // of the elements 
    sort(p, p + n, compare); 
  
    // Calculating the length of the segment-tree 
    int len = pow(2, (int)(ceil(sqrt(n))) + 1) - 1; 
    int tree[len]; 
  
    // Initializing the tree with zeroes 
    memset(tree, 0, sizeof(tree));  
  
    // Building the segment-tree, the root node of  
    // which contains the length of LIS for the n 
    // elements 
    for (int i = 0; i < n; i++) { 
        buildTree(tree, 0, 0, n - 1, p[i].second,  
     findMax(tree, 0, 0, n - 1, 0, p[i].second) + 1); 
    } 
      
    return tree[0]; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Length of the LIS: " << findLIS(arr, n); 
    return 0; 
} 