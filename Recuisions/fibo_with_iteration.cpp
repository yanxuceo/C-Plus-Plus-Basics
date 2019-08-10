#include <iostream>

int Fib(int n) {
    if(n <= 1)
    {
        return n;
    }

    int F1, F2, F;
    F1 = 0;
    F2 = 1;
    for(int i = 2; i <= n; i++) {
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    return F;
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