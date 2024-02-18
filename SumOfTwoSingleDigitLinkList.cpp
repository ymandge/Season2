#include <iostream>

/*

    Program limitation : Size of both the linked list should be same.

*/

struct Node
{
    Node* next;
    int data;
};

void Append(Node **head, int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    if (*head == nullptr)
    {
        *head = temp;
    }
    else
    {
        Node* traversar = *head;

        while (traversar->next != nullptr)
            traversar = traversar->next;

        traversar->next = temp;
    }
}


void AddList(Node* ptr1, Node*ptr2, int& carry, Node** new_list)
{
    if (ptr1 == nullptr && ptr2 == nullptr)
        return;

    if (ptr1 != nullptr && ptr2 != nullptr)
        AddList(ptr1->next, ptr2->next, carry, &(*new_list));
   /* else if (ptr1 != nullptr && ptr2 == nullptr)
        AddList(ptr1->next, nullptr, carry, &(*new_list));
    else
        AddList(nullptr, ptr2->next, carry, &(*new_list));*/

    int addition = 0;

    if (ptr1 != nullptr && ptr2 != nullptr)
        addition = ptr1->data + ptr2->data + carry;
    //else if (ptr1 != nullptr && ptr2 == nullptr)
    //    addition = ptr1->data + carry;
    //else
    //    addition = ptr2->data + carry;

    carry = addition > 9 ? 1 : 0;
    addition = addition > 9 ? addition % 10: addition;
 
    Node* temp = new Node();
    temp->data = addition;
    temp->next = nullptr;

    temp->next = *new_list;
    *new_list = temp;
}

int main()
{
    auto printList = [](Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            temp = temp->next;
        }
        std::cout << std::endl;
        };

    Node* list1 = nullptr;
    Append(&list1, 1);
    Append(&list1, 0);
    Append(&list1, 0);
    printList(list1);

    Node* list2 = nullptr;
    Append(&list2, 0);
    Append(&list2, 9);
    Append(&list2, 9);
    printList(list2);

    
    std::cout << "========" << std::endl;

    Node* new_list = nullptr;
    int carry = 0;
    AddList(list1, list2, carry, &new_list);
    if (carry)
    {
        Node* temp = new Node();
        temp->data = carry;

        temp->next = new_list;
        new_list = temp;
    }

    printList(new_list);

    return 0;
}

