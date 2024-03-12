#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

     Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    
     Node()
    {
        this->next=NULL;
        this->prev=NULL;
    }
     void insertAtHead(Node* &head,Node* &tail, int d)
    {
       //empty list 
         Node*temp=new Node(d);

        if(head==NULL)
        {
            temp=head;
            temp=tail;
        }
        else{
        temp->next=head;
        head->prev=temp;
        head = temp;
        }
      
    } 
    
     void deleteNode(int position,Node* &head,Node* &tail)
    {
        if(position==1)
        {
            Node* temp = head;
            head = head->next;
             temp->next->prev=NULL;
            temp->next=NULL;
            delete temp;
            if (head == NULL)
            tail = NULL;
        }
        else
        {
            //In middle and last position
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
            prev= curr->next->prev  ;
            curr->prev=NULL;
            curr->next=NULL;

            delete curr;
        }
    }
     void insertAtTail(Node* &tail,Node* &head, int d)
    {
         Node*temp=new Node(d);

        if(tail==NULL)
        {
            temp=tail;
            temp=head;
        }
        else
        {
        tail->next=temp;
        temp->prev=tail;
        tail = temp;
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

      void InsertAtPosition(Node* &tail,Node* &head,int position,int d)
    {
        if(position==1)
        {
            insertAtHead(head,tail,d);
            return;
        }
         if (position > getLength(head) ) {
            cout << "Invalid position!" << endl;
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
            insertAtTail(tail,head,d);
            return;
        }

        Node* nodeToInsert=new Node(d);
        nodeToInsert->next=temp->next;
         temp->next->prev=nodeToInsert ;
                 
        nodeToInsert->prev=temp->next;
        
        temp->next=nodeToInsert;
        nodeToInsert->prev=temp;
    }


    int getLength(Node* &head)
    {
        int len=0;
        Node *temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
    
};
int main(){
Node* node1 = new Node(10);
Node* head=node1;
Node* tail=node1;

node1->print(head);
cout<<"length of the list "<<node1->getLength(head)<<"\n";

node1->insertAtHead(head,tail,12);
node1->print(head);

node1->insertAtTail(tail,head,13);
node1->print(head);

node1-> InsertAtPosition(tail,head,1,22);
node1->print(head); 

node1-> InsertAtPosition(tail,head,6,25);
node1->print(head); 

node1-> InsertAtPosition(tail,head,2,25);
node1->print(head); 

Node* obj = new Node();
obj->deleteNode( 3,head,tail);
node1->print(head); 
    cout<<"head "<<head->data<<"\n";
    cout<<"tail "<<tail->data<<"\n";
return 0;
}