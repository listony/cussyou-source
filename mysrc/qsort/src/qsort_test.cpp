
#include <iostream>
#include <iomanip>

void print_arr(int* arr, int start, int end)
{
	const int number_width = 5;
	for(int i = 0; i < start; i++){
		std::cout<<std::setw(number_width)<<'-'<<' ';
	}
	for(int i = start; i < end; i++){
		std::cout<<std::setw(number_width)<<arr[i]<<' ';
	}
	std::cout<<std::endl;
}
// return the index, where the arr is parted.
// meanwhile, the arr[return] will be set to a 
int mypart(int* arr, int start, int end)
{
	int counter = 0; // the counter that how many number less than 'value'
	int value = arr[end-1];
	for(int i = start; i < end-1; i++){
		if(arr[i] < value){ // 
			// exchange
			int tmp = arr[start+counter] ;
			arr[start+counter] = arr[i] ;
			arr[i] = tmp;
			counter++;
			//print_arr(arr,start,i+1);
		}
	}
	// after above,
	// from arr[start] .. arr[start+counter-1] are less than "value"
	// and, arr[start+counter] .. arr[end-1] are greater than "value" 
	arr[end-1] = arr[start+counter];
	arr[start+counter] = value;
	return start+counter;
}

void myqsort(int* arr, int start, int end)
{
	if(start >= end-1){
		return ;
	}
	std::cout<<"qsort the array: "<<std::endl;
	print_arr(arr,start,end);
	int q = mypart(arr,start,end);
	std::cout<<"after mypart("<<start<<","<<end<<")"<<std::endl;
	print_arr(arr,start,end);
	myqsort(arr,start,q);
	myqsort(arr,q+1,end);
}

int test1[] = {
	1,3,7,12,18,5,7,4,20
};
int test2[] = {
	30,20,25,16,8,4,5
};
int main()
{
	myqsort(test1,0,sizeof(test1)/sizeof(test1[0]));
	std::cout<<"the result:"<<std::endl;
	print_arr(test1,0,sizeof(test1)/sizeof(test1[0]));
	return 0;
}