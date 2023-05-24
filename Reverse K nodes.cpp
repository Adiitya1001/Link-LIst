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
void print(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void atTail(node* & tail,int data){
	node* temp=new node(data);
	tail->next=temp;
	tail=temp;
}
int getLength(node* head) {
        int len = 0;
        node* temp = head;
        while(temp != NULL) {
                temp = temp -> next; 
                len++;
        }
        return len;
}

node* reverseKNode(node*& head,int k){
//	if(head==NULL){
//		return NULL;
//	}
//	int len = getLength(head);
//        if(k > len) {
//                //cout << "Enter valid value for k " << endl;
//                return head;
//        }
	int count	=0;
	node* prev=NULL;
	node* curr=head;
	node* forw=curr->next;
	while(count<k){
		forw=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forw;
		count++;
	}
//	print(head);
	if(forw!=NULL){
		head->next=reverseKNode(forw,k);
	}
	return prev;
}




int main() {
node* tail=new node(10);
node* head=tail;
atTail(tail,20);
atTail(tail,30);
atTail(tail,40);
atTail(tail,50);
atTail(tail,60);
atTail(tail,70);
atTail(tail,80);
atTail(tail,90);
atTail(tail,100);
print(head);
head=reverseKNode(head,2);
print(head);


 return 0;
}

