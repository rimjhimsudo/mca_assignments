#include<iostream>
using namespace std;
#include "Dllnode.h"
template<class T>
class dllist{
public:	
	Node<T>*head;
	Node<T>*tail;
	dllist<T>(){
		head=NULL;
		tail=NULL;
	}
	
	Node<T>* insertAtBeg(T a){
		Node<T>*p=new Node<T>(a);
		if(head==NULL){
			p->prev=NULL;
			p->next=NULL;
			head=p;
			tail=head;
			return head;
		}
		p->next=head;
		head->prev=p;
		head=p;
		return head;
	}
	Node<T>* insertAtEnd(T a){
		Node<T>*p=new Node<T>(a);
		if(head==NULL){
			p->prev=NULL;
			p->next=NULL;
			head=p;
			tail=head;
			return head;
		}
		tail->next=p;
		p->prev=tail;
		tail=p;	
		return head;
	}
	Node<T>* insertAtPos(int index, T a){
		Node<T>*p=new Node<T>(a);
		Node<T>*r=head;
		Node<T>*q=NULL;
		if(head==NULL || index==0){
			head=insertAtBeg(a);
			return head;
		}
		else{
			for(int i=0;i<(index-1);i++){
				r=r->next;
			}
			q=r->next;
			r->next=p;
			p->next=q;
			q->prev=p;
			return head;
		}
	}
	void deleteAtBeg(Node<T>*head){
		if(head==NULL){
			cout<<"list is empty"<<endl;
			//return 0;
		}
		Node<T>*p=head;
		dllist::head=head->next;
		head->prev=NULL;
		delete(p);
		//return head;		
	}
	void deleteAtend(Node<T>*head){
		if(head==NULL){
			cout<<"list is empty"<<endl;
			//return 0;
		}
		Node<T>*p=tail->prev;
		Node<T>*temp=tail;
		p->next=NULL;
		delete(temp);
		tail=p;
	}
	Node<T>*reverse(Node<T>*head){
		Node<T>*temp1=head;
		head=head->next;
		Node<T>*r=NULL;
		Node<T>*temp2=NULL;
		temp1->next=NULL;
		tail=temp1;
		temp1->prev=head;
		while(head!=NULL){
			r=head;
			head=head->next;
			r->prev=head;
			r->next=temp1;
			temp1=r;
			r=r->next;
		}
		return r->prev; //or return temp1;
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
	
};
int main(){
	dllist<int> ob;
	Node<int>*head=NULL;
	head=ob.insertAtBeg(1);
	ob.display(head);
	cout<<endl;
	head=ob.insertAtBeg(0);
	ob.display(head);
	cout<<endl;
	head=ob.insertAtEnd(3);
	ob.display(head);
	cout<<endl;
	head=ob.insertAtEnd(4);
	ob.display(head);
	cout<<endl;
	head=ob.insertAtEnd(5);
	ob.display(head);
	cout<<endl;
	head=ob.insertAtEnd(6);
	ob.display(head);
	cout<<endl;
	ob.deleteAtend(head);
	ob.display(head);
	cout<<endl;
	//Node<int>*head1=ob.deleteAtBeg(head);
	ob.deleteAtBeg(head);
	ob.display(ob.head);
	cout<<endl;
	//ob.head=head1;
	head=ob.insertAtEnd(7);
	ob.display(head);
	cout<<endl;
	head=ob.insertAtEnd(8);
	ob.display(head);
	cout<<endl;
	head=ob.insertAtEnd(9);
	cout<<endl;
	ob.display(head);
	head=ob.insertAtPos(2,2);
	cout<<endl;
	ob.display(head);
	cout<<endl;
	head=ob.reverse(head);
	ob.display(head);
}








	

