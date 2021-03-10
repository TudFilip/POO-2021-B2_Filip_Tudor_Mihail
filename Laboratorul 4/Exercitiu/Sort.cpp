#include "Sort.h"

Sort::Sort(int count, int min, int max)
{
	L.curent = nullptr;
	L.first = nullptr;
	L.last = nullptr;
	L.right = new node;
	L.left = new node;
	L.right->info = 0;
	L.right->next = nullptr;
	L.right->prev = L.left;
	L.left->info = 0;
	L.left->next = L.right;
	L.left->prev = nullptr;

	srand(time(NULL));
	node* new_node = new node;
	new_node->info = min + rand() % (max - (min - 1));
	new_node->next = L.right;
	new_node->prev = L.left;
	L.right->prev = new_node;
	L.left->next = new_node;
	L.first = new_node;
	L.last = L.first;
	L.curent = L.first;

	count--;

	while (count != 0)
	{
		node* new_node = new node;
		new_node->info = min + rand() % (max - (min - 1));
		new_node->next = L.right;
		new_node->prev = L.last;
		L.right->prev = new_node;
		L.last->next = new_node;
		L.last = new_node;
		L.curent = L.last;
		count--;
	}
}

Sort::Sort(int* init)
{
	L.curent = nullptr;
	L.first = nullptr;
	L.last = nullptr;
	L.right = new node;
	L.left = new node;
	L.right->info = 0;
	L.right->next = nullptr;
	L.right->prev = L.left;
	L.left->info = 0;
	L.left->next = L.right;
	L.left->prev = nullptr;

	int i = 0;

	node* new_node = new node;
	new_node->info = init[i];
	new_node->next = L.right;
	new_node->prev = L.left;
	L.right->prev = new_node;
	L.left->next = new_node;
	L.first = new_node;
	L.last = L.first;
	L.curent = L.first;

	i++;
	while (init[i] != NULL)
	{
		node* new_node = new node;
		new_node->info = init[i];
		new_node->next = L.right;
		new_node->prev = L.last;
		L.right->prev = new_node;
		L.last->next = new_node;
		L.last = new_node;
		L.curent = L.last;
		i++;
	}
}

Sort::Sort(int v[], int count)
{
	L.curent = nullptr;
	L.first = nullptr;
	L.last = nullptr;
	L.right = new node;
	L.left = new node;
	L.right->info = 0;
	L.right->next = nullptr;
	L.right->prev = L.left;
	L.left->info = 0;
	L.left->next = L.right;
	L.left->prev = nullptr;

	int i = 0;
	node* new_node = new node;
	new_node->info = v[i];
	new_node->next = L.right;
	new_node->prev = L.left;
	L.right->prev = new_node;
	L.left->next = new_node;
	L.first = new_node;
	L.last = L.first;
	L.curent = L.first;

	i++;
	while (i < count)
	{
		node* new_node = new node;
		new_node->info = v[i];
		new_node->next = L.right;
		new_node->prev = L.last;
		L.right->prev = new_node;
		L.last->next = new_node;
		L.last = new_node;
		L.curent = L.last;
		i++;
	}
}

Sort::Sort(int count, ...)
{
	L.curent = nullptr;
	L.first = nullptr;
	L.last = nullptr;
	L.right = new node;
	L.left = new node;
	L.right->info = 0;
	L.right->next = nullptr;
	L.right->prev = L.left;
	L.left->info = 0;
	L.left->next = L.right;
	L.left->prev = nullptr;

	va_list ap;
	int i = 0, value;

	va_start(ap, count);
	value = va_arg(ap, int);
	node* new_node = new node;
	new_node->info = value;
	new_node->next = L.right;
	new_node->prev = L.left;
	L.right->prev = new_node;
	L.left->next = new_node;
	L.first = new_node;
	L.last = L.first;
	L.curent = L.first;

	i++;
	while (i < count)
	{
		value = va_arg(ap, int);
		node* new_node = new node;
		new_node->info = value;
		new_node->next = L.right;
		new_node->prev = L.last;
		L.right->prev = new_node;
		L.last->next = new_node;
		L.last = new_node;
		L.curent = L.last;
		i++;
	}

	va_end(ap);
}

Sort::Sort(char* str)
{
	L.curent = nullptr;
	L.first = nullptr;
	L.last = nullptr;
	L.right = new node;
	L.left = new node;
	L.right->info = 0;
	L.right->next = nullptr;
	L.right->prev = L.left;
	L.left->info = 0;
	L.left->next = L.right;
	L.left->prev = nullptr;

	char number[256];
	bool first_number = true;
	char* word = strtok(str, ",");
	while (word != NULL)
	{
		//char number[256];
		strcpy_s(number, word);
		node* new_node = new node;
		if (first_number)
		{
			new_node->info = atoi(number);
			new_node->next = L.right;
			new_node->prev = L.left;
			L.right->prev = new_node;
			L.left->next = new_node;
			L.first = new_node;
			L.last = L.first;
			L.curent = L.first;
			first_number = false;
		}
		else
		{
			new_node->info = atoi(number);
			new_node->next = L.right;
			new_node->prev = L.last;
			L.right->prev = new_node;
			L.last->next = new_node;
			L.last = new_node;
			L.curent = L.last;
		}
		word = strtok(NULL, ",");
	}
}



void Sort::Print()
{
	node* curent_node = new node;
	curent_node = L.first;

	while (curent_node != L.right)
	{
		cout << curent_node->info << " ";
		curent_node = curent_node->next;
	}
	cout << "\n\n";
}

int Sort::GetElementsCount()
{
	node* curent_node = new node;
	curent_node = L.first;

	int count = 0;
	while (curent_node != L.right)
	{
		count++;
		curent_node = curent_node->next;
	}
	return count;
}

int Sort::GetElementFromIndex(int index)
{
	node* curent_node = new node;
	curent_node = L.first;

	while (curent_node != L.right)
	{
		index--;
		if (index == 0)
			return curent_node->info;
		curent_node = curent_node->next;
	}
	if (index != 0)
		return -1;
}