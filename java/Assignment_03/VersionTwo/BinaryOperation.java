public abstract class BinaryOperation extends Expression
{
    private Expression lhs;
    private Expression rhs;
    private char binaryOperation;

    public String toString()
    {
        return "(" + lhs.toString() + " " + binaryOperation + " " + rhs.toString() + ")";
    };

    public double evaluateMe()
    {
        return myOperation(lhs.evaluateMe(), rhs.evaluateMe());
    };
    
    protected abstract double myOperation(double d1, double d2);

    BinaryOperation(Expression e1, Expression e2, char op)
    {
        lhs = e1;
        rhs = e2;
        binaryOperation = op;
    }
}
