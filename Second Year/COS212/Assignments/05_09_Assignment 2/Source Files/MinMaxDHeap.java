/* Complete this class to implement a fully functional min-max d-heap. Read the comments to determine what each aspect of the class is supposed to do.
You must add any additional features (methods, references) which may aid you in your task,
BUT you are not allowed to remove or change the names or properties of any of the features you were given.

Importing Java's built in data structures will result in a mark of 0.
*/
@SuppressWarnings("unchecked")
public class MinMaxDHeap<T> {
	public Node[] arr;
	int size;

	public MinMaxDHeap(int d) {

		/* Parameter d specifies the order of your min-max heap. If d = 2, you should construct a binary heap,
		   if d = 3, you should construct a ternary heap, etc. You may implement this constructor to suit your
		   needs, or you may add additional constructors. This is the constructor which will be used for marking. */
		this.d = d;
		size = 0;
		arr = new Node[size];
	}

	/* Insertion */
	public void insert(T data, int key) {
		/* Insert a Node object according to its key (priority).
			 The Node object has to be initialised with the given data/key values.
		   Refer to the assignment spec for insertion algorithm details. */
		//make temp:
		/*Node[] temp = new Node[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		temp[size] = new Node<T>(data, key);
		arr = temp;
		size++;*/

		Node[] temp = new Node[size + 1];

		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}

		temp[size] = new Node<T>(data, key);
		arr = temp;
		size++;


		int insertlvl = 0;
		insertlvl = getLevel(size - 1);

		if (size == 1) return;

