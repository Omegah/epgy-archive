public class Sum extends BinaryOperation
{
	public Sum(Expression e1, Expression e2)
	{
		super(e1, e2, '+');
	}
	
	protected double myOperation(double d1, double d2)
	{
		return d1 + d2;
	}
}
