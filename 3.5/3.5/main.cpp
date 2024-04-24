#include <iostream>
#include <stack>

void sortStack(std::stack<int>& stack) {
    std::stack<int> tempStack;

    while (!stack.empty())
    {
        int temp = stack.top();
        stack.pop();

        while (!tempStack.empty() && tempStack.top() < temp)
        {
            stack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    stack = tempStack;
}


int main()
{
    std::stack<int> s;
    s.push(6);
    s.push(7);
    s.push(2);
    s.push(4);
    s.push(5);
    sortStack(s);
    for (int i = 0; i < 5; ++i) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}