 /* Find the length of Longest Subarray with Sum k
      Author - Raman Mehta
 */
 
 #include<bits/stdc++.h>
 using namespace std;

 
 
  int lenOfLongSubarr(vector<int>&A,  int N, int K) 
  {
    int pref=0,ans=0;
    unordered_map<int,int>m;
    m
    for(int i=1;i<=N;i++)
     {
      pref+=A[i-1];

      if(pref==K)   ans=i;  //handling edge case

      if(m[pref-K]!=0)      //getting pair of P[i] and updating answer
           ans=max(ans,i-m[pref-K]);

      if(m[pref]==0){m[pref]=i;  ;   }  //storing only first occurrence


 }
    return ans;
} 

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<lenOfLongSubarr(v,n,k)<<endl;
    }
}
