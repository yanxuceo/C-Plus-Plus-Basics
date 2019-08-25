#include <iostream>

int BinarySearch(int A[], int n, int x)
{
    int low = 0;
    int high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(x == A[mid])  {
            return mid;
        }
        else if(x < A[mid]) {
            high = mid - 1;
        }
        else {   
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int array[] = {2,6,8,23,57,60,700};
    int x;

    std::cout << "Enter a number: ";
    std::cin >> x;

    int index = BinarySearch(array, 7, x);
    if(index != -1) {
        std::cout << "Number "<<x<<" is at index " << index << std::endl;
    }
    else {
        std::cout << "Number "<<x<<" not found!" << std::endl;
    }

    return 0;
}
