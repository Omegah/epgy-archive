namespace WordCountExample
{
    using System;
    using System.Collections;
    using System.IO;

    /// <summary>
    /// The main entry class for the application.
    /// </summary>
    public class WordCountExampleProgram
    {
        /// <summary>
        /// The main entry point of the application - does all the work, really.
        /// </summary>
        public static void Main()
        {
            SortedList table = new SortedList();
            string fileData = string.Empty;

            Console.WriteLine("This program counts how many times each word occurs in a file.");
            Console.Write("Enter the filename of the file to read from:\n > ");
            string filename = Console.ReadLine();
            while (string.IsNullOrEmpty(filename))
            {
                Console.Write("You cannot enter a blank path name - try again:\n > ");
                filename = Console.ReadLine();
            }

            // Try to access the file and bail out if an error occurred
            try
            {
                fileData = File.ReadAllText(filename);
            }
            catch
            {
                Console.WriteLine("File was not accessible. Please make sure it exists and you have appropriate permission to read it.");
                return;
            }

            // Get the file contents, convert to lowercase and remove all non-alpha and non-space characters,
            // then get a raw array (still contains duplicates) of all the words
            string[] rawWordArray = WordCountExampleProgram.GetWordsArray(fileData.ToLower());
            
            // For each for in the array...
            for (int i = 0; i < rawWordArray.Length; i++)
            {
                if (!table.ContainsKey(rawWordArray[i]))
                {
                    // If the table does not already contain the key, add it to the list with a count of 1
                    table.Add(rawWordArray[i], 1);
                }
                else
                {
                    // Otherwise it was already in the table, increment its previous count by one
                    table[rawWordArray[i]] = Convert.ToInt32(table[rawWordArray[i]]) + 1;
                }
            }

            // Make a variable to count total words
            int totalWords = 0;

            // Print out the key and value of each along with some headers
            Console.WriteLine("\nWord" + string.Empty.PadRight(50 - "Word".Length, ' ') + "Count\n" + string.Empty.PadRight(50 + "Count".Length, '-'));
            for (int i = 0; i < table.Count; i++)
            {
                int value = Convert.ToInt32(table.GetByIndex(i));
                totalWords += value;
                Console.WriteLine(String.Format("{0,-50}{1}", table.GetKey(i), value));
            }

            Console.WriteLine("{0,-50}{1}\n", "TOTAL", totalWords);
        }

        /// <summary>
        /// Get an array of words from a string.
        /// </summary>
        /// <param name="data">The string to obtain the list of words from.</param>
        /// <returns>An unsorted array containing the words in the string (may contain duplicates).</returns>
        private static string[] GetWordsArray(string data)
        {
            string alphaOnly = string.Empty;

            for (int i = 0; i < data.Length; i++)
            {
                if ((data[i] >= 'a' && data[i] <= 'z') || data[i] == ' ')
                {
                    alphaOnly += data[i];
                }
            }

            return alphaOnly.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }
    }
}
