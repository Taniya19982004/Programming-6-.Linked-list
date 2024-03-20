#include<iostream>
using namespace std;
class Node
{
    public :
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
};
    void insertAtHead(Node* &head,Node* &tail, int d)
    {
       //empty list 
         Node*temp=new Node();
         temp->data=d;
         temp->next=nullptr;

        if(head==nullptr)
        {
            head=temp;
           tail=temp;
        }
        else{
        temp->next=head;
        head->prev=temp;
        head = temp;
        }
        
     }

    void insertAtTail(Node* &head,Node* &tail, int d)
    {
       //empty list 
         Node*temp=new Node();
         temp->data=d;
         temp->next=nullptr;

        if(head==nullptr)
        {
            head=temp;
           tail=temp;
        }
        else{
        temp->prev=tail;
        tail->next=temp;
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

     void reverse(Node* &head,Node* &tail)
    {
        Node* ptr1 = head;
        Node* ptr2 = ptr1->next;

        ptr1 ->next =nullptr;
        ptr2 ->prev = ptr2;
        
        while(ptr2 !=nullptr)
        {
            ptr2->prev=ptr2->next;
            ptr2->next=ptr1;
            ptr1=ptr2;
            ptr2 = ptr2->prev;
        }
    
        tail= head;
        head=ptr1;
    }
    

    

      void InsertAtPosition(Node* &tail,Node* &head,int position,int d)
    {
        getLength(head);
        if(position==1)
        {
            insertAtHead(head,tail,d);
            return;
        }
         if (position > getLength(head) ) {
            cerr << "Invalid position!" << endl;
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

        Node* nodeToInsert=new Node();
         nodeToInsert->data= d;
          nodeToInsert->next=nullptr;

        nodeToInsert->next=temp->next;
         temp->next->prev=nodeToInsert ;
                 
        //nodeToInsert->prev=temp->next;
        
        temp->next=nodeToInsert;
        nodeToInsert->prev=temp;

        
    }



int  main()
{
    Node* head = nullptr;
    Node* tail=nullptr;
    insertAtHead(head,tail,12);
    print(head);
    
    insertAtTail(head,tail,11);
    print(head);
    
    InsertAtPosition(tail,head,2,13);
    print(head);

    InsertAtPosition(tail,head,4,15);
    print(head);

    InsertAtPosition(tail,head,3,15);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    reverse(head,tail);
    cout<<"Reversed linked list is :  "<<"\n";
    print(head);
   return 0;
}
