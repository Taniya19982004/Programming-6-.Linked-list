#include<iostream>
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

    void InsertAtPosition(Node* &tail,Node* &head,int position,int d)
    {
        if(position==1)
        {
            insertAtHead(head,d);
            return;
        }
        Node* temp=head;
        int cnt = 1;

        while(cnt<position-1)
        {
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL)
        {
            insertAtTail(tail,d);
            return;
        }

        Node* nodeToInsert=new Node(d);
        nodeToInsert->next=temp->next;
        temp->next=nodeToInsert;
    }

    void deleteNode(int position,Node* &head,Node* &tail)
    {
        if(position==1)
        {
            Node* temp = head;
            head = head->next;
            temp->next=NULL;
            delete temp;
            if (head == NULL)
            tail = NULL;
        }
        else
        {
            Node* curr = head;
            Node* prev = NULL;

            int cnt=1;
            while(cnt<position)
            {
                prev=curr;
                curr=curr->next;
                cnt++;
            }

            if(curr -> next==NULL)
            {
                tail=prev;
            }

            prev -> next = curr -> next;
            curr->next = NULL;
            delete curr;
        }
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
 node1->print(head);
node1->insertAtHead(head,12);
node1->print(head);
 node1->insertAtTail(tail, 13);
  node1->print(head);  

  node1-> InsertAtPosition(tail,head,1,22);
  node1->print(head); 
  Node* obj = new Node();
   obj->deleteNode( 3,head,tail);
    node1->print(head); 
    cout<<"head "<<head->data<<"\n";
    cout<<"tail "<<tail->data<<"\n";
return 0;
}