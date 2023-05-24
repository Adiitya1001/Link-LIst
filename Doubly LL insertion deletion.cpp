#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* prev;
		node* next;
		node(int d) : data(d),prev(NULL),next(NULL){};
};

void atHead(node* &head,node* &tail,int data){
	if(head==NULL){
		node* temp=new node(data);
		head=temp;
		tail=temp;
		return;
	}
	node* temp=new node(data);
	head->prev=temp;
	temp->next=head;
	head=temp;
}

void atTail(node* &head,node* &tail,int data){
	if(head==NULL){
		node* temp=new node(data);
		head=temp;
		tail=temp;
		return;
	}
	node* temp=new node(data);
	tail->next=temp;
	temp->prev=tail;
	tail=temp;	
}

int getLength(node* head){
	node* temp=head;
	int count=0;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	return count;
}

void atPos(node* &head,node* &tail,int data,int pos){
	if(pos==0){
		atHead(head,tail,data);
		return;
	}
	if(pos>=getLength(head)){
		atTail(head,tail,data);
		return;
	}
	int  i=1;
	node* temp=head;
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	node * newn=new node(data);
	node* curr=temp->next;
	newn->prev=temp;
	newn->next=curr;
	temp->next=newn;
	curr->prev=newn;
}

void print(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
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
atTail(head,tail,20);
atTail(head,tail,30);
atTail(head,tail,40);
atTail(head,tail,50);
print(head);
atPos(head,tail,16,5);
print(head);
cout<<getLength(head)<<endl;
cout<<head->data<<" "<<tail->data<<endl;


 return 0;
}

