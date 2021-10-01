 #include <iostream>
 #include<stack>
 #include<vector>
using namespace std;

void next_greater_element(vector<int>&arr,int n)
{
    vector<int>nge(n,-1);
    stack<int>idx;
    
    for(int i=0;i<n;i++)
     {
        while(!idx.empty()&&arr[idx.top()]<arr[i]){
             nge[idx.top()]=i;
             idx.pop();
        }
        idx.push(i);
     }
    while(!idx.empty()) idx.pop();
           
    for(int x:nge) cout<<x<<" ";
 }
int main() {
    int t; cin>>t;
    while(t--){
    int n; cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
                                            
    next_greater_element(arr,n);
  }
  return 0;
}
                              
