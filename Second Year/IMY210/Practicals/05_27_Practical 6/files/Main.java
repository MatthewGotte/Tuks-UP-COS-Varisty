import java.util.Random;

public class Main
{
	public static void test1()
	{
		System.out.println();
		System.out.println("This is the test that was provided with the practical");
		System.out.println();

		char[] letters = {'E', 'Q', 'R', 'T', 'W', 'Y'};
		Trie trie = new Trie(letters);

		trie.insert("TERRY");
		trie.insert("WERE");
		trie.insert("RYE");
		trie.insert("TYRE");
		trie.insert("YET");
		trie.insert("EYE");
		trie.print(true);
		System.out.println();

		trie.insert("YEW");
		trie.insert("WRY");
		trie.insert("ERR");
		trie.insert("EWE");
		trie.insert("EWER");
		trie.print(false);

		System.out.println(trie.contains("WHERE"));
		System.out.println(trie.contains("TERRY"));
		System.out.println(trie.contains("JEW"));
		System.out.println(trie.contains("EWE"));

		trie.printKeyList();/*

		/* Expected Output:
		Level 1 [ (#,0)  (E,1)  (Q,0)  (R,1)  (T,1)  (W,1)  (Y,1) ]
		Level 2 [EYE]
		Level 2 [RYE]
		Level 2 [ (#,0)  (E,1)  (Q,0)  (R,0)  (T,0)  (W,0)  (Y,1) ]
		Level 2 [WERE]
		Level 2 [YET]
		Level 3 [TERRY]
		Level 3 [TYRE]

		Level 1 [ (E,1)  (R,1)  (T,1)  (W,1)  (Y,1) ]
		Level 2 [ (R,1)  (W,1)  (Y,1) ]
		Level 2 [RYE]
		Level 2 [ (E,1)  (Y,1) ]
		Level 2 [ (E,1)  (R,1) ]
		Level 2 [ (E,1) ]
		Level 3 [ERR]
		Level 3 [ (E,1) ]
		Level 3 [EYE]
		Level 3 [TERRY]
		Level 3 [TYRE]
		Level 3 [WERE]
		Level 3 [WRY]
		Level 3 [ (T,1)  (W,1) ]
		Level 4 [ (#,1)  (R,1) ]
		Level 4 [YET]
		Level 4 [YEW]
		Level 5 [EWE]
		Level 5 [EWER]
		false
		true
		false
		true
		ERR EWE EWER EYE RYE TERRY TYRE WERE WRY YET YEW
		*/
	}

	public static void insertTest1()
	{
		char[] letters = {'A', 'B', 'C', 'D', 'E', 'F'};
		Trie trie = new Trie(letters);
		String key = "";

		System.out.println();
		System.out.println("Let's insert a large number of non-sensical words");
		System.out.println("It is addvisable to run this test multiple times since it will test diffrent orders of inputs when run multiple times and therefore catch errors you might have");
		System.out.println();

		for (int i = 0; i < 100; i++)
		{
			key = "";
			for (int j = (int)(Math.random()*(6)); j>=0 && j < 6 ; j++)
			{
				key += letters[j];
			}
			trie.insert(key);
		}
		trie.print(true);

		/*Output:
		Level 1 [ (#,0) (A,1) (B,1) (C,1) (D,1) (E,1) (F,1)]
		Level 2 [ABCDEF]
		Level 2 [BCDEF]
		Level 2 [CDEF]
		Level 2 [DEF]
		Level 2 [EF]
		Level 2 [F]
		*/
	}

