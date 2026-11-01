#include<iostream>
#include<queue>  // For level Order Traversal

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
		left = NULL;
		right = NULL;
	}
};

class AVL {
	Node* root;

	void inOrder(Node* temp)
	{
		if (temp == NULL) return;
		inOrder(temp->left);
		cout << temp->data << " , ";
		inOrder(temp->right);
	}
	void preOrder(Node* temp)
	{
		if (temp == NULL) return;
		cout << temp->data << " , ";
		preOrder(temp->left);
		preOrder(temp->right);
	}
	void postOrder(Node* temp)
	{
		if (temp == NULL) return;
		postOrder(temp->left);
		postOrder(temp->right);
		cout << temp->data << " , ";
	}

	void clear(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		clear(temp->left);
		clear(temp->right);
		delete temp;
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

	Node* add(Node* root, int data)
	{
		if (root == NULL)
		{
			return new Node(data);
		}

		if (root->data > data)
		{
			root->left = add(root->left, data);
		}

		else if (root->data < data)
		{
			root->right = add(root->right, data);
		}

		return balance(root);
	}

	Node* update(Node* temp, int oldData, int newData)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		if (temp->data == oldData)
		{
			temp->data = newData;
		}

		if (temp->data > oldData)
		{
			temp->left = update(temp->left, oldData, newData);
		}

		else if (temp->data < oldData)
		{
			temp->right = update(temp->right, oldData, newData);
		}

		return balance(temp);
	}

	Node* search(Node* temp, int data)
	{
		if (temp == NULL || temp->data == data)
		{
			return temp;
		}

		if (temp->data > data)
		{
			return search(temp->left, data);
		}

		else if (temp->data < data)
		{
			return search(temp->right, data);
		}
	}

	Node* remove(Node* temp, int data)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		if (data < temp->data)
		{
			temp->left = remove(temp->left, data);
		}
		else if (data > temp->data)
		{
			temp->right = remove(temp->right, data);
		}

		else
		{
			// Case-1: Lead Node
			if (temp->left == NULL && temp->right == NULL)
			{
				delete temp;
				return NULL;
			}

			// Case-2: Left Child
			if (temp->left != NULL && temp->right == NULL)
			{
				Node* temp1 = temp->left;
				delete temp;
				return temp1;
			}

			// Case-3: Right Child
			if (temp->left == NULL && temp->right != NULL)
			{
				Node* temp1 = temp->right;
				delete temp;
				return temp1;
			}

			// Case-4: Both Childs
			if (temp->left != NULL && temp->right != NULL)
			{
				Node* successor = minNode(temp->right);
				temp->data = successor->data;

				temp->right = remove(temp->right, successor->data);
			}
		}

		return balance(temp);
	}

	int getHeight(Node* temp)
	{
		if (temp == NULL)
		{
			return 0;
		}

		return temp->height;
	}

	void updateHeight(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
	}

	int calculateBF(Node* temp)
	{
		if (temp == NULL)
		{
			return 0;
		}

		return getHeight(temp->left) - getHeight(temp->right);
	}

	Node* rotateRight(Node* x)
	{
		Node* y = x->left;
		Node* temp = y->right;
		y->right = x;
		x->left = temp;
		updateHeight(x);
		updateHeight(y);
		return y;
	}

	Node* rotateLeft(Node* x)
	{
		Node* y = x->right;
		Node* temp = y->left;
		y->left = x;
		x->right = temp;
		updateHeight(x);
		updateHeight(y);
		return y;
	}

	Node* balance(Node* temp)
	{
		updateHeight(temp);

		// Case-1: Right Side Heavy (Negative BF)
		if (calculateBF(temp) == -2)
		{
			// Agar right child Left Heavy hai
			// toh ye RL Case hai
			// Pehle right child par Right Rotation
			if (calculateBF(temp->right) > 0)
			{
				temp->right = rotateRight(temp->right);
			}

			// Agar right child bhi Right Heavy hai
			// toh inner if nahi chalega
			// Ye RR Case hai aur direct Left Rotation hogi
			return rotateLeft(temp);
		}

		// Case-2: Left Side Heavy (Positive BF)
		if (calculateBF(temp) == 2)
		{
			// Agar left child Right Heavy hai
			// toh ye LR Case hai
			// Pehle left child par Left Rotation
			if (calculateBF(temp->left) < 0)
			{
				temp->left = rotateLeft(temp->left);
			}

			// Agar left child bhi Left Heavy hai
			// toh inner if nahi chalega
			// Ye LL Case hai aur direct Right Rotation hogi
			return rotateRight(temp);
		}

		// Agar BF -2 ya +2 nahi hai
		// toh tree already balanced hai
		return temp;
	}


public:
	AVL()
	{
		root = NULL;
	}

	~AVL()
	{
		clear(root);
		root = NULL;
	}

	void insert(int data)
	{
		root = add(root, data);
	}

	void remove(int data)
	{
		root = remove(root, data);
	}

	Node* search(int data)
	{
		return search(root, data);
	}

	void update(int oldData, int newData)
	{
		if (search(root, oldData) == NULL)
		{
			return;
		}

		root = remove(root, oldData);
		root = add(root, newData);
	}

	int findMax()
	{
		return maxNode(root)->data;
	}

	int findMin()
	{
		return minNode(root)->data;
	}

	void displayInorder()
	{
		inOrder(root);
	}

	void displayPreorder()
	{
		preOrder(root);
	}

	void displayPostorder()
	{
		postOrder(root);
	}

	void levelorderTraversal()
	{
		if (root == NULL)
		{
			return;
		}

		queue<Node*> q;

		q.push(root);

		while (!q.empty())
		{
			Node* current = q.front();
			q.pop();

			cout << current->data << " ";

			if (current->left != NULL)
			{
				q.push(current->left);
			}

			if (current->right != NULL)
			{
				q.push(current->right);
			}
		}
	}
};

int main()
{
	AVL avl;

	return 0;
}
