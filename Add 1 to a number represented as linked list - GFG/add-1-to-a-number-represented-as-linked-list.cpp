//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node * reverse(Node *head)
    {
        Node *prev=NULL;
        Node *next;
        
        while(head!=NULL)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *newhead=reverse(head);
        Node *curr=newhead;
        
        while(curr)
        {
            if(curr->data+1<10)
            {
                curr->data+=1;
                break;
            }
            
            else
            {
                curr->data=0;
                
                if(curr->next)
                {
                    curr=curr->next;
                }
                
                else
                {
                    Node *newNode=new Node(1);
                    curr->next=newNode;
                    break;
                }
            }
        }
        
        Node *newhead1=reverse(newhead);
        return newhead1;
    
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends