//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     vector<int>v;
     
     Node *curr=head;
     
     while(curr!=NULL)
     {
         v.push_back(curr->data);
         curr=curr->next;
     }
     
     unordered_map<int,int>mp;
     
     for(int i=0;i<v.size();i++)
     mp[v[i]]++;
     
     vector<int>v1;
     
     for(int i=0;i<v.size();i++)
     {
         if(mp[v[i]]!=0)
         {
             v1.push_back(v[i]);
             mp[v[i]]=0;
         }
     }
     
     Node *head1=new Node(0);
     curr=head1;
     
     for(auto it:v1)
     {
         Node *n=new Node(it);
         curr->next=n;
         curr=curr->next;
     }
     
     return head1->next;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends