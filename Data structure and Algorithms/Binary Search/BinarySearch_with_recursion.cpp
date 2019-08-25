#include <iostream>

int BinarySearch(int A[], int low, int high, int x)
{
    if(low > high)
        return -1;
    int mid = low + (high-low)/2;

    if(x == A[mid])
        return mid; 
    else if(x < A[mid])
    {
        BinarySearch(A, low, mid-1, x);
    }  
    else
    {
        BinarySearch(A, mid+1, high, x);
    } 
}

int main()
{
    int array[] = {2,6,8,23,57,60,700};
    int x;

    std::cout << "Enter a number: ";
    std::cin >> x;

    int index = BinarySearch(array, 0, sizeof(array)/sizeof(array[0]), x);
    if(index != -1) {
        std::cout << "Number "<<x<<" is at index " << index << std::endl;
    }
    else {
        std::cout << "Number "<<x<<" not found!" << std::endl;
    }

    return 0;
}
