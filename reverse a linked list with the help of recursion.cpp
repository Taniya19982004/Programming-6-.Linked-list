#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node*next;
    Node()
    {
        this->next=NULL;
    }

    static void insert_at_head(Node* &head,Node* &tail,int d)
    {
        Node* temp=new Node();
        temp->data=d;
        temp->next = head;
        head = temp;
        if (tail == nullptr) {
            tail = head = temp; // Update tail if it's the first node
        }
        
    }

    static void insert_at_tail(Node* &tail,Node* &head,int d)
    {
        Node* temp = new Node();
        temp->data = d;
        temp->next = nullptr;
        if (tail == nullptr) {
            head = tail = temp; // If list is empty, head and tail both point to the new node
        } else {
            tail->next = temp; // Link the new node to the end of the list
            tail = temp; // Update tail to the new node
        }

    }

    static void insert_at_position(Node* &tail,Node* &head,int position,int d)
    {
        if(position==1)
        {
            insert_at_head(head,tail,d);
            return;
        }
        int count = 1;
        Node* temp = head;
        while(count<position-1)
        {
            temp=temp->next;
            count++;
        }
        if (temp == nullptr)
    {
        cerr << "Invalid position\n";
        return;
    }
        Node* insert_at_position = new Node();
        insert_at_position->data = d;
        insert_at_position->next = nullptr;
        insert_at_position->next = temp->next;
        temp->next = insert_at_position;
         
        if(temp->next == nullptr)
        {
            insert_at_tail(tail,head, d);
            return;
        }

    }

    static void reverse(Node* &head,Node* &tail)
    {
        Node* prev=nullptr;
        Node* curr = head;
        Node* forward = nullptr;

        while(curr!=nullptr)
        {
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
    
        tail= head;
        head=prev;
    }

    static void print(Node* &head)
    {
        Node *temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
       
};
int main(){
Node* head = nullptr;
Node* tail = nullptr;


Node::insert_at_head(head,tail,1);
Node::insert_at_tail(tail,head,5);
Node:: print(head);
Node ::insert_at_tail(tail,head,6);
Node:: print(head);
Node::insert_at_position(tail,head,2,4);
Node:: print(head);
Node:: reverse(head,tail);
Node:: print(head);
return 0;
}
