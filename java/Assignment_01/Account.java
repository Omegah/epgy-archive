/**
 * This is a class that calculates compound interest rates.
 * @author Jake Petroules
 * @version 1.0 final
 */
public class Account
{
	private int initialBalance;
	private float interestRate;
	
	/**
	 * Creates an account with given initial balance and interest rate.
	 * @param initialBalance The starting balance.
	 * @param interestRate The interest rate.
	 */
	public Account(int initialBalance, float interestRate)
	{
		this.initialBalance = initialBalance;
		this.interestRate = interestRate;
	}
	
	/**
	 * Gets the account balance after the specified number of years.
	 * @param years The number of years that interest has accrued.
	 * @return The balance after the specified number of years.
	 */
	public double getBalance(int years)
	{
		return (this.initialBalance * Math.pow(1 + (this.interestRate / 100), years));
	}
}
