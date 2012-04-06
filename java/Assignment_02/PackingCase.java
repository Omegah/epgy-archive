/*
 * comp285 PackingCase template
 */
import java.util.Date;
import java.util.Vector;
/**
 *
 *
 * This is the starting template for a class called
 * <TT>PackingCase</TT>. They are used to store single objects. Each 
 * <TT>PackingCase</TT> has a unique integer serial number, and a 
 * <TT>PackingCase</TT> can be reused. They, do however, keep track
 * of how many times they have been used. They are also are time stamped
 * (via a <TT>java.util.Date</TT> object) when they are created, 
 * and also know when the current contents was stored,
 * (via another <TT>java.util.Date</TT> object). 
 * You can also ask for the name (a string) of the class of the object
 * currently stored in the packing case (see the hints section). 
 * The <TT>PackingCase</TT> has a default constructor, a constructor that takes
 * an object, and a constructor for each primitive type. But remember
 * like <TT>java.util.Vector</TT>, a <TT>PackingCase</TT> only stores objects,
 * not primitive types. So you will have to make use of the wrapper
 * classes. To make things easier I have given you a template to begin with.
 * Note that the <TT>main</TT> of the class really puts it through its paces
 * (like all good test <TT>main</TT>s do). Here is the body of  <TT>main</TT>:
 * <PRE>
 *     public static void main(String[] args){
 *
 *      //create a default packing case and print it out
 *      PackingCase empty = new  PackingCase();
 *      System.out.println(empty);
 *        
 *      //print out ten new packing cases, each containing an Integer
 *      for(int i = 0; i < 10; i++) System.out.println(new PackingCase(i));
 *
 *      //make a packing case containing a Double, and then just for fun
 *      //reset the contents with it ten thousand times
 *      PackingCase b = new PackingCase(3.1598989889999999);
 *      for(int i = 0; i < 100000; i++)b.setContents(b.getContents());
 *      System.out.println(b);
 *      //so now lets make a vector
 *      Vector v = new Vector();
 *      //packing cases are objects, so they can be stored
 *      //in a vector
 *      v.add(b);
 *      //add a packing case with a Boolean in it
 *      v.add(new PackingCase(true));
 *      //add a packing case with a  Byte in it
 *      v.add(new PackingCase((byte)2));
 *      //add a packing case with a  Short in it
 *      v.add(new PackingCase((short)3));
 *      //add a packing case with a  Character
 *      v.add(new PackingCase((char)5));
 *      //add a packing case with a Integer in it
 *      v.add(new PackingCase((int)7));
 *      //add a packing case with a Double
 *      v.add(new PackingCase((double)11));
 *      //add a packing case with a Float
 *      v.add(new PackingCase((float)13));
 *      //add a packing case with another Double
 *      v.add(new PackingCase((double)17));
 *      //add a packing case with a String
 *      v.add(new PackingCase("Danger String"));
 *      //hey even arrays are objects, so lets make one and
 *      //shove it in a packing case
 *      int[] golly = new int[23];
 *      v.add(new PackingCase(golly));
 *      // note the funny name for arrays of ints: [I
 *      // in the output.
 *      // ok lets go crazy, packing cases are object, so they
 *      // can be stored in packing cases, lets use the vector
 *      // we just made to add a bunch of packing cases, that each store
 *      // a packing case alread in the vector. lets go completely overbaord!
 *      // not only that these
 *      // new packing cases are objects too so they can be stored in
 *      // the vector as well!!!
 *      int s = v.size();
 *      for(int k = 0; k < s; k++) v.add(new PackingCase(v.elementAt(k)));
 *      // our vector now contains lots of packing cases, some of which store
 *      // packing cases!! lets see which ones by asking the packing cases
 *      // to print the name of the class of the object they store!
 *      for(int j = 0; j < v.size(); j++)
 *          System.out.println(((PackingCase)v.elementAt(j)).getClassOfContents());
 *      // finally for each packing case in the vector, lets look inside
 *      // those that contain other packing cases!
 *      for(int j = 0; j < v.size(); j++){
 *          Object o = ((PackingCase)v.elementAt(j)).getContents();
 *              if( o instanceof PackingCase ){
 *                  PackingCase c = (PackingCase)o;
 *                  System.out.println(c.getClassOfContents());
 *                  System.out.println("\t" + c.getSerialNo());
 *                  System.out.println("\t" + c.getContents());
 *                  System.out.println("\t" + c.getCreatedOnDate());
 *                  System.out.println("\t" + c.getPackagedOnDate());
 *                  System.out.println("\t" + c.getStorageCounter());
 *              }
 *              
 *      }
 *  }
 * </PRE>
 * I have included the output
 * from my final version as well to give you some idea of what is required:
 * <PRE>
 *PackingCase No 1
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       java.lang.Object@209f4e
 * of java.lang.Object
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 2
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       0
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 3
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       1
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 4
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents:       
 * 2
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 5
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       3
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 6
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       4
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 7
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       5
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 8
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       6
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 9
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       7
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 10
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       8
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 11
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       9
 * of java.lang.Integer
 * packaged on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * and has been used: 
 *      1 times
 *PackingCase No 12
 * created on: 
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 * with contents: 
 *       3.1598989889999998
 * of java.lang.Double
 * packaged on: 
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 * and has been used: 
 *      100001 times
 *java.lang.Double
 *java.lang.Boolean
 *java.lang.Byte
 *java.lang.Short
 *java.lang.Character
 *java.lang.Integer
 *java.lang.Double
 *java.lang.Float
 *java.lang.Double
 *java.lang.String
 *[I
 *PackingCase
 *PackingCase
 *PackingCase
 *PackingCase
 *PackingCase
 *PackingCase
 *PackingCase
 *PackingCase
 *PackingCase
 *PackingCase
 *PackingCase
 *java.lang.Double
 *      12
 *      3.1598989889999998
 *      Tue Mar 13 10:02:16 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      100001
 *java.lang.Boolean
 *      13
 *      true
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *java.lang.Byte
 *      14
 *      2
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *java.lang.Short
 *      15
 *      3
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *java.lang.Character
 *      16
 *        ^E
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *java.lang.Integer
 *      17
 *      7
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *java.lang.Double
 *      18
 *      11.0
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *java.lang.Float
 *      19
 *      13.0
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *java.lang.Double
 *      20
 *      17.0
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *java.lang.String
 *      21
 *      Danger String
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *[I
 *      22
 *      [I@55af5
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      Tue Mar 13 10:02:17 GMT+10:00 2001
 *      1
 *
 * </PRE>
 * Think carefully about where and how things are done.
 * Since the assignment is so simple, style will play an important part
 * is the assessment.
 * @see >java.util.Date<code/>
 * @see <code>java.lang.Object<code/>
 * @see <code>java.lang.Double<code/>
 * @see <code>java.lang.Boolean<code/>
 * @see <code>java.lang.Byte<code/>
 * @see <code>java.lang.Short<code/>
 * @see <code>java.lang.Character<code/>
 * @see <code>java.lang.Integer<code/>
 * @see <code>java.lang.Double<code/>
 * @see <code>java.lang.Float<code/>
 * @see <code>java.lang.Double<code/>
 * @see <code>java.lang.String<code/>
 * @see <code>java.util.Vector<code/>
 */
