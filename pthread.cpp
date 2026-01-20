#include <pthread.h>
#include <iostream>
#include <unistd.h>
using namespace std;
struct T{
	int age;
	int num;
};
void* func(void* arg) {
    for(int i = 0; i < 5; i++) {
        cout << "i =" << i << endl;
    }
    cout << "id = " << pthread_self() << endl;
    T* ptr = (T*) arg;
    ptr->age = 34;
    ptr->num = 14;
    pthread_exit(ptr);

    return NULL;
}
int main() {
    T t;
    pthread_t tid;
    pthread_create(&tid, NULL, func, &t);
    cout << "master id = " << pthread_self() << endl;
    cout << "age = " << t.age << "num = " << t.num;

}
