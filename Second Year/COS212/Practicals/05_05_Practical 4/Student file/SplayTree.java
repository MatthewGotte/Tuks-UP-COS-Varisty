/**
 * Name: Matthew Gotte
 * Student Number: u20734621
 */

public class SplayTree<T extends Comparable<T>> {

	protected enum SplayType {
		SPLAY,
		SEMISPLAY,
		NONE
	}	

	protected Node<T> root = null;
	
	/**
	 * Prints out all the elements in the tree
	 * @param verbose
	 *			If false, the method simply prints out the element of each node in the tree
	 *			If true, then the output provides additional detail about each of the nodes.
	 */
	public void printTree(boolean verbose) {
		String result;
		result = preorder(root, verbose);
		System.out.println(result);
	}
	
	protected String preorder(Node<T> node, boolean verbose) {
		if (node != null) {
			String result = "";
			if (verbose) {
				result += node.toString()+"\n";
			} else {
				result += node.elem.toString() + " ";
			}
			result += preorder(node.left, verbose);
			result += preorder(node.right, verbose);
			return result;
		}
		return "";
	}
	
	////// You may not change any code above this line //////

	////// Implement the functions below this line //////
	
	/**
	* Inserts the given element into the tree, but only if it is not already in the tree.
	* @param elem 
	* 		 	The element to be inserted into the tree
	* @return 
	*			Returns true if the element was successfully inserted into the tree. 
	*			Returns false if elem is already in the tree and no insertion took place.
	*
	*/
	public boolean insert(T elem) {
		if (!contains(elem)) {
			if (isEmpty()) {
				root = new Node<T>(elem);
			}
			else {
				Node<T> newNode = new Node<T>(elem);
				Node<T> nRoot= root;
				Node<T> temp = null;
				while (nRoot != null) {
					temp = nRoot;
					if (elem.compareTo(nRoot.elem) < 0) {
						nRoot = nRoot.left;
					}
					else {
						nRoot = nRoot.right;
					}
				}
				if (temp == null) {
					temp = newNode;
				}
				else if (elem.compareTo(temp.elem) < 0) {
					temp.left = newNode;
				}
				else {
					temp.right = newNode;
				}
			}
			return true;
		}
		return false;
		//Your code goes here
	}
	
	/**
	* Checks whether a given element is already in the tree.
	* @param elem 
	* 		 	The element being searched for in the tree
	* @return 
	*			Returns true if the element is already in the tree
	*			Returns false if elem is not in the tree
	*
	*/
	public boolean contains(T elem) {
		if (!isEmpty()) {
			Node<T> temp = root;
			while (temp != null) {
				if (temp.elem.equals(elem))
					return true;
				else if (temp.elem.compareTo(elem) > 0)
					temp = temp.left;
				else
					temp = temp.right;
			}
		}
		return false;
		//Your code goes here
	}

	public boolean isEmpty() {
		// Your code goes here
		return root == null;
	}
	
	/**
	 * Accesses the node containing elem. 
	 * If no such node exists, the node should be inserted into the tree.
	 * If the element is already in the tree, the tree should either be semi-splayed so that 
	 * the accessed node moves up and the prt of that node becomes the new root or be splayed 
	 * so that the accessed node becomes the new root.
	 * @param elem
	 *			The element being accessed
	 * @param type
	 *			The adjustment type (splay or semi-splay or none)
	 */
	public void access(T elem, SplayType type) {
			if (!contains(elem))
				insert(elem);
			if (type == SplayType.SPLAY) {
				if (root.elem.equals(elem))
					splay(root);
				Node<T> temp = root;
				Node<T> prt = null;
				Node<T> gprt = null;
				while (temp != null) {
					if (temp.elem.equals(elem)) {
						splay(temp);
						break;
					}
					else if (temp.elem.compareTo(elem) < 0) {
						gprt = prt;
						prt = temp;
						temp = temp.right;
					}else if (temp.elem.compareTo(elem) > 0) {
						gprt = prt;
						prt = temp;
						temp = temp.left;
					}
				}
			} else if (type == SplayType.SEMISPLAY) {
				if (root.elem.equals(elem))
					semisplay(root);
				Node<T> temp = root;
				Node<T> prt = null;
				Node<T> gprt = null;
				while (temp != null) {
					if (temp.elem.equals(elem)) {
						semisplay(temp);
						break;
					}
					else if (temp.elem.compareTo(elem) < 0) {
						gprt = prt;
						prt = temp;
						temp = temp.right;
					}else if (temp.elem.compareTo(elem) > 0) {
						gprt = prt;
						prt = temp;
						temp = temp.left;
					}
				}
			}
		}

