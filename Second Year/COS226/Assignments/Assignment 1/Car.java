//Matthew Gotte
//u20734621

public class Car
{
	public volatile long washTime, dryTime;
	public String name;

	public Car(char c, String n){
		name = n;

		switch(c){
			case 's': 	washTime = 500;
						dryTime = 1000;
						break;
			case 'm':	washTime = 1000;
						dryTime = 1500;
						break;
			case 'l':	washTime = 1500;
						dryTime = 2000;
		}
	}
}
