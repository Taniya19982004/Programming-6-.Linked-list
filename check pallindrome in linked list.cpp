/*#include<bits/stdc++.h>
using namespace std;
bool pallindrome(vector<int>v,int s,int e)
  {
      if(s>=e)
      {
          return true;
      }
      if(s==e)
      {
        pallindrome(v,s+1,e-1);
      }
      else
      {
          return false;
      }
  }
class Node{
  public:
  int data;
  Node *next;
  Node(int x)
  {
    data=x;
    next=NULL;
  }
  Node ()
  {
    next=NULL;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> v;
        Node *temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->data);
        
        }
        return pallindrome(v,0,v.size()-1);
    }
};
int main()
{
    int n,l;
    Node *head=NULL,*tail=NULL;
    head=new Node(1);
    tail=head;
    for(int i=1;i<n;i++)
    {
        cin>>l;
        tail->next=new Node(l);
        tail=tail->next;

    }
    Node obj;
    cout<<obj.isPalindrome(head);

return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

bool isPalindrome(Node* head) {
    vector<int> v;
    Node* temp = head;
    while (temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int n = v.size();
    for (int i = 0; i < n / 2; ++i) {
        if (v[i] != v[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int firstdata, n, l;
    cin >> firstdata >> n; // Assuming you provide the first data and the number of elements
    Node* head = new Node(firstdata);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        cin >> l;
        tail->next = new Node(l);
        tail = tail->next;
    }
    cout << (isPalindrome(head) ? "Yes" : "No") << endl;
    return 0;
}