	public static void insertTest2()
	{
		char[] letters = {'A', 'B', 'C', 'D', 'E', 'F'};
		Trie trie = new Trie(letters);

		System.out.println();
		System.out.println("Let's insert a bunch of word so that we can test if the trie is structured correctly after inserting");
		System.out.println("This test also makes sure that the trie won't insert duplicates or words that contain characters that's not in the lettrs array");
		System.out.println();

		trie.insert("BAD");
		trie.insert("DEAD");
		trie.insert("FED");
		trie.insert("ADD");
		trie.insert("CAB");
		trie.insert("EDD");
		trie.insert("SAD");
		trie.insert("EDDE");
		trie.insert("ABBE");
		trie.insert("FRED");
		trie.insert("DEAF");
		trie.insert("BEE");
		trie.insert("BEED");
		trie.insert("BEAD");
		trie.insert("TERRY");
		trie.insert("ABCDEF");
		trie.insert("FEDCBA");
		trie.insert("DEE");
		trie.insert("FEE");
		trie.insert("FEED");
		trie.insert("FEEDA");
		trie.insert("ACE");
		trie.insert("ACER");
		trie.insert("ACED");
		trie.insert("ACE");
		trie.insert("FEAD");
		trie.insert("DEAD");
		trie.insert("BED");
		trie.insert("RED");
		trie.insert("EDF");

		trie.print(false);

		/*Output:
		Level 1 [ (A,1) (B,1) (C,1) (D,1) (E,1) (F,1)]
		Level 2 [ (B,1) (C,1) (D,1) ]
		Level 2 [(A,1) (E,1) ]
		Level 2 [CAB]
		Level 2 [ (E,1) ]
		Level 2 [ (D,1) ]
		Level 2 [ (E,1) ]
		Level 3 [ (B,1) (C,1) ]
		Level 3 [ (E,1) ]
		Level 3 [ADD]
		Level 3 [BAD]
		Level 3 [ (A,1) (D,1) (E,1) ]
		Level 3 [ (A,1) (E,1) ]
		Level 3 [ (D,1) (F,1) ]
		Level 3 [ (A,1) (D,1) (E,1) ]
		Level 4 [ABBE]
		Level 4 [ABCDEF]
		Level 4 [ (#,1) (D,1) ]
		Level 4 [BEAD]
		Level 4 [BED]
		Level 4 [ (#,1) (D,1) ]
		Level 4 [ (D,1) (F,1) ]
		Level 4 [DEE]
		Level 4 [ (#,1) (E,1) ]
		Level 4 [EDF]
		Level 4 [FEAD]
		Level 4 [ (#,1) (C,1) ]
		Level 4 [ (#,1) (D,1) ]
		Level 5 [ACE]
		Level 5 [ACED]
		Level 5 [BEE]
		Level 5 [BEED]
		Level 5 [DEAD]
		Level 5 [DEAF]
		Level 5 [EDD]
		Level 5 [EDDE]
		Level 5 [FED]
		Level 5 [FEDCBA]
		Level 5 [FEE]
		Level 5 [ (#,1) (A,1) ]
		Level 6 [FEED]
		Level 6 [FEEDA]
		*/
	}

	public static void insertTest3()
	{
		char[] letters = {'A', 'B', 'D', 'E'};
		Trie trie = new Trie(letters);

		System.out.println();
		System.out.println("This tests a very specific case of an insert.");
		System.out.println("In this case the second element to be added has the same prefix as the root");
		System.out.println();

		trie.insert("DEA");
		trie.insert("DEAD");
		trie.insert("ABB");
		trie.insert("ABB");
		trie.print(false);

		/*Output:
		Level 1 [ (A,1) (D,1) ]
		Level 2 [ABB]
		Level 2 [ (E,1) ]
		Level 3 [ (A,1) ]
		Level 4 [ (#,1) (D,1) ]
		Level 5 [DEA]
		Level 5 [DEAD]

		*/
	}

	public static void insertTest4()
	{
		char[] letters = {'A', 'B', 'D', 'E'};
		Trie trie = new Trie(letters);

		System.out.println();
		System.out.println("This tests is very similar to insertTest3().");
		System.out.println("In this test the order of insert of the first 2 keys have been swapped");
		System.out.println();

		trie.insert("DEAD");
		trie.insert("DEA");
		trie.insert("ABB");
		trie.insert("ABB");
		trie.print(false);

		/*Output:
		Level 1 [ (A,1) (D,1) ]
		Level 2 [ABB]
		Level 2 [ (E,1) ]
		Level 3 [ (A,1) ]
		Level 4 [ (#,1) (D,1) ]
		Level 5 [DEA]
		Level 5 [DEAD]

		*/
	}

