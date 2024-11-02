// Source
//https://www.udemy.com/course/cplusplus-multithreading/learn/lecture/21641164#overview

#include <iostream>
#include<thread>
#include<chrono>

using namespace std;


#define FB std::cout << "[.....FUNCTION BEGIN]--->" <<  __FUNCTION__<< "()"<<"   LINE #...."<<__LINE__<<"       In File {"<<__FILE__<<"}"<<std::endl<<std::endl<<std::endl;
#define FE std::cout<<std::endl<< "[.....FUNCTION END]---->  " <<  __FUNCTION__<< "()"<<"In File {"<<__FILE__<<"}"<<std::endl<<std::endl<<std::endl;



//  foo function to hold the execution of main thread you can pass function name directly to thread constructor 
void foo()
{
    std::cout << "[Functio]" << __FILE__<<"\t\t"<< __FUNCTION__<< "\t\t[Thread-id ]"<< std::this_thread::get_id() << std::endl;
    for (int  i = 0;  i < 5; ++i)
    {
        this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Inside " << __FUNCTION__<<std::endl;
    }     
}

// 
void bar()
{
    std::cout << "[Function]" << __FILE__<<"\t\t"<< __FUNCTION__<< "\t\t[Thread-id ]"<< std::this_thread::get_id() << std::endl;
    for (int  i = 0;  i < 5; ++i)
    {
        this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Inside " << __FUNCTION__<<std::endl;
    }
 
}

// join() --> is used at two different places notice the difference 
// join() --> at Place 1 --> hold execution of main thread 
// join() --> at Place 2 --> Being last statement hold main thtread till "t1" completes 
int  main()
{
    thread t1(foo);
    thread t2(bar);
    t2.detach();
   // t1.join();  //  Place --> 1 main thread is halted at "join" statement till "t1" thread is finished 
    for (int  i = 0;  i < 5; ++i)
    {
        std::cout << "Inside " << __FUNCTION__<<std::endl;
    }
    t1.join();  //  main thread is halted at "join" statement till "t1" thread is finished 
    return 1;
}
