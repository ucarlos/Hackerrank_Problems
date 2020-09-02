//--------------------------------------------------------------------------------------------------
// Created by Ulysses Carlos on 8/30/20 using Ulysses-H270-HD3.
//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstddef>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int d){
		data=d;
		next=NULL;
	}
};
class Solution{
public:

	Node* insert(Node *head,int data)
	{
		//Complete this method
		Node *temp = new Node(data);
		if (!head){
			return temp;
		}
		// Otherwise seach from head to next nullptr
		Node *current = head;
		Node *next = current->next;
		while (next){
			next = next->next;
			current = current->next;
		}
		// Insert at current
		current->next = temp;
		return head;

	}

	void display(Node *head)
	{
		Node *start=head;
		while(start)
		{
			cout<<start->data<<" ";
			start=start->next;
		}
	}
};
int main()
{
	Node* head=NULL;
	Solution mylist;
	int T,data;
	cin>>T;
	while(T-->0){
		cin>>data;
		head=mylist.insert(head,data);
	}
	mylist.display(head);

}
