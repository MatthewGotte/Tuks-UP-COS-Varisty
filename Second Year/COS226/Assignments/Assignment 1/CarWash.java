//Matthew Gotte
//u20734621

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

public class CarWash
{
	private volatile Queue<Car> washCars = new LinkedList<>(), dryCars = new LinkedList<>();

	public CarWash(){
		washCars.add(new Car('s', "Panda"));
		washCars.add(new Car('m', "Cerato"));
		washCars.add(new Car('s', "Swift"));
		washCars.add(new Car('l', "Defender"));
		washCars.add(new Car('m', "A3"));
		washCars.add(new Car('l', "Ranger"));
		washCars.add(new Car('s', "GTI"));
	}

	public void wash() {
		//[100-500] subtracted

		//get lock
		//subtract time
		//sleep
		//check if finish wash
		//move to dry/continue
		//release lock
	}

	public void dry() {
		//[100-500] subtracted
	}

	public boolean toWash() {
		if (dryCars.isEmpty())
			return false;
		return true;
	}

	public boolean toDry() {
		if (washCars.isEmpty())
			return false;
		return true;
	}
}
