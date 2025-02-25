/**
 * Name: Matthew Gotte
 * Student Number: 20734621
 */

abstract class OrganisingList {

    public ListNode root = null;

    public OrganisingList() {

    }
    
    /**
     * Calculate the data field of all nodes in the list using the recursive functions.
     */
    public void calculateData() {
        if (root != null) {
            dataRec(root);
        }
    }

    ////// You may not change any code above this line //////

    ////// Implement the functions below this line //////

    
    //Recursive functions

    /**
     * Calculate the sum of keys recursively, starting with the given node until the end of the list
     * @return The sum of keys from the current node to the last node in the list
     * NOTE: 'int' and not 'Integer' here because it cannot return 'null'
     */
    public static int sumRec(ListNode node) {

        //Your code goes here
        int temp = 0;
        if (node.next == null) {
            temp = node.key;
        }
        else {
            temp = sumRec(node.next) + node.key;
        }
        return temp;

    }

    /**
     * Calculate and set the data for the given node.
     * @return The calculated data for the given node
     * NOTE: 'int' and not 'Integer' here because it cannot return 'null'
     */
    public static int dataRec(ListNode node) {

        //Your code goes here
        int temp = 0;
        if (node.next == null) {
            temp = node.key;
        }
        else {
            temp = (node.key * sumRec(node) - dataRec(node.next));
        }
        node.data = temp;
        return node.data;

    }


    //Organising List functions

    /**
     * Retrieve the node with the specified key, move the node as required and recalculate all data fields.
     * @return The node with its data value before it has been moved, otherwise 'null' if the key does not exist.
     * Implement only in specific subclass!
     */
    public abstract ListNode searchNode(Integer key);

    /**
     * Check if a key is contained in the list
     * @return true if the key is in the list, otherwise false
     */
    public boolean contains(Integer key) {

        ListNode temp = root;
        while (temp != null) {
            if (temp.key.equals(key)) {
                return true;
            }
            else {
                temp = temp.next;
            }
        }
        return false;
    }

    /**
     * Insert a new key into the linked list.
     * New nodes should be inserted at the back.
     * calculateData() should be called after insertion.
     * Duplicate keys should not be added.
     */
    public void insert(Integer key) {

        //Your code goes here
        if (!contains(key)) {
            ListNode newNode = new ListNode(key);
            if (root != null) {
                ListNode temp = root;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = newNode;
            }
            else {
                root = newNode;
            }
            calculateData();
        }

    }
	
    /**
     * Delete the node with the given key.
     * calculateData() should be called after deletion.
     * If the key does not exist, do nothing.
     */
    public void delete(Integer key) {

        //Your code goes here
        if (contains(key)) {
            if (root != null) {
                ListNode temp = root;
                ListNode prev = null;
                while (!temp.key.equals(key)) {
                    prev = temp;
                    temp = temp.next;
                }
                if (temp != root) {
                    prev.next = temp.next;
                    temp.next = null;
                }
                else {
                    root = temp.next;
                }
            }
        }
        calculateData();

    }


    //Helper functions

    


}