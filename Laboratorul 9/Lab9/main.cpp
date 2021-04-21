#include "Map_Template.h"

int main()
{
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "------------------\n\n";

    m.Set(10, "laborator");
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Set(15, "clasa");

    const char *val;
    m.Get(20, val);
    printf("%s\n", val);

    printf("In mapa avem %d elemente\n", m.Count());

    m.Delete(10);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    Map<int, const char*> m2;

    m2[30] = "albastru";
    m2[20] = "rosu";

    if (m.Includes(m2))
        cout << "m2 se regaseste in m\n";
    else
        cout << "m2 nu se regaseste in m\n";

    m.Clear();
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}