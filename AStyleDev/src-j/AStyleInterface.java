// AStyleInterface.java

/**
* AStyleInterface contains methods to call the Artistic Style formatter.
* Changing the class name requires changing Artistic Style.
*/

class AStyleInterface
{   /**
    *  Call the AStyleMain function in Artistic Style.
    *  @param   textIn   A string containing the source code to be formatted.
    *  @param   options  A string of options to Artistic Style.
    *  @return  A String containing the formatted source from Artistic Style,
    *           or an empty string on error.
    */
    public String formatSource(String textIn, String options)
    {   // Return the allocated string
        // Memory space is allocated by OnAStyleMemAlloc, a callback function from AStyle
        String textOut = new String("");
        try
        {   textOut = AStyleMain(textIn, options);
        }
        catch (UnsatisfiedLinkError e)
        {   //~ System.out.println(e.getMessage());
            System.out.println("Cannot call function AStyleMain");
        }
        return textOut;
    }

    /**
    *  Call the AStyleGetVersion function in Artistic Style.
    *  @return  A String containing the formatted source from Artistic Style,
    *           or an empty string on error.
    */
    public String getVersion()
    {   String version = new String();
        try
        {   version = AStyleGetVersion();
        }
        catch (UnsatisfiedLinkError e)
        {   //~ System.out.println(e.getMessage());
            System.out.println("Cannot call function GetVersion");
        }
        return version;
    }

    // functions to call Artistic Style ---------------------------------------------------

    /**
    * Static constructor to load the native Artistic Style library.
    * Does not need to terminate if the shared library fails to load.
    * But the exception must be handled when a function is called.
    */
    static
    {   // load shared library from the classpath
        String astylePath = System.getProperty("user.dir")
                            + System.getProperty("file.separator")
                            + System.mapLibraryName("astylej");
        try
        {   System.load(astylePath);
        }
        catch (UnsatisfiedLinkError e)
        {   System.out.println(e.getMessage());
            System.out.println("Cannot load native library " + astylePath);
            System.out.println("The program has terminated!");
            System.exit(1);
        }
    }

    /**
    *  Calls the AStyleMain function in Artistic Style.
    *
    *  @param   textIn   A string containing the source code to be formatted.
    *  @param   options  A string of options to Artistic Style.
    *  @return  A String containing the formatted source from Artistic Style.
    */
    public native String AStyleMain(String textIn, String options);

    /**
    * Calls the AStyleGetVersion function in Artistic Style.
    *
    * @return    A String containing the version number of Artistic Style.
    */
    public native String AStyleGetVersion();

    /**
    * Error handler for messages from Artistic Style.
    * This method is called only if there are errors when AStyleMain is called.
    * This is for debugging and there should be no errors when the calling
    * parameters are correct.
    * Changing the method name requires changing Artistic Style.
    * Signature: (ILjava/lang/String;)V
    *
    *  @param  errorNumber   The error number from Artistic Style.
    *  @param  errorMessage  The error message from Artistic Style.
    */
    private void ErrorHandler(int errorNumber, String errorMessage)
    {   System.out.println("AStyle error "
                           + String.valueOf(errorNumber)
                           + " - " + errorMessage);
    }

}   // class AStyleInterface
