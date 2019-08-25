#include <iostream>

int FindRotationCount(int A[], int n)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        if(A[low] <= A[high])
            return low;                               // case 1
        int mid = low + (high-low)/2;
        int next = (mid+1) % n;
        int prev = (mid+n-1) % n;

        if(A[mid] <= A[next] && A[mid] <= A[prev])    // case 2
            return mid;
        else if(A[mid] <= A[high]) high = mid-1;      // case 3
        else if(A[mid] >= A[low]) low = mid+1;        // case 4
    }
    return -1;
}

int main()
{
    int array[] = {800,900, 2,6,8,23,57,60,700,701};
    int count = FindRotationCount(array, sizeof(array)/sizeof(array[0]));

    std::cout << "Array rotated "<<count<<" times." << std::endl;
    return 0;
}
