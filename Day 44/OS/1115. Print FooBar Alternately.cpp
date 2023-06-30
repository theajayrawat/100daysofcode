// Link: https://leetcode.com/problems/print-foobar-alternately/

class FooBar
{
private:
    int n;
    mutex m;
    condition_variable cv;
    bool turn;

public:
    FooBar(int n)
    {
        this->n = n;
        turn = false;
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {

            // printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lock(m);
            while (turn)
            {
                cv.wait(lock);
            }
            printFoo();
            turn = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {

            // printBar() outputs "bar". Do not change or remove this line.
            unique_lock<mutex> lock(m);
            while (!turn)
            {
                cv.wait(lock);
            }
            printBar();
            turn = false;
            cv.notify_all();
        }
    }
};