#include<iostream>
using namespace std;

Node *removeDuplicates(Node *head)
{
 Node* temp=head;
 Node* forward=head->next;
 while(temp!=NULL && forward!=NULL){
     if(temp->data==(forward->data)){
         temp->next=forward->next;
         forward=forward->next;
     }
        else{
             temp=temp->next;
         forward=forward->next;
         }
     
 }
 return head;
}

int main() {





 return 0;
}

