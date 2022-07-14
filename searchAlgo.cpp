#include "iostream"
#include "algorithm"
#include "time.h"
using namespace std;

void print(int *ar,int n){
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<"\n";
}

bool linearSearch(int *ar,int key,int n){
	for(int i=0;i<n;i++)
		if(ar[i] == key)
			return true;
	return false;
}

bool binarySearch(int *ar,int key,int n){
	int i = 0,j = n-1,mid;

	while(i <= j){
		mid = (i + j) / 2;

		if(ar[mid] == key){
			cout<<"Found at "<<mid<<"<--\n";
			return true;
		}
		else{
			if(key > ar[mid])
				i = mid + 1;
			else
				j = mid - 1;
		}
	}
	return false;
}

int main(){
	srand(time(0));
	int n,key;
	cin>>n;

	int ar[n];

	for(int i=0;i<n;i++)
		ar[i] = rand() % 1000;
	sort(ar,ar+n);
	print(ar,n);

	cin>>key;

	if(!(linearSearch(ar,key,n)))
		cout<<"Not Found\n";

	if(!(binarySearch(ar,key,n)))
		cout<<"Not Found<\n";
}