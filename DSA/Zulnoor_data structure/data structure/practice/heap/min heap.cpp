#include<iostream> 
#include<climits> 
using namespace std; 

class MinHeap 
{ 
	int *arr; 
	int capacity;  
	int hsize; 
public:  
	MinHeap(int cap) 
	{ 
		hsize = 0; 
		capacity = cap; 
		arr = new int[cap]; 
	} 

	void MinHeapify(int i)
	{ 
		int l = left(i); 
		int r = right(i); 
		int smallest = i; 
		if (l < hsize && arr[l] < arr[i]) 
			smallest = l; 
		if (r < hsize && arr[r] < arr[i]) 
			smallest = r; 
		if (smallest != i) 
		{ 
			swap(&arr[i], &arr[smallest]); 
			MinHeapify(smallest); 
		} 
	} 

	int parent(int i)
	{ 
		return (i-1)/2; 
	} 

	int left(int i) 
	{ 	
		return (2*i + 1); 
	} 

	int right(int i)
	{
		return (2*i + 2); 
	} 

	int extractMin()
	{ 
		if (hsize <= 0) 
			return INT_MAX; 
		if (hsize == 1) 
		{ 
			hsize--; 
			return arr[0]; 
		} 
	
		int root = arr[0]; 
		arr[0] = arr[hsize-1]; 
		hsize--; 
		MinHeapify(0); 
	
		return root; 
	}

	void decreaseKey(int i, int new_val)
	{ 
		arr[i] = new_val; 
		while (i != 0 && arr[parent(i)] > arr[i]) 
		{ 
			swap(&arr[i], &arr[parent(i)]); 
			i = parent(i); 
		} 
	}  

	int getMin() 
	{
		return arr[0]; 
	} 

	void deleteKey(int i)
	{ 
		decreaseKey(i, 0); 
		extractMin(); 
	} 

	void swap(int *x, int *y) 
	{ 
		int temp = *x; 
		*x = *y; 
		*y = temp; 
	} 

	void insert(int k)
	{ 
		if (hsize == capacity) 
		{ 
			cout << "\nOverflow: Could not insert\n"; 
			return; 
		} 
	
		hsize++; 
		int i = hsize - 1; 
		arr[i] = k; 
	
		while (i != 0 && arr[parent(i)] > arr[i]) 
		{ 
		swap(&arr[i], &arr[parent(i)]); 
		i = parent(i); 
		} 
	}  
	void display()
	{
		for(int i=0;i<hsize;i++)
		{
			if(arr[i]==0)
				continue;	
			else	
				cout<<arr[i]<<" ";			
		}
			
		cout<<endl; 	
	}
}; 
 
int main() 
{ 
	MinHeap h(10); 
	h.insert(31); 
	h.insert(12); 
	h.insert(19); 
	h.insert(52); 
	h.insert(46); 
	h.insert(45); 
	h.display();
	h.deleteKey(11); 
	h.display();
	cout << h.extractMin() << " "; 
	cout << h.getMin() << " "; 
	h.decreaseKey(3, 17); 
	cout << h.getMin();
	cout<<endl;
	h.display(); 
	return 0; 
} 

