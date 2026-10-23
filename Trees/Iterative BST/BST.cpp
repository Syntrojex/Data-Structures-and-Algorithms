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

	void remove(int key) {
		Node* current = root;
		Node* parent = nullptr;

		// Step 1: Node ko dhoondo aur uska parent track karo
		while (current != NULL && current->data != key)
		{
			parent = current;
			if (key < current->data)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}

		// current wo Node ban jay gi aise jo delete krni ha

		// Agar node mila hi nahi
		if (current == NULL)
		{
			cout << key << " Not Found" << endl;
			return;
		}

		// ==========================================
		// CASE 1: Leaf Node (0 Children - Na left hai, na right)
		// ==========================================
		if (current->left == NULL && current->right == NULL)
		{
			if (parent == NULL)
			{
				root = NULL;
			}
			else if (parent->left == current)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
			delete current;
		}

		// ==========================================
		// CASE 2: One Child (Sirf 1 child ho - chahe left ho ya right)
		// ==========================================
		else if (current->left == NULL || current->right == NULL)
		{
			// Pata lagao ke child kis taraf hai
			Node* child = (current->left != NULL) ? current->left : current->right;

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

		// ==========================================
		// CASE 3: Two Children (Dono children mojood hon)
		// ==========================================
		else
		{
			// Right subtree ka sabse chota node inorder Successor
			Node* succParent = current;
			Node* succ = current->right;

			while (succ->left != NULL)
			{
				succParent = succ;
				succ = succ->left;
			}

			// Successor ki data ko current node mein copy kar do
			current->data = succ->data;

			// Ab successor node ko link hata kar delete kar do
			if (succParent->left == succ)
			{
				succParent->left = succ->right;
			}
			else
			{
				succParent->right = succ->right;
			}
			delete succ;
		}

		cout << key << " Successfully Removed!" << endl;
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
