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
            tail = head; // Update tail if it's the first node
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
Node ::insert_at_tail(tail,head,5);
Node:: print(head);
return 0;
}