public class PackingCase
{
	// private fields go here
	private static int serialCount = 0;
	
	private Object contents = null;
	private Date packageCreateDate = null;
	private Date packagePackagedDate = null;
	private int usageCount = 0;
	
	private int serialNumber;

    // we provide a constructor for every type of data
    // possible in Java, this should not be taken as 
    // invitation for code duplication. a good program
    // will not have unnecessary code duplication.
    /**
     * The default constructor constructs the default 
     * <TT>PackingCase</TT>. The default <TT>PackingCase</TT>
     * is not an empty <TT>PackingCase</TT>, but rather it is one
     * that contains a default object, perhaps created by a 
     * call to the default constructor of objects.
     * @see java.lang.Object
     */
    public PackingCase()
    { 
    	setContents(new Object());
    }
    /** This constructor takes a <TT>Object o</TT> as its argument and
     * constructs a packing case object with that <TT>o</TT> as 
     * its argument.
     * @see java.lang.Object
     */
    public PackingCase(Object o)
    {
    	setContents(o);
    }
    /** This constructor takes a <TT>boolean b</TT> as its argument and
     * constructs a packing case object with an object that represents 
     * the <TT>boolean b</TT> argument. Since the argument is primitive data,
     * and not an object, you will have to use the wrapper class for this
     * datatype. This is one of the two main reasons for the wrapper class.
     * The other main reason is its use as a library of static methods for 
     * doing useful things with this and related data.
     * @see java.lang.Boolean
     */
    public PackingCase(boolean b)
    {
    	setContents(b);
    }
    /** This constructor takes a <TT>byte by</TT> as its argument and
     * constructs a packing case object with an object that represents 
     * the <TT>byte by</TT> argument. Since the argument is primitive data,
     * and not an object, you will have to use the wrapper class for this
     * data type. This is one of the two main reasons for the wrapper class.
     * The other main reason is its use as a library of static methods for 
     * doing useful things with this and related data.
     * @see java.lang.Byte
     */
    public PackingCase(byte by)
    {
    	setContents(by);
    }
    /** This constructor takes a <TT>short s</TT> as its argument and
     * constructs a packing case object with an object that represents 
     * the <TT>short s</TT> argument. Since the argument is primitive data,
     * and not an object, you will have to use the wrapper class for this
     * data type. This is one of the two main reasons for the wrapper class.
     * The other main reason is its use as a library of static methods for 
     * doing useful things with this and related data.
     * @see java.lang.Short
     */
    public PackingCase(short s)
    {
    	setContents(s);
    }

