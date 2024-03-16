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
    
    void insertAtNode(Node* tail,int element,int d)
    {
        if(tail==NULL)
        {
            Node* newnode=new Node(d);
            newnode->next=newnode;
            newnode=tail;
        }
        else
        {
            Node* curr=tail;
            while(curr->data!=element)
            {
                curr=curr->next;
                if(curr == tail)
            {
                cout << "Element not found in the list!" << endl;
                return;
            }
            }
            Node* temp = new Node(d);
            temp->next=curr->next;
            curr->next=temp;
        
            if( d < tail->data) // If the new node is inserted before tail
        {
            tail = tail->next; // Update the tail to the new node
        }
        }
    }
    void print(Node* tail)
    {
         if(tail == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp =tail;
        do
        {
            /* code */
            cout<<tail->data <<" ";
            tail=tail->next;
            
        } while (tail!=temp);
        cout<<endl;
        
    }

    void deleteatnode(Node* tail, int element)
    {
        if(tail==NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        else{
            Node* prev=tail;
            Node* curr=tail->next;
            while(curr->data !=element)
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
        }

    }
};

int main(){
Node* node1=new Node(3);
Node* tail = node1;

node1->insertAtNode(tail,3,44);
node1->print(tail);

node1->insertAtNode(tail,44,8);
node1->print(tail);

node1->deleteatnode(tail,44);
node1->print(tail);

node1->insertAtNode(tail,3,99);
node1->print(tail);

return 0;
}