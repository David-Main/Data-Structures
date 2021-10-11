# Observations:

I observed while implementing linked lists using recursion that  
any pointer variable created in a recursive function must be used  
with caution.  

For example  

``` cpp
void recursiveReverse(node *currentNode, node *prev = nullptr)
{
	node* nextNode = currentNode->next
	if (nullptr != currentNode->next)
		recursiveReverse(currentNode->next, currentNode);
	if (currentNode->next == nullptr)
		head = currentNode;
	nextNode = prev;
}
```
On the last line in the function above, we want to set nextNode to  
the previous Node.  
While the logic of this is clear and valid, the implementation isn't why;  
because at the end of that statement, the function ends and all variables  
created in the stack frame of that function will be deleted.

The problem here is, that even though nextNode and currentNode->next  
give us information about the same address of memory, nextNode will be  
deleted hence, it will be set to a nullpointer.  

This happens for all items in the list and subsequently, 
- we loose access to all list items aside from the last node  
which becomes the head node. 
- we also cause memory leaks in our program since the lost list  
items will still be occupying memory.  


In order to avoid this, we need to use currentNode->next directly instead.   
What I mean is...

``` cpp
void recursiveReverse(node *currentNode, node *prev = nullptr)
{
	if (nullptr != currentNode->next)
		recursiveReverse(currentNode->next, currentNode);
	if (currentNode->next == nullptr)
		head = currentNode;
	currentNode->next = prev;
}
```

I do not have full closure on why this works but I believe it has to  
do with the fact that by using "currentNode->next" directly, we are rather dealing  
with the list items themselves and not a representation of them as the local variable would have it.  

Full code at [Implementation Section](https://github.com/David-Main/Data-Structures/blob/6c9ee2591ad37094b95fd5cce5de4a9b963ffbdd/arrays%26Lists/Implementation/LinkedListImplement.cpp#L207)
