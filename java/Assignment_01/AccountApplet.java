/** 
 * This class version is an Applet GUI interface to the Account class
 * @author   Ian A Mason.
 * @version  1.0 beta
 */

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.text.DecimalFormat;

public class AccountApplet extends Applet {
      final String answer = "Account balance = $";
      final DecimalFormat formatter =  new DecimalFormat("#.##");
      final TextField afield  = new TextField("0",12);
      final TextField rfield  = new TextField("0.00", 4);
      final TextField tfield  = new TextField("0", 4);
      final Button button = new Button("To Compute the Value of the Account -- Press Me!");

    public void paint(){
	validate();
	repaint();
    }

    
    public void init(){
	setLayout(new FlowLayout());
	Label alabel = new Label("Amount in Account (an int):", Label.CENTER);
	alabel.setFont(new Font("SansSerif", Font.PLAIN, 15));
	add(alabel);   
	afield.setFont(new Font("SansSerif", Font.PLAIN, 15));
	add(afield);   
	Label rlabel = new Label("Interest Rate for Account (an float):", Label.CENTER);
	rlabel.setFont(new Font("SansSerif", Font.PLAIN, 15));
	add(rlabel);   
	rfield.setFont(new Font("SansSerif", Font.PLAIN, 15));
	add(rfield);   
	Label tlabel = new Label("Length of Deposit (an int):", Label.CENTER);
	tlabel.setFont(new Font("SansSerif", Font.PLAIN, 15));
	add(tlabel);   
	tfield.setFont(new Font("SansSerif", Font.PLAIN, 15));
	add(tfield);   
	button.setFont(new Font("SansSerif", Font.PLAIN, 20));
	button.setForeground(Color.blue);
	add(button);
	final Label answerLabel = new Label(answer + 0 , Label.LEFT);
	answerLabel.setFont(new Font("SansSerif", Font.PLAIN, 25));
	add(answerLabel);
	
	button.addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent ae){
		    int   a = 0; 
		    int   t = 0;
		    float r = 0F;
		    try{
			a = Integer.parseInt(afield.getText());
			r = Float.parseFloat(rfield.getText());
			t = Integer.parseInt(tfield.getText());
		    }catch(NumberFormatException e){ }
		    Account acc = new Account(a,r);        
		    answerLabel.setText(answer + formatter.format(acc.getBalance(t)));
		    validate();
		}
	    });
	validate();
	setVisible(true);
    }
}
