#include <iostream>

using namespace std;
int main()
{
	int *array, n, min = 9999999, min_index = 0, max = 0,max_index=0,sum=0,temp_sum=0;
	cin >> n;
	array = new int[n];
	int *sum_array =new int [n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	// cout<<endl<<endl;
	// for (int i = 0; i < n; i++) //Arranges the array in descending order
	// {
		// int temp = 0;
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		if (array[i] > array[j])
	// 		{
	// 			temp = array[i];
	// 			array[i] = array[j];
	// 			array[j] = temp;
	// 		}
	// 	}
	// }
	//		for(int i=0;i<n;i++)
	//	{
	//		cout<<array[i]<<" ";
	//	}
	// for (int i = 0; i < n; i++) 		//sums and compares the array
	// {
		//		cout<<"this ran\n";
		// if(array[i]>n){
			
		// cout<<sum<<endl;
		// cout<<"index "<<i<<" is +ve"<<endl;
		// // if (temp_sum > sum)
		// // {
		// // 	break;
		// // }
		// // temp_sum = sum;
		// // index = i + 1;
		
		// }
		// else
		// {
		// 	cout<<"index "<<i<<" is -ve"<<endl;
		// }
		
	// }
	for (int i = 0; i < n; i++)
	{
		sum+=array[i];
		sum_array[i]=sum;



	}
	cout<<"The value of the sum array is\n";
	for (int  i = 0; i<n; i++)
	{
		cout<<sum_array[i]<<" ";
	}
	
	
	// cout<<"Max element is "<<max<<"  and it index is "<<max_index+1<<".\n";
	//	cout<<"The index is "<<index<<endl;
	//	cout<<"The array is \n";
	// for (int i = 0; i < index; i++)
	// 	cout << array[i] << " ";
	// 	cout << endl
	// 	 << temp_sum;
	return 0; // always return 0 from here
}

//;C:\Users\k200183\AppData\Local\Programs\Microsoft VS Code\bin