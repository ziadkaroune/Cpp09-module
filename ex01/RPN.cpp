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
            {
                std::cerr << "ERROR" << std::endl;
                return ;
             } 
            else
                stack.push(num);
        }
        
        else if(tracker == "+" || tracker == "-" || tracker == "*" || tracker == "/"  )
        {
            if(stack.size() < 2)
            {
                std::cerr << "ERROR" << std::endl;
                return ;
            }
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
                    {
                        std::cerr << "ERROR" << std::endl;
                        return ;
                    }
                    operation = a / b; 
                }
                     
                stack.push(operation);
            }
        }
        else 
        {
            std::cerr << "ERROR" << std::endl;
             return ;
        }    
    }
    if(stack.size() != 1)
    {
        std::cerr << "ERROR" << std::endl;
        return  ;
    }
    
    std::cout << stack.top() << std::endl;
    return;

}