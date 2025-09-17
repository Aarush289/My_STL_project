#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
  int value;
  Node* next;
  Node(int v){value = v;next=NULL;}
};
class linked_list{
  private:
    Node* head;
  public:
    linked_list():head(NULL){}
    void push_end(int val){
      Node* temp=head;
      Node* ne = new Node(val);
      if(!head){head = ne;return;}
      while(temp && temp->next){temp = temp->next;}
      temp->next = ne;
    }
    void push_front(int val){
      Node* temp=head;
      Node* ne = new Node(val);
      if(!head){head = ne;return;}
      ne->next = head;
      head = ne;
    }
    void delete_(int val){
      Node* temp = head;
      Node* prev =NULL;
      while(temp){
        if(temp->value==val){break;}
        prev = temp;
        temp = temp->next;
      }
      if(!temp){return;}
      if(temp==head){
        head = temp->next;
        delete temp;
      }
      else{
          prev->next = temp->next;
          delete temp;
      }
    }
    Node* reverseFirstK(int k) {
      if (!head || k <= 1) return head;

      Node* prev = nullptr;
      Node* curr = head;
      Node* next = nullptr;

      int count = 0;
      while (curr && count < k) {
          next = curr->next;     // store next
          curr->next = prev;     // reverse link
          prev = curr;           // advance prev
          curr = next;           // advance curr
          ++count;
      }

      // head is now the tail of the reversed block
      head->next = curr;         // attach the remainder (could be nullptr)

      // prev is the new head of the list
      head = prev;
      return prev;
  }
  void rotate(int k){
    Node* temp = head;
    int count=0;
    while(temp){count++;temp = temp->next;}
    temp = head;
    k%=count;
    Node* prev = nullptr;
    int l = (count-k)%count;
    if(l==0){return;}
    while(l--){
      prev = temp;
      temp = temp->next;
    }
    Node* temp1 = head;
    head = temp;
    prev->next =NULL;
    while(temp->next){temp = temp->next;}
    temp->next = temp1;
  }
  void print(){
    Node* temp = head;
    while(temp){
      cout << temp->value << " " ;
      temp = temp->next;
    }
    cout << endl;
  }

};

int main(){
  linked_list l;
  int n;
  cin >> n;
  while(n--){
    string str;
    cin >> str;
    if(str=="NEW"){}
    if(str=="PUSH_BACK"){
      int k; cin >>k;
      l.push_end(k);
    }
    if(str=="PUSH_FRONT"){
      int k ; cin >> k;
      l.push_front(k);
    }
    if(str=="REVERSE"){
      int k; cin >>k;
      l.reverseFirstK(k);
    }
    if(str=="ROTATE"){
      int k;
      cin >>k;
      l.rotate(k);
    }
    l.print();
  }
}