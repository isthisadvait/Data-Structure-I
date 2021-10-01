 #include<iostream>
using namespace std;


  struct ListNode {
                 int val;
                ListNode *next;
                
        };


       class stackLL{

                       private:
                                 ListNode *head;
                                 int size;
                      public:
                                stackLL(){
                                              head=NULL;
                                              size=0;
                                         }
                                
             void push(int x);
             int pop();
             int top();
             int getSize();
             bool empty();
};

void stackLL::push(int x){

                     ListNode *temp=new ListNode;
                     temp->next=NULL;
                     temp->val=x;
                     if(head==NULL){
                                       head=temp;
                       }else{
                               temp->next=head;
                               head=temp;
                         }
                    size++;
                   
               }

int  stackLL::top(){
                     
                       if(size==0)
                              {
                                     cout<<"Stack Underflow";
                                       return 0;
                             }
                      return head->data;
     }

void stackLL::pop(){
                 
                     if(size==0)
                         {
                                cout<<"Stack Underflow"; return;
                        }
                   ListNode *temp= head;
                   head= head->next;
                   size--;
                   delete temp;
   }

  int stackLL::getSize(){
                   return size;
  }

 bool stackLL::isEmpty(){
                         return size==0;
}

