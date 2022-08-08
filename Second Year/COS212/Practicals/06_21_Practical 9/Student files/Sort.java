import java.util.Arrays;

@SuppressWarnings("unchecked")
public class Sort {
	////// Implement the functions below this line //////
	/********** HEAP **********/
	public static <T extends Comparable<? super T>> void heapsort(T[] data, boolean debug) {
		// Your code here
		int first = 0;
		int last = data.length - 1;
		for (int i = data.length / 2 - 1; i >= 0; i--) {
			movedown(data, i, data.length - 1, debug);
		}
		for (int i = data.length - 1; i >= 1; i--) {
			//swap root with i:
			T temp = data[i];
			data[i] = data[0];
			data[0] = temp;
			movedown(data, 0, i - 1, debug);
		}
	}

	private static <T extends Comparable<? super T>> void movedown(T[] data, int first, int last, boolean debug) {
		// Your code here
		int largest = 2*first + 1;
		while (largest <= last) {
			if (largest < last && ((Comparable)data[largest]).compareTo(data[largest+1]) < 0)
				largest++;
			if (((Comparable)data[first]).compareTo(data[largest]) < 0) {
				//swap(data,first,largest);
				T temp = data[first];
				data[first] = data[largest];
				data[largest] = temp;

				first = largest;
				largest = 2*first + 1;
			}
			else largest = last + 1;
		}
//		// DO NOT MOVE OR REMOVE!
		if (debug)
			System.out.println(Arrays.toString(data));
	}

	private static <T extends Comparable<? super T>> boolean not_is_leaf(int last, int pos) {
		int temp = ( 2 * pos ) + 1;
		return temp <= last;
	}

	/********** MERGE **********/
	public static <T extends Comparable<? super T>> void mergesort(T[] data, int first, int last, boolean debug) {
		// Your code here
		if (first < last) {
			int midpnt = (first + last) / 2;
			mergesort(data, first, midpnt, debug);
			mergesort(data, midpnt + 1, last, debug);
			merge(data, first, last, debug);
		}
	}

	private static <T extends Comparable<? super T>> void merge(T[] data, int first, int last, boolean debug) {
		// Your code here
//		int mid = (first + last) / 2;
//
//		int left = mid - first + 1;
//		int right = last - mid;
//
//		T[] right_array = (T[]) new Comparable[right];
//		T[] left_array = (T[]) new Comparable[left];
//
//		for (int i = 0; i < right; i++) {
//			right_array[i] = data[mid + 1 + i];
//		}
//
//		for (int i = 0; i < left; i++) {
//			left_array[i] = data[first + i];
//		}
//
//		int i = 0, j = 0, p = first;
//
//		while ((j < right) && (i < left)) {
//			if (!(left_array[i].compareTo(right_array[j]) <= 0)) {
//				data[p] = right_array[j];
//				j++;
//			} else {
//				data[p] = left_array[i];
//				i++;
//			}
//			p++;
//		}
//
//		while (j < right) {
//			data[p] = right_array[j];
//			j++;
//			p++;
//		}
//
//		while (i < left) {
//			data[p] = left_array[i];
//			i++;
//			p++;
//		}

		int mid = (first + last) / 2;
		int ione = 0;
		int itwo = first;
		int ithree = mid + 1;

		Comparable [] temp = new Comparable[last - first + 1]; //length

		while ((itwo <= mid) && (ithree <= last)) {
			if (data[itwo].compareTo(data[ithree]) < 0)
				temp[ione++] = data[itwo++];
			else
				temp[ione++] = data[ithree++];
		}

		while (itwo <= mid)
			temp[ione++] = data[itwo++];
		while (ithree <= last)
			temp[ione++] = data[ithree++];

		for (int i = first, j = 0; i <= last; i++, j++)
			data[i] = (T) temp[j];

		// DO NOT MOVE OR REMOVE!
		if (debug)
			System.out.println(Arrays.toString(data));
	}
}