

#include <iostream>

int test[] = { 1, 2, 3, 4};

void print_array(int* test, int len)
{
	for(int i=0;i<len;i++){
		std::cout<<test[i]<<' ';
	}
	std::cout<<std::endl;
}
void ordinal_number_algorithm(int* arr, int len)
{
	// calclute the n!, that n is the "len"
	int product = 1;
	for(int i=1; i<=len; i++){
		product = product * i;
	}
	// less_than saves the counter that less than less_than[i], that are at right side of arr[i];
	int* less_than = new int[len-1];
	int* tmp_array = new int[len];
	for(int i=0;i<=product-1;i++){
		int n = i;
		int r = 0;
		for(int p = 2; p<=len-1;p++){
			n = n/p;
			r = n%p;
			less_than[p-2] = r; // now less_than[i] means, how many elements right arr[i+1] ;
		}
		std::cout<<"the ordinal array is:"<<std::endl;
		print_array(less_than, len-1);
		// print this permutation
		for(int j=len-2;j>=0;j--){
			
		}
	}

}

int main()
{
	ordinal_number_algorithm(test, sizeof(test)/sizeof(test[0]));	
	return 0;
}
