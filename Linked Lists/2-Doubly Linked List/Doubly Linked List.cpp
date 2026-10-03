#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data)
	{
		this->data = data;
		next = NULL;
		prev = NULL;
	}

	~Node() {}
};

class DoublyLinkedList {
	Node* head;
	Node* tail;
	int size;

	// Iterator class for Traversing like vector(STL)
	class Iterator {
	private:
		Node* current;

	public:
		Iterator(Node* node)
		{
			current = node;
		}

		int& operator*()
		{
			return current->data;
		}

		Iterator& operator++()
		{
			if (current != NULL)
			{
				current = current->next;
			}
			return *this;
		}

		bool operator!=(const Iterator& other)
		{
			return current != other.current;
		}
	};

public:

	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	~DoublyLinkedList()
	{
		Node* current = head;

		while (current != NULL)
		{
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}

		head = NULL;
		tail = NULL;
	}

	Iterator begin()
	{
		return Iterator(head);
	}

	Iterator end()
	{
		return Iterator(NULL);
	}

	bool isEmpty()
	{
		return head == NULL;
	}

	// Display Forward
	void display()
	{
		if (isEmpty())
		{
			cout << "LinkedList is Empty" << endl;
			return;
		}

		Node* temp = head;

		while (temp != NULL)
		{
			cout << temp->data << "<->";
			temp = temp->next;
		}

		cout << "NULL" << endl;
	}

	// Display Backward
	void displayReverse()
	{
		if (isEmpty())
		{
			cout << "LinkedList is Empty" << endl;
			return;
		}

		Node* temp = tail;

		while (temp != NULL)
		{
			cout << temp->data << "<->";
			temp = temp->prev;
		}

		cout << "NULL" << endl;
	}

	// Traverse using Function Pointer
	void traverse(void (*func)(int))
	{
		Node* temp = head;

		while (temp != NULL)
		{
			func(temp->data);
			temp = temp->next;
		}
	}

	void insertAtStart(int value)
	{
		Node* newNode = new Node(value);

		if (isEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}

		size++;
	}

	void insertAtEnd(int value)
	{
		Node* newNode = new Node(value);

		if (isEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}

		size++;
	}

	void insertAt(int position, int value)
	{
		if (position < 1 || position > size + 1)
		{
			cout << "Invalid Position! Position must be between 1 and "
				<< size + 1 << endl;
			return;
		}

		if (position == 1)
		{
			insertAtStart(value);
			return;
		}

		if (position == size + 1)
		{
			insertAtEnd(value);
			return;
		}

		Node* current = head;

		for (int i = 1; i < position; i++)
		{
			current = current->next;
		}

		Node* newNode = new Node(value);

		newNode->prev = current->prev;
		newNode->next = current;

		current->prev->next = newNode;
		current->prev = newNode;

		size++;
	}

	void deleteFromStart()
	{
		if (isEmpty())
		{
			cout << "LinkedList is Empty" << endl;
			return;
		}

		if (head == tail)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			Node* temp = head;

			head = head->next;
			head->prev = NULL;

			delete temp;
		}

