/*
 * comp285 Editor class
 */
import java.awt.*;
/** 
 * 
 * @author   Ian A Mason.
 * @see          CenteredFrame
 * @see          java.awt.Frame
 * @version  1.0 beta
 * @date 7/02/01
 */
class Editor extends CenteredFrame
{	
	/**
	 * I get a warning when compiling if I don't add this...
	 */
	static final long serialVersionUID = 1;
	
    /**
     * A static flag, accessed via the class, not an instance!!
     * A boolean flag used to turn on/off error messaging to System.err.
     * This protected constant can be used by the other classes in this
     * application. You can turn it off once you think your program
     * is ready to ship!
     */
    protected static final boolean VERBOSE = false;
    
    /** 
     * Static data, accessed via the class, not an instance!!
     * The labels for the items in the file pulldown menu.
     * This protected constant can be used by the other classes in this
     * application. These are used by the EditorMenuHandler object to 
     * decide which item has been selected.
     */
    protected static final String[] fileLabels = { "Open ...", "Save ...", "Search ...", "Quit ..." };
    
    /** 
     * Static data, accessed via the class, not an instance!!
     * The labels for the items in the edit pulldown menu.
     * This protected constant can be used by the other classes in this
     * application. These are used by the EditorMenuHandler object to 
     * decide which item has been selected.
     */
    protected static final String[] editLabels = { "Cut", "Copy", "Paste" };
    
    /**
     * The TextArea instance textArea is the little workhorse of the editor.
     * <em>Note that it is private, and must remain so!</em> Only the editor object
     * is permitted to talk to this object.
     * @see          java.awt.TextArea
     * @see          java.awt.TextComponent
     */
    private final TextArea textArea = new TextArea("", 40, 80, TextArea.SCROLLBARS_BOTH); 
    
    /**
     * The MenuBar instance menuBar is the toplevel widget at the top of the editor
     * that contains the pull down menus. <em>Note that it is private, and must 
     * remain so! Only the editor object is permitted to talk to this object.</em>
     * @see          java.awt.MenuBar
     */
    private final MenuBar menuBar = new MenuBar();
    
    /**
     * The file menu is the thing that one clicks on to pull down the menu items.
     * @see          java.awt.Menu
     */
    private final Menu fileMenu = new Menu("File");
    
    /**
     * The items in the pull down file menu belong to this array. Its length is determined
     * by the static final array of file item labels.
     * @see          java.awt.MenuItem
     */
    private final MenuItem[] fileItem = new MenuItem[fileLabels.length];
    
    /**
     * The edit menu is the thing that one clicks on to pull down the menu items.
     * @see          java.awt.Menu
     */
    private final  Menu         editMenu = new  Menu("Edit");
    
    /**
     * The items in the pull down edit menu belong to this array. Its length is determined
     * by the static final array of edit item labels.
     * @see          java.awt.MenuItem
     */
    private final  MenuItem[]   editItem = new  MenuItem[editLabels.length];
    
    /**
     * This is the name we use to refer to the  object that handles the editors
     * events. Though we will not actually ever send it any messages, just merely
     * register it with Java as a listener to the appropriate events.
     * 
     * @see          EditorMenuHandler
     */
    private EditorMenuHandler menuHandler;
    
    /**
     * An auxiliary procedure for initializing the pull down menus. It eliminates
     * a small amount of code duplication.
     */
    private void initMenu(MenuItem[] menuItems, String[] menuLabels, Menu menu, EditorMenuHandler menuHandler, MenuBar menuBar)
    {
		for (int i = 0; i < menuItems.length; i++)
		{
		    menuItems[i] = new MenuItem(menuLabels[i]);
		    menu.add(menuItems[i]);
		    menuItems[i].addActionListener(menuHandler);
		}
		
		menuBar.add(menu);
    }
    
