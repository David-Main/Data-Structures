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

	void add(int value)
	{
		node *temp = headNode;
		if (0 == listCount && nullptr == headNode)
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
		if (0 == listCount)
		{
			cout << "list is empty\n";
			return;
		}

		while (temp != nullptr)
		{
			cout << setw(4) << temp->data;
			temp = temp->next;
		}
	}
};

int main()
{
	dlList items;
	items.add(3);

	items.print();

	return 0;
}