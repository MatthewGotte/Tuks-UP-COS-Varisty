/*
	You may not change the signatures of any of the given methods.  You may 
	however add any additional methods and/or field(s) which you may require to aid 
	you in the completion of this practical.
 */

public class BPlusTree {
	int order;
	int minKeys;
	int maxKeys;
	BPlusNode root; // do not modify

	public BPlusTree(int m) {
		/*
		The constructor.  Creates a BPlusTree object of order m,
		where m is passed as a parameter to the constructor. 
		You may assume that m >= 3.
		*/
		order = m;
		minKeys = (int) Math.ceil(m / 2.0) - 1;
		maxKeys = order - 1;
		root = new BPlusNode(m, true); /* root starts as leaf node and root's parent is null */
	}

	/* insert an element into the BPlusTree, you may assume duplicates will not be inserted. */
	public void insertElement(int element) {
		// your code goes here

		//get insert node:
		Integer temp = (Integer)element;
		insertElement(temp);

	}

	public String runner(int element) {
		Integer temp = (Integer)element;
		return runner(temp);
	}


	/*
	    This method should return the left-most leaf node in the tree.
		If the tree is empty, return null.
	 */
	public BPlusNode getFirstLeaf() {
		// your code goes here
		if (root.keyTally == 0) return null;
		return getleaf(root);
	}

	public BPlusNode getleaf(BPlusNode temp) {
		if (temp.leaf) {
			return temp;
		}
		return getleaf(temp.branches[0]);
	}

}
