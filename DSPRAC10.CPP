#include<iostream.h>
#include<conio.h>
#include<process.h>
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};
void push(Node** head_ref, int new_data)
{
   Node* new_node = new Node();
   new_node->data = new_data;
   new_node->next = (*head_ref);
   new_node->prev = NULL;
   if((*head_ref) != NULL)
    (*head_ref)->prev = new_node;
   (*head_ref) = new_node;
}
void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
	cout<<"the given previous node cannot be NULL";
	return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
	new_node->next->prev = new_node;
}
void insertNodeAtGivenPos(struct Node** head_ref, int n, int new_data)
{
    if (*head_ref == NULL || n <= 0)
	return;
    struct Node* current = *head_ref;
    int i;
    for (i = 1; current != NULL && i < n-1; i++)
	current = current->next;
    if (current == NULL)
	return;
    insertAfter(current , new_data);
}
void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
	new_node->prev = NULL;
	*head_ref = new_node;
	return;
    }
    while (last->next != NULL)
	last = last->next;

    last->next = new_node;
    new_node->prev = last;

    return;
}
void deleteNode(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL)
	return;
    if
     (*head_ref == del)
	*head_ref = del->next;
    if (del->next != NULL)
	del->next->prev = del->prev;
    if (del->prev != NULL)
	del->prev->next = del->next;
    delete(del);
    return;
}
void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
    if (*head_ref == NULL || n <= 0)
	return;
    struct Node* current = *head_ref;
    int i;
    for ( i = 1; current != NULL && i < n; i++)
	current = current->next;
    if (current == NULL)
	return;
    deleteNode(head_ref, current);
}
void printList(Node* node)
{
    while (node != NULL)
    {
	cout<<" "<<node->data<<" ";
	node = node->next;
    }
}
void main()
{   int ele,ch,ch1,ch2,pos;
    Node* head = NULL;
    do
    {
     clrscr();
     cout<<"\n CURRENT D.L.L. : "; printList(head);
     cout<<"\n ---------MENU---------";
     cout<<"\n 1. INSERTION IN THE LIST \n 2. DELETION IN THE LIST \n 3. DISPLAY \n 4. EXIT";
     cout<<"\n ENTER YOUR CHOICE : ";
     cin>>ch;
     switch(ch)
     {
      case 1 : cout<<"\n ENTER ELEMENT TO BE INSERTED IN THE LIST : ";
	       cin>>ele;
	       cout<<"\n WHERE TO PERFORM INSERTION ? ";
	       cout<<"\n 1. BEGINNING   2. END   3. GIVEN LOCATION";
	       cout<<"\n ENTER YOUR CHOICE : ";
	       cin>>ch1;
	       switch(ch1)
	       {
		case 1 : push(&head, ele);
			 break;
		case 2 : append(&head, ele);
			 break;
		case 3 : cout<<"\n ENTER VALID POSITION FOR INSERTION : ";
			 cin>>pos;
			 insertNodeAtGivenPos(&head,pos,ele);
			 break;
		default : cout<<"\WRONG CHOICE !!!!";
	       }
	       break;

      case 2 : cout<<"\n WHERE TO PERFORM DELETION ? ";
	       cout<<"\n 1. BEGINNING    2. GIVEN LOCATION";
	       cout<<"\n ENTER YOUR CHOICE : ";
	       cin>>ch2;
	       switch(ch2)
	       { case 1 : deleteNode(&head, head);
			  break;
		 case 2 : cout<<"\n ENTER VALID POSITION FOR DELETION : ";
			  cin>>pos;
			  deleteNodeAtGivenPos(&head,pos);
			  break;
		 default : cout<<"\n WRONG CHOICE !!!";
	       }
	       break;

      case 3 : cout<<"\n CURRENT D.L.L. IS : "<<endl;
	       printList(head);
	       break;

      case 4 : exit(0);
      default : cout<<"\n WRONG CHOICE!!!!";
     }
    }while(1);

}