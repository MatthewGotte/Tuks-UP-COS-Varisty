public class Test
{
	public static void main(String[] args)
	{
		//Do not uncomment tests at the same time,
		//I called them all mmh so you can only run the file in pieces.

		//There is no heapify test


		//Test 1 insert output:
		//1,90,36,2,4,3,6,70,19,9,24,7,21,12,23,5,38,8

		//(a):
	/*
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println("Empty List Here -> " + mmh);
*/

		//TEST 1 OUTPUT with max delete from (a) uncommented:
		/*
		1,90,36,2,4,3,6,70,19,9,24,7,21,12,23,5,38,8
		1,90,36,2,4,3,6,70,19,9,24,7,21,12,23,5,38,8
		DELETED = 90
		1,9,36,2,4,3,6,70,19,8,24,7,21,12,23,5,38
		OUTPUT = 5
		OUTPUT = 11
		DELETED = 36
		1,9,3,2,4,7,6,70,19,8,24,38,21,12,23,5
		DELETED = 9
		1,8,3,2,4,7,6,70,19,5,24,38,21,12,23
		DELETED = 8
		1,5,3,2,4,7,6,70,19,23,24,38,21,12
		DELETED = 5
		1,19,3,2,4,7,6,70,12,23,24,38,21
		DELETED = 19
		1,12,3,2,4,7,6,70,21,23,24,38
		DELETED = 12
		1,21,3,2,4,7,6,70,38,23,24
		DELETED = 21
		Empty List Here -> 1,23,3,2,4,7,6,70,38,24
		*/







		//test 2
		/*
		MinMaxDHeap<Integer> mmh = new MinMaxDHeap<Integer>(2);

		Node[] values = new Node[10];
		for (int i = 1; i <= 10; i++) {
			values[i - 1] = new Node<Integer>(i, i);
		}
		mmh.construct(values);
		System.out.println(mmh);

		 */

		//test 2 output:
		//1,10,7,2,4,3,6,5,8,9







		//test 3
		/*
		MinMaxDHeap<Integer> mmh = new MinMaxDHeap<Integer>(2);

		mmh.insert(24, 24);
		System.out.println(mmh);
		mmh.insert(38, 38);
		System.out.println(mmh);
		mmh.insert(36, 36);
		System.out.println(mmh);
		mmh.insert(21, 21);
		System.out.println(mmh);
		mmh.insert(7,7);
		System.out.println(mmh);
		mmh.insert(4,4);
		System.out.println(mmh);
		mmh.insert(8,8);
		System.out.println(mmh);
		mmh.insert(9,9);
		System.out.println(mmh);
		*/

		//only test 3 output:
		/*
		24
		24,38
		24,38,36
		21,38,36,24
		7,38,36,24,21
		4,38,36,24,21,7
		4,38,36,24,21,7,8
		4,38,36,9,21,7,8,24
		 */

		//test 3 with deletes -> uncomment EITHER option 1 or option 2, not both

		//OPTION 1:
		/*
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println(mmh);
		System.out.println("DELETED = " + mmh.deleteMax());
		System.out.println("Empty List Here -> " + mmh);
		//System.out.println("DELETING:");
		*/

		//output test 3 with OPTION 1:
		/*
		24
		24,38
		24,38,36
		21,38,36,24
		7,38,36,24,21
		4,38,36,24,21,7
		4,38,36,24,21,7,8
		4,38,36,9,21,7,8,24
		4,38,36,9,21,7,8,24
		DELETED = 38
		4,24,36,9,21,7,8
		OUTPUT = 5
		DELETED = 36
		4,24,7,9,21,8
		DELETED = 24
		4,21,7,9,8
		DELETED = 21
		4,9,7,8
		DELETED = 9
		4,8,7
		DELETED = 8
		4,7
		DELETED = 7
		4
		DELETED = 4
		Empty List Here ->
		 */

		//OPTION 2
		/*
		System.out.println("Removed = " + mmh.deleteMin());
		System.out.println(mmh);
		System.out.println("Removed = " + mmh.deleteMin());
		System.out.println(mmh);
		System.out.println("Removed = " + mmh.deleteMin());
		System.out.println(mmh);
		System.out.println("Removed = " + mmh.deleteMin());
		System.out.println(mmh);
		System.out.println("Removed = " + mmh.deleteMin());
		System.out.println(mmh);
		System.out.println("Removed = " + mmh.deleteMin());
		System.out.println(mmh);
		System.out.println("Removed = " + mmh.deleteMin());
		System.out.println(mmh);
		System.out.print("Removed = " + mmh.deleteMin());
		System.out.println(mmh);
		System.out.print("Nothing here-> " + mmh);
		*/

		//output Test 3 with OPTION 2:
		/*
		24
		24,38
		24,38,36
		21,38,36,24
		7,38,36,24,21
		4,38,36,24,21,7
		4,38,36,24,21,7,8
		4,38,36,9,21,7,8,24
		OUTPUT = 5
		Removed = 4
		7,38,36,9,21,24,8
		Removed = 7
		8,38,36,9,21,24
		Removed = 8
		24,38,36,9,21
		Removed = 24
		21,38,36,9
		Removed = 21
		9,38,36
		Removed = 9
		36,38
		Removed = 36
		38
		Removed = 38
		Nothing here->
		 */

		//test clear ->use this after inserting anything to test if clear worked
		/*
		System.out.println(mmh);
		mmh.clear();
		System.out.println("Cleared");
	*/
















	}
}
