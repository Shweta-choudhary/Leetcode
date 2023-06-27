//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        set<int>s;
        
        struct Node *curr=head1;
        
        while(curr!=NULL)
        {
            s.insert(curr->data);
            curr=curr->next;
        }
        
        curr=head2;
        
        while(curr!=NULL)
        {
            s.insert(curr->data);
            curr=curr->next;
        }
        
        vector<int>v;
        
        for(auto it:s)
        v.push_back(it);
        
        sort(v.begin(),v.end());
        
        struct Node *res=new struct Node(0);
        curr=res;
        
        for(int i=0;i<v.size();i++)
        {
            struct Node *curr2=new struct Node(v[i]);
            curr->next=curr2;
            curr=curr->next;
        }
        
        return res->next;
    }
};


//{ Driver Code Starts.

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
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends