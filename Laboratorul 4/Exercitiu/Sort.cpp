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

	int lenght = sizeof(init) / sizeof(init[0]);
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
	while (i < lenght)
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

void Sort::InsertSort(bool ascendent)
{
	int lenght = GetElementsCount();
	int i = 1, j, last;
	node* curent_node = new node;
	curent_node = L.first;

	while (i <= lenght)
	{
		last = GetElementFromIndex(i);
		j = i - 1;
		node* curent_element = new node;
		curent_element = curent_node->prev;

		if (ascendent)
		{
			while (j > 0 && GetElementFromIndex(j) > last)
			{
				int tmp = curent_element->info;
				curent_element->info = curent_element->next->info;
				curent_element->next->info = tmp;
				curent_element = curent_element->prev;
				j = j - 1;
			}
		}
		else
		{
			while (j > 0 && GetElementFromIndex(j) < last)
			{
				int tmp = curent_element->info;
				curent_element->info = curent_element->next->info;
				curent_element->next->info = tmp;
				curent_element = curent_element->prev;
				j = j - 1;
			}
		}
		curent_element->next->info = last;
		i++;
		curent_node = curent_node->next;
	}
}

void Sort::BubbleSort(bool ascendent)
{
	int i = 0, j;
	bool swap;
	int lenght = GetElementsCount();

	while (i < lenght - 1)
	{
		swap = false;
		j = 1;
		node* curent_element = new node;
		curent_element = L.first;

		while (j <= lenght - i - 1)
		{
			if (ascendent)
			{
				if (GetElementFromIndex(j) > GetElementFromIndex(j + 1))
				{
					int tmp = curent_element->info;
					curent_element->info = curent_element->next->info;
					curent_element->next->info = tmp;
					swap = true;
				}
			}
			else
			{
				if (GetElementFromIndex(j) < GetElementFromIndex(j + 1))
				{
					int tmp = curent_element->info;
					curent_element->info = curent_element->next->info;
					curent_element->next->info = tmp;
					swap = true;
				}
			}
			curent_element = curent_element->next;
			j++;
		}

		if (!swap)
			break;
		i++;
	}
}

void Sort::QuickSort(bool ascendent)
{
	
	if (L.left != L.right)
	{
		int tmp;
		node* pivot = new node;
		pivot = L.left;
		node* i = new node;
		i = L.left->next;
		node* j = new node;
		j = L.left;
		
		while (j->next != L.right)
		{
			if (j->info >= pivot->info)
			{
				tmp = j->info;
				j->info = i->info;
				i->info = tmp;
				i = i->next;
			}
		}
		tmp = i->next->info;


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