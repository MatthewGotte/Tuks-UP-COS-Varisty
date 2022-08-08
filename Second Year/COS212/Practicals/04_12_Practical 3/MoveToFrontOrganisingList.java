/**
 * Name: Matthew Gotte
 * Student Number: 20734621
 */

public class MoveToFrontOrganisingList extends OrganisingList {

    ////// Implement the function below this line //////

    /**
     * Retrieve the node with the specified key and move the accessed node
     * to the front, then recalculate all data fields.
     * @return The node with its data value before it has been moved to the front,
     * otherwise 'null' if the key does not exist.
     */
    @Override
    public ListNode searchNode(Integer key) {

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
                    temp.next = root;
                    root = temp;
                }
                ListNode output = new ListNode(key);
                output.data = temp.data;
                calculateData();
                return output;
            }
        }
        return null;
    }


}