		int last = size - 1;
		if (insertlvl % 2 == 0) {
			//even level -> min
			//System.out.println("even");
			int parent = getParent(last);
			if (arr[last].key < arr[parent].key) {
				keyLTgp(last);
			}
			else {
				swap(last, parent);
				keyGTgp(parent); //?parent or last?
			}
		}
		else {
			//odd level -> max
			//System.out.println("odd");
			int parent = getParent(last);
			if (arr[last].key > arr[parent].key) {
				keyGTgp(last);
			}
			else {
				swap(last, parent);
				keyLTgp(parent); //?parent or last?
			}
		}

	}

	public void keyLTgp(int index) {
		int gp = getGParent(index);
		if (gp == -1) return;
		if (arr[index].key < arr[gp].key) {
			swap(index, gp);
			keyLTgp(gp);
		}
	}

	public void keyGTgp(int index) {
		int gp = getGParent(index);
		if (gp == -1) return;
		if (arr[index].key > arr[gp].key) {
			swap(index, gp);
			keyGTgp(gp);
		}
	}

	public void swap(int ind1, int ind2) {
		Node<T> temp = arr[ind1];
		arr[ind1] = arr[ind2];
		arr[ind2] = temp;
	}

	/* Read-only access */
	public T peekMin() {
		/* Return the data of the min priority Node. Min-max heap should not be modified by this function. */
		//return null;
		if (size != 0) {
			return (T) arr[0].data;
		}
		return null;
	}

	public T peekMax() {
		/* Return the data of the max priority Node. Min-max heap should not be modified by this function. */
		//return null;
		if (size != 0) {
			Node<T> highest = arr[getChildNo(0, 1)];
			int curr = highest.key;
			for (int i = 1; i <= d; i++) {
				if (curr < arr[getChildNo(0, i)].key) {
					highest = arr[getChildNo(0, i)];
					curr = highest.key;
				}
			}
			return highest.data;
		}
		return null;
	}

	public String toString() {
		/* Return a breadth-first traversal representation of the Min-Max d-heap by constructing
		   a comma-separated string of the data stored in the heap. To construct the string,
       iterate over the heap, and append each Node object by invoking the toString() method.
       NB: The output format should contain no spaces and/or new line characters.
       Individual nodes must be comma-separated. Eg., if alphabetical characters A, B, and C
       were stored in the min-max heap in this order, you should return the string "A,B,C"
       */
		//return "";
		String output = "";
		for (int i = 0; i < size; i++) {
			output += (T) arr[i].toString();
			if (i != size - 1)
				output += ",";
		}
		return output;
	}


	/* Deletion */
	public T deleteMin() {
		/* Remove the Node with the min priority, and return its data.
			 Min-max heap has to be restructured accordingly: see spec for details. */
		//return null;
		//System.out.println("SIZE + " + size);
		if (size == 1) {
			Node<T> temp = arr[0];
			clear();
			return (T) temp.getData();
		}

		if (size == 2) {
			Node[] temp = new Node[size - 1];
			temp[0] = arr[1];
			Node<T> tempNode = arr[0];
			arr = temp;
			size--;
			return tempNode.getData();
		}

		Node[] temp = new Node[size - 1];
		Node<T> deleted = arr[0];
		temp[0] = arr[size - 1];
		for (int i = 1; i < size - 1; i++) {
			temp[i] = arr[i];
		}
		arr = temp;
		size--;
		trickleMin(0);
		return deleted.data;
	}

	public void trickleMin(int index) {
		boolean child = true;
		//System.out.println("INDEX VALUE first= " + index);
		int i1 = getSmallestChild(index);
		int i2, i, j = index;
		if (i1 != -1) {
			i = i1;
			//System.out.println(arr[i1].data);
			i2 = getSmallestGChild(j);
			if (i2 != -1) {
				//compare to child
				//if (i2 == size) System.out.println("SIZE FOUND!!" + i2);
				if (arr[i1].key > arr[i2 - 1].key) {
					child = false;
					i = i2;
				}
			}
			if (child) {
				if (arr[i].key < arr[j].key) {
					//swap
					swap(i, j);
					j = i;
				}
			}
			else {
				if (arr[i].key < arr[j].key) {
					swap(i, j);
					j = i;
					int newParent = getParent(j);
					if (arr[j].key > arr[newParent].key) {
						swap(newParent, j);
						j = newParent;
					}
				}
			}
			//System.out.println("INDEX VALUE = " + j);
			//System.out.println(this.toString());
			//if (j == 0) return;
			if (j == 0 || j == 1 || j == 2) return;
			System.out.println("OUTPUT = " + j);
			trickleMin(j);
		}
	}

	public int getSmallestChild(int index) {
		int output = getChildNo(index, 1);

		if (output == -1) return -1;

		for (int i = 2; i <= d; i++) {
			if (getChildNo(index, i) >= size) break;
			if (arr[output].key > arr[getChildNo(index, i)].key) {
				output = getChildNo(index, i);
			}
		}
		return output;
	}

	public int getSmallestGChild (int index) {
		int output = getChildNo(index, 1);
		if (output == -1) return output;
		output = getChildNo(output, 1);
		if (output == -1) return output; //output has index of left left gChild.

		for (int i = 1; i <= d; i++) {
			int child = getChildNo(index, i); //index of child, [1, d]

			//System.out.println("CHILD = " + getChildNo(index, i));

			if (getChildNo(index, i) == -1) break;

			for (int j = 1; j <= d; j++) {
				int temp = getChildNo(child, j);
				if (temp >= size || temp == -1) break;
				if (arr[output].key > arr[temp].key) {
					output = getChildNo(child, j);
				}
			}

		}

		return output;
	}

	public T deleteMax() {
		/* Remove the Node with the max priority, and return its data.
			 Min-max heap has to be restructured accordingly: see spec for details. */
		//return null;
		if (size == 1) {
			Node<T> temp = arr[0];
			clear();
			return (T) temp.getData();
		}

		if (size == 2) {
			Node<T> output = arr[1];
			Node[] temp = new Node[1];
			temp[0] = arr[0];
			arr = temp;
			size--;
			return output.getData();
		}

		int todelete = getLargestChild(0);
		Node<T> deleted = arr[todelete];
		//System.out.println("TO DELETE = " + arr[todelete].getData());
		arr[todelete] = arr[size - 1];
		Node[] temp = new Node[size - 1];
		for (int i = 0; i < size - 1; i++) {
			temp[i] = arr[i];
		}
		arr = temp;
		size--;

		trickleMax(todelete);

		return deleted.getData();
	}

	public void trickleMax(int index) {
		boolean child = true;
		//System.out.println("INDEX VALUE first= " + index);
		int i1 = getLargestChild(index);
		int i2, i, j = index;
		if (i1 != -1) {
			i = i1;
			//System.out.println(arr[i1].data);
			i2 = getLargestGChild(j);
			if (i2 != -1) {
				//compare to child
				//if (i2 == size) System.out.println("SIZE FOUND!!" + i2);
				if (arr[i1].key < arr[i2 - 1].key) {
					child = false;
					i = i2;
				}
			}
			if (child) {
				if (arr[i].key > arr[j].key) {
					//swap
					swap(i, j);
					j = i;
				}
			}
			else {
				if (arr[i].key > arr[j - 1].key) {
					swap(i, j);
					j = i;
					int newParent = getParent(j);
					if (arr[j].key < arr[newParent].key) {
						swap(newParent, j);
						j = newParent;
					}
				}
			}
			//System.out.println("INDEX VALUE = " + j);
			//System.out.println(this.toString());
			//if (j == 0) return;
			if (j == 0 || j == 1) return;
			trickleMin(j);
		}
	}

	public int getLargestChild(int index) {
		int output = getChildNo(index, 1);

		if (output == -1) return -1;

		if (output >= size || index >= size) return -1;

		for (int i = 2; i <= d; i++) {
			if (getChildNo(index, i) >= size) break;
			if (arr[output].key < arr[getChildNo(index, i)].key) {
				output = getChildNo(index, i);
			}
		}
		return output;
	}

	public int getLargestGChild (int index) {
		int output = getChildNo(index, 1);
		if (output == -1) return output;
		output = getChildNo(output, 1);
		if (output == -1) return output; //output has index of left left gChild.

		for (int i = 1; i <= d; i++) {
			int child = getChildNo(index, i); //index of child, [1, d]

			//System.out.println("CHILD = " + getChildNo(index, i));

			if (getChildNo(index, i) == -1) break;

			for (int j = 1; j <= d; j++) {
				int temp = getChildNo(child, j);
				if (temp >= size || temp == -1) break;
				if (arr[output].key > arr[temp].key) {
					output = getChildNo(child, j);
				}
			}

		}

		return output;
	}

	/* Construction */
	public void construct(Node<T>[] arr) {
		/* Given an array of Node objects in arbitrary order, construct a min-max heap by
       applying Floyd's algorithm modified for min-max d-heaps. */
		for (int i = 0; i < arr.length; i++) {
			this.insert(arr[i].data, arr[i].key);
		}


	}

	public void changeD(int newD) {
		/* Given a new order d, restructure the current min-max d-heap such that it is a d-heap with d = newD. */
		Node[] temp = new Node[size];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		clear();
		this.d = newD;
		for (int i = 0; i < temp.length; i++) {
			insert((T) temp[i].data, temp[i].key);
		}
	}

	/* Clearing */
	public void clear() {
		/* Clear the min-max heap by removing all nodes. */
		size = 0;
		Node[] temp = new Node[size];
		arr = temp;
	}

	private int d; // The d-order of the min-max d-heap

	///////////////////////////////////////
	public int getParent(int index) {
		if (index == 0) return -1;
		return (index - 1) / d;
	}

	public int getGParent(int index) {
		if (getLevel(index) == 1) return -1;
		int parent = getParent(index);
		return (parent - 1) / d;
	}

	public int getChildNo(int index, int childNo) {
		int i = ((d * index) + childNo);
		if (i > size) return -1; //had size - 1 here before
		return i;
	}

	public int getLevel(int index) {
		if (index == 0) return 0;
		int exp = 0;
		while (index >= 0) {
			index -= Math.pow(d, exp);
			exp++;
		}
		exp--;
		return exp;
	}

	public int getLastNonLeaf() {
		return getParent(size - 1);
	}

	public boolean isLeaf(int index) {
		int test = getChildNo(index, 1);
		if (test == -1) return true;
		return false;
	}

}
