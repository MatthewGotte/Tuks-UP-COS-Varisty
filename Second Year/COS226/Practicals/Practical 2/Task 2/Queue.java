// Name: Matthew Gotte
// Student Number: u20734621

public class Queue extends Thread
{
	Store store;
	public Queue(Store s){
		store = s;
	}
//TODO
	@Override
	public void run()
	{
		String concat = this.getName();
		for (int i = 1; i <= 5; i++) {
			this.setName(concat + " Person " + i);
			System.out.printf("%s is trying to get inside.%n", this.getName());
			this.store.enterStore();
		}
	}

}