    /** This constructor takes a <TT>char c</TT> as its argument and
     * constructs a packing case object with an object that represents 
     * the <TT>char c</TT> argument. Since the argument is primitive data,
     * and not an object, you will have to use the wrapper class for this
     * data type. This is one of the two main reasons for the wrapper class.
     * The other main reason is its use as a library of static methods for 
     * doing useful things with this and related data.
     * @see java.lang.Character
     */
    public PackingCase(char c)
    {
    	setContents(c);
    }
    /** This constructor takes a <TT>int i</TT> as its argument and
     * constructs a packing case object with an object that represents 
     * the <TT>int i</TT> argument. Since the argument is primitive data,
     * and not an object, you will have to use the wrapper class for this
     * data type. This is one of the two main reasons for the wrapper class.
     * The other main reason is its use as a library of static methods for 
     * doing useful things with this and related data.
     * @see java.lang.Integer
     */
    public PackingCase(int i)
    {
    	setContents(i);
    }
    /** This constructor takes a <TT>long l</TT> as its argument and
     * constructs a packing case object with an object that represents 
     * the <TT>long l</TT> argument. Since the argument is primitive data,
     * and not an object, you will have to use the wrapper class for this
     * data type. This is one of the two main reasons for the wrapper class.
     * The other main reason is its use as a library of static methods for 
     * doing useful things with this and related data.
     * @see java.lang.Long
     */
    public PackingCase(long l)
    {
    	setContents(l);
    }
    /** This constructor takes a <TT>float f</TT> as its argument and
     * constructs a packing case object with an object that represents 
     * the <TT>float f</TT> argument. Since the argument is primitive data,
     * and not an object, you will have to use the wrapper class for this
     * data type. This is one of the two main reasons for the wrapper class.
     * The other main reason is its use as a library of static methods for 
     * doing useful things with this and related data.
     * @see java.lang.Float
     */
    public PackingCase(float f)
    {
    	setContents(f);
    }
    /** This constructor takes a <TT>double b</TT> as its argument and
     * constructs a packing case object with an object that represents 
     * the <TT>double b</TT> argument. Since the argument is primitive data,
     * and not an object, you will have to use the wrapper class for this
     * data type. This is one of the two main reasons for the wrapper class.
     * The other main reason is its use as a library of static methods for 
     * doing useful things with this and related data.
     * @see java.lang.Double
     */
    public PackingCase(double d)
    {
    	setContents(d);
    }
    /**
     * The <TT>public String toString()</TT> method describes how the 
     * system should print packing case objects. </EM>All objects in Java
     * are printable.</EM> This is because all objects eventually inherit from
     * the <TT>java.lang.Object</TT> class.
     * I have provided the
     * code for this method, so you should not have to futz with it:
     * <PRE>
     *     public String toString(){
     *         return "PackingCase No " + 
     *             getSerialNo() + 
     *             "\n created on: \n\t" +
     *             getCreatedOnDate() +
     *             "\n with contents: \n\t " + 
     *             getContents() + 
     *             "\n of "  + 
     *             getClassOfContents() +
     *             "\n packaged on: \n\t" +
     *             getPackagedOnDate() +
     *             "\n and has been used: \n\t" + 
     *             getStorageCounter() + " times";    }
     * </PRE>
     * @see java.lang.Object
     */
    public String toString()
    {
        return "PackingCase No " + 
            getSerialNo() + 
            "\n created on: \n\t" +
            getCreatedOnDate() +
            "\n with contents: \n\t " + 
            getContents() + 
            "\n of "  + 
            getClassOfContents() +
            "\n packaged on: \n\t" +
            getPackagedOnDate() +
            "\n and has been used: \n\t" + 
            getStorageCounter() + " times";
    }
    /**
     * This method returns the current contents of the messaged packing case.
     * The provided code contains a fake <TT>return</TT> to get it to compile.
     * This is because all methods that have a non-<TT>void</TT> return
     * must have a <TT>return</TT> statement in them, otherwise they will not
     * compile. You will need to fix this <TT>return</TT> statement so that it 
     * returns the right thing.
     */
    public Object getContents()
    {
        return contents;
    }
    
