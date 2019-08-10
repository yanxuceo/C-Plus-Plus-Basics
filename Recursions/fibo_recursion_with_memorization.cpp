#include <iostream>

const int STORAGE = 100;
long int F[STORAGE];

long int Fib(long int n) {
    if(n <= 1)
    {
        return n;
    }

    if(F[n] != -1)
    {
        return F[n];
    }

    F[n] = Fib(n-1) + Fib(n-2);
    return F[n];
}

int main()
{
    for(int i = 0; i < STORAGE; i++)
    {
        F[i] = -1;
    }

    int n;
    std::cout << "Type an number n: ";
    std::cin >> n;

    long int result = Fib(n);
    std::cout << result << std::endl;

    return 0;
}