// let us see what has gone where in our program, in what secion of the memory.
/*
 * The memory that is allocated to our program or application is typically divided 
 * into these four parts or these four sections. 
 * 
 * 1. one section of the application's memory is used to store all the instructions
 *    that need to be executed.
 * 
 * 2. Another section is allocated to store the global variables that live for the 
 *    entire lifetime of the program, of the application.
 * 
 * 3. The stack is used to store all the information about function call executions,
 *    to store all the local variables.
 * 
 * Three three sections are fixed in size, their size is decided at compile time.
 * 
 * 4. The last section - heap, is not fixed. And we can request memory from the heap
 *    during run-time and that's what we do when we use malloc or new operator.
 * 
*/

#include <iostream>
struct Node {
    int data_;
    Node* next_;
};


void Insert(Node** head, int data, int n)
{
    Node* temp1 = new Node();
    temp1->data_ = data;
    temp1->next_ = nullptr;

    if(n == 1) {
        temp1->next_ = *head;
        *head = temp1;
        return;
    }
    Node* temp2 = *head;
    for(int i = 0; i < n-2; i++) {
        temp2 = temp2->next_;
    }

    temp1->next_ = temp2->next_;
    temp2->next_ = temp1;
}


void Print(Node** head)
{
    Node* temp = *head;
    while(temp != nullptr)
    {
        std::cout << temp->data_;
        temp = temp->next_;
    }
    std::cout << std::endl;
} 


int main() 
{
    Node* head = nullptr; // empty list
    Insert(&head, 2, 1);   // 2
    Insert(&head, 3, 2);   // 2 3
    Insert(&head, 4, 1);   // 4 2 3
    Insert(&head, 5, 2);   // 4 5 2 3

    Print(&head);
}
