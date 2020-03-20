#include<iostream>
using namespace std;
#include "Node.h"
template <typename t>
class cllist{
	public:
			Node<t> *cursor;
				cllist<t>(){
				cursor=NULL;
			}
			
			t getFront(Node<t>*cursor){
				Node<t>*p=cursor;
					do{
						p=p->next;
					}
					while(p->next!=cursor);
					return p->data;
			}
			t getBack(Node<t>*cursor){
				if(cursor==NULL){
					cout<<"error: list is empty";
					return 0;
				}
				return cursor->next->data;	
				
			}
			Node<t>* getAdvance(Node<t>*cursor){
				cllist::cursor=cursor->next;
				return cllist::cursor;
			}
			Node<t>* input(t data){
				Node<t>*n;
				while(data!=-1){
					Node<t>*p=new Node<t>(data);
					if(cursor==NULL){
						cursor=p;
						p->next=p;
					}
					else{
						n->next=p;
						n=p;
						p->next=cursor;
					}
					n=p;
					cin>>data;
				}
			}
			void display(Node<t>*cursor){
					Node<t>*p=cursor;
					do{
						cout<<p->data;
						//cout<<"->";
						if(p->next!=cursor){
							cout<<"->";
						}
						p=p->next;
					}
					while(p!=cursor);
			}
			Node <t>* add(t a){
				Node<t>*node=new Node<t>(a);	
				if(cursor==NULL){
					cursor=node;
					return cursor;
				}
				Node<t>*p=cursor->next;
				cursor->next=node;
				node->next=p;
				return cursor;
				
			}
			Node<t>*remove(Node<t>*cursor){
				if(cursor==NULL){
					cout<<"error:list is empty"<<endl;
					return 0;
				}
				else if(cursor->next==cursor){
					delete(cursor);
					return 0;
				}
				else{
					Node<t>*p=cursor->next->next;
					cursor->next=cursor->next->next;
					return cursor;
					
				}
			
			}



};
int main(){
	cllist<int> ob;
	int data;
	cout<<"enter data for LL & enter -1 to terminate"<<endl;
	cin>>data;
	ob.input(data);
	ob.display(ob.cursor);
	ob.add(6);
	ob.remove(ob.cursor);
	int frontval=ob.getFront(ob.cursor);
	cout<<endl<<"value at front is  :  "<<frontval<<endl;
	ob.cursor=ob.getAdvance(ob.cursor);
	int backval=ob.getBack(ob.cursor);
	cout<<endl<<"value at back is  :  "<<backval<<endl;
	
}
