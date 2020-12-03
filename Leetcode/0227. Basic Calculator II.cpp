/* Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero. */

class Solution {
public:

    int get_priority(char op)
    {
        if(op == '+' || op == '-')
            return 0;
        else // * /
            return 1;
    }

    bool has_less_or_equal_priority(char op1, char op2)
    {
        return get_priority(op1) <= get_priority(op2);
    }

    int calc(int a, int b, char op)
    {
        if(op == '+')
            return a + b;
        if(op == '-')
            return a - b;
        if(op == '*')
            return a * b;
        return a / b;
    }

    void do_one_calculation(stack<int> &operands, stack<int> &operators)
    {
        int b 	= operands.top(); 	operands.pop();
        int a 	= operands.top(); 	operands.pop();
        char op = operators.top(); 	operators.pop();
        operands.push(calc(a, b, op));
    }

    int calculate(string exp)
    {
        stack<int> operands, operators;
        for(int i = 0; i < exp.length(); i++)
        {
            if(exp[i] == ' ')
                continue;
            else if(isdigit(exp[i])) // is operand
            {
                int num = 0;
                while(i < exp.length() && isdigit(exp[i]))
                    num = num * 10 - '0' + exp[i++];

                if(i < exp.length())
                    i--;
                operands.push(num);
            }
            else // is operator
            { 
                while(!operators.empty() && has_less_or_equal_priority(exp[i], operators.top()))
                    do_one_calculation(operands, operators);
                operators.push(exp[i]);
            }
        }

        while(!operators.empty())
            do_one_calculation(operands, operators);

        return operands.top();
    }

};