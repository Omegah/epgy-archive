public class Fgrep extends Sgrep implements Runnable
{
	public Fgrep(String searchString, String searchFilename)
	{
		super(searchString, searchFilename);
	}
	
	public void run()
	{
		System.out.println(super.getFilename());
		System.out.println(super.search());
	}
	
	public static void main(String[] args)
	{
        if (args.length < 2)
        {
            System.out.println("Usage: java Fgrep <string> <filename1> ... <filenameN>");
            return;
        }
        
        for (int i = 1; i < args.length; i++)
        {
            Fgrep task = new Fgrep(args[0], args[i]);
            Thread thd = new Thread(task);
            thd.start();
            
            try
            {
            	thd.join();
            }
            catch (InterruptedException e)
            {
            	System.out.println("Internal error has occurred.");
            }
        }
    }
}
