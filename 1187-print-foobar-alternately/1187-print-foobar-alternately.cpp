class FooBar {
private:
    int n;
    bool barTime; 

public:
    FooBar(int n) {
        this->n = n;
        this->barTime = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while(barTime)
                sched_yield();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            barTime = true;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while(!barTime)
                sched_yield();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            barTime = false;
        }
    }
};