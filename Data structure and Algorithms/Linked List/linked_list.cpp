#include <iostream>

struct Node {
    int data;
    Node* link;
};

Node* head;
void Insert(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->link = nullptr;

    if(head != nullptr)
        temp->link = head;
    head = temp;
}

void Print()
{
    Node* temp = head;
    std::cout << "List is: ";
    while(temp != nullptr)
    {
        std::cout << temp->data;
        temp = temp->link;
    }
    std::cout << std::endl;
}


int main()
{
    head = nullptr;
    std::cout << "How many numbers?\n";
    int n,x;

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter the number \n";
        std::cin >> x;
        Insert(x);
        Print();
    }

    return 0;
}