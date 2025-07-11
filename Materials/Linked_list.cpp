#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;

    node(int value)
    {
        data=value;
        next=NULL;
    }
};

node* head=NULL;

void insert_head(int value)
{
    node* newItem=new node(value);
    newItem->next=head;
    head=newItem;

}

void printList()
{
    if(head==NULL)
    {
        cout<<"No element in the Linked List"<<endl;
    }

    else
    {
        node* current=head;
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;

    }

}

void insert_last(int value)
{
    node* newItem= new node(value);
    node* last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newItem;

}

void insert_middle(int target, int value)
{
    node* newItem= new node(value);
    node* prev=head;
    while(prev->data!= target)
    {
        prev=prev->next;
    }
    newItem->next=prev->next;
    prev->next=newItem;
}

void delete_head()
{
    if(head==NULL)
    {
        cout<<"Nothing left to be deleted"<<endl;
    }

    else
    {
        node* current= head;
        head=head->next;
        delete current;
    }
}

void delete_last()
{
    if(head==NULL)
    {
        cout<<"Nothing left to delete"<<endl;
    }

    node* current=head;
    node* prev=NULL;

    while(current->next!=NULL)
    {
        prev=current;
        current=current->next;
    }

    if(prev!=NULL)
    {
        prev->next=NULL;
    }
    else
    {
        head=NULL;
    }

    delete current;
}


void delete_any(int value)
{
   if(head==NULL)
   {
       cout<<"Nothing left to delete"<<endl;
   }

   else
   {
       node* current=head;
       node* prev=NULL;

       while(current->data!=value)
       {
           prev=current;
           current=current->next;
       }

       if(prev!=NULL)
       {
           prev->next=current->next;
       }

       else
       {
           head=NULL;
       }
       delete current;
   }
}

int main()
{
    //printList();
    insert_head(10);
    insert_head(20);
    insert_head(30);
    insert_last(40);
    insert_middle(20,50);
    printList();
    //delete_head();

    //delete_last();
    delete_any(20);
    printList();
}



