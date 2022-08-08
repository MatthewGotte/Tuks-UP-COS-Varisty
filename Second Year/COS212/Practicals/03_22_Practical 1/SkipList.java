import java.util.Random;

@SuppressWarnings("unchecked")
public class SkipList<T extends Comparable<? super T>> {

	public int maxLevel;
	public SkipListNode<T>[] root;
	private int[] powers;
	private Random rd = new Random();

	SkipList(int i) {
		maxLevel = i;
		root = new SkipListNode[maxLevel];
		powers = new int[maxLevel];
		for (int j = 0; j < i; j++)
			root[j] = null;
		choosePowers();
		rd.setSeed(202003); // do not modify this line
	}

	SkipList() {
		this(4);
	}

	public void choosePowers() {
		powers[maxLevel - 1] = (2 << (maxLevel - 1)) - 1;
		for (int i = maxLevel - 2, j = 0; i >= 0; i--, j++)
			powers[i] = powers[i + 1] - (2 << j);
	}

	public int chooseLevel() {
		int i, r = Math.abs(rd.nextInt()) % powers[maxLevel - 1] + 1;
		for (i = 1; i < maxLevel; i++) {
			if (r < powers[i])
				return i - 1;
		}
		return i - 1;
	}

	public boolean isEmpty() {
		// your code goes here
		return root[0] == null;
	}

	public void insert(T key) {
		SkipListNode<T> [] curr = new SkipListNode[maxLevel];
		SkipListNode<T> [] prev = new SkipListNode[maxLevel];
		SkipListNode<T> newNode;
		int lvl, i;
		curr[maxLevel - 1] = root[maxLevel - 1];
		prev[maxLevel - 1] = null;
		for (lvl = maxLevel - 1; lvl >= 0; lvl--) {
			while (curr[lvl] != null && curr[lvl].key.compareTo(key) < 0) {
				prev[lvl] = curr[lvl];
				curr[lvl] = curr[lvl].next[lvl];
			}
			if (curr[lvl] != null && curr[lvl].key.equals(key))
				return;
			if (lvl > 0) {
				if (prev[lvl] == null) {
					curr[lvl - 1] = root[lvl - 1];
					prev[lvl - 1] = null;
				}
				else {
					curr[lvl - 1] = prev[lvl].next[lvl - 1];
					prev[lvl - 1] = prev[lvl];
				}
			}
		}
		lvl = chooseLevel();

		newNode = new SkipListNode<T>(key, lvl + 1);

		for (i = 0; i <= lvl; i++) {
			newNode.next[i] = curr[i];
			if (prev[i] == null)
				root[i] = newNode;
			else prev[i].next[i] = newNode;
		}
	}

	public boolean delete(T key) {
		int lvl;
		SkipListNode<T> prev, curr, temp;
		for (lvl = maxLevel - 1; lvl >= 0 && root[lvl] == null; lvl--);
		prev = curr = root[lvl];
		while (true) {
			if (key.equals(curr.key)) {
				////////////////
				for (int i = 0; i < maxLevel; i++) {
					if (root[i] != null) {
						if (root[i].equals(curr))
							root[i] = curr.next[i];
						else {
							temp = root[i];
							while (temp != null) {
								if (temp.next[i] != null) {
									if (temp.next[i].equals(curr)) {
										temp.next[i] = curr.next[i];
									}
									else temp = temp.next[i];
								}
								else temp = null;
							}
						}
					}
				}
				return true;
				////////////////
			}
			else if (key.compareTo(curr.key) < 0) {
				if (lvl == 0)
					return false;
				else if (curr.equals(root[lvl]))
					curr = root[--lvl];
				else curr = prev.next[--lvl];
			}
			else {
				prev = curr;
				if (curr.next[lvl] != null)
					curr = curr.next[lvl];
				else {
					for (lvl--; lvl >= 0 && curr.next[lvl] == null; lvl--);
					if (lvl >= 0)
						curr = curr.next[lvl];
					else return false;
				}
			}
		}
	}

	public T first() {
		// your code goes here
		if (root[0] == null)
			return null;
		return root[0].key;
	}

	public T search(T key) {
		int lvl;
		SkipListNode<T> prev, curr;
		for (lvl = maxLevel - 1; lvl >= 0 && root[lvl] == null; lvl--);

		prev = curr = root[lvl];

		while (true) {
			if (key.equals(curr.key)) {
				return curr.key;
			}
			else if (key.compareTo(curr.key) < 0) {
				if (lvl == 0)
					return null;
				else if (curr.equals(root[lvl]))
					curr = root[--lvl];
				else curr = prev.next[--lvl];
			}
			else {
				prev = curr;
				if (curr.next[lvl] != null)
					curr = curr.next[lvl];
				else {
					for (lvl--; lvl >= 0 && curr.next[lvl] == null; lvl--);
					if (lvl >= 0)
						curr = curr.next[lvl];
					else return null;
				}
			}
		}
	}
	
	public String getPathToLastNode() {
		// your code goes here
		String output = "";
		int lvl;
		for (lvl = maxLevel - 1; lvl >= 0 && root[lvl] == null; lvl--);
		SkipListNode<T> temp = root[lvl];
		while (temp != null) {
			output += "[" + temp.key + "]";
			if (temp.next[lvl] != null) {
				temp = temp.next[lvl];
			}
			else {
				for (	; lvl >= 0 && temp.next[lvl] == null; lvl--);
				if (lvl < 0) {
					temp = null;
					break;
				}
				else {
					temp = temp.next[lvl];
				}
			}
		}
		return output;
	}

}