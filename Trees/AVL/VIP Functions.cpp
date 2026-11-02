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
