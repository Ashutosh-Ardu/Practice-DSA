#include "iostream"
#include "time.h"
using namespace std;

void swap(int &a,int &b){
	int t=a;a=b;b=t;
}

void sort(int *ar,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(ar[j] > ar[j+1])
				swap(ar[i],ar[j]);
		}
	}
}

void print(int *ar,int n){
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<"\n";
}

int main(){
	srand(time(0));
	int n;
	cin>>n;

	int ar[n];

	for(int i=0;i<n;i++)
		ar[i] = rand() % 1000;

	print(ar,n);
	sort(ar,n);
	print(ar,n);
}