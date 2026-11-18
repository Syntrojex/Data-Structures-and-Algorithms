#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	int height;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		height = 0;
		left = right = NULL;
	}
};

class BST {
	Node* root;

	void clear(Node* current)
	{
		if (current == NULL)
		{
			return;
		}

		clear(current->left);
		clear(current->right);
		delete current;
	}

	int getHeight(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		int leftHeight = getHeight(root->left);
		int rightHeight = getHeight(root->right);

		return max(leftHeight, rightHeight) + 1;
	}

	Node* add(Node* temp, int data)
	{
		if (temp == NULL)
		{
			return new Node(data);
		}

		if (data < temp->data)
		{
			temp->left = add(temp->left, data);
		}

		else if (data > temp->data)
		{
			temp->right = add(temp->right, data);
		}

		return temp;
	}

	Node* search(Node* temp, int data) const
	{
		if (temp == NULL || temp->data == data)
		{
			return temp;
		}

		if (data < temp->data)
		{
			return search(temp->left, data);
		}

		else
		{
			return search(temp->right, data);
		}
	}

	Node* remove(Node* temp, int key)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		if (temp->data == key)
		{
			// Case-1: Leaf Node
			if (temp->left == NULL && temp->right == NULL)
			{
				delete temp;
				return NULL;
			}

			// Case-2(a): Left Child Exist
			if (temp->left != NULL && temp->right == NULL)
			{
				Node* temp1 = temp->left;

				delete temp;
				return temp1;
			}

			// Case-2(b): Right Child Exists
			if (temp->left == NULL && temp->right != NULL)
			{
				Node* temp1 = temp->right;

				delete temp;
				return temp1;
			}

			// Case-3: Both Childs Exists
			if (temp->left != NULL && temp->right != NULL)
			{
				Node* successor = minNode(temp->right);  // Kio k right side ka min Node Successor bane ga

				temp->data = successor->data;

				temp->right = remove(temp->right, successor->data);
			}
		}

		if (key < temp->data)
		{
			temp->left = remove(temp->left, key);
		}

		else if (key > temp->data)
		{
			temp->right = remove(temp->right, key);
		}

		return temp;
	}

	Node* minNode(Node* temp)
	{
		while (temp->left != NULL)
		{
			temp = temp->left;
		}

		return temp;
	}

	Node* maxNode(Node* temp)
	{
		while (temp->right != NULL)
		{
			temp = temp->right;
		}

		return temp;
	}

	Node* update(Node* temp, int oldVal, int newVal)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		if (temp->data == oldVal)
		{
			temp->data = newVal;
		}

		else if (oldVal < temp->data)
		{
			temp->left = update(temp->left, oldVal, newVal);
		}

		else
		{
			temp->right = update(temp->right, oldVal, newVal);
		}

		return temp;
	}

	void inorder(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		inorder(temp->left);
		cout << temp->data << " ";
		inorder(temp->right);
	}

	void postorder(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		postorder(temp->left);
		postorder(temp->right);
		cout << temp->data << " ";
	}

	void preorder(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		cout << temp->data << " ";
		preorder(temp->left);
		preorder(temp->right);
	}

	void calculateHeight(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
	}

	void printAtLevel(Node* root, int level)
	{
		if (root == NULL)
		{
			return;
		}

		if (level == 1)
		{
			cout << root->data << " ";
		}

		else if (level > 1)
		{
			printAtLevel(root->left, level - 1);
			printAtLevel(root->right, level - 1);
		}
	}

public:
	BST()
	{
		root = NULL;
	}

	void insert(int data)
	{
		root = add(root, data);
	}

	Node* search(int key)
	{
		return search(root, key);
	}

	void remove(int key)
	{
		root = remove(root, key);
	}

	int getMin()
	{
		Node* min = minNode(root);

		return min->data;
	}

	int getMax()
	{
		Node* max = maxNode(root);

		return max->data;
	}

	void displayInorder()
	{
		inorder(root);
	}

	void displayPostorder()
	{
		postorder(root);
	}

	void displayPreorder()
	{
		preorder(root);
	}

	void levelorderUsingHeight()
	{
		// sab se phele max height nikal li yani root ki 
		int h = getHeight(root);

		for (int i = 0;i < h;i++)
		{
			printAtLevel(root, i);
		}
	}

	void levelorderUsingQueue()
	{
		queue<Node*> q1;

		q1.push(root);

		while (!q1.empty())
		{
			Node* current = q1.front();
			q1.pop();

			cout << current->data << " ";

			if (current->left != nullptr)
			{
				q1.push(current->left);
			}

			if (current->right != nullptr)
			{
				q1.push(current->right);
			}
		}
	}

	void update(int oldVal, int newVal)
	{
		root = update(root, oldVal, newVal);
	}

	~BST()
	{
		clear(root);
		root = NULL;
	}

};

int main()
{
	BST bst;


	// Insertion
	bst.insert(109);
	bst.insert(99);
	bst.insert(23);
	bst.insert(31);
	bst.insert(56);
	bst.insert(11);
	bst.insert(83);
	bst.insert(101);
	bst.insert(25);
	bst.insert(30);
	bst.insert(12);




	return 0;
}