		size--;
	}

	void deleteFromEnd()
	{
		if (isEmpty())
		{
			cout << "LinkedList is Empty" << endl;
			return;
		}

		if (head == tail)
		{
			delete tail;
			head = tail = NULL;
		}
		else
		{
			Node* temp = tail;

			tail = tail->prev;
			tail->next = NULL;

			delete temp;
		}

		size--;
	}

	void deleteAt(int position)
	{
		if (position < 1 || position > size)
		{
			cout << "Out of Bounds" << endl;
			return;
		}

		if (position == 1)
		{
			deleteFromStart();
			return;
		}

		if (position == size)
		{
			deleteFromEnd();
			return;
		}

		Node* current = head;

		for (int i = 1; i < position; i++)
		{
			current = current->next;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;

		delete current;
		size--;
	}

	void emptyAfter(int position)
	{
		if (position < 1 || position > size)
		{
			cout << "Out of Bounds" << endl;
			return;
		}

		if (position == size)
		{
			return;
		}

		Node* current = head;

		for (int i = 1; i < position; i++)
		{
			current = current->next;
		}

		Node* deleteNode = current->next;

		current->next = NULL;
		tail = current;

		while (deleteNode != NULL)
		{
			Node* nextNode = deleteNode->next;
			delete deleteNode;
			deleteNode = nextNode;
			size--;
		}
	}

	void updateAtStart(int value)
	{
		if (isEmpty())
		{
			cout << "List is Empty" << endl;
			return;
		}

		head->data = value;
	}

	void updateAtEnd(int value)
	{
		if (isEmpty())
		{
			cout << "List is Empty" << endl;
			return;
		}

		tail->data = value;
	}

	void updateAt(int position, int value)
	{
		if (position < 1 || position > size)
		{
			cout << "Out of Bounds!" << endl;
			return;
		}

		Node* temp = head;

		for (int i = 1; i < position; i++)
		{
			temp = temp->next;
		}

		temp->data = value;
	}

	void search(int value)
	{
		if (isEmpty())
		{
			cout << "List is Empty. Element can't be found" << endl;
			return;
		}

		Node* temp = head;

		while (temp != NULL)
		{
			if (temp->data == value)
			{
				cout << "Element Found in List" << endl;
				return;
			}

			temp = temp->next;
		}

		cout << "Element Not Found" << endl;
	}

	void reverse()
	{
		if (isEmpty() || head == tail)
		{
			return;
		}

		Node* current = head;

		while (current != NULL)
		{
			Node* temp = current->next;

			current->next = current->prev;
			current->prev = temp;

			current = temp;
		}

		Node* temp = head;
		head = tail;
		tail = temp;
	}

	void rotate(int k)
	{
		if (isEmpty() || head == tail || k == 0)
		{
			return;
		}

		k = k % size;

		if (k == 0)
		{
			return;
		}

		// Make circular
		tail->next = head;
		head->prev = tail;

		int stepsToNewTail = size - k;

		Node* newTail = head;

		for (int i = 1; i < stepsToNewTail; i++)
		{
			newTail = newTail->next;
		}

		head = newTail->next;
		tail = newTail;

		head->prev = NULL;
		tail->next = NULL;
	}

	int findMiddle()
	{
		if (isEmpty())
		{
			cout << "List is Empty" << endl;
			return -1;
		}

		Node* slow = head;
		Node* fast = head;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow->data;
	}

	void sort()
	{
		if (isEmpty() || size == 1)
		{
			cout << "Can't Be swapped" << endl;
			return;
		}

		bool swapped;

		do
		{
			swapped = false;

			Node* temp1 = head;
			Node* temp2 = temp1->next;

			while (temp2 != NULL)
			{
				if (temp1->data > temp2->data)
				{
					int data = temp1->data;
					temp1->data = temp2->data;
					temp2->data = data;

					swapped = true;
				}

				temp1 = temp1->next;
				temp2 = temp2->next;
			}

		} while (swapped);
	}

	void removeDuplicates()
	{
		Node* temp1 = head;

		while (temp1 != NULL)
		{
			Node* temp2 = temp1;

			while (temp2->next != NULL)
			{
				if (temp2->next->data == temp1->data)
				{
					Node* duplicate = temp2->next;

					temp2->next = duplicate->next;

					if (duplicate->next != NULL)
					{
						duplicate->next->prev = temp2;
					}
					else
					{
						tail = temp2;
					}

					delete duplicate;
					size--;
				}
				else
				{
					temp2 = temp2->next;
				}
			}

			temp1 = temp1->next;
		}
	}
};

int main()
{
	DoublyLinkedList l1;

	cout << "Program Start: " << endl;
	l1.display();

	cout << "\n===== Insertion =====" << endl;

	cout << "Insertion At Start: " << endl;
	l1.insertAtStart(10);
	l1.insertAtStart(5);
	l1.display();

	cout << "\nInsertion At End: " << endl;
	l1.insertAtEnd(3);
	l1.display();

	cout << "\nInsertion At Specific Node: " << endl;
	l1.insertAt(2, 9);
	l1.display();

	// Making List with some random values
	cout << "\nMaking List with some random values" << endl;

	l1.insertAtEnd(5);
	l1.insertAtEnd(8);
	l1.insertAtStart(21);
	l1.insertAtEnd(13);

	l1.display();

	cout << "\n===== Reverse Display =====" << endl;
	l1.displayReverse();

	cout << "\n===== Deletion =====" << endl;

	cout << "Deletion from start: " << endl;
	l1.deleteFromStart();
	l1.display();

	cout << "\nDeletion from End: " << endl;
	l1.deleteFromEnd();
	l1.display();

	cout << "\nDeletion At specific Node: " << endl;
	l1.deleteAt(3);
	l1.display();

	cout << "\nEmpty List after Node: " << endl;
	l1.emptyAfter(3);
	l1.display();

	// Making List with some random values
	cout << "\nAgain Making List with some random values" << endl;

	l1.insertAtEnd(5);
	l1.insertAtEnd(8);
	l1.insertAtStart(21);
	l1.insertAtEnd(13);
	l1.insertAtStart(15);
	l1.insertAtEnd(100);
	l1.insertAtStart(29);
	l1.insertAtEnd(34);

	l1.display();

	cout << "\n===== Searching =====" << endl;
	cout << "Searching for Element 9 in List" << endl;
	l1.search(9);

	cout << "\n===== Updation =====" << endl;

	cout << "Update At Start: " << endl;
	l1.updateAtStart(23);
	l1.display();

	cout << "\nUpdate At End: " << endl;
	l1.updateAtEnd(103);
	l1.display();

	cout << "\nUpdate At Specific Node: " << endl;
	l1.updateAt(2, 89);
	l1.display();

	cout << "\n===== Rotation =====" << endl;
	l1.rotate(3);
	l1.display();

	cout << "\n===== Find Middle =====" << endl;
	cout << l1.findMiddle() << endl;

	cout << "\n===== Reverse =====" << endl;
	l1.reverse();
	l1.display();

	cout << "\nReverse Display After Reverse: " << endl;
	l1.displayReverse();

	cout << "\n===== Sorting =====" << endl;
	l1.sort();
	l1.display();

	cout << "\n===== Remove Duplicates =====" << endl;
	l1.removeDuplicates();
	l1.display();

	cout << "\n=== Traversing the Final List using Iterator ===" << endl;

	for (auto it = l1.begin(); it != l1.end(); ++it)
	{
		cout << *it << "<->";
	}

	cout << "NULL" << endl;

	return 0;
}
