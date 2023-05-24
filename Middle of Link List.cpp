#include<iostream>
using namespace std;

class node{
	public:
		
		int data;
		node* next;
		
		node(int data){
			this->data=data;
			this->next=NULL;
		}
};

node* middle(node* head){
	node* slow=head;
	node* fast=head->next;
	while(fast!=NULL && slow!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
		
	}
	return slow;
}

void atHead(node* &head,int data){
	node* temp=new node(data);
	temp->next=head;
	head=temp;
}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}


int main() {

node* head=new node(10);
atHead(head,9);
atHead(head,8);
atHead(head,7);
atHead(head,6);
atHead(head,5);
atHead(head,4);
atHead(head,3);
atHead(head,2);
atHead(head,1);
print(head);
node* mid;
mid=middle(head);
cout<<mid->data;



 return 0;
}

