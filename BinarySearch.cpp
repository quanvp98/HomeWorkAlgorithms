#include<iostream>

using namespace std;


void init(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap a["<<i<<"] : ";
		cin>>a[i];
	}
}
int swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
void print(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}
int binarySearch(int a[],int left,int right,int x){
	if(right>=left){
		int mid=left+(right-left)/2;
		if(a[mid]==x)return mid;
		if(a[mid]>x){
			return binarySearch(a,left,mid-1,x);
		}
		else return binarySearch(a,mid+1,right,x);
	}
}
int partition(int a[],int low,int high){
	int pivot=a[high];
	int left=low;
	int right=high-1;
	while(true){
		while(left<=right&&a[left]<pivot)left++;
		while(right>=left&&a[right]>pivot)right--;
		if(left>=right)break;
		swap(a[left],a[right]);
		left++;
		right--;
	}
	swap(a[left],a[high]);
	return left;
}
void quickSort(int a[],int low,int high){
	if(low<high){
		int p=partition(a,low,high);
		quickSort(a,low,p-1);
		quickSort(a,p+1,high);
	}
}
int main(){
	int n;
	cout<<"Nhap n : ";
	cin>>n;
	int a[n];
	init(a,n);
	print(a,n);
	quickSort(a,0,n-1);
	print(a,n);
	int x;
	cout<<"Nhap x : ";
	cin>>x;
	int index=binarySearch(a,0,n-1,x);
	if(index==-1){ 
		cout<<"Khong co gia tri x trong mang";
	}else{
		cout<<"Gia tri : "<<x<<", Vi tri : "<<index;
	}
}
