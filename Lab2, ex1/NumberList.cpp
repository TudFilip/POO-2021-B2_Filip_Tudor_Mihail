#include "NumberList.h"

void NumberList::Init()
{
    count = 0;
}

bool NumberList::Add(int x)
{
    if (count == 9)
        return false;
    numbers[count] = x;
    count++;
}

void NumberList::Sort()
{
    int i, j;
    for (i = 0; i <= count - 1; i++)
        for (j = i + 1; j <= count; j++)
            if (numbers[i] > numbers[j])
                switch (numbers[i], numbers[j]);
}

void NumberList::Print()
{
    cout << count << '\n';
    for (int i = 0; i <= count; i++)
        cout << numbers[i] << ' ';
}