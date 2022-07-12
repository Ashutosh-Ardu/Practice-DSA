#include "iostream"
#include "time.h"
using namespace std;

void swap(int &a,int &b){
	int t=a;a=b;b=t;
}

void bucketSort(int *ar,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(ar[j] > ar[j+1])
				swap(ar[i],ar[j]);
		}
	}
}

void insertionSort(int *ar,int n){
	int j,key;
	for(int i=1;i<n;i++){
		j = i - 1;
		key = ar[i];
		while(j >= 0 && ar[j] > key){
			ar[j + 1] = ar[j];
			j--;
		}
		ar[j] = key;
	}
}

void selectionSort(int *ar,int n){
	int min;
	for(int i=0;i<n-1;i++){
		min = i;
		for(int j=i+1;j<n;j++){
			if(ar[j] < ar[min])
				min = j;
		}
		swap(ar[i],ar[min]);
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
	bucketSort(ar,n);
	print(ar,n);
}