	/**
	 * Semi-splays the tree using the prt-to-root strategy
	 * @param node
	 *			The node the prt of which will be the new root
	 */
	protected void semisplay(Node<T> node) {
		if ((node == this.root) || ((this.root.left == node || this.root.right == node)))
			return;
		if(contains(node.elem)){
			Node<T> prt = getprt(node);
			Node<T> gprt = null;
			if(checkroot(node))
				return;
			gprt = getprt(prt);
			if(gprt==null){
				if(prt.left!=null){
					if(prt.left.equals(node))
						rotateRight(node,prt,gprt);
				}
				if(prt.right!=null){
					if(prt.right.equals(node))
						rotateLeft(node,prt,gprt);
				}
			}
			if(gprt != null) {
				if (gprt.left != null && prt.left != null) {
					if ((gprt.left.equals(prt) && prt.left.equals(node))) {
						Node<T> gGprt = getprt(gprt);
						rotateRight(prt, gprt, gGprt);
						if (checkroot(prt) || checkroot(node))
							return;
						semisplay(prt);
						return;
					}
				}
				if (gprt.right != null && prt.right != null) {
					if ((gprt.right.equals(prt) && prt.right.equals(node))) {
						Node<T> gGprt = getprt(gprt);
						rotateLeft(prt, gprt, gGprt);
						if (checkroot(prt) || checkroot(node))
							return;
						semisplay(prt);
						return;
					}
				}

				if (gprt.left != null && prt.right != null) {
					if ((gprt.left.equals(prt) && prt.right.equals(node))) {
						rotateLeft(node, prt, gprt);
						Node<T> gGprt = getprt(gprt);
						rotateRight(node, gprt, gGprt);
						if (checkroot(prt) || checkroot(node))
							return;
						semisplay(node);
						return;
					}
				}
				if (gprt.right != null && prt.left != null) {
					if ((gprt.right.equals(prt) && prt.left.equals(node))) {
						rotateRight(node, prt, gprt);
						Node<T> gGprt = getprt(gprt);
						rotateLeft(node, gprt, gGprt);
						if (checkroot(prt) || checkroot(node))
							return;
						semisplay(node);
						return;
					}

				}
			}
		}
		//Your code goes here
	}

	/**
	 * Splays the tree using the node-to-root strategy
	 * @param node
	 *			The node which will be the new root
	 */
	protected void splay(Node<T> node) {
		if(contains(node.elem)){
			if(checkroot(node)){
				return;
			}
			Node<T> prt = getprt(node);
			Node<T> gp = null;
			
			if(!checkroot(prt))
				gp = getprt(prt);

			if(checkroot(prt)){
				if(prt.left.equals(node))
					rotateRight(node, prt, gp);
				else
					rotateLeft(node, prt, gp);
				if(!checkroot(node)){
					splay(node);
				}
				return;
			}
			
			if(gp != null) {
				if(gp.left!=null && prt.left!=null) {
					if ((gp.left.equals(prt) && prt.left.equals(node))) {
						Node<T> ggp = getprt(gp);
						rotateRight(prt, gp, ggp);
						gp = getprt(prt);

						rotateRight(node, prt, gp);

						if (!checkroot(node)) {
							splay(node);
						}
						return;
					}
				}
				if (gp.right != null && prt.right!=null) {
					if ((gp.right.equals(prt) && prt.right.equals(node))) {
						Node<T> ggp = getprt(gp);
						rotateLeft(prt, gp, ggp);
						gp = getprt(prt);

						rotateLeft(node, prt, gp);

						if (!checkroot(node)) {
							splay(node);
						}
						return;
					}
				}
				if(gp.left!=null && prt.right!=null) {
					if ((gp.left.equals(prt) && prt.right.equals(node))) {
						rotateLeft(node, prt, gp);
						Node<T> ggp = getprt(gp);

						rotateRight(node, gp, ggp);

						if (!checkroot(node)) {
							splay(node);
						}
						return;
					}
				}
				if(gp.right!=null && prt.left!=null) {
					if ((gp.right.equals(prt) && prt.left.equals(node))) {
						rotateRight(node, prt, gp);
						Node<T> ggp = getprt(gp);

						rotateLeft(node, gp, ggp);

						if (!checkroot(node)) {
							splay(node);
						}
						return;
					}
				}

			}
		}
		//Your code goes here
	}

	//Helper functions

	public boolean checkroot(Node<T> node){
		if(node!=null) return node.equals(root);
		else return false;
	}

	protected Node<T> getNode(T element) {
		if (!isEmpty()) {
			Node<T> temp = root;
			while (temp != null) {
				if (temp.elem.equals(element))
					return temp;
				else if (temp.elem.compareTo(element) > 0)
					temp = temp.left;
				else
					temp = temp.right;
			}
		}
		return null;
	}

	protected void rotateLeft(Node<T> node, Node<T> prt, Node<T> gp) {
		prt.right = node.left;
		node.left = prt;
		if (gp != null) {
			if(gp.left!=null) {
				if (gp.left.equals(prt)) {
					gp.left = node;
				}
			}
			if(gp.right!=null) {
				if (gp.right.equals(prt)) {
					gp.right = node;
				}
			}
			//if (gp.equals(root))
			//	root = node;
		}
		else if (prt.equals(root)) {
			root = node;
		}
	}

	protected void rotateRight(Node<T> node, Node<T> prt, Node<T> gp) {
		prt.left = node.right;
		node.right = prt;
		if(gp != null) {
			if(gp.left!=null) {
				if (gp.left.equals(prt))
					gp.left = node;
			}
			if(gp.right!=null) {
				if (gp.right.equals(prt))
					gp.right = node;
			}

		}
		else if (prt.equals(root)) {
			root = node;
		}
	}

	public Node<T> getprt(Node<T> curr) {
		if (this.root == null) return null;

		if (curr == null) return null;
		//if (!contains(curr.elem)) return null;
		if (root.left == curr || root.right == curr) {
			return root;
		}
		if (curr == root) return null;
		SplayTree<T> L = new SplayTree<T>();
		L.root = this.root.left;
		SplayTree<T> R = new SplayTree<T>();
		R.root = this.root.right;
		if (L.getprt(curr) != null)
				return L.getprt(curr);
		if (R.getprt(curr) != null)
				return R.getprt(curr);
		return null;
	}



}