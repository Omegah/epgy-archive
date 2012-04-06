/* 
 * comp285  SearchDialog Widget
 */
import java.awt.*;
import java.awt.event.*;
/** 
 * This here widget is used by the EditMenuHandler, come back now, ya hear!
 * @author   Ian A Mason.
 * @version  1.0 beta
 * @date 8/03/01
 * @see  java.awt.Dialog
 */
public class SearchDialog extends Dialog
{
	/**
	 * I get a warning when compiling if I don't add this...
	 */
	static final long serialVersionUID = 1;
	
    /** 
     * 
     * @see  java.awt.TextField
     */
    private final TextField target  = new TextField(12);
    
    /** 
     * 
     * @see  java.awt.Button
     */
    private Button button = new Button("Search File");
    
    /** 
     * Gets the text the user typed into the search box.
     */
    protected String getText()
    {
    	return target.getText();
    }
    
    /** 
     * Creates an new search dialog.
     */
    protected SearchDialog(Editor editor)
    {
		super(editor, "Search Dialog", true); 
		setLayout(new FlowLayout());
		
		button.setFont(new Font("SansSerif", Font.PLAIN, 20));
		button.setForeground(Color.red);
		add(button);
		
		Label label = new Label("String: ", Label.CENTER);
		label.setFont(new Font("SansSerif", Font.PLAIN, 20));
		add(label);
		
		target.setFont(new Font("SansSerif", Font.PLAIN, 15));
		add(target);
		
		Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
		int screenH = d.height;
		int screenW = d.width;
		setSize(screenW / 3, screenH / 8);
		setLocation(screenW / 2, screenH / 2);
		pack();
		
		button.addActionListener
		(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent ae)
				{
				    if (Editor.VERBOSE)
				    {
				    	System.out.println("Shutting down dialog (terminatining call to dialog.show();");
				    }
				    
				    // disposes the Dialog and then causes its show() to return if it is currently blocked.
				    SearchDialog.this.dispose();
				    
				    if (Editor.VERBOSE)
				    {
				    	System.out.println("String to be searched for = " + target.getText());
				    }
				}
			}
		);
    }
}


