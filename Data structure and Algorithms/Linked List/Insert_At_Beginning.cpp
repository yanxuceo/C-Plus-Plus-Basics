#include <iostream>

struct Node {
    int data_;
    Node* next_;
};


void Insert_at_beginning(Node** head, int data)
{
    Node* temp = new Node();
    temp->data_ = data;
    temp->next_ = nullptr;

    if(*head != nullptr)
    {
        temp->next_ = *head;
    }
    *head = temp;
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
    Node* head = nullptr;

    int number = 0;
    int data = 0;

    std::cout << "Enter the number of nodes: ";
    std::cin >> number;

    for(int i = 0; i < number; i++)
    {
        std::cout << "Enter a value for the node: ";
        std::cin >> data;
        Insert_at_beginning(&head, data);
        Print(&head);
    }
}