	public static void containsTest1()
	{
		char[] letters = {'A', 'B', 'C', 'D', 'E', 'F'};
		Trie trie = new Trie(letters);
		String key = "";

		System.out.println();
		System.out.println("This test uses the same trie as in insertTest1() to test the contains(key) method");
		System.out.println();

		for (int i = 0; i < 100; i++)
		{
			key = "";
			for (int j = (int)(Math.random()*(6)); j>=0 && j < 6 ; j++)
			{
				key += letters[j];
			}
			trie.insert(key);
		}

		System.out.println("ABCDEF : " + trie.contains("ABCDEF"));
		System.out.println("DEAD : " + trie.contains("DEAD"));
		System.out.println("CDEF : " + trie.contains("CDEF"));
		System.out.println("ADD : " + trie.contains("ADD"));
		System.out.println("DEF : " + trie.contains("DEF"));
		System.out.println("EDD : " + trie.contains("EDD"));
		System.out.println("EF : " + trie.contains("EF"));
		System.out.println("EDDE : " + trie.contains("EDDE"));
		System.out.println("F : " + trie.contains("F"));
		System.out.println("FRED : " + trie.contains("FRED"));


		/*Output:
		ABCDEF : true
		DEAD : false
		CDEF : true
		ADD : false
		DEF : true
		EDD : false
		EF : true
		EDDE : false
		F : true
		FRED : false
		 */
	}

	public static void containsTest2()
	{
		char[] letters = {'A', 'B', 'C', 'D', 'E', 'F'};
		Trie trie = new Trie(letters);

		System.out.println();
		System.out.println("This test uses the same trie as in insertTest2() to test the contains(key) method");
		System.out.println();


		trie.insert("BAD");
		trie.insert("DEAD");
		trie.insert("FED");
		trie.insert("ADD");
		trie.insert("CAB");
		trie.insert("EDD");
		trie.insert("SAD");
		trie.insert("EDDE");
		trie.insert("ABBE");
		trie.insert("FRED");
		trie.insert("DEAF");
		trie.insert("BEE");
		trie.insert("BEED");
		trie.insert("BEAD");
		trie.insert("TERRY");
		trie.insert("ABCDEF");
		trie.insert("FEDCBA");
		trie.insert("DEE");
		trie.insert("FEE");
		trie.insert("FEED");
		trie.insert("FEEDA");
		trie.insert("ACE");
		trie.insert("ACER");
		trie.insert("ACED");
		trie.insert("ACE");
		trie.insert("FEAD");
		trie.insert("DEAD");
		trie.insert("BED");
		trie.insert("RED");
		trie.insert("EDF");

		System.out.println("BAD : " + trie.contains("BAD"));
		System.out.println("DEAD : " + trie.contains("DEAD"));
		System.out.println("FED : " + trie.contains("FED"));
		System.out.println("ADD : " + trie.contains("ADD"));
		System.out.println("CAB : " + trie.contains("CAB"));
		System.out.println("EDD : " + trie.contains("EDD"));
		System.out.println("SAD : " + trie.contains("SAD"));
		System.out.println("EDDE : " + trie.contains("EDDE"));
		System.out.println("ABBE : " + trie.contains("ABBE"));
		System.out.println("FRED : " + trie.contains("FRED"));
		System.out.println("DEAF : " + trie.contains("DEAF"));
		System.out.println("BEE : " + trie.contains("BEE"));
		System.out.println("BEED : " + trie.contains("BEED"));
		System.out.println("BEAD : " + trie.contains("BEAD"));
		System.out.println("TERRY : " + trie.contains("TERRY"));
		System.out.println("ABCDEF : " + trie.contains("ABCDEF"));
		System.out.println("FEDCBA : " + trie.contains("FEDCBA"));
		System.out.println("DEE : " + trie.contains("DEE"));
		System.out.println("FEE : " + trie.contains("FEE"));
		System.out.println("FEED : " + trie.contains("FEED"));
		System.out.println("FEEDA : " + trie.contains("FEEDA"));
		System.out.println("ACE : " + trie.contains("ACE"));
		System.out.println("ACER : " + trie.contains("ACER"));
		System.out.println("ACED : " + trie.contains("ACED"));
		System.out.println("ACE : " + trie.contains("ACE"));
		System.out.println("FEAD : " + trie.contains("FEAD"));
		System.out.println("DEAD : " + trie.contains("DEAD"));
		System.out.println("BED : " + trie.contains("BED"));
		System.out.println("RED : " + trie.contains("RED"));
		System.out.println("EDF : " + trie.contains("EDF"));

		/*Output:
		BAD : true
		DEAD : true
		FED : true
		ADD : true
		CAB : true
		EDD : true
		SAD : false
		EDDE : true
		ABBE : true
		FRED : false
		DEAF : true
		BEE : true
		BEED : true
		BEAD : true
		TERRY : false
		ABCDEF : true
		FEDCBA : true
		DEE : true
		FEED : true
		FEEDA : true
		ACE : true
		ACER : false
		ACED : true
		ACE : true
		FEAD : true
		DEAD : true
		BED : true
		RED : false
		EDF : true
		*/
	}

