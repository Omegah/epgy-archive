import java.text.*;

public class Number extends Expression
{
	private double d;
	
	public Number(double d)
	{
		this.d = d;
	}
	
	public double evaluateMe()
	{
		return d;
	}
	
	public String toString()
	{
		DecimalFormat format = new DecimalFormat("0.##");
		return format.format(d);
	}
}
