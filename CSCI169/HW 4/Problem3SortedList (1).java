
public class Problem3SortedList {
	private int n, array[];
	
	public Problem3SortedList() {
		array = new int[0];
		n=0;
	}
	
	public Problem3SortedList(int a[], int size) {
		array = a;
		n = size;
		quicksort(array, 0, size-1);
	}
	
	public void print(int[] input) {
		for(int i=0; i<input.length; i++) {
			System.out.print(input[i] + " ");
		}
		System.out.println();
	}
	
	public int binarySearch(int search) {
		int first = 0;
		int last = n-1;
		int middle = (first + last)/2;
		while(first <= last) {
			if(array[middle] < search) {
				first = middle +1;
			} else if(array[middle] == search) {
				return middle;
			} else {
				last = middle-1;
			}
			middle = (first + last)/2;
		}
		if(first > last) {
			return -1;
		}
		return 0;
	}
	
	public int partition(int[] input, int p, int r) {
		int pivot = input[r];
		while(p < r) {
			while(input[p] < pivot) {
				p++;
			}
			while(input[r] > pivot) {
				r--;
			}
			if(input[p] == input[r]) {
				p++;
			} else if(p < r) {
				int tmp = input[p];
				input[p] = input[r];
				input[r] = tmp;
			}
		}
		return r;
	}
	
	public void quicksort(int[] input, int p, int r) {
		if(p < r) {
			int j = partition(input, p, r);
			quicksort(input, p, j-1);
			quicksort(input, j+1, r);
		}
	}
	
	public int[] insertion(int v) {
		int[] result = new int[n+1];
		int key = 0;
		for(int i=0; i<n-1; i++) {
			if(v < array[i]) {
				key=i;
			}
		}
		for(int i=0; i<key; i++) {
			result[i] = array[i];
		}
		result[key] = v;
		for(int i=key+1; i<n+1; i++) {
			result[i] = array[i-1];
		}
		return result;
	}

}
