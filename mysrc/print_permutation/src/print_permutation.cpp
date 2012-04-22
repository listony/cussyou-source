

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
		r = n%2;
		less_than[0] = r; // now less_than[i] means, how many elements right arr[i+1] ;
		for(int p = 2; p<=len-1;p++){
			n = n/p;
			r = n%(p+1);
			less_than[p-1] = r; // now less_than[i] means, how many elements right arr[i+1] ;
		}
		std::cout<<"the ordinal array is:";
		print_array(less_than, len-1);
		// init the tmp_array;
		for(int j = 0; j<len; j++){
			tmp_array[j] = arr[0];
		};
		for(int j=len-1;j>=1;j--){
			int p = len-1;
			int counter = less_than[j-1] ;
			while(counter>0){
				if(
			}
		}
		// print this permutation
		std::cout<<"this permutation is:"<<std::endl;
		print_array(tmp_array,len);
	}

}

int main()
{
	ordinal_number_algorithm(test, sizeof(test)/sizeof(test[0]));	
	return 0;
}
