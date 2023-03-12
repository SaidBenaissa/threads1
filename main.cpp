#include <iostream>
#include <pthread.h>
#include <ctime>
#include <iomanip>


void *thread_func(void *add);

int main() {
    long value1 = 4;
    long value2 = 4;
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL /* set attributes of thread*/, thread_func, (void*) &value1 /* pass arguments to thread_func */);
    pthread_join(thread1, NULL /* return value of thread_func */);

    pthread_create(&thread2, NULL /* set attributes of thread*/, thread_func, (void*) &value2 /* pass arguments to thread_func */);
    pthread_join(thread2, NULL /* return value of thread_func */);

    return 0;
}

void *thread_func(void *add) {
    long sum = 0;
    long *add_num = (long*) add;
    for (long i = 0; i < 1000000000; i++) {
        sum += *add_num;
    }

    // get current time
    std::time_t current_time = std::time(nullptr);

    // convert current time to struct tm
    std::tm* time_info = std::gmtime(&current_time);

    // output time in desired format
    std::cout << "Current time: "; // 2018-01-01 00:00:01
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_sec << std::endl;   //  01 // seconds

    std::cout <<  " thread: " << *add_num <<std::endl;
    // output: 2018-01-01 00:00:01 thread: 4
//            Current time: 26
//            thread1: 4
//            Current time: 27
//            thread2: 4

    return NULL;
}
