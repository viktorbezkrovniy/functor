#include <algorithm>
#include <iostream>
#include <omp.h>

class EvenOddFunctor {
    int even_;
    int odd_;
public:
    EvenOddFunctor() : even_(0), odd_(0) {}
    void operator()(int x) {
        if (x%2 == 0) even_ += x;
        else odd_ += x;
    }
    int even_sum() const { return even_; }
    int odd_sum() const { return odd_; }
};

int main() {
   /* EvenOddFunctor evenodd;
    
    int my_list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    evenodd = std::for_each(my_list,
                  my_list+sizeof(my_list)/sizeof(my_list[0]),
                  evenodd);*/

#pragma omp parallel
	{
		int i,n;
		i = omp_get_thread_num();
		n = omp_get_num_threads();
		printf("I'm thread %d of %d\n",i,n);

		
		
	}
#pragma omp parallel for
	{
		for(int i = 0; i < 10000; i++)
			printf("%d",i);
	}
	/*
	int i;
	pragma omp parallel section private(i)
	{
		#prgma omp section
		  //code
		#prgma omp section
		  //code
	}

    /*std::cout << "even " << evenodd.even_sum() << "\n";
    std::cout << "odd " << evenodd.odd_sum() << std::endl;

    // вывод:
    // Сумма чётных: 30
    // Сумма нечётных: 25*/

	return 0;
}