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

node* reverse(node*&head){
	node* prev=NULL;
	node* curr=head;
	node* temp=curr->next;
	while(curr!=NULL){
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
return prev;
}

node* middle(node* head){
	node* slow=head;
	node* fast=head->next;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	cout<<slow->data<<endl;
	return slow;
}

bool palindrome(node* head){
	node* mid=middle(head);
	node* ptr2=mid->next;
	node*ptr1=head;
	mid->next=reverse(ptr2);
	node*ptr=mid->next;
	while(ptr!=NULL){
	if(ptr1->data!=ptr->data){
		return false;
	}	
	else{
		ptr1=ptr1->next;
		ptr=ptr->next;
	}
	}
	return true;
}


void athead(int data,node* &head){
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
node*head=new node(10);
athead(11,head);
athead(12,head);
athead(13,head);
athead(14,head);
athead(14,head);
athead(13,head);
athead(12,head);
athead(16,head);
athead(10,head);
print(head);
head=reverse(head);
cout<<palindrome(head);
//print (head);


 return 0;
}

