import java.util.Scanner;

class LinkedList{
  int val;
  LinkedList next;

  LinkedList(){
    val = 0;
    next = null;
  }

  LinkedList(int val){
    this.val = val;
    next = null;
  }

  LinkedList push(LinkedList head,int val){
    if(head == null)
      return new LinkedList(val);
    head.next = push(head.next,val);
    return  head;
  }

  // using iteration
  LinkedList rev1(LinkedList head){
    LinkedList cur = head,temp = null;

    while(head != null){
      cur = cur.next;
      head.next = temp;
      temp = head;
      head = cur;
    }

    return temp;
  }

  // using recursion
  LinkedList rev2(LinkedList head){
    if(head == null || head.next == null)
      return head;

    LinkedList temp = rev2(head.next);
    head.next.next = head;
    head.next = null;
    return temp;
  }

  void show(LinkedList head){
    if(head != null){
      System.out.print(head.val+" ");
      show(head.next);
    }
  }
}

public class LinkedListRunner {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    
    int n = scan.nextInt();

    LinkedList head = null,b = new LinkedList();

    for(int i=0;i<n;i++){
      int val = (int) (Math.random() * 101);
      head = b.push(head, val);
    }
    
    b.show(head);
    System.out.println();
    head = b.rev1(head);
    b.show(head);
    System.out.println();
    head = b.rev2(head);
    b.show(head);
    System.out.println();
  }
}
