// Example.cs

using System;
using System.IO;
using System.Text;

/// Example opens the source files, calls the AStyleInterface methods
/// to format the files, and saves the reformatted source. The files
/// are in a test-s directory. The option mode=cs must be included
/// for C# files.
public class Example
{   /// Main function for Example
    public static void Main(string[] args)
    {   // files to pass to AStyle
        String[] fileName =  { "../test-s/FileUtility.cs",
                               "../test-s/MainClass.cs" ,
                               "../test-s/StringParser.cs" ,
                             };

        // options to pass to AStyle
        // mode=cs is required for C# files
        String options = "brackets=linux mode=cs";

        // create an object
        AStyleInterface AStyle = new AStyleInterface();

        // get Artistic Style version
        // does not need to terminate on an error
        String version = AStyle.GetVersion();
        if (version != String.Empty)
            Console.WriteLine ("\nAStyle Version " + version);

        // process the files
        for (int i = 0; i < fileName.Length; i++)
        {   // get the text to format
            String textIn = GetText(fileName[i]);

            // call the Artistic Style formatting function
            // does not need to terminate on an error
            String textOut = AStyle.FormatSource(textIn, options);
            if (textOut == String.Empty)
            {   Console.WriteLine("cannot format "  + fileName[i]);
                continue;
            }

            // return the formatted text
            Console.WriteLine("formatted " + fileName[i]);
            SetText(textOut, fileName[i]);
        }

        return;
    }

    ///  Error message function for this example.
    private static void Error(String why, String what)
    {   Console.WriteLine(why + ' ' + what);
        Console.WriteLine("The program has terminated!");
        Environment.Exit(1);
    }

    ///  Get the text to be formatted.
    ///  Usually the text would be obtained from an edit control.
    private static String GetText(string fileName)
    {   // create input buffers
        int readSize = 1024;
        StringBuilder bufferIn = new StringBuilder(readSize);
        char[] fileIn = new char[readSize];

        // read file data
        try
        {   FileStream file = new FileStream(fileName, FileMode.Open);
            StreamReader streamIn = new StreamReader(file);
            // use ReadBlock to preserve the current line endings
            int charsIn = streamIn.ReadBlock(fileIn, 0, readSize);
            while (charsIn != 0)
            {   bufferIn.Append(fileIn, 0, charsIn);
                charsIn = streamIn.ReadBlock(fileIn, 0, readSize);
            }
            streamIn.Close();
        }
        catch (DirectoryNotFoundException e)
        {   Console.WriteLine(e.ToString());
            Error("Cannot find directory", fileName);
        }
        catch (FileNotFoundException e)
        {   Console.WriteLine(e.ToString());
            Error("Cannot find file", fileName);
        }
        catch (Exception e)
        {   Console.WriteLine(e.ToString());
            Error("Error reading file", fileName);
        }

        return bufferIn.ToString();
    }

    ///  Return the formatted text.
    ///  Usually the text would be returned to an edit control.
    private static void SetText(String textOut, String fileName)
    {   // create a backup file
        String origFileName = fileName +  ".orig";
        File.Delete(origFileName);                  // remove a pre-existing file
        FileInfo outFile = new FileInfo(fileName);
        outFile.MoveTo(origFileName);

        // write the output file - same name as input
        try
        {   char[] bufferOut = textOut.ToCharArray();
            FileStream file = new FileStream(fileName, FileMode.Create);
            StreamWriter streamOut = new StreamWriter(file);
            streamOut.Write(bufferOut, 0, bufferOut.Length);
            streamOut.Close();
        }
        catch (Exception e)
        {   Console.WriteLine(e.ToString());
            Error("Error writing file", fileName);
        }

        return;
    }

}   // class Example
