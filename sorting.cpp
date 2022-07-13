#include "iostream"
#include "time.h"
#include "algorithm"
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

int getMax(int *ar,int n){
	int out = ar[0];
	for(int i=1;i<n;i++)
		if(ar[i] > out)
			out = ar[i];
	return out;
}

void digitSort(int *ar,int exp,int n){
	int output[n];
	int count[10] = {0};

	for(int i=0;i<n;i++)
		count[(ar[i]/exp)%10]++;

	for(int i=1;i<10;i++)
		count[i] += count[i-1];

	for(int i=n-1;i>=0;i--){
		output[(count[(ar[i]/exp%10)])-1] = ar[i];
		count[(ar[i]/exp)%10]--;
	}

	for(int i=0;i<n;i++)
		ar[i] = output[i];
}

void radixSort(int *ar,int n){
	int max = getMax(ar,n);

	for(int i=1;max/i>0;i*=10)
		digitSort(ar,i,n);
}

void countSort(int *ar,int n){
	// assume all the numbers in the array are <= 1000
	int output[n];
	int count[1000] = {0};

	for(int i=0;i<n;i++)
		count[ar[i]]++;

	for(int i=1;i<1000;i++)
		count[i] += count[i-1];

	for(int i=0;i<n;i++){
		output[(count[ar[i]])-1] = ar[i];
		count[ar[i]]--;
	}

	for(int i=0;i<n;i++)
		ar[i] = output[i];
}

void heapifyTB(int *ar,int index,int n){
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int max = index;

	if(left < n && ar[left] > ar[max])
		max = left;

	if(right < n && ar[right] > ar[max])
		max = right;

	if(max != index){
		swap(ar[max],ar[index]);
		heapifyTB(ar,max,n);
	}
}

void heapSort(int *ar,int n){
	// first converting the array into a max heap
	for(int i=n/2-1;i>=0;i--)
		heapifyTB(ar,i,n);


	for(int i=n-1;i>=0;i--){
		swap(ar[0],ar[i]);
		heapifyTB(ar,0,i);
	}
}

struct bucket{
	int ar[30]; // the max capacity is 30 for now
	int n;
};

void bucketSort(int *ar,int n){
	bucket b[10];

	for(int i=0;i<10;i++)
		b[i].n = 0;

	int k;
	for(int i=0;i<n;i++){
		k = ar[i] / 100;
		b[k].ar[b[k].n] = ar[i];
		b[k].n += 1;
	}

	int index = 0;
	for(int i=0;i<10;i++){
		sort(b[i].ar,b[i].ar + b[i].n);

		for(int j=0;j<b[i].n;j++)
			ar[index++] = b[i].ar[j];
	}
}

void shellSort(int *ar,int n){
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int key,j;
			key = ar[i];
			for(j=i;j>=gap && ar[j-gap] > key;j-=gap)
				ar[j] = ar[j-gap];
			ar[j] = key;
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
	// bubbleSort(ar,n);
	// insertionSort(ar,n);
	// selectionSort(ar,n);
	// mergeSort(ar,0,n-1);
	// quickSort2(ar,0,n-1);
	// radixSort(ar,n);
	// countSort(ar,n);
	// heapSort(ar,n);
	// bucketSort(ar,n);
	// shellSort(ar,n);
	print(ar,n);
}