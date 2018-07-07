#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}linkdlst;


void PrintLinkedList(linkdlst* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void Push1(linkdlst** head_ref,int data){
    linkdlst* new_node = new linkdlst;
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

linkdlst* Push2(linkdlst* head,int data){
    linkdlst* new_node = new linkdlst;
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

void InsertAfter(linkdlst* prevNode,int data){
    
    if(prevNode == NULL){
        cout<<"The given previous node cannot be null"<<endl;
        return;
    }
    
    linkdlst* new_node = new linkdlst;
    new_node->data = data;
    new_node->next = prevNode->next;
    prevNode->next = new_node;
    
}

void Append(linkdlst**head_ref,int data){
    
    linkdlst* last = *head_ref;
    
    linkdlst* new_node = new linkdlst;
    new_node->data = data;
    new_node->next = NULL;
    
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    
    //traverse till last
    
    while(last->next != NULL){
        last = last->next;
    }
    
    last->next = new_node;
    
}

void DeleteNode(linkdlst** head_ref,int key){
    
    linkdlst* temp = *head_ref ;
    linkdlst* prev;
    
    if(temp !=NULL && temp->data == key){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        return;
    }
    
    prev->next = temp->next;
    delete temp;
    
}

void deletePos(linkdlst** head_ref,int pos){
    
    if(*head_ref == NULL){
        return;
    }
    
    linkdlst* temp = *head_ref;
    
    if(temp != NULL && pos == 0){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    
    //traverse to prev node to the given position
    for(int i=0;i<pos-1 && temp != NULL;i++){
        temp = temp->next;
    }
    
    //if pos > no.of nodes
    if(temp == NULL && temp->next == NULL){
        return;
    }
    
    temp->next = temp->next->next;
    delete temp->next;
    
}

void DeleteAll(linkdlst** head_ref){
    
    linkdlst *current = *head_ref;
    linkdlst *nextnode ;
    
    while(current != NULL){
        nextnode = current->next;
        delete current;
        current = nextnode;
    }
    
    *head_ref = NULL;
}

int getCount(linkdlst* head){
    
    int count = 0;
    linkdlst* current = head;
    
    while(current != NULL){
        count++;
        current = current -> next;
    }
    
    return count;
}


int getCountRecursive(linkdlst* head){
    
    if(head == NULL){
        return 0;
    }
    
    return 1 + getCountRecursive(head->next);
}


bool SearchElement(linkdlst* head,int x){
    
    linkdlst* current = head;
    
    while(current != NULL){
        
        if(current->data == x){
            return true;
        }
        current = current->next;
    }
    return false;
}

bool SearchElementRecursive(linkdlst* head,int x){
    
    if(head == NULL){
        return false;
    }
    
    if(head->data == x){
        return true;
    }
    
   return SearchElementRecursive(head->next,x);
    
}

int middle1(linkdlst*head){
    linkdlst* current = head;
    int count = 0;
    while(current != NULL){
        ++count;
        current = current->next;
    }
    
    current = head;
    
    for(int i=0;i<(count/2);i++){
        current = current->next;
    }
    
    return current->data;
}

//slowptr and fastptr concept
int middle2(linkdlst*head){
    linkdlst* slwptr = head;
    linkdlst* fastptr = head;
    
    while(fastptr != NULL && fastptr->next != NULL){
        fastptr = fastptr->next->next;
        slwptr = slwptr->next;
    }
    
    return slwptr->data;
}


int middle3(linkdlst*head){
    linkdlst* current = head;
    linkdlst* middle = head;
    int count = 0;
     while(current != NULL){
         
         if(count % 2 != 0){
             middle = middle->next;
         }
          ++count;
          current = current->next;
     }
     
     return middle->data;
}

int getNth(linkdlst* head,int index){
    
    linkdlst* current = head;
    int count = 0;
    
    while(current != NULL){
        if(count == index){
            return current->data;
        }
        current = current->next;
        ++count;
    }
    
    assert(0); //if user enters invalid index
}

int getNthRecursive(linkdlst* head,int index){
    
    linkdlst* current = head;
    
    int count = 0;
     if(count == index)
     return current->data;
     
     return getNthRecursive(head->next,index-1);
}

int nthFromEnd(linkdlst* head){
    
}

int nthFromEnd2(linkdlst* head){
    
}

void Reverse(linkdlst** head){
    linkdlst* current = *head;
    linkdlst* prev = NULL;
    linkdlst* nextnode = NULL;
    
    
    
}

//number of times a given int occurs 
int no_of_times(linkdlst* head,int x){
    linkdlst* current = head;
    int count = 0;
    while(current != NUll){
        if(x == current->data){
            ++count;
        }
        
        current = current->next;
    }
    
    return count;
}

int main()
{
    linkdlst* head = new linkdlst;
    linkdlst* second = new linkdlst;
    linkdlst* third = new linkdlst;
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next =NULL;
    
   head = Push2(head,4);
   Push1(&head,5);
   
   InsertAfter(head,6);
   Append(&head,4);
   
    PrintLinkedList(head);
    
    cout<<endl;
  
   cout<<middle3(head) <<endl;
    
    return 0;
}
