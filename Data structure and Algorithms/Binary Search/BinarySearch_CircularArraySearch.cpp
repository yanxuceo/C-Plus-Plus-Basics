#include <iostream>

int CircularArraySearch(int A[], int n, int x)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(x == A[mid]) 
            return mid;                  // case 1: Found X
        if(A[mid] <= A[high])            // case 2: right half is sorted
        {
            if(x > A[mid] && x <= A[high])
                low = mid + 1;           // go searching in right sorted half
            else
            {
                high = mid - 1;          // go searching left
            }
        }
        else if(A[low] <= A[mid])        // case 3: left half is sorted 
        {
            if(A[low] <= x && x < A[mid]) // go searching in left sorted half
                high = mid - 1;
            else
                low = mid + 1;           // go searching right
        }
    }
    return -1;
}


int main()
{
    int array[] = {800,900,2,6,8,23,57,60,700,701};

    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;

    int index = CircularArraySearch(array, sizeof(array)/sizeof(array[0]),x);
    if(index != -1)
    {
        std::cout << index << std::endl;
    }
    else
    {
        std::cout << "Not found!" << std::endl;
    }
   
    return 0;
}
