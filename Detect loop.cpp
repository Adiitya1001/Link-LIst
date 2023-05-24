#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next=NULL;
		
		node(int d):data(d){};
};

bool detectLoop(node* head){
	node*slow=head;
	node*fast=head;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
		if(fast==slow){
			return true;
		}
	}
	return false;
}
node* deleteLoop(node* head){
	node* slow=head;
	node* fast=head;
	node* prev=NULL;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
		if(slow==fast){
			slow=head;
			break;
		}
	}
	while(slow!=fast){
		prev=fast;
		fast=fast->next;
		slow=slow->next;
	}
	prev->next=NULL;
	return slow;
}

void atTail(node* &head,node* & tail,int data){
	if(head==NULL){
		node* temp=new node(data);
		head=temp;
		tail=temp;
		return;
	}
	node* temp=new node(data);
	tail->next=temp;
	tail=temp;
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
node*tail=head;
node* first=new node(20);
node* two=new node(30);
node* three=new node(40);
node* four=new node(50);
node* five=new node(60);
node* six=new node(70);
node* seven=new node(80);
head->next=first;
first->next=two;
two->next=three;
three->next=four;
four->next=five;
five->next=six;
six->next=seven;
seven->next=four;
//print(head);

cout<<detectLoop(head);
node*ans=deleteLoop(head);
cout<<endl<<detectLoop(head);
cout<<ans->data;



 return 0;
}

