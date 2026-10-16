void shiftLeft(int* arr, int size, int fromIndex)
{
	// size-1 is liye kia kio k last element ko kisi agle element se replace nahi karna
	// left wale me agle elements ko peeche late hain 
	for (int i = fromIndex;i < size - 1;i++)
	{
		arr[i] = arr[i + 1];
	}
}

void shiftRight(int* arr, int size, int fromIndex)
{
	// right wale me agle element pr pichle ko le kr jate hain
	// yahan loop size-1 se isi liye shuru howa kio k elements ko right side move karte waqt end se start karna hota hai
	for (int i = size - 1;i >= fromIndex;i++)
	{
		arr[i + 1] = arr[i];
	}
}

void reverse(int start, int end)
{
	int* arr; // it will come throguh paramter 
	while (start <= end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		start++;
		end--;
	}
}

void rotateLeft(int k, int size)
{
	k = k % size;

	reverse(0, k - 1);
	reverse(k, size - 1);
	reverse(0, size - 1);
}


void rotateRight(int k, int size)
{
	k = k % size;

	reverse(0, size - 1);
	reverse(0, k - 1);
	reverse(k, size - 1);
}

void duplicates_remove(int array[], int& size)
{
	int duplicate = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
			{
				for (int k = j; k < size - 1; k++)
				{
					array[k] = array[k + 1];

				}
				size--;
				j--;
			}
		}
	}
}
