/** 
 * This class provides a GUI interface to the Account class
 * @author   Ian A Mason.
 * @version  1.0 beta
 */

import java.awt.*;
import java.awt.event.*;
import java.text.DecimalFormat;

class AccountApplication {

  public static void main(String[] args){
      final String answer = "Account balance = $";
      final CenteredFrame f = new CenteredFrame("Compound Interest Tester");
      final DecimalFormat formatter =  new DecimalFormat("#.##");
      f.setLayout(new FlowLayout());
      Label alabel = new Label("Amount in Account (an int):", Label.CENTER);
      alabel.setFont(new Font("SansSerif", Font.PLAIN, 15));
      f.add(alabel);   
      final TextField afield  = new TextField("0",12);
      afield.setFont(new Font("SansSerif", Font.PLAIN, 15));
      f.add(afield);   
      Label rlabel = new Label("Interest Rate for Account (an float):", Label.CENTER);
      rlabel.setFont(new Font("SansSerif", Font.PLAIN, 15));
      f.add(rlabel);   
      final TextField rfield  = new TextField("0.00", 4);
      rfield.setFont(new Font("SansSerif", Font.PLAIN, 15));
      f.add(rfield);   
      Label tlabel = new Label("Length of Deposit (an int):", Label.CENTER);
      tlabel.setFont(new Font("SansSerif", Font.PLAIN, 15));
      f.add(tlabel);   
      final TextField tfield  = new TextField("0", 4);
      tfield.setFont(new Font("SansSerif", Font.PLAIN, 15));
      f.add(tfield);   
      final Button button = new Button("To Compute the Value of the Account -- Press Me!");
      button.setFont(new Font("SansSerif", Font.PLAIN, 20));
      button.setForeground(Color.blue);
      f.add(button);
      final Label answerLabel = new Label(answer + 0 , Label.LEFT);
      answerLabel.setFont(new Font("SansSerif", Font.PLAIN, 25));
      f.add(answerLabel);

      //note the use of an anonymous inner class to do the event
      //handling, this explains why the widgets used in the body 
      //are declared final 

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
		  Account account = new Account(a,r);        
		  answerLabel.setText(answer + formatter.format(account.getBalance(t)));
		  f.validate();
	      }
	  });
      f.validate();
      f.setVisible(true);
  }
}

