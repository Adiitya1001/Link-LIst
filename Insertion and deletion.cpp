#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next=NULL;
		
		node(int d):data(d){};
};

int lengthList(node* temp){
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
}
return count;
}

void deletep(node* &head,node* & tail,int pos){
	if(pos==1){
		node*temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
		return;
	}
	int len=lengthList(head);

	if(pos>=len){
		node* temp=head;
		int i=1;
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		tail=temp;
		tail->next=NULL;
		temp=temp->next;
		delete temp;
		return;
	}
	int i=1;
	node* temp=head;
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	node * curr=temp->next;
	temp->next=curr->next;
	curr->next=NULL;
	delete curr;
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

void position(node* &head,node* &tail,int data,int pos){
	if(head==NULL){
		node * temp=new node(data);
		head=temp;
		tail=temp;
		return;
	}
	if(pos==0){
	
		atHead(head,tail,data);
		return;
	}
	int len=lengthList(head);
	if(pos>=len){
		atTail(head,tail,data);
		return;
	}
	int i=1;
	node* temp=head;
	while(i<pos){
		i++;
		temp=temp->next;
	}
	node* curr=temp->next;
	node* newn=new node(data);
	newn->next=curr;
	temp->next=newn;
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
atTail(head,tail,20);
atTail(head,tail,30);
atTail(head,tail,40);
atTail(head,tail,50);
atHead(head,tail,60);
atHead(head,tail,70);
atHead(head,tail,80);
atHead(head,tail,90);
atHead(head,tail,100);
position(head,tail,16,9);
print(head);
deletep(head,tail,1);
print(head);
deletep(head,tail,10);
print(head);
cout<<head->data<<" "<<tail->data<<endl;
 return 0;
}

