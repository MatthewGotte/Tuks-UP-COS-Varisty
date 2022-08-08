//Matthew Gotte - u20734621

public class Trie {
	protected char[] letters;
	protected Node root = null;
	private int numPtrs;

	public Trie(char[] letters) {
		this.letters = letters;
		this.numPtrs = letters.length + 1;
	}


	//Provided Helper functions
	
	private int index(char c) {
		for (int k = 0; k < letters.length; k++) {
			if (letters[k] == (c)) {
				return k+1;
			}
		}
		return -1;
	}
	
	private char character(int i) {
		if (i == 0) {
			return '#';
		} else {
			return letters[i-1];
		}
	}
	
	private String nodeToString(Node node, boolean debug) {
		if (node.isLeaf) {
			return node.key;
		}
		else {
			String res = "";
			for (int k = 0; k < node.ptrs.length; k++) {
				if (node.ptrs[k] != null) {
					res += " (" + character(k) + ",1) ";
				} else if (debug) {
					res += " (" + character(k) + ",0) ";
				}
			}
			return res;
		}
	}

	public void print(boolean debug) {
		Queue queue = new Queue();
		Node n = root;
		if (n != null) {
			n.level = 1;
			queue.enq(n);
			while (!queue.isEmpty()){
				n = queue.deq();
				System.out.print("Level " + n.level + " [");
				System.out.print(nodeToString(n, debug));
				System.out.println("]");
				for (int k = 0; k < n.ptrs.length; k++) {
					if (n.ptrs[k] != null) {
						n.ptrs[k].level = n.level+1;
						queue.enq(n.ptrs[k]);
					}
				}
			}
		}
	}


	////// You may not change any code above this line //////

	////// Implement the functions below this line //////

	
	// Function to insert the given key into the trie at the correct position.
	public void insert(String key) {

		// Your code goes here

		if (root == null) {
			root = new Node(key, numPtrs);
			return;
		}

		///////////
		for (int i = 0; i < key.length(); i++) {
			int checker = index(key.charAt(i));
			if (checker == -1) return;
		}
		///////////

		boolean complete = false;
		int i = 0;
		Node temp = root;

		while(!complete) {

			if (i == key.length()) {
				temp.endOfWord = true;
				temp.ptrs[0] = new Node(key, numPtrs);
				complete = true;
			}
			else if (temp.ptrs[index(key.charAt(i))] == null) {

				if (temp.isLeaf) {
					temp.isLeaf = false;
					String leafKey = temp.key;
					insert(leafKey);
					insert(key);
					complete = true;
				} else {
					temp.ptrs[index(key.charAt(i))] = new Node(key, numPtrs);
					complete = true;
				}

			}
			else if (temp.ptrs[index(key.charAt(i))].isLeaf) {

				String keyleaf = temp.ptrs[index(key.charAt(i))].key;

				while (i < keyleaf.length() && key.charAt(i) == keyleaf.charAt(i)) {
					int charpos = index(key.charAt(i));
					temp.ptrs[charpos] = new Node(numPtrs);
					temp = temp.ptrs[charpos];
					i++;
					if (i == key.length()) break;
				}

				if (i == key.length()) {
					temp.endOfWord = true;
					temp.ptrs[0] = new Node(key, numPtrs);
					insert(keyleaf);
					return;
				}

				else if (i == keyleaf.length()) {
					temp.endOfWord = true;
					temp.ptrs[0] = new Node(keyleaf, numPtrs);
					insert(key);
				}
				else if (key.charAt(i) != keyleaf.charAt(i)) {
					Node copy = new Node(key, numPtrs);
					temp.ptrs[index(key.charAt(i))] = copy;
					Node copy2 = new Node(keyleaf, numPtrs);
					temp.ptrs[index(keyleaf.charAt(i))] = copy2;
				}
				complete = true;

			} else {
				temp = temp.ptrs[index(key.charAt(i++))];
			}

		}
	}
	

	// Function to determine if a node with the given key exists.
	public boolean contains(String key) {
		// Your code goes here
		Queue queue = new Queue();
		Node n = root;
		if (n != null) {
			n.level = 1;
			queue.enq(n);
			while (!queue.isEmpty()){
				n = queue.deq();
//				System.out.print("Level " + n.level + " [");
//				System.out.print(nodeToString(n, debug));
//				System.out.println("]");
				if (n.isLeaf && key.equals(n.key))
					return true;
				for (int k = 0; k < n.ptrs.length; k++) {
					if (n.ptrs[k] != null) {
						n.ptrs[k].level = n.level+1;
						queue.enq(n.ptrs[k]);
					}
				}
			}
		}
		return false;
	}

	public String finaloutput = "";

	// Function to print all the keys in the trie in alphabetical order.
	public void printKeyList() {

		// Your code goes here
		printRecursive(root);
		System.out.println(finaloutput.substring(0, finaloutput.length() - 1));

	}

	public void printRecursive(Node temp) {
		if (temp == null) return;
		for (int i = 0; i < this.numPtrs; i++) {
			if (temp.ptrs[i] != null) {
				if (temp.ptrs[i].isLeaf)
					finaloutput += temp.ptrs[i].key + " ";
				else {
					printRecursive(temp.ptrs[i]);
				}
			}
		}
	}

	
	//Helper functions

}