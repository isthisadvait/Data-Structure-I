#include <iostream>
#include<stack>
#include<vector>
using namespace std;
void previous_greater_element(vector<int>&arr,int n)
  {
     stack<int> s;
     s.push(0);
     vector<int>ans ;
     ans.push_back(-1) ;
  
    for (int i = 1; i < n; i++) {
  
       while (!s.empty() && arr[s.top()] < arr[i])   s.pop();
       s.empty() ?ans.push_back(-1):ans.push_back(s.top()) ;
       s.push(i);
    }
   for(int x:ans) cout<<x<<" ";
}
int main() {
 int t; cin>>t;
 while(t--){
     int n; cin>>n;
     vector<int>arr(n);
     for(int i=0;i<n;i++)   cin>>arr[i];
     previous_greater_element(arr,n);
  }
     return 0;
}
