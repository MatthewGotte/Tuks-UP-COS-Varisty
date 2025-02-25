public class Main {

	//Some helper functions to help you test

	public static void searchElement(BST<Integer> tree, Integer element) {
		if (tree.isEmpty())
			System.out.println("Tree is empty");
		else {
			Integer result = tree.search(element);
			if (result != null)
				System.out.println("Found element " + result);
			else
				System.out.println("Element " + element + " not found");
		}
	}

	public static void deleteElement(BST<Integer> tree, Integer element, String type) {
		if (tree.isEmpty())
			System.out.println("Tree is empty");
		else {
			boolean result = false;
			if (type.trim().equals("m"))
				result = tree.deleteByMerge(element);
			else if (type.equals("c"))
				result = tree.deleteByCopy(element);

			if (result)
				System.out.println("Deleted element " + element);
			else
				System.out.println("Element " + element + " not found for deletion");
		}
	}

	public static void printTree(BST<Integer> tree) {
		String result;
		System.out.println("Binary Search Tree Content:");
		result = tree.inorder(tree.root);
		System.out.println(result);
	}

	public static void main(String[] args) {
		// Practical 3 - Some code to help you test (by no means exhaustive)

	BST<Integer> x = new BST<Integer>();
	printTree(x);
	x.insert(10);
	x.insert(5);
	printTree(x);
	x.mirror();
	printTree(x);

		/* Expected Output:

		Tree is empty: true
		Binary Search Tree Content:
		5 [L: null]  [R: null]
		8 [L: 5]  [R: 12]
		12 [L: null]  [R: 16]
		13 [L: null]  [R: null]
		16 [L: 13]  [R: null]

		Binary Search Tree Content:
		16 [L: null]  [R: 13]
		13 [L: null]  [R: null]
		12 [L: 16]  [R: null]
		8 [L: 12]  [R: 5]
		5 [L: null]  [R: null]

		Element 10 not found
		Found element 10

		Tree before deletion:
		Binary Search Tree Content:
		3 [L: null]  [R: null]
		5 [L: 3]  [R: 7]
		7 [L: null]  [R: null]
		8 [L: 5]  [R: 12]
		10 [L: null]  [R: null]
		12 [L: 10]  [R: 16]
		13 [L: null]  [R: 14]
		14 [L: null]  [R: null]
		16 [L: 13]  [R: null]

		Deleted element 8
		Binary Search Tree Content:
		3 [L: null]  [R: null]
		5 [L: 3]  [R: 7]
		7 [L: null]  [R: 12]
		10 [L: null]  [R: null]
		12 [L: 10]  [R: 16]
		13 [L: null]  [R: 14]
		14 [L: null]  [R: null]
		16 [L: 13]  [R: null]

		Deleted element 8
		Binary Search Tree Content:
		3 [L: null]  [R: null]
		5 [L: 3]  [R: null]
		7 [L: 5]  [R: 12]
		10 [L: null]  [R: null]
		12 [L: 10]  [R: 16]
		13 [L: null]  [R: 14]
		14 [L: null]  [R: null]
		16 [L: 13]  [R: null]

		Predecessor of 7: 5
		Predecessor of 16: 14
		Successor of 7: 10
		Successor of 16: null

		*/

	}
}