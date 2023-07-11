#include<iostream>
using namespace std;

class MaxHeap
{
 	int *arr;        // pointer to array of elements in heap
    int capacity;    // maximum possible size of min heap
    int size; 
public:
	
	MaxHeap(int capacity)
    {
		arr = new int[capacity]; // create an array with size capacity
 		this->capacity = capacity;
  		this->size = 0;    //
	}
	
    int getSize()
    {
		return size;
	}
	
	int getparent(int child)
	{
		if(child%2==0)
		return (child/2)-1;
		else
		return (child/2);
	}
	
	int getleft(int parent)
	{
		return (2*parent+1);
	}
	
	int getright(int parent)
	{
		return (2*parent+2);
	}
	
    int getMax()
    {
		for(int i = 0;i<size;i++)
		{
    		cout<<arr[i]<<" ";
  		}
  		cout<<endl;
  		cout<<"max: ";
  		return arr[0];
	}
	
	bool isleaf(int i)
	{
  		if(i>=size)
     		return true;
 		return false;
	}
	
	void siftup(int i)
	{
		if(i == 0)
      		return;     //only one element in the array
		int parent_index = getparent(i);        // get the index of the parent 
		if(arr[parent_index] < arr[i])   
  		{
       		int temp = arr[parent_index];   //if value at parent index is less than inserted value
       		arr[parent_index] = arr[i];     // swap the values
       		arr[i] = temp;
       		siftup(parent_index);    // loop untill it satisfies parent child max heap relationship
  		}
	}
	
	void siftdown(int i)
	{	
    	int l = getleft(i);
    	int r = getright(i);
	    if(isleaf(l))
       		return;
    	int maxIndex = i;
    	if(arr[l] > arr[i])
    	{
    	 	maxIndex = l;
    	}
    	if(!isleaf(r) && (arr[r] > arr[maxIndex]))
    	{
     	 	maxIndex = r;
    	}
    	if(maxIndex != i)
    	{
	      	int temp = arr[i];
	      	arr[i] = arr[maxIndex];
	      	arr[maxIndex] = temp;
	     	siftdown(maxIndex);
    	}
	}
	
    void insert(int k)
    {
		arr[size] = k;   // insert the value into array
 	 	siftup(size);
  		size++;     //increment the size of the array
  		for(int i = 0;i<size;i++)
  		{
     		cout<<arr[i]<<" ";
  		}
  		cout<<endl;
	}
	
    int extractMax()
    {
		int max = arr[0];
  		arr[0] = arr[size - 1];
  		size--;
  		siftdown(0);
  		return max;
	}
	
    int removeAt(int K)
    {
		int r = arr[K];
 		arr[K] = arr[size -1];  // replace with rightmost leaf 
  		size-- ;
  		int p = getparent(K);
  		if(K == 0 || arr[K] < arr[p])
     		siftdown(K);
  		else
     		siftup(K);
  		return r;   
	}
    
	void heapify(int *array, int len)
    {	
		size = len;
		arr = array;
		for(int i=size-1; i>=0; --i)
		{
		    siftdown(i);
		}
	}
};

int main()
{
	MaxHeap h(10); 
	h.insert(31); 
	h.insert(12); 
	h.removeAt(11); 
	h.insert(19); 
	h.insert(52); 
	h.insert(46); 
//	h.insert(45); 
	cout<<"max in a heap: "<<endl;
	cout << h.extractMax() << " ";
	cout<<endl;
	cout<<"after removing maximun: "<<endl;
	cout << h.getMax() << " "; 
	return 0; 
}

