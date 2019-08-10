## Recursion Notebooks
I am following this [guy on YouTube](https://www.youtube.com/channel/UClEEsT7DkdVO_fkrBw0OTrA) to review and solid my knowledge on Data Structure and algorithms. His demonstration on each topic is nice, beautiful and excellent!   

### Iterative method for Fibonacci
_Pseudo code_

```
Fib(n)
{
    if(n <= 1)
        return n
    F1 <-- 0
    F2 <-- 1
    for i <-- i to n
        F <-- F1 + F2
        F1 <-- F2
        F2 <-- F
    
    return F
}
```


### Plain recursion
_C++ code for Fibonacci Sequence_
```
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
```

### Recursion with memorization

_Fibonacci Sequence pseudo code_

```
Fib(n)
{
    if n <= 1
        return n
    if Fn is in memory 
        return Fn
    else
        Fn = Fib(n-1) + Fib(n-2)
        Save Fn in memory
        return Fn
}
```

By this way, we are avoiding all the re-calculation of the same state again and again. Here is an [Implementaion Example](fibo_recursion_with_memorization.cpp). Note in this particular example, the recursion with memorization is not as efficient as an iterative implementation in terms of memory but it is as good as an iterative implementation in terms of time for larger values of n. And it is a lot better than simple recursion which grows exponentially with the input.


### Recursion space complexity analysis
We need to understand how recursive program executes in the memory to understand and analyze the memory consumption. A recursive call is not different from a function A calling another function B except for the fact that A and B are same. But in terms of execution, separate memory and resources are allocated to the new function call.  

_Executing Demo_
<p align = "center">
  <img src="media/space_complexity_fibo.png"  width="620" height="380">
</p>

As this figure illustrated, even though explicitly we have not declared any variable or used any memory in the Fib(n), behind the scene all the states of these methods are being saved in the memory or these function calls are stacked in the memory and spaces are getting consumed. we often say that an implicit stack is growing in the memory.


<p align = "center">
  <img src="media/recursion_tree.png"  width="580" height="360">
</p>

As can be seen in the above recursion tree, the maximum growth of this call stack due to this particular recursion was when we were at the bottom-most node. When Fib(1) was executing, then all these states of Fib(5), Fib(4), Fib(3) and Fib(2) were saved in the memory and we were consuming kind of 5 units of space in the memory and the call stack stack did not grow any futher than this. So, this is the maximum space consumed. The maximum space consumed by a recursive program is proportional to the maximum depth of this recursion tree. And the maximum depth of recursion tree is defined as the length of the longest path in the tree. Say, Level 0 -> level 1 -> level 2 -> level 3 and level 4. The maximum depth in this case is the path from Level 0 to Level 4, which consumed 5 units of space. 

For Fib(n), the maximum depth of the recursion tree would be n-1 units and the maximum space consumed would be n units. So **O(n)** as the space complexity due to the max depth of the recursive tree.






