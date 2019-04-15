#include <vector>

double solveExpr(const std::vector<ElemContainer>& expr)
{
    Stack<double> dataStack;

    for (int idx = 0; idx < expr.size(); idx++)
    {
        switch (expr[idx].type)
        {
        // DATA
        case ElementType::DATA:
            // Data gets pushed to stack
            dataStack.push(expr[idx].value);
            break;

        // KEYWORD
        case ElementType::KEYWORD:
            // Get keyword code
            int kwCode = expr[idx].kwCode;
            
            // Constants are already pushed as doubles during parsing
            // Hence only operators need to be considered
            
            // Get operator using keyword code
            auto op = keywords[kwCode];
            int operandCount = op.opType;

            // This array will contain the operands required by the operator
            double* values = new double[operandCount];

            // Place values into the array
            while (operandCount--)
            {
                values[operandCount] = dataStack.top();
                dataStack.pop();
            }

            // Operation is performed and result is pushed back into the stack
            double res = op.operate(values);
            dataStack.push(res);

            // Delete the array of operands
            delete[] values;
            break;
        }
    }

    // The last remaining value in the stack will be the result
    return dataStack.top();
}