    /**
     * The private Editor object constructor is where most of the work gets done.
     * Making the CenteredFrame part using the super construct (i.e by calling the
     * CenteredFrame constructor. It also makes the other 
     * important toplevel object, the menuHandler.
     * It also must make
     * all the awt components that are part of the editor: the text area, the 
     * pull down menus, and register the menuHandler with the widgets that it 
     * needs to listen to (the events that they generate).
     */
    private Editor()
    {
		super("Text Editor");
		menuHandler = new EditorMenuHandler(this);
		textArea.setFont(new Font("SansSerif", Font.PLAIN, 15));
		setMenuBar(menuBar);
		
		// make the pull down file menu
		initMenu(fileItem,fileLabels,fileMenu,menuHandler,menuBar);
		
		// make the pull down edit menu
		initMenu(editItem,editLabels,editMenu,menuHandler,menuBar);
		
		//set the layout manager to be a BorderLayout object
		setLayout(new BorderLayout());
		
		//put the textArea in the center
		add(textArea, BorderLayout.CENTER);
		
		//validate the layout
		validate();
		
		//make the editor visible
		setVisible(true);
    }
    
    /**
     * The main method that creates an Editor instance, and
     * thus starts the whole kit and kaboodle.
     */
    public static void main(String[] args)
    {
		new Editor();
		//the reason this doesn't exit immediately is because
		//this is actually a multithreaded application. The other
		//thread sitting in the background is the <em>event handler thread</em>
    }
    
    /**
     * Sets the text of the editor.
     * @param s The text to set.
     */
    public void setEditorText(String s)
    {
    	textArea.setText(s);
    }
    
    /**
     * Appends the text to the editor.
     * @param s The text to append.
     */
    public void appendEditorText(String s)
    {
    	textArea.setText(textArea.getText() + s);
    }
    
    /**
     * Gets the editor text.
     * @return The editor text.
     */
    public String getEditorText()
    {
    	return textArea.getText();
    }
    
    /**
     * Gets the editor text starting at the specified point.
     * @param start Start of the selection.
     * @return The requested part of the editor text.
     */
    public String getEditorText(int start)
    {
    	return textArea.getText().substring(start);
    }
    
    /**
     * Gets the editor text between the specified points.
     * @param start Start of the selection.
     * @param end End of the selection.
     * @return The requested part of the editor text.
     */
    public String getEditorText(int start, int end)
    {
    	return textArea.getText().substring(start, end);
    }
    
    /**
     * Highlights the area of text from the start point to the start point plus the specified length.
     * @param start The point to begin highlighting at.
     * @param length The amount of characters after the start point to highlight.
     */
    public void setHighlight(int start, int length)
    {
    	textArea.setSelectionStart(start);
    	textArea.setSelectionEnd(start + length);
    }
    
    /**
     * Gets the text currently selected in the editor.
     * @return The text currently selected in the editor.
     */
    public String getSelectedText()
    {
    	return textArea.getSelectedText();
    }
    
    /**
     * Deletes the currently selected text from the editor.
     */
    public void deleteSelectedText()
    {
    	int caretPos = textArea.getCaretPosition();
    	setEditorText(getEditorText(0, textArea.getSelectionStart()) + getEditorText(textArea.getSelectionEnd()));
    	textArea.setCaretPosition(caretPos);
    }
    
    /**
     * Inserts the given text at the caret position.
     * @param text The text to insert.
     */
    public void insertTextAt(String text)
    {
    	textArea.insert(text, textArea.getCaretPosition());
    }
    
    /**
     * Gets the contents of a file.
     * @param filename The filename of the file to read.
     * @return The contents of the file, or a blank string if the file could not be read.
     */
    public String getFileContents(String filename)
    {
    	SimpleFileReader reader = SimpleFileReader.openFileForReading(filename);
    	if (reader == null)
    	{
    		 System.out.println("Couldn't open file!");
    		 return "";
    	}
    	String text = "";
    	String line;
    	while ((line = reader.readLine()) != null)
    	{
    		text += line + "\n";
    	}
    	reader.close();
    	
    	return text;
    }
    
    /**
     * Saves the specified text to the specified file.
     * @param filename The filename of the file to write to.
     * @param text The text to write.
     */
    public void saveTextFile(String filename, String text)
    {
    	SimpleFileWriter writer = SimpleFileWriter.openFileForWriting(filename);
	    if (writer == null)
	    {
	    	System.out.println("Couldn't open file!");
	    	return;
	    }
    	writer.print(getEditorText());
    	writer.close();
    }
}





