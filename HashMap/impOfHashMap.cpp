/*     Implementation Of HashMap Using Chaining And Linear Probing

        Author - Raman Mehta
  */
#include<bits/stdc++.h>
using namespace std;

class HashMapChaining{
    private:
    int B;
    int sz;
    vector<pair<int,string>>v[20];//Phone Number -> Name
    public:
    HashMap(){
        B=20;
        sz=0;
    }
    int hash(int key){
        return key%B;

    }
    void insert(int phone,string name){
        int idx=hash(phone);
        v[idx].push_back({phone,name});
        sz++;
    }
    void remove(int phone){
        int idx=hash(phone);
        int n=v[idx].size();
        for(int i=0;i<n;i++){
            if(v[idx][i].first==phone){
                  swap(v[idx][i],v[idx][n-1]);
                  v[idx].pop_back();
                  cout<<"Value Found And deleted Successfully\n";
                  return;
            }
        }
        cout<<"No Value Found\n";
    }
    string search(int phone){
        int idx=hash(phone);
        for(auto &ele:v[idx])
        {
            if(ele.first==phone){
                return ele.second;
            }
        }
        return "NIL";
    }
    void print(){
        for(int i=0;i<B;i++){
            cout<<"In Bucket "<<i<<" -> ";
            for(auto &ele:v[i]){
                cout<<"{ "<<ele.first<<" "<<ele.second<<" } ";
            }
            cout<<endl;
        }
    }
};
class HashMapProbing{
    private:
    int B;
    int sz;
    pair<int,string>v[7];//Phone Number -> Name
    bool isFresh[7];
    public:
    HashMapProbing(){
        B=7;
        sz=0;
        for(int i=0;i<B;i++){
            v[i]={-1,"NIL"};
            isFresh[i]=true;
        }
    }
    int hash(int key){
        return key%B;

    }
    void insert(int phone,string name){
        for(int i=0;i<B;i++){
           int idx=hash(phone+i);
           if(isFresh[idx]==true){
               v[idx]=make_pair(phone ,name);
               break;
           }
        }
        sz++;
    }
    void remove(int phone){
        for(int i=0;i<B;i++){
           int idx=hash(phone+i);
           
           if(isFresh[idx]==true){
               return;
           }else if(v[idx].first==phone){
              v[idx].second="NIL";
              return;
           }
        }
    }
    string search(int phone){
         for(int i=0;i<B;i++){
           int idx=hash(phone+i);
           if(isFresh[idx]==true){
               return "NIL";
           }else if(v[idx].first==phone){
               return v[idx].second;
           }
        }
    }
    void print(){
        for(int ele=0;ele<B;ele++){
            cout<<"In Bucket "<<ele<<" -> ";
            cout<<"{ "<<v[ele].first<<" "<<v[ele].second<<" }\n ";
        }
    }
};
int main(){
   HashMapProbing H;
   H.insert(123,"Ram");
   H.insert(234,"Raman");
   H.insert(345,"Ananad");
   H.insert(143,"Sezal");
   H.print();

}
