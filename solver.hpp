#include <vector>

double solveExpr(const std::vector<ElemContainer>& expr)
{
    Stack<double> dataStack;

    for (int idx = 0; idx < expr.size(); idx++)
    {
        switch (expr[idx].type)
        {
        // Data gets pushed to stack
        case ElementType::DATA:
            dataStack.push(expr[idx].value);
            break;

        // Get values from data stack and operate accourding to operator
        case ElementType::OPERATOR:
            int opCode = expr[idx].opCode;

            int operandCount = opDataList[opCode].type;
            double* values = new double[operandCount];

            // Data stack contains values in reverse order
            // Hence the values added to the array in the correct order
            while (operandCount--)
            {
                values[operandCount] = dataStack.top();
                dataStack.pop();
            }

            double res = opDataList[opCode].operate(values);
            dataStack.push(res);
            delete[] values;
            
            break;
        }
    }

    return dataStack.top();
}