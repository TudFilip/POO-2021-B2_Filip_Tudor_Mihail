#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

void partitie(char a[][256], int p, int n, int &poz)
{
    int x = strlen(a[p]);
    char sir_x[256];
    strcpy(sir_x,a[p]);
    int i = p+1;
    int j = n;
    while(i<=j)
    {
        if(strlen(a[i])<x)
            i++;
        if(strlen(a[j])>x)
            j--;
        if(i<j && strlen(a[i])>x && strlen(a[j])<x)
        {
            char aux[256];
            strcpy(aux,a[i]);
            strcpy(a[i],a[j]);
            strcpy(a[j],aux);
            i++;
            j--;
        }
    }
    poz = i-1;
    strcpy(a[p],a[poz]);
    strcpy(a[poz],sir_x);
}

void quick(char a[][256], int p, int n)
{
    int poz;
    while(p<n)
    {
        partitie(a, p, n, poz);
        quick(a, p, poz-1);
        quick(a, poz+1, n);
    }
}

int main()
{
    char text[256], *t, a[256][256], b[256];
    int i=0;

    scanf("%[^\n]s", text);

    t = strtok(text, " ");

    while(t!=NULL)
    {
        strcpy(a[i], t);
        i++;
        t = strtok(NULL, " ");
    }

    int n=i, j;

    /*for(i=0; i<=n; i++)
        for(j=i+1; j<=n-1; j++)
            if(strlen(a[i]) < strlen(a[j]))
            {
                strcpy(b, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], b);
            }*/
    quick(a, 0, n-1);

    for(i=0; i<=n; i++)
        cout<<a[i]<<"\n";


    return 0;
}
