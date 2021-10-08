#include <iostream>
#include <iomanip>

using namespace std;

class dlList
{
private:
	struct node
	{
		int data;
		node *prev = nullptr;
		node *next = nullptr;
	};

public: //variables
	size_t listCount;
	node *headNode = nullptr;

public: //functions
	dlList()
	{
		listCount = 0; // empty list
	}

	dlList(int value)
	{
		headNode = new node{value};
		++listCount;
	}

	bool isEmpty()
	{
		return ((0 == listCount) ? true : false);
	}

	void add(int value)
	{
		node *temp = headNode;
		if (isEmpty() && nullptr == headNode)
		{
			headNode = new node{value};
			++listCount;
		}
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new node{value};
			++listCount;
		}
	}

	void print()
	{
		node *temp = headNode;
		if (isEmpty())
			return;
		while (temp != nullptr)
		{
			cout << setw(4) << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}

	void print(size_t position)
	{
		if (isEmpty() || (position > listCount))
			return;

		node *temp = headNode;
		size_t currentPos = 1;
		while (currentPos != position)
		{
			temp = temp->next;
			++currentPos;
		}
		cout << temp->data << endl;
	}

	void insert(int value, size_t position)
	{
		if (isEmpty())
			return;
		if (position > listCount)
		{
			cout << "Position out of range:" << endl;
			return;
		}
		node *currentNode = headNode;
		size_t currentPos = 1;
		while (currentPos != position)
		{
			currentNode = currentNode->next;
			++currentPos;
		}
		if (1 == currentPos && currentNode == headNode)
		{
			currentNode->prev = new node{value, nullptr, currentNode};
			headNode = currentNode->prev;
		}
		else
		{
			currentNode->prev->next = new node{value, currentNode->prev, currentNode};
			currentNode->prev = currentNode->prev->next;
		}
		++listCount;
	}

	size_t search(int value) //returns 0 if item is not found
	{
		if (!isEmpty())
		{
			node *temp = headNode;
			size_t position = 1;
			while ((value != temp->data) && (nullptr != temp->next))
			{
				temp = temp->next;
				++position;
			}
			return ((temp->data == value) ? (position) : (0));
		}
		return 0;
	}

	bool remove(size_t position)
	{
		if (isEmpty() || position > listCount || 0 == position)
			return false;

		node *temp = headNode;
		size_t currentPos = 1;
		while (currentPos != position)
		{ //Go to target Position;
			temp = temp->next;
			++currentPos;
		}

		if (temp == headNode)
		{ // Delete head node
			headNode = temp->next;
		}
		else if (nullptr == temp->next)
		{ // Delete last node;
			temp->prev->next = nullptr;
		}
		else if (position < listCount)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}

		delete temp;
		temp = nullptr;
		return true;
	}
};

int main()
{
	dlList items;
	items.add(3);

	items.print();

	//Insert Test
	for (int i = 1, p = 1; i < 30; i *= 2, ++p)
	{
		items.insert(i, p);
	}
	items.print();

	items.search(32);

	//Overloaded Print test
	for (int i = 1; i <= items.listCount; ++i)
	{
		items.print(i);
	}

	// Testing removal of node
	items.remove(1);
	items.print();
	items.remove(items.search(3));
	items.print();
	items.remove(items.search(16));
	items.print();
	items.remove(items.search(16));
	items.print();

	return 0;
}