public class Clipboard
{

    public Clipboard()
    {
    }

    public void storeObject(Object object)
    {
        this.object = object;
    }

    public Object retrieveObject()
    {
        return object;
    }

    private static final long serialVersionUID = 1L;
    private Object object;
}
