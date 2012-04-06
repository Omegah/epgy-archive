/**
 * This is the main class for a program that calculates compound interest rates.
 * @author Jake Petroules
 * @version 1.0 final
 */
public class Compound
{
	/**
	 * @param args The command-line arguments passed to this program.
	 * @see #DisplayUsage()
	 */
	public static void main(String[] args)
	{
		// Make sure the input is valid, and if it's not, display usage and exit
		if (!IsInputValid(args))
		{
			DisplayUsage();
			System.exit(0);
		}
		
		Account account = new Account(Integer.valueOf(args[0]), Float.valueOf(args[1]));
		
		System.out.println(String.format("Total = $%1$s", (int)account.getBalance(Integer.valueOf(args[2]))));
	}
	
	/**
	 * Checks the input of this program to see if it is valid.
	 * @param args The string arguments passed to the program at execution time.
	 * @return Whether the input was valid.
	 */
	private static boolean IsInputValid(String[] args)
	{
		// Make sure the correct number of arguments was passed
		if (args.length != 3)
		{
			return false;
		}
		
		// Check all three arguments and see if they're of the correct data type
		try
		{
			Integer.valueOf(args[0]);
		}
		catch (NumberFormatException nfe)
		{
			return false;
		}
		
		try
		{
			Float.valueOf(args[1]);
		}
		catch (NumberFormatException nfe)
		{
			return false;
		}
		
		try
		{
			Integer.valueOf(args[2]);
		}
		catch (NumberFormatException nfe)
		{
			return false;
		}
		
		// Nothing wrong was detected, so we're okay!
		return true;
	}
	
	/**
	 * Displays the way this program should be used.
	 */
	public static void DisplayUsage()
	{
		System.out.println("usage: java Compound initialAmount interestRate yearsAccrued\n");
		System.out.println("(integer) initialAmount is the initial dollar amount");
		System.out.println("(decimal) interestRate is the interest rate percentage");
		System.out.println("(integer) yearsAccrued is the time in years the interest has accrued\n");
	}
}