    /**
     * This method returns the unique serial number of the messaged
     * packing case.
     * The provided code contains a fake <TT>return</TT> to get it to compile.
     * This is because all methods that have a non-<TT>void</TT> return
     * must have a <TT>return</TT> statement in them, otherwise they will not
     * compile. You will need to fix this <TT>return</TT> statement so that it 
     * returns the right thing.
     */
    public int getSerialNo()
    {
        return serialNumber;
    }
    /**
     * This method returns the date that the packing case was created on.
     * The provided code contains a fake <TT>return</TT> to get it to compile.
     * This is because all methods that have a non-<TT>void</TT> return
     * must have a <TT>return</TT> statement in them, otherwise they will not
     * compile. You will need to fix this <TT>return</TT> statement so that it 
     * returns the right thing.
     * @see java.lang.Date
     */
    public Date getCreatedOnDate()
    {
        return packageCreateDate;
    }
    /**
     * This method returns the date that the messaged packing case was 
     * packed with its current contents.
     * The provided code contains a fake <TT>return</TT> to get it to compile.
     * This is because all methods that have a non-<TT>void</TT> return
     * must have a <TT>return</TT> statement in them, otherwise they will not
     * compile. You will need to fix this <TT>return</TT> statement so that it 
     * returns the right thing.
     */
    public Date getPackagedOnDate()
    {
        return packagePackagedDate;
    }
    /**
     * This method returns the number of times the
     * packing case has been used. The first time it is created is the first 
     * time it is used. Thus an initially created packing case should 
     * reply with one.
     * The provided code contains a fake <TT>return</TT> to get it to compile.
     * This is because all methods that have a non-<TT>void</TT> return
     * must have a <TT>return</TT> statement in them, otherwise they will not
     * compile. You will need to fix this <TT>return</TT> statement so that it 
     * returns the right thing.
     */
    public int getStorageCounter()
    {
        return usageCount;
    }

