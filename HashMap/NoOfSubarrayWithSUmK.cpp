/*   How many subarray are there with sum =k
     Author -Raman Mehta

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
    int t; cin>>t; 
    while(t--){
    int n,k; cin>>n>>k;

    int prefSum=0,ans=0;
    unordered_map<int ,int >m;
    m[0]++; // TO take care of single element Subarray
    for(int i=0;i<n;i++){
        prefSum+=arr[i];
        ans+=m[prefSum-k];  //adding number of prefix with value prefSum - k in left of it .
        m[prefSum]++;
    }
    cout<<ans<<endl;
    }
}
