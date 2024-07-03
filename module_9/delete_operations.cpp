#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val;
    Node * next;
    Node * prev;
    Node (int val){
        this->val =val;
        this->next= NULL;
        this->prev = NULL;
    }
};
void print_normal(Node * head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next; 
    }
    cout << endl;
    
}
int size(Node * head){
    int count = 0;
    Node * tmp = head;
    while (tmp != NULL)
    {
        count ++;
        tmp = tmp->next;
    }
    return count;
}

void delete_any_pos(Node * &head, Node *& tail, int pos)
{
    Node *tmp = head;
    if (pos == 0)
    {
        head = head->next;
        if (head !=NULL)
        {
            head->prev = NULL;
        }
        delete tmp;
        return;
        
    }
    else if (pos == size(head))
    {
        Node * deleteNode = tail;
        tail = tail->prev;
        delete deleteNode;
        tail->next = NULL;
        return;

    }
    
    
    for (int i = 1; i <= pos -1; i++)
    {
        tmp = tmp->next;
    }
    Node * deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev= tmp;
    delete deleteNode;
}
int main()
{
    Node * head = new Node(10);
    Node * a = new Node(20);
    Node * b = new Node(30);
    Node * c = new Node(40);
    Node * tail = c;
    head->next=a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    int pos;
    cin>> pos;
   
    delete_any_pos(head, tail, pos);
     print_normal(head);
    return 0;
}
