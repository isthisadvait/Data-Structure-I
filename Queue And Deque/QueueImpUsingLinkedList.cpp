#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class Queue{
    private:
      node *head,*tail;
      int size;
      
      node *getNode(int val){
         node *temp=new node;
         temp->data=val;
         temp->next =NULL;
         return temp;
      }
    public:
     Queue(){
         head=NULL;
         tail=NULL;
         size=0;
     }
     void print(){
         node *temp=head;
         while(temp!=NULL){
             cout<<temp->data;
             if(temp->next==NULL){
                 cout<<endl;
             }else{
                 cout<<"--> ";
             }
             temp=temp->next;
         }
     }
     void enqueue(int val){
         node *temp=getNode(val);
         if(head==NULL){
             head=tail=temp;
         }else{
             tail->next=temp;
             tail=temp;
             
         }
         size++;
     }
     int getSize(){
         return size;
     }
     void dequeue(){
        
         if(head==NULL)
              return;
          node *temp=head;
          head=head->next;
          if(head==NULL){tail=NULL;}
          free(temp);
         
     }
    int front(){
        if(head!=NULL) return head->data;
        else return 0;
    }
    int back(){
        if(tail!=NULL) return tail->data;
        else return 0;
    }
     
     
};
int main() {
    Queue a;
    a.enqueue(5);
    a.enqueue(100);
    cout<<a.front()<<" ";
   
    a.dequeue();
     cout<<a.front()<<" ";
   
    a.dequeue();
    cout<<a.front();
   
    
}

