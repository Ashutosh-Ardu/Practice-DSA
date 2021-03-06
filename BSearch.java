import java.util.Scanner;

class BSearch{

  static int pivot(int[] ar,int start,int end){
    int mid = (start+end)/2,i = start,j=end;
    int p = ar[mid];

    while(i<=j){
      if(ar[i] < p)
        i++;
      else if(ar[j] > p)
        j--;
      else{
        int t=ar[i];ar[i]=ar[j];ar[j]=t;
        i++;j--;
      }
    }
    return i;
  }

  static void quickSort(int[] ar,int start,int end){
    if(start < end){
      int p = pivot(ar,start,end);

      if(start < p-1)
        quickSort(ar,start,p-1);
      if(p < end)
        quickSort(ar,p,end);
    }
  }

  static void linearSearch(int[] ar,int val,int n){
    for(int i=0;i<n;i++){
      if(ar[i] == val){
        System.out.println("Found");
        return;
      }
    }
    System.out.println("Not Found");
  }

  static void binarySearch(int[] ar,int val,int n){
    int i = 0,j = n-1;
    int mid;

    while(i <= j){
      mid = (i + j) / 2;
      if(ar[mid] == val){
        System.out.println("Found");
        return;
      }
      else{
        if(val > ar[mid])
          i = mid+1;
        else
          j = mid-1;
      }
    }
    System.out.println("Not Found");
  }

  static void sort(int[] ar,int n){
    for(int i=0;i<n-1;i++){
      for(int j=0;j<n-i-1;j++){
        if(ar[j] > ar[j+1]){
          int t=ar[j];ar[j]=ar[j+1];ar[j+1]=t;
        }
      }
    }
  }

  static void show(int[] ar,int n){
    for(int i=0;i<n;i++)
      System.out.print(ar[i]+" ");
    System.out.println(); 
  }

  public static void main(String args[]){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();

    int[] ar = new int[n];

    for(int i=0;i<n;i++)
      ar[i] = (int) (Math.random() * 1001);
    
    // sort(ar,n);
    quickSort(ar,0,n-1);
    // show(ar,n);
    int val = in.nextInt();
    // binarySearch(ar,val,n);
    // linearSearch(ar,val,n);
  }
}