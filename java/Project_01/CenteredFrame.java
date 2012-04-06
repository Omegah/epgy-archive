/* comp285 CenteredFrame.java
 */
import java.awt.*;

/**
 * CenteredFrame is a simple subclass of Frame that uses the
 * Toolkit to center the frame in the middle of the screen, 
 * and sizes it to be half the height and width of the screen.
 * @see          java.awt.Toolkit
 * @see          java.awt.Frame
 * @version      1.0 beta 
 * @author       Ian A Mason
 */
public class CenteredFrame extends Frame
{	
	/**
	 * I get a warning when compiling if I don't add this...
	 */
	static final long serialVersionUID = 1;
	
    /**
     * The CenteredFrame contructor, contructs an initially 
     * invisible frame, it uses the Toolkit to center the 
     * frame in the middle of the screen, and size
     * it to be half the height and width of the screen.
     */
     public CenteredFrame(String title)
     {
		 super(title);
		 Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
		 int screenH = d.height;
		 int screenW = d.width;
		 setSize(screenW / 2, screenH / 2);
		 setLocation(screenW / 4, screenH / 4);
     }

    /**
     * For testing, constructs a CenteredFrame object 
     * and then makes it visible.
     */
     public static void main(String[] args)
     {
    	 CenteredFrame f = new CenteredFrame("Centered Frame");
    	 f.setVisible(true);
     }
 }