    // sets the contents of the packing case,
    // doing all the necessary book-keeping
    /**
     * This method sets the contents of the messaged packing case,
     * doing all the necessary book-keeping.
     */
    public void setContents(Object o)
    {
    	if (packageCreateDate == null)
    	{
    		packageCreateDate = new Date();
    		serialNumber = ++serialCount;
    	}
    	
    	contents = o;
        usageCount++;
        packagePackagedDate = new Date();
    }

    // returns the string representing the full
    // name of the class the current contents
    // belongs to 
    /**
     * This method returns the string representing the full
     * name of the class the current contents
     * belongs to.
     * The provided code contains a fake <TT>return</TT> to get it to compile.
     * This is because all methods that have a non-<TT>void</TT> return
     * must have a <TT>return</TT> statement in them, otherwise they will not
     * compile. You will need to fix this <TT>return</TT> statement so that it 
     * returns the right thing.
     * @see java.lang.Object
     */
    public String getClassOfContents()
    {
        return contents.getClass().getName();
    }

    /**
     * This method test the class. To see more details please look
     * at both the code and its output.
     * @see PackingCase
     */
    public static void main(String[] args)
    {
        //create a default packing case and print it out
        PackingCase empty = new  PackingCase();
        System.out.println(empty);
        
        //print out ten new packing cases, each containing an Integer
        for(int i = 0; i < 10; i++) System.out.println(new PackingCase(i));

        //make a packing case containing a Double, and then just for fun
        //reset the contents with it ten thousand times
        PackingCase b = new PackingCase(3.1598989889999999);
        for(int i = 0; i < 100000; i++)b.setContents(b.getContents());
        System.out.println(b);

        //so now lets make a vector
        Vector<PackingCase> v = new Vector<PackingCase>();
        //packing cases are objects, so they can be stored
        //in a vector
        v.add(b);
        //add a packing case with a Boolean in it
        v.add(new PackingCase(true));
        //add a packing case with a  Byte in it
        v.add(new PackingCase((byte)2));
        //add a packing case with a  Short in it
        v.add(new PackingCase((short)3));
        //add a packing case with a  Character
        v.add(new PackingCase((char)5));
        //add a packing case with a Integer in it
        v.add(new PackingCase((int)7));
        //add a packing case with a Double
        v.add(new PackingCase((double)11));
        //add a packing case with a Float
        v.add(new PackingCase((float)13));
        //add a packing case with another Double
        v.add(new PackingCase((double)17));
        //add a packing case with a String
        v.add(new PackingCase("Danger String"));

        //hey even arrays are objects, so lets make one and
        //shove it in a packing case
        int[] golly = new int[23];
        v.add(new PackingCase(golly));
        // note the funny name for arrays of ints: [I
        // in the output.
              
        // ok lets go crazy, packing cases are object, so they
        // can be stored in packing cases, lets use the vector
        // we just made to add a bunch of packing cases, that each store
        // a packing case already in the vector. lets go completely overboard!
        // not only that these
        // new packing cases are objects too so they can be stored in
        // the vector as well!!!
        int s = v.size();
        for (int k = 0; k < s; k++)
        {
        	v.add(new PackingCase(v.elementAt(k)));
        }

        // our vector now contains lots of packing cases, some of which store
        // packing cases!! lets see which ones by asking the packing cases
        // to print the name of the class of the object they store!
        for(int j = 0; j < v.size(); j++)
            System.out.println(((PackingCase)v.elementAt(j)).getClassOfContents());
              
        // finally for each packing case in the vector, lets look inside
        // those that contain other packing cases!
        for (int j = 0; j < v.size(); j++)
        {
            Object o = ((PackingCase)v.elementAt(j)).getContents();
            if (o instanceof PackingCase)
            {
                PackingCase c = (PackingCase)o;
                System.out.println(c.getClassOfContents());
                System.out.println("\t" + c.getSerialNo());
                System.out.println("\t" + c.getContents());
                System.out.println("\t" + c.getCreatedOnDate());
                System.out.println("\t" + c.getPackagedOnDate());
                System.out.println("\t" + c.getStorageCounter());
            }
        }
    }
}
