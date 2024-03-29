#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
      Node()
    {   
        this->next=NULL;
    }
    

   ~Node(){
        int value = this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node data "<<value<<endl;
    }

    void insertAtHead(Node* &head, int d)
    {
        Node*temp=new Node(d);
        temp->next=head;
        head = temp;
    }

      void insertAtTail(Node* &tail, int d)
    {
        Node*temp=new Node(d);
        tail->next=temp;
        tail = temp;
    }

   
     bool detect_loop(Node* head)
    {
        if(head==NULL)
        {
            return false;
        }
        map<Node*,bool> visited;
        Node*temp=head;
        while(temp!=NULL){
        if(visited[temp]==true)
        {
            cout<<"creating a loop\n";
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
        }
        return false;
    }


    void print(Node* &head)
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
Node* node1 = new Node(10);

Node* head = node1;
Node* tail = node1;
 
   node1->insertAtHead(head,12);
   node1->insertAtTail(tail, 13);
  node1->insertAtTail(tail, 22);
  
   node1->print(head); 

   tail->next=head->next;
   cout<<node1->detect_loop( head)<<endl;
  
    
    cout<<"head "<<head->data<<"\n";
    cout<<"tail "<<tail->data<<"\n";
return 0;
}