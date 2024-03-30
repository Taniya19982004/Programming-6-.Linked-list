/*#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

node * removeDuplicates( node *head) 
    {
     node *curr=head;
     while(curr!=NULL)
     {
        node *temp=curr->next;
        while(temp!=NULL)
        {
            if(curr->data==temp->data)
            {
                curr->next=temp->next;
                
                curr=curr->next;
                delete(temp);
            }
            else
            {
                curr=curr->next;
            }
        }
        curr=curr->next;
     }
     return head;
    }


int main() {
    int k;
    cout << "Enter the number of nodes\n";
    cin >> k;
    node* head = nullptr;
    node* temp = head;
    for (int i = 0; i < k; i++) {
        int data;
        cin >> data;
        if (head == nullptr) {
            head = temp = new node(data);
        } else {
            temp->next = new node(data);
            temp = temp->next;
        }
    }
    removeDuplicates(head);
    // Printing the linked list
    cout << "Linked list: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}*/

#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        next = nullptr;
    }
};

node* removeDuplicates(node* head) {
  node *curr=head;
     
     while(curr!=NULL)
     {
         node *c_d = curr;
        node *temp=curr->next;
        while(temp!=NULL)
        {
            if(curr->data==temp->data)
            {
                node *duplicate = temp;
                c_d->next=temp ->next;
             //  c_d=c_d->next;
                temp =c_d->next;
                  delete(duplicate);
            }
            else
            {
                temp =temp->next;
                c_d=c_d->next;
            }
        }
        curr=curr->next;
        
     }
     return head;
}

int main() {
    int k;
    cout << "Enter the number of nodes\n";
    cin >> k;
    node* head = nullptr;
    node* temp = head;
    for (int i = 0; i < k; i++) {
        int data;
        cin >> data;
        if (head == nullptr) {
            head = temp = new node(data);
        } else {
            temp->next = new node(data);
            temp = temp->next;
        }
    }
    head = removeDuplicates(head);
    // Printing the linked list
    cout << "Linked list: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}

