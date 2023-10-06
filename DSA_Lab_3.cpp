// DSA_Lab_3.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node* next;

    node()
    {
        value = 0;
        next = NULL;
    }
    node(int x)
    {
        value = x;
        next = NULL;
    }
};

class list
{
    node* head;
    node* tail;

public:
    void insert_at_head(int value)
    {
        node* newnode = new node(value);
        if (head == NULL)           // Checks to see if linked list is empty, in that case both head and tail pointers need to be updated
        {
            head = newnode;
            tail = newnode;
            newnode = NULL;
            delete newnode;
        }
        else                    // if list is not empty then it simply moves the head pointer 
        {
            newnode->next = head;
            head = newnode;
            newnode = NULL;
            delete newnode;
        }
    }
    void insert_at_location(int location, int value)
    {
        node* newnode = new node(value);
        node* currentnode = head;
        for (int x = 1; x < location-1; x++) // itertates to 1 location before the intended location passed into the function
        {
            if (currentnode == NULL)
            {
                cout << "Invalid location for list" << endl;
                break;
            }
            currentnode = currentnode->next;
        }
        newnode->next = currentnode->next;
        currentnode->next = newnode;
        newnode = NULL;
        delete newnode;
    }
    void insert_at_tail(int value)
    {
        node* newnode = new node(value); // Checks if List is empty
            if (tail == NULL)
            {
                head = newnode;
                tail = newnode;
                newnode = NULL;
                delete newnode;
            }
            else
            {
                tail->next = newnode;
                tail = newnode;
                newnode = NULL;
                delete newnode;
            }
    }
    void deleteNode_Location(int location)
    {
        node* currentnode = head;
        node* temp;
        for (int x = 1; x < location - 1; x++) // itertates to 1 location before the intended location passed into the function
        {
            if (currentnode == NULL)
            {
                cout << "Invalid location for list" << endl;
                break;
            }
            currentnode = currentnode->next;
        }
        temp = currentnode->next; // saves address of node to be deleted
        currentnode->next = currentnode->next->next; // removes lists link to said node
        delete temp; // empties memory used by deleted node
    }
    void deleteNode_Value(int value)
    {
        node* currentnode = head;
        if (currentnode == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        while (1)
        {
            if (currentnode->value == value) // In case the value is at first location i.e head of list
            {
                node* temp = head;
                currentnode->next = head->next;
                head->next = currentnode;
                delete temp;
                break;
            }
            else if (currentnode->next->value == value) // All cases in which it is not at first location
            {
                node* temp = currentnode->next;
                currentnode->next = currentnode->next->next;
                delete temp;
                break;
            }
            currentnode = currentnode->next;
        }
    }
    void displayList()
    {
        if (head != NULL) // Checking if list is empty
        {
            node* currentnode = head;
            while (currentnode != NULL) // iterating until end of list is eached
            {
                cout << currentnode->value << endl;
                currentnode = currentnode->next;
            }
        }
        else
        {
            cout << "List is empty" << endl;
            return;
        }
    }
    void Countlist()
    {
        int count = 0;
        if (head != NULL) // Checks if list is empty
        {
            node* currentnode = head;
            while (currentnode != NULL)
            {
                currentnode = currentnode->next;
                count += 1;
            }
            cout << "List node count = " << count << endl;
        }
        else
        {
            cout << "List is empty" << endl;
            return;
        }
    }
    list()
    {
        head = NULL;
        tail = NULL;
    }
};
int main()
{
    list Llist;
        char a = NULL; //drawing menu
    Label:
        cout << " Select from one of the following\n A.Create a node or Insert at HEAD \n B.Display Linked list entries \n C.Insert at location \n D.Delete from location \n E.Insert at End \n F.Show count of nodes in the list \n G.Exit program" << endl;
        cout << "Enter Choice : ";
        cin >> a;
        switch (a) {
        case 'A':
            cout << "\nInsert any value to Create a node\n" << endl;
            int a1;
            cin >> a1;
            Llist.insert_at_head(a1);
            system("cls");
            goto Label;
            break;
        case 'B':
            cout << "\nDisplay Linked list entries\n" << endl;
            system("cls");
            Llist.displayList();
            cout << "\n\n\n\n\n";
            goto Label;
            break;
        case 'C':

            cout << "\nChoose which location to enter the value\n" << endl;
            cout << "\n" << endl;
            int b1, b2;
            cin >> b1;
            cout << "\nChoose the value to be entered\n" << endl;
            cin >> b2;
            cout << "\n\n" << endl;
            Llist.insert_at_location(b1, b2);
            system("cls");
            goto Label;

            break;
        case 'D':
            cout << "Delete from entry location" << endl;
            int d1;
            cin >> d1;
            Llist.deleteNode_Location(d1);
            system("cls");
            goto Label;
            break;
        case 'E':
            int E1;
            cout << "Insert Value to be added to new node at tail : ";
            cin >> E1;
            Llist.insert_at_tail(E1);
            system("cls");
            break;
        case 'F':
            system("cls");
            Llist.Countlist();
            goto Label;
            break;
        case 'G':
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
}

