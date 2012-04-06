/* comp285 SimpleFileReader.java
 */
import java.io.*;
/**
 * SimpleFileReader is a small class to wrap around the usual FileReader
 * to shield you from the exception handling which we haven't yet gotten
 * to in class. 
 * <P>It has just three methods of note: one to open a new file for reading,
 * one to read line from an open file, and one to close the file when done.
 * <P>Here is a simple example that shows using the SimpleFileReader to
 * to display the contents of a file on the console:
 * <PRE>
 *    SimpleFileReader reader = SimpleFileReader.openFileForReading("letter.txt");
 *    if (reader == null) {
 *        System.out.println("Couldn't open file!");
 *        return;
 *    }
 *    String line;
 *    while ((line = reader.readLine()) != null)
 *        System.out.println(line);
 *    reader.close();
 * </PRE>
 * <P>You don't need to make any changes.
 *
 *
 * @see           java.io.FileReader
 * @see          java.io.BufferedReader
 * @version      1.1 10/01/99
 * @author       Julie Zelenski
 */
public class SimpleFileReader
{
	private BufferedReader reader;
	
	/**
	 * Opens a new file for reading. The filename can either be a relative
	 * path, which will be relative to the working directory of the program
	 * when started, or an absolute path. If the file exists and can be
	 * opened, a new SimpleFileReader is returned. If the file cannot be
	 * opened (for any reason: wrong name, wrong path, lack of permissions, etc.)
	 * null is returned.
	 */
	public static SimpleFileReader openFileForReading(String filename)
	{
		try
		{
			return new SimpleFileReader(new BufferedReader(new FileReader(filename)));
		}
		catch (IOException e)
		{
			return null;
		}	
	}
	
	
	/**
	 * Reads the next line from the open file. Returns the entire contents
	 * of the line as one string, excluding the newline at the end.
	 * If at EOF and no more lines to read, null is returned. null is also
	 * returned on any I/O error.
	 */
	public String readLine()
	{
		try
		{
			return reader.readLine();
		}
		catch (IOException e)
		{
			return null;
		}
	}

	/**
	 * Closes the file when done reading.  You should close a reader when
	 * you are finished to release the OS resources for use by others.
	 */
	public void close()
	{
		try
		{
			reader.close();
		}
		catch (IOException e)
		{
		}
	}
	
	/**
	 * Constructor is private so that only means to create a new reader
	 * is through the static method which does error checking.
	 */
	private SimpleFileReader(BufferedReader reader) 
	{
		this.reader = reader;
	}
}