	public static void printKeyKistTest1()
	{
		char[] letters = {'A', 'B', 'C', 'D', 'E', 'F'};
		Trie trie = new Trie(letters);
		String key = "";

		System.out.println();
		System.out.println("This test uses the same trie as in insertTest1() to test the printKeyList() method");
		System.out.println();


		for (int i = 0; i < 100; i++)
		{
			key = "";
			for (int j = (int)(Math.random()*(6)); j>=0 && j < 6 ; j++)
			{
				key += letters[j];
			}
			trie.insert(key);
		}

		trie.printKeyList();

		/*Output:
		ABCDEF BCDEF CDEF DEF EF F
		*/
	}

	public static void printKeyKistTest2()
	{
		char[] letters = {'A', 'B', 'C', 'D', 'E', 'F'};
		Trie trie = new Trie(letters);

		System.out.println();
		System.out.println("This test uses the same trie as in insertTest2() to test the printKeyList() method");
		System.out.println();

		trie.insert("BAD");
		trie.insert("DEAD");
		trie.insert("FED");
		trie.insert("ADD");
		trie.insert("CAB");
		trie.insert("EDD");
		trie.insert("SAD");
		trie.insert("EDDE");
		trie.insert("ABBE");
		trie.insert("FRED");
		trie.insert("DEAF");
		trie.insert("BEE");
		trie.insert("BEED");
		trie.insert("BEAD");
		trie.insert("TERRY");
		trie.insert("ABCDEF");
		trie.insert("FEDCBA");
		trie.insert("DEE");
		trie.insert("FEE");
		trie.insert("FEED");
		trie.insert("FEEDA");
		trie.insert("ACE");
		trie.insert("ACER");
		trie.insert("ACED");
		trie.insert("ACE");
		trie.insert("FEAD");
		trie.insert("DEAD");
		trie.insert("BED");
		trie.insert("RED");
		trie.insert("EDF");

		trie.printKeyList();

		/*Output:
		ABBE ABCDEF ACE ACED ADD BAD BEAD BED BEE BEED CAB DEAD DEAF DEE EDD EDDE EDF FEED FED FEDCBA FEE FEED FEEDA
		*/
	}

	public static void main(String[] args)
	{
		System.out.println();
		System.out.println("THIS MAIN DOES NOT GUARANTEE FULL MARKS OR ANY MARKS ON FITCH FORK.");
		System.out.println("IT WILL SIMPLY AID YOU IN TESTING YOU'RE CODE.");
		System.out.println("PLEASE DO YOUR OWN TESTS AS WELL.");
		System.out.println("GOOD LUCK!!!!");
		test1();
		insertTest1();
		insertTest2();
		insertTest3();
		insertTest4();
		containsTest1();
		containsTest2();
		printKeyKistTest1();
		printKeyKistTest2();
	}
}
