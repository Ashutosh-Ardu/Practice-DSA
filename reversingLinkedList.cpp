#include <bits/stdc++.h>
using namespace std;

// linked list
class LinkedList
{
  public:
  int val;
  LinkedList *next;

  LinkedList()
  {
    val = 0;
    next = nullptr;
  }

  LinkedList(int val)
  {
    this->val = val;
    next = nullptr;
  }

// enqueue
  LinkedList *push(LinkedList *root, int val)
  {
    if (!root)
      return new LinkedList(val);
    else
      root->next = push(root->next, val);
    return root;
  }

// reversing using iteration
  LinkedList *rev1(LinkedList *head)
  {
    LinkedList *cur = head, *temp = nullptr;

    while (head)
    {
      cur = cur->next;
      head->next = temp;
      temp = head;
      head = cur;
    }

    return temp;
  }

// reversing using recursion
  LinkedList* rev2(LinkedList *head)
  {
    if(head == nullptr || head->next == nullptr)
      return head;
    LinkedList *temp = rev2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
  }

  void print(LinkedList *head){
    if(head){
      cout << head->val << " ";
      print(head->next);
    }
  }
};

int main()
{
  int n;
  cin >> n;

  LinkedList *head = nullptr,b;

  for(int i=0;i<n;i++){
    int temp = rand() % 100;
    // cout << temp << " ";
    head = b.push(head,temp);
  }

  b.print(head);
  cout << endl;
  head = b.rev1(head);
  b.print(head);
  cout << endl;
  head = b.rev2(head);
  b.print(head);
  cout << endl;
}