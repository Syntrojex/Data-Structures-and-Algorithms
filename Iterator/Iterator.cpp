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
			if (current != other.current)
			{
				return true;
			}
			return false;
		}
	};


	Iterator begin()
	{
		return Iterator(head);
	}

	Iterator end()
	{
		return Iterator(NULL);
	}
