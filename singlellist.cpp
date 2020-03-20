#include<iostream>
#include "Node.h"
using namespace std;
template<class T>
class llist{
public:	
	Node<T>*head;
	Node<T>*tail;
	llist<T>(){
		head=NULL;
		tail=NULL;
	}

Node<T>* input(T data){
	while(data!=-1){
		Node<T>*p=new Node<T>(data);
		if(head==NULL){
			head=p;
			tail=p;
		}
		else{
			tail->next=p;
			tail=p;
		}
		cin>>data;
	}
	return head;
}
void display(Node<T>*head){
		Node<T>*p=head;
		while(p!=NULL){
			cout<<p->data;
			p=p->next;
			if(p!=tail->next){
				cout<<"->";
			}
		}
}

Node<T>* insertAtBeg(T a){
	Node<T>*p=new Node<T>(a);
	if(head==NULL){
		head=p;
		tail=p;
		return head;
	}
	p->next=head;
	head=p;
	return head;
}
Node<T>* insertAtEnd(T a){
	Node<T>*p=new Node<T>(a);
	if(head==NULL){
		head=p;
		tail=p;
		return head;
	}
	tail->next=p;
	tail=p;
	return head;
}

Node<T>* insertByIndex(T n,T b){
	Node<T>*p=head;
	Node<T>*r=new Node<T>(b);
	if(n==0 && head==NULL){
		head=r;
		tail=r;
		return head;
	}
	for(int i=2;i<n;i++){
		p=p->next;
	}
			r->next=p->next;
		    p->next=r;
		    
			return head;
}

void deleteLL(T a){
	Node<T>* p=head;
	Node<T>*prev=NULL;
	if(head->data==a){
		head=p->next;
		delete p;
	}
	
	while(p!=tail->next){
		if(p->data==a){
			prev->next=p->next;
			delete(p);
		}
		prev=p;
		p=p->next;
	}
}
Node<T>*  deleteAtBeg(Node<T>* head){
	Node<T>*p=head;
	if(head==NULL){
		cout<<"list is empty"<<endl;
		return 0;
	}
	head=head->next;
	delete(p);
	cout<<"node at beginning is deleted"<<endl;
	return head;
}
void deleteAtEnd(Node<T>*head){
	Node<T>*p=head;
	if(head==NULL){
		cout<<"list is empty"<<endl;
	}
	while(p->next->next!=NULL){
		p=p->next;
	}
	delete(tail);
	tail=p;
	tail->next=NULL;
}
Node<T>* deleteByPos(int n){ 
	Node<T>*p=head;
	if(n==1){
		head=p->next;
		delete(p);
		return head;
	}
	for(int i=1;i<n-1;i++){
		p=p->next;
	}
	p->next=p->next->next;
	
	//tail=p;
	return head;
	
	
}

Node<T>* reverse(Node<T>*head){
	Node<T>*p=head;
	Node<T>*tail1=tail;
	tail=p;
	head=p->next;
	p->next=NULL;
	//Node*tail1=tail;
	//tail=p;
	Node<T>*r=NULL;
	while(head!=NULL){
	r=head;
	head=r->next;
	r->next=p;
	p=r;
	}
	return r;
}
Node<T>* replace_prevwithnext(T a){
	Node<T>*p=head;
	Node<T>*prev=NULL;
	if(head==NULL){
		cout<<"list is empty"<<endl;
		return 0;
	}
	while(p!=tail->next){
		if(p->data==a){
			if(p==head){
				head=head->next;
				delete(p);
				return head;
			}
			else{
				int temp=p->data;
				p->data=prev->data;
				prev->data=temp;
				return head;
			}
		}
		prev=p;
		p=p->next;
	}
	cout<<"no such value";
	return 0;
}

};


int main(){
 //T val;
 llist<int> ob;
 char a;
 int n,index,num;
 int data,val;
 Node<int> * obhead=NULL;
 do{
 	cout<<"*************menu************";
 	cout<<endl<<"1.create list"<<endl<<"2.display list"<<endl<<"3.delete at beginning"<<endl<<"4.deleteAtEnd"<<endl<<"5.deleteByPos"<<endl;
 	cout<<"6.insertAtBeg"<<endl<<"7.insertAtEnd"<<endl<<"8.insertByIndex"<<endl<<"9.replace_prevwithnext"<<endl<<"10.reverse"<<endl;
 	cout<<endl<<"enter choice"<<endl;
 	cin>>n;
 	switch(n){
 		case 1: cout<<endl<<"enter -1 to stop"<<endl<<"enter input : "<<endl;
 				cin>>data;
 				obhead=ob.input(data);
 				break;
 		case 2: ob.display(obhead);
 				break;
 		case 3: obhead=ob.deleteAtBeg(obhead);
 				ob.display(obhead);
 				break;
 		case 4: ob.deleteAtEnd(obhead);
 				break;
 		case 5: cout<<"enter index whose value has to be deleted"<<endl;
 				cin>>num;
		 		ob.deleteByPos(num);
		 		break;
		case 6: cout<<"enter a value"<<endl;
				cin>>val;
				obhead=ob.insertAtBeg(val);
				break;
		case 7: cin>>val;
				obhead=ob.insertAtEnd(val);
				break;
		case 8: cout<<"enter index  :  ";
				cin>>index;
				cout<<"enter value  :  ";;
				cin>>val;
				obhead=ob.insertByIndex(index,val);
				break;
		case 9: cout<<"enter value to be serached and swapped witth its previous"<<endl;
				cin>>val;
				obhead=ob.replace_prevwithnext(val);
				break;
		case 10: obhead=ob.reverse(obhead);
				 break;
				
	 }
	 cout<<endl<<"do you want to continue?(enter y or Y)"<<endl;
	 cin>>a;
 }
 while(a=='y' || a=='Y');
 
}
