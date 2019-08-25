#include <iostream>

int BinarySearch(int A[], int n, int x, bool searchFirst)
{
    int low = 0;
    int high = n-1;
    int result = -1;

    while(low <= high)
    {
        int mid = (low+high)/2;
        if(x == A[mid]) {
            result = mid;
            if(searchFirst)
                high = mid - 1;
            else
                low = mid+1;
        }
        else if(x < A[mid]) 
        {
            high = mid - 1;
        }
        else {   
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int array[] = {2,6,6,6,8,23,57,60,700};
    int x;

    std::cout << "Enter a number: ";
    std::cin >> x;

    int firstIndex = BinarySearch(array, sizeof(array)/sizeof(array[0]), x, true);

    if(firstIndex == -1)
    {
        std::cout << "Count of "<<x<<" is 0!" << std::endl;
    }
    else
    {
        int lastIndex = BinarySearch(array, sizeof(array)/sizeof(array[0]), x, false);
        std::cout << "Count of "<<x<<" is " << lastIndex-firstIndex+1 << std::endl;
    }

    return 0;
}
