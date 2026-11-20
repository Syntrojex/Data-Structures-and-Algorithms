#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class HashTable {
	enum State { EMPTY, OCCUPIED, DELETED };
	struct Bucket {
		int key;
		int value;
		State state;

		Bucket()
		{
			key = -1;
			value = -1;
			state = EMPTY;
		}
	};

	vector<Bucket> table;
	int count;
	int capacity;

	bool checkPrime(int num)
	{
		if (num < 2)
		{
			return false;
		}

		for (int i = 2; i < num - 1; i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}

		return true;
	}

	double loadFactor()
	{
		return (double)count / capacity;
	}

	// 1. Division Method  h(k) = key % capacity
	int divisionHash(int key)
	{
		return key % capacity;
	}

	// 2. Multiplication Method (k) = floor( capacity * (key * A) )
	int multiplicationHash(int key)
	{
		const double A = 0.6180339887; // Knuth's suggested constant (Golden Ratio)
		double product = key * A;
		double fractionalPart = product - floor(product); // Sirf decimal hissa nikalna

		return floor(capacity * fractionalPart);
	}

	// 3. Mid Square Method h(k) = middle_digits(k * k)
	int midSquare(int key)
	{
		int sq = key * key;            // Step 1: Square nikala (e.g. 12 * 12 = 144)
		string s = to_string(sq);      // Step 2: String mein badla ("144")
		int mid = s.length() / 2;      // Step 3: Beech ka index nikala (3 / 2 = 1)
		return (s[mid] - '0') % capacity;           // Step 4: Beech wala digit wapas int mein return kr diya ('4' -> 4)
	}

	// 4. Folding Method h(k) = (part1 + part2 + part3 + ...) % capacity
	int foldingHash(long long key)
	{
		int sum = 0;

		// Key ke 2-2 digits ke tukre karke add karna
		while (key > 0) {
			sum += key % 100; // Aakhri 2 digits add karein
			key /= 100;       // Aakhri 2 digits hata dein
		}

		return sum % capacity;
	}

	int nextPrime(int num)
	{
		while (!checkPrime(num))
		{
			num++;
		}

		return num;
	}

	void rehashing()
	{
		vector<Bucket> old = table;
		capacity = nextPrime(capacity * 2);
		int oldSize = old.size();

		table = vector<Bucket>(capacity);
		count = 0;

		for (int i = 0; i < oldSize; i++)
		{
			if (old[i].state == OCCUPIED)
			{
				insert(old[i].key, old[i].value);
			}
		}
	}

public:
	HashTable(int size = 7)
	{
		capacity = size;
		count = 0;
		table.resize(capacity);
	}

	int size() const
	{
		return count;
	}

	bool empty()
	{
		return count == 0;
	}

	bool insert(int key, int value)
	{
		// 1. Agar key pehle se maujood hai, toh purani entry delete kar dein
		remove(key);

		if (loadFactor() > 0.7)
		{
			rehashing();
		}

		int hashIndex = divisionHash(key);
		for (int i = 0; i < capacity; i++)
		{
			int current = (hashIndex + i) % capacity;
			if (table[current].state != OCCUPIED)
			{
				table[current].key = key;
				table[current].value = value;
				table[current].state = OCCUPIED;
				count++;
				return true;
			}
		}

		return false;
	}


	// & is liye kio k key ko search kren ge or jo valuer us key pr ho gi use main me reference se return kren ge
	bool search(int key, int& value)
	{
		int hashIndex = divisionHash(key);

		for (int i = 0; i < table.size(); i++)
		{
			int current = (hashIndex + i) % capacity; // Linear Probing

			if (table[current].state == EMPTY)
			{
				return false;
			}

			if (table[current].state == OCCUPIED && table[current].key == key)
			{
				value = table[current].value;
				return true;
			}

			// DELETED pr continue hi rhe ga
		}

		return false;
	}

	bool remove(int key)
	{
		int index = divisionHash(key);

		for (int i = 0; i < table.size(); i++)
		{
			int current = (index + i) % capacity;

			if (table[current].state == EMPTY)
			{
				return false;
			}

			if (table[current].state == OCCUPIED && table[current].key == key)
			{
				table[current].state = DELETED;
				count--;
				return true;
			}
		}

		return false;
	}

	void display()
	{
		cout << "\nIndex\tKey\tValue\tState" << endl;
		for (int i = 0; i < table.size(); i++)
		{
			// First Printed Index
			cout << i << "\t";

			// agar occipied ha yani koi na koi value pri ha to us ki key or value or state print kr di
			if (table[i].state == OCCUPIED)
			{
				cout << table[i].key << "\t" << table[i].value << "\t" << table[i].state << endl;
			}

			// agar deleted ha to sirf state show kr do
			else if (table[i].state == DELETED)
			{
				cout << "-\t-\tDELETED" << endl;
			}

			// agar empty to sirf state
			else
			{
				cout << "-\t-\tEMPTY" << endl;
			}
			cout << endl;
		}
	}

	~HashTable()
	{
		table.clear();
	}

};
