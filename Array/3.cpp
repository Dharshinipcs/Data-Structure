//Program to find and Remove Duplicate Elements from Array
#include<iostream>
using namespace std;
int main()
{
    int A[10],B[10],n,i,j,k=0;
    cout<<"Enter the no of elements of the array:";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            if (A[i] == B[j])
                break;
        }
        if (j == k) {
            B[k] = A[i];
            k++;
        }
    }

    cout << "Repeated elements after deletion: ";
    for (i = 0; i < k; i++)
        cout << B[i] << " ";
    return 0;
}
