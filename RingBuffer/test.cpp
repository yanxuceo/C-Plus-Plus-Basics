#include <iostream>
#include "ringbuffer.h"


int main()
{
    RingBuffer<char, 5U> charBuffer;
    charBuffer.PushBack('a');
    charBuffer.PushBack('b');

    bool result = false;

    std::cout << charBuffer.Front(result) << std::endl;
    std::cout << result << std::endl;

    std::cout << charBuffer.Back(result) << std::endl;

    return 0;
}
