//---------------------------------------------------------------80 columns---|

/* comp285 Square.java
 * --------------
 */

class Square
{
	protected Location location;
	protected Sokoban game;
	protected Thing contents;

	public Square(Location loc, Sokoban g)
	{
		location = loc;
		game = g;
	}

	public boolean addContents(Thing c)
	{
		if (canEnter())
		{
			boolean wasGoal = (c.getSquare() instanceof Goal);

			c.getSquare().removeContents();

			// Add to this square
			contents = c;

			// Make sure thing knows where it is
			c.setSquare(this);

			// Draw the contents of the square
			drawSelf();

			if (this instanceof Goal && c instanceof Treasure && !wasGoal)
			{
				game.decrementSlots();
			}
			else if (!(this instanceof Goal) && c instanceof Treasure && wasGoal)
			{
				game.incrementSlots();
			}

			if (Sokoban.VERBOSE)
			{
				System.out.println("Vacant slots: " + game.vacantSlots());
			}

			return true;
		}

		return false;
	}

	public boolean canEnter()
	{
		return (contents == null);
	}

	public boolean canPush(int direction)
	{
		Square neighbour = game.squareAt(location.adjacentLocation(direction));

		return (contents != null && neighbour != null && neighbour.canEnter());
	}

	public void drawContents() {
		if (contents != null) {
			contents.drawSelf(getLocation());
		}
	}

	public void drawImage() {
		game.drawAtLocation(getImageName(), getLocation());
	}

	public void drawSelf() {
		drawImage();
		drawContents();
	}

	public Thing getContents() {
		return contents;
	}

	public String getImageName() {
		return "Empty";
	}

	public Location getLocation() {
		return location;
	}

	public boolean pushContents(int direction) {
		if (!canPush(direction)) {
			return false;
		}

		Square neighbour = game.squareAt(location.adjacentLocation(direction));
		neighbour.addContents(contents);

		return true;
	}

	public void removeContents() {
		contents = null;
		drawSelf();
	}
}
