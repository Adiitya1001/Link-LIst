#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next=NULL;
		
		node(int d):data(d){};
};

node* reverse(node* prev,node* curr){
	if(curr==NULL){
		return prev;
	}
	node* forw=curr->next;
	curr->next=prev;
	reverse(curr,forw);
	
}


void atHead(node* &head,node* & tail,int data){
	if(head==NULL){
		node* temp=new node(data);
		head=temp;
		tail=temp;
		return;
	}
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
node* tail=head;
atHead(head,tail,60);
atHead(head,tail,70);
atHead(head,tail,80);
atHead(head,tail,90);
atHead(head,tail,100);
print(head);
//node* curr=head;
//node* prev=NULL;
//head=reverse(NULL,head);
node* temp;
node* prev;
node* curr=head;
while(curr!=NULL){
	temp=curr->next;
	curr->next=prev;
	prev=curr;
	curr=temp;
}
print(prev);



 return 0;
}

