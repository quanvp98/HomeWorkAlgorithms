#include<iostream>

using namespace std;

struct List{
	int data;
	struct List *next;
};
typedef struct List *Node;
Node createNode(int value){
	Node node;
	node =new List();
	node->data=value;
	node->next=NULL;
	return node;
}
Node addTail(Node head,int value){//head la phan tu dau tien cua list
	Node temp,p;
	temp = createNode(value);
	if(head==NULL){//neu chua ton tai head
		head=temp;//khoi tao head bang temp
	}
	else{//neu co head r
		p=head;//khoi tao p =head 
		while(p->next!=NULL){//duyet list tu head den tail
			p=p->next;
		}//het vong lap nay p se la tail
		p->next=temp;//tail->next=temp;
	}
	return head;
}
Node addHead(Node head,int value){
	Node temp=createNode(value);//tao moi 1 node co data la value
	if(head==NULL){
		head=temp;
	}
	else{
		temp->next=head; 
		head=temp;//head luc nay la phan tu vua them vao
	}
	return head;//Tra ve danh sach dau tien cua list
}
Node addAt(Node head,int value,int index){
	if(index==0){//Them vao dau
		addHead(head,value);
	}
	else{
		int k=1;//khoi tao gia tri duyet tu 1
		Node p=head;//Phan tu de duyet
		while(p!=NULL&&k!=index){
			p=p->next;
			k++;
		}//sau vong lap nay se duoc gia tri Node p o vi tri index
		if(k!=index){//vi tri index > so luong phan tu trong list
			addTail(head,value);
		}
		else{//tim dc Node p o vi tri index
			Node temp=createNode(value);
			temp->next=p->next;
			p->next=temp;
		}
	}
	return head;
}
Node delHead(Node head){
	if(head==NULL){
		cout<<"List rong!!";
	}else{
		head=head->next;//head luc nay la head next va bo head ban dau
	}
	return head;
}
Node delTail(Node head){
	if(head==NULL){
		cout<<"List rong !!!";
	}else{
		Node p=head;
		while(p->next->next!=NULL){//Tim Node p truoc tail
			p=p->next;
		}
		p->next=NULL;
	}
	return head;
}
Node delAt(Node head,int index){
	if(index==0){
		head=delHead(head);
	}else{
		int k=1;
		Node p=head;
		while(p->next->next!=NULL && k!=index){//Tim Node p truoc tail
			p=p->next;
			k++;
		}
		if(k!=index){
			delTail(head);
		}else{
			p->next=p->next->next;//Tro Node p(truoc index)->Node (sau index)
		}
	}
	return head;
}
int get(Node head,int index){
	int k=0;
	Node p=head;
	while(p->next!=NULL&&k!=index){
		p=p->next;
		k++;
	}
	return p->data;
}
int search(Node head,int value){
	Node p=head;
	int k=0;
	while(p->next!=NULL){
		if(p->data==value){
			return k;
		}
		p=p->next;
		k++;
	}
	return -1;
}
void print(Node head){
	for(Node p=head;p!=NULL;p=p->next){
		cout<<p->data<<" ";
	}
	cout<<endl;
}
Node init(){
	Node p;
	p=NULL;
	return p;
}
Node input(){
	Node head=init();
	int n,value;
	cout<<"Nhap so luong phan tu : ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap value : ";
		cin>>value;
		head=addTail(head,value);
	}
	return head;
}
int main(){
	Node head=input();
	print(head);
//	int x;
//	cout<<"Them vao head phan tu x = ";cin>>x;
//	head=addHead(head,x);
//	print(head);
//	int y;
//	cout<<"Them vao tail phan tu y = ";
//	cin>>y;
//	head=addTail(head,y);
//	print(head);
//	int z,index;
//	cout<<"Them vao phan tu z : ";cin>>z;
//	cout<<"O vi tri : ";cin>>index;
//	head=addAt(head,z,index);
//	print(head);
//	cout<<"Xoa phan tu dau : ";
//	head=delHead(head);
//	print(head);
//	cout<<"Xoa pha tu cuoi : ";
//	head=delTail(head);
//	print(head);
//	int pos;
//	cout<<"Xoa phan tu o vi tri : ";cin>>pos;
//	head=delAt(head,pos);
//	print(head);
//	int v;
//	cout<<"Nhap gia tri can tim : ";
//	cin>>v;
//	cout<<"Vi tri : "<<search(head,v);
	int position;
	cout<<"Nhap vi tri can lay gia tri : ";cin>>position;
	cout<<"Gia tri : "<<get(head,position);
	
}
