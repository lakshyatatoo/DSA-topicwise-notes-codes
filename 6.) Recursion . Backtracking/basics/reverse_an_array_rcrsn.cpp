#include <bits/stdc++.h>
using namespace std;

void revarr(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(arr[l], arr[r]);

    revarr(arr, l + 1, r - 1);
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    revarr(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

#include <bits/stdc++.h>
using namespace std;

void revarr(int arr[], int i, int n) // only 1 pointer is used i and only i is being modified
{
    if (i >= n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);

    revarr(arr, i + 1, n);
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    revarr(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}