import java.io.*;

public class Sgrep
{
	private String searchString;
	private String searchFilename;
	
	public String getFilename()
	{
		return searchFilename;
	}
	
	public String search()
	{
		String returnData = "";
		
		if (searchFilename != null)
		{
			try
			{
				FileReader reader = new FileReader(searchFilename);
				LineNumberReader lineReader = new LineNumberReader(reader);
				
				try
				{
					String line = "";
					while ((line = lineReader.readLine()) != null)
					{
						if (line.indexOf(searchString) != -1)
						{
							returnData += "\n\tline " + lineReader.getLineNumber() + ":\t" + line;
						}
					}
				}
				catch (IOException e)
				{
					return returnData + "\n";
				}
				
				return returnData + "\n";
			}
			catch (FileNotFoundException e)
			{
				return "";
			}
		}
		else
		{
			return "";
		}
	}
	
	public Sgrep(String searchString, String searchFilename)
	{
		this.searchString = searchString;
		this.searchFilename = searchFilename;
	}
	
	public static void main(String[] args)
	{
        if (args.length != 2)
        {
            System.out.println("Usage: java Sgrep <string> <filename>");
            return;
        }
        
        Sgrep task = new Sgrep(args[0], args[1]);
        System.out.println(task.getFilename());
        System.out.println(task.search());
    }
}
