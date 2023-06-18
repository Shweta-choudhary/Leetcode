//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node * reverse(struct Node *head)
    {
        struct Node *prev=NULL;
        struct Node *next;
        
        while(head)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node* l1=reverse(first);
        struct Node* l2=reverse(second);
        
        struct Node *head=new struct Node(0);
        struct Node *curr=head;
        int carry=0;
        
        while(l1 || l2 || carry==1)
        {
            int sum=0;
            
            if(l1)
            {
                sum+=l1->data;
                l1=l1->next;
            }
            
            if(l2)
            {
                sum+=l2->data;
                l2=l2->next;
            }
            
            sum+=carry;
            curr->next=new struct Node(sum%10);
            curr=curr->next;
            carry=sum/10;
        }
        
        struct Node *result=reverse(head->next);
        return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends