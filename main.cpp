#include<iostream>
using namespace std;
void MergeSort(int* a,int n)
{
    if (n == 1)
    {
        return;
    }
    int mid = n / 2;
    int* pLeft = (int*)malloc(mid * sizeof(int));
    int* pRight = (int*)malloc((n - mid) * sizeof(int));
    for (int i = 0; i < mid; i++)
    {
        *(pLeft + i) = a[i];
    }
    for (int i = mid, k = 0; i < n; i++, k++)
    {
        *(pRight + k) = a[i];
    }
    MergeSort(pLeft,mid);
    MergeSort(pRight,n-mid);
    int loc = 0;
    int i = 0, j = 0;
    int lenLeft = mid;
    int lenRight = n-mid;
    while (i < lenLeft && j < lenRight)
    {
        if (pLeft[i] <= pRight[j])
        {
            a[loc] = pLeft[i];
            i++;
            loc++;
        }
        if (pLeft[i] > pRight[j])
        {
            a[loc] = pRight[j];
            j++;
            loc++;
        }
    }
    if (i == lenLeft)
    {
        while (j != lenRight)
        {
            a[loc] = pRight[j];
            j++;
            loc++;
        }
    }
    if (j == lenRight)
    {
        while (i != lenLeft)
        {
            a[loc] = pLeft[i];
            i++;
            loc++;
        }
    }
    free(pLeft);
    free(pRight);
}

int main()
{
    int a[10] = { 10,7,5,11,21,8,4,1,6,11};
    int len=sizeof(a) / sizeof(a[0]);
    MergeSort(a,len);
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
}
