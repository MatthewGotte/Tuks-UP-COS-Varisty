@SuppressWarnings("unchecked")
public class BST<T extends Comparable<? super T>> {

	protected BSTNode<T> root = null;

	public BST() {
	}

	public void clear() {
		root = null;
	}

	// returns a verbose inorder string of the BST
	public String inorder(BSTNode<T> node) {
		boolean verbose = true;
		if (node != null) {
			String result = "";
			result += inorder(node.left);
			if (verbose) {
				result += node.toString() + "\n";
			} else {
				result += node.element.toString() + " ";
			}
			result += inorder(node.right);
			return result;
		}
		return "";
	}

	////// You may not change any code above this line //////

	////// Implement the functions below this line //////

	public boolean isEmpty() {
		// Your code goes here
		return root == null;
	}

	public BSTNode<T> clone() {
		// Your code goes here
		return cloneTree(this.root);
	}

	public BSTNode<T> cloneTree(BSTNode<T> root) {
		if (root == null) return null;
		BSTNode<T> newNode = new BSTNode<T>(root.element);
		newNode.left = cloneTree(root.left);
		newNode.right = cloneTree(root.right);
		return newNode;
	}

	BSTNode<T> mirrorTree(BSTNode<T> root) {
		if (root == null) return null;
		BSTNode<T> newNode = new BSTNode<T>(root.element);
		newNode.right = mirrorTree(root.left);
		newNode.left = mirrorTree(root.right);
		return newNode;
	}

	public BSTNode<T> mirror() {
		// Your code goes here
		return mirrorTree(this.root);
	}

	public void insert(T element) {
		// Your code goes here
		if (search(element) == null) {
			if (isEmpty()) {
				root = new BSTNode<T>(element);
			}
			else {
				BSTNode<T> newNode = new BSTNode<T>(element);
				BSTNode<T> nRoot= root;
				BSTNode<T> temp = null;
				while (nRoot != null) {
					temp = nRoot;
					if (element.compareTo(nRoot.element) < 0) {
						nRoot = nRoot.left;
					}
					else {
						nRoot = nRoot.right;
					}
				}
				if (temp == null) {
					temp = newNode;
				}
				else if (element.compareTo(temp.element) < 0) {
					temp.left = newNode;
				}
				else {
					temp.right = newNode;
				}
			}
		}
	}

	public boolean deleteByMerge(T element) {
		// Your code goes here
		BSTNode<T> temp, node, nRoot = root, prev = null;
		while (nRoot != null && !nRoot.element.equals(element)) {
			prev = nRoot;
			if (nRoot.element.compareTo(element) < 0)
				nRoot = nRoot.right;
			else nRoot = nRoot.left;
		}

		node = nRoot;

		if (nRoot != null && nRoot.element.equals(element)) {
			if (node.right == null)
				node = node.left;
			else if (node.left == null)
				node = node.right;
			else {
				temp = node.left;
				while (temp.right != null)
					temp = temp.right;
				temp.right = node.right;
				node = node.left;
			}
			if (nRoot == root)
				root = node;
			else if (prev.left == nRoot)
				prev.left = node;
			else prev.right = node; // 5.
		}
		else if (root != null) {
			return false;
		}
		else {
			return false;
		}
		return true;
	}

	public boolean deleteByCopy(T element) {
		// Your code goes here
		BSTNode<T> node, nRoot = root, prev = null;
		while (nRoot != null && !nRoot.element.equals(element)) {
			prev = nRoot;
			if (nRoot.element.compareTo(element) < 0)
				nRoot = nRoot.right;
			else nRoot = nRoot.left;
		}

		node = nRoot;

		if (nRoot != null && nRoot.element.equals(element)) {
			if (node.right == null)
				node = node.left;
			else if (node.left == null)
				node = node.right;
			else {
				BSTNode<T> temp = node.left;
				BSTNode<T> previous = node;
				while (temp.right != null) {
					previous = temp;
					temp = temp.right;
				}
				node.element = temp.element;
				if (previous == node)
					previous.left  = temp.left;
				else previous.right = temp.left;
			}
			if (nRoot == root)
				root = node;
			else if (prev.left == nRoot)
				prev.left = node;
			else prev.right = node;
		}
		else if (root != null) {
			return false;
		}
		else {

			return false;
		}
		return true;
	}

	public T search(T element) {
		// Your code goes here
		if (!isEmpty()) {
			BSTNode<T> temp = root;
			while (temp != null) {
				if (temp.element.equals(element))
					return element;
				else if (temp.element.compareTo(element) > 0)
					temp = temp.left;
				else
					temp = temp.right;
			}
		}
		return null;
	}

	public T getPredecessor(T element) {
		// Your code goes here
		if (isEmpty())
			return null;

		BSTNode<T> pred = null;
		BSTNode<T> prt = root;
		while (true) {
			if (element.compareTo(prt.element) < 0)
				prt = prt.left;
			else if (element.compareTo(prt.element) > 0) {
				pred = prt;
				prt = prt.right;
			} else {
				if (prt.left != null) {
					pred = last(prt.left);
				}
				break;
			}
			if (prt == null)
				return null;
		}
		if (pred != null) {
			return pred.element;
		}
		return null;
	}

	public BSTNode<T> last(BSTNode<T> root) {
		while (root.right != null)
			root = root.right;
		return root;
	}

	private BSTNode<T> min(BSTNode<T> root)
	{
		while (root.left != null) {
			root = root.left;
		}
		return root;
	}

	private T succ(BSTNode<T> root, BSTNode<T> succ, T element) {
		if (isEmpty())
			return null;
		
		if (root.element.equals(element)) {
			if (root.right != null)
				return min(root.right).element;
		} else if (element.compareTo(root.element) > 0) {
			return succ(root.right, succ, element);
		} else {
			succ = root;
			return succ(root.left, succ, element);
		}
		if (succ != null)
			return succ.element;
		else
			return null;
	}

	public T getSuccessor(T element) {
		return succ(root, null, element);
	}
}