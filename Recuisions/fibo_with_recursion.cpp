#include <iostream>

int Fib(int n) {
    if(n <= 1)
    {
        return n;
    }
    return Fib(n-1) + Fib(n-2);
}

int main()
{
    int n;
    std::cout << "Type an number n: ";
    std::cin >> n;

    int result = Fib(n);
    std::cout << result << std::endl;

    return 0;
}