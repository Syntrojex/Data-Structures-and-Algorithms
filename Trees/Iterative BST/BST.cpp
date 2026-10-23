#include<iostream>
#include<stack>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

class BST {
	Node* root;

public:
	BST()
	{
		root = NULL;
	}

	~BST()
	{
		clear();
	}

	void clear()
	{
		if (isEmpty())
		{
			return;
		}

		stack<Node*> st;
		st.push(root);

		while (!st.empty())
		{
			Node* node = st.top();
			st.pop();

			if (node->left != NULL)
			{
				st.push(node->left);
			}

			if (node->right != NULL)
			{
				st.push(node->right);
			}

			delete node;
		}

		root = NULL;
	}


	bool isEmpty() const
	{
		return root == nullptr;
	}

	void insert(int data)
	{
		Node* newNode = new Node(data);
		if (root == NULL)
		{
			root = newNode;
			return;
		}

		Node* current = root;
		Node* parent = NULL;

		while (current != NULL)
		{
			parent = current;

			if (data < current->data)
			{
				current = current->left;
			}

			else if (data > current->data)
			{
				current = current->right;
			}

			else
			{
				delete newNode;  // To Avoid Duplicates
				return;
			}
		}

		if (data < current->data)
		{
			current->left = newNode;
		}

		else
		{
			current->right = newNode;
		}
	}

	bool search(int key) const
	{
		Node* temp = root;

		while (temp != NULL)
		{
			if (key == temp->data)
			{
				return true;
			}

			else
			{
				if (key < temp->data)
				{
					temp = temp->left;
				}
				else if (key > temp->data)
				{
					temp = temp->right;
				}
			}
		}
		return false;
	}

	int findMin() const
	{
		if (root == NULL)
		{
			cout << "Tree is Empty" << endl;
			return;
		}

		Node* temp = root;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}

		return temp->data;
	}

	int findMax() const
	{
		if (root == NULL)
		{
			cout << "Tree is Empty" << endl;
			return;
		}

		Node* temp = root;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}

		return temp->data;
	}

	void remove(int key)
	{
		if (root == NULL)
		{
			cout << "Tree is Empty" << endl;
			return;
		}

		Node* current = root;
		Node* parent = NULL;

		while (current != NULL && current->data != key)
		{
			parent = current;

			if (key < current->data)
			{
				current = current->left;
			}

			else if (key > current->data)
			{
				current = current->right;
			}
		}

		if (current == NULL)
		{
			cout << key << "Not Found" << endl;
		}

		// Both Childs exist
		if (current->left != NULL && current->right != NULL)
		{
			Node* succParent = current;
			Node* succ = current->right;

			while (succ->left != NULL)
			{
				succParent = succ;
				succ = succ->left;
			}

			current->data = succ->data;
			current = succ;               // now delete successor node
			parent = succParent;
		}

		// Zero or one child

		Node* child;
		if (current->left != NULL)
		{
			child = current->left;
		}
		else
		{
			current = current->right;
		}

		if (parent == NULL)
		{
			root = child;
		}

		else if (parent->left == current)
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
		delete current;
	}
};

int main()
{
	BST bst;

	bst.insert(99);
	bst.insert(88);
	bst.insert(54);
	bst.insert(76);
	bst.insert(101);
	bst.insert(23);
	bst.insert(15);
	bst.insert(93);

	return 0;
}
