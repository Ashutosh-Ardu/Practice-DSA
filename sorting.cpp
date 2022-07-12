#include "iostream"
#include "time.h"
using namespace std;

void swap(int &a,int &b){
	int t=a;a=b;b=t;
}

void bubbleSort(int *ar,int n){
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

void merge(int *ar,int start,int end,int mid){
	int i = start,j = mid + 1,k = start;
	int b[100];

	while(i <= mid && j <= end){
		if(ar[i] < ar[j])
			b[k++] = ar[i++];
		else
			b[k++] = ar[j++];
	}

	if(i > mid){
		while(j <= end)
			b[k++] = ar[j++];
	}
	else{
		while(i <= mid)
			b[k++] = ar[i++];
	}

	for(k=start;k<=end;k++)
		ar[k] = b[k];
}

void mergeSort(int *ar,int start,int end){
	if(start < end){
		int mid = (start + end) / 2;
		mergeSort(ar,start,mid);
		mergeSort(ar,mid+1,end);
		merge(ar,start,end,mid);
	}
}

//first element as the pivot 
int pivot1(int *ar,int start,int end){
	int p = ar[start],i = start,j = end;

	while(i < j){
		while(i <= end && ar[i] <= p)
			i++;
		while(j >= start && ar[j] > p)
			j--;

		if(i < j)
			swap(ar[i],ar[j]);
	}
	swap(ar[start],ar[j]);
	return j;
}

//last element as the pivot 
int pivot2(int *ar,int start,int end){
	int p = ar[end],i = start,j = end;

	while(i < j){
		while(i <= end && ar[i] < p)
			i++;
		while(j >= start && ar[j] >= p)
			j--;

		if(i < j)
			swap(ar[i],ar[j]);
	}
	swap(ar[start],ar[i]);
	return i;
}

void quickSort1(int *ar,int start,int end){
	if(start < end){
		int p = pivot1(ar,start,end);// pivot2 can also be used here
		quickSort1(ar,start,p-1);
		quickSort1(ar,p+1,end);
	}
}

int pivot3(int *ar,int start,int end){
	int mid = (start + end) / 2;
	int p = ar[mid],i = start,j = end;

	while(i <= j){
		if(ar[i] < p)
			i++;
		else if(ar[j] > p)
			j--;
		else{
			swap(ar[i],ar[j]);
			i++;j--;
		}
	}
	return i;
}

void quickSort2(int *ar,int start,int end){
	if(start < end){
		int p = pivot3(ar,start,end);

		if(start < p - 1)
			quickSort2(ar,start,p-1);
		if(p < end)
			quickSort2(ar,p,end);
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
	// bubbleSort(ar,n);
	// insertionSort(ar,n);
	// selectionSort(ar,n);
	// mergeSort(ar,0,n-1);
	// quickSort2(ar,0,n-1);
	print(ar,n);
}