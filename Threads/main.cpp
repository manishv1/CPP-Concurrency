#include <iostream>
#include<thread>

using namespace std;

#define FB std::cout << "[.....FUNCTION BEGIN]--->" <<  __FUNCTION__<< "()"<<"   LINE #...."<<__LINE__<<"       In File {"<<__FILE__<<"}"<<std::endl<<std::endl<<std::endl;
#define FE std::cout<<std::endl<< "[.....FUNCTION END]---->  " <<  __FUNCTION__<< "()"<<"In File {"<<__FILE__<<"}"<<std::endl<<std::endl<<std::endl;



// Various method to launch threads in C++  



// Method 1 --> you can pass function name directly to thread constructor i
void foo()
{
    FB 
    std::cout << "[Thread-id ]"<< std::this_thread::get_id() << std::endl;
    FE
}




// Method 2 --> you need to create a callable class and pass object of that class to the constructor of the thread constructor 

class callable_function    // class with "()" function overloaded is called the  "callable function class "
{

    public:

        callable_function operator()() 
        {
            FB
            std::cout <<"[Thread-id ]"<< std::this_thread::get_id() << std::endl;
            FE
            return *this;

        }

};



// Method 3 -->  You can use labmda operator 




int main()
{

    thread t1(foo);

    callable_function cb;   // Method 1-->  Function name passed 
    thread t2(cb);          // Method 2 --> callable object 
    thread t3([]() {

                FB 
        });

    // before join you should check that thread is joinable or not, one thread is joinable once in its lifetime 

    if(t1.joinable())
    {
        std::cout << "t1 thread id joinable \n" << std::endl;
        t1.join();         
    }
    else {

        std::cout << "t1 thread is not joinable " << std::endl;
    }


    t2.join();  // not checking for the join conditon directly calling join() function 
    t3.join();

    return 1; 
}