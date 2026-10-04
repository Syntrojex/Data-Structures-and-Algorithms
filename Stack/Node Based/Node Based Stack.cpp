#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) 
    {
        this->data = data;
        next = NULL;
    }

    ~Node() {}
};

class Stack {
private:
    Node* head;
    int count;

public:
    class Iterator {
        Node* current;
    public:
        Iterator(Node* curr) 
        {
            current = curr;
        }

        int& operator*() 
        {
            return current->data;
        }

        bool operator!=(const Iterator& other)
        {
            return current != other.current;
        }

        Iterator& operator++()
        {
            if (current != NULL) 
            {
                current = current->next;
            }
            return *this;
        }
    };

    Stack() 
    {
        head = NULL;
        count = 0;
    }

    ~Stack() 
    {
        Node* current = head;
        while (current != NULL) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    Iterator begin() 
    {
        return Iterator(head);
    }

    Iterator end() 
    {
        return Iterator(NULL);
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow! Stack is Empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        cout << "Element popped successfully." << endl;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow! Stack khali hai." << endl;
            return -1;
        }
        return head->data; // Top element hamesha head par hota hai
    }

    int getElementCount() 
    {
        return count;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow! Stack khali hai." << endl;
            return;
        }

        cout << "\nStack is (Top to Bottom): " << endl;
        Node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

void menu() 
{
    cout << "\n===== STACK MENU =====" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Get Count" << endl;
    cout << "5. Display" << endl;
    cout << "6. Display Using Iterator" << endl;
}

int main() 
{
    Stack s1;
    int choice = -1;

    while (choice != 0) 
    {
        menu();
        do
        {
            cout << "Enter Your choice (0-6): ";
            cin >> choice;

            if (choice < 0 || choice > 6) 
            {
                cerr << "ERROR: Invalid Choice!" << endl;
            }
        } while (choice < 0 || choice > 6);

        switch (choice) 
        {
        case 0:
            cout << "Exited Successfully." << endl;
            return 0;

        case 1: 
        {
            int val;
            cout << "Enter Value to Push: ";
            cin >> val;
            s1.push(val);
            break;
        }

        case 2:
            s1.pop();
            break;

        case 3: 
        {
            int p = s1.peek();
            if (p != -1) 
            {
                cout << "Top Element is: " << p << endl;
            }
            break;
        }

        case 4:
            cout << "Total Elements in Stack: " << s1.getElementCount() << endl;
            break;

        case 5:
            s1.display();
            break;

        case 6:
            cout << "Traversing Stack using Iterator (Top to Bottom): " << endl;
            for (auto it = s1.begin(); it != s1.end(); ++it) 
            {
                cout << *it << " ";
            }
            cout << endl;
            break;

        default:
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}
