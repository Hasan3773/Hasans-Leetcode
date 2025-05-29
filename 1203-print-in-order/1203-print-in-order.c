typedef struct {
    // User defined data may be declared here.
    volatile int turn; // for mutex
} Foo;

// Function Declaration, do not remove
void printFirst();
void printSecond();
void printThird();

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    obj->turn = 1;
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj->turn += 1;
}

void second(Foo* obj) {
    while(obj->turn != 2)
        sched_yield();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    obj->turn += 1;
}

void third(Foo* obj) {
    while(obj->turn != 3)
        sched_yield();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj);
}