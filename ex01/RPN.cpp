#include "RPN.hpp"

void  RPN(std::string expr)
{
    std::stringstream ss(expr);
    std::stack<int> stack;
    std::string tracker;

    while(ss >> tracker)
    {
        if(isnumber(tracker[0])  )
        {
            int num = std::stoi(tracker);
            if( num > 9  )
                throw std::runtime_error("error");
            else
                stack.push(num);
        }
        
        else if(tracker == "+" || tracker == "-" || tracker == "*" || tracker == "/"  )
        {
            if(stack.size() < 2)
                throw std::runtime_error("error");
            else
            {
                int operation = 0;
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                if(tracker  == "+")
                    operation = a + b;
                else if(tracker  == "-")
                    operation = a - b;
                else if(tracker  == "*")
                    operation = a * b;
                else if(tracker  == "/")
                {
                    if(0 == b)
                        throw std::runtime_error("error");
                    operation = a / b; 
                }
                stack.push(operation);
            }
        }
        else 
            throw std::runtime_error("error");   
    }
    if(stack.size() != 1)
        throw std::runtime_error("error");
    std::cout << stack.top() << std::endl;
    return;
}