#include<iostream>
#include<string>

using namespace std;

struct Stack{
	char data;
	struct Stack *next;
};
typedef struct Stack *Node;
Node createNode(char value){
	Node node;
	node =new Stack();
	node->data=value;
	node->next=NULL;
	return node;
}
Node push(Node head,char c){
	Node temp=createNode(c);
	if(head==NULL){
		head=temp;
	}
	else{
		temp->next=head; 
		head=temp;
	}
	return head;
}
Node pop(Node head){
	if(head==NULL){
		cout<<"List rong!!";
	}else{
		head=head->next;
	}
	return head;
}
char get(Node head,int index){
	int k=0;
	Node p=head;
	while(p->next!=NULL&&k!=index){
		p=p->next;
		k++;
	}
	return p->data;
}
Node init(){
	Node p;
	p=NULL;
	return p;
}
bool check(string s){
	Node head=init();
	for(int i=0;i<s.length();i++){
		char c=s.at(i);		
		if(c=='['||c=='('){
			head=push(head,c);
		}else if(c==')'){
			if(head->data!='(')return false;
			head=pop(head);
		}else if(c==']'){
			if(head->data!='[')return false;
			head=pop(head);
		}
	}
	if(head==NULL)return true;
	else return false;
}
int main(){
	string s;
	cout<<"Nhap bieu thuc : ";cin>>s;
	if(check(s)==false)cout<<"Khong hop le";
	else cout<<"Hop le";	
}
