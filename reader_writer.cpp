#include<iostream>
#include<mutex>

using namespace std;

struct semaphore{
    public:
        int mutex = 1;
        int rcount = 0;
        int rwait = 0;
        bool wrt = 0;
};

void addReader(struct semaphore *s)
{
    if(s->mutex == 0 && s->rcount == 0)
    {
        cout << "File open in read mode" << endl;
        cout << "Reader added in the read queue" << endl;
        s->rwait++;
    }
    else
    {
        cout << "Reader process added" << endl;
        s->mutex--;
        s->rcount++;
    }
    return;
}

void addWriter(struct semaphore*s)
{
    if(s->mutex == 1)
    {
        s->mutex--;
        s->wrt = 1;
        cout << "Writer process added" << endl;
    }
    else if(s->wrt == 1)
    {
        cout << "Writer process already operational" << endl;
    }
    else
    {
        cout << "File open in read mode" << endl;
    }
    return;
}

void removeReader(struct semaphore*s)
{
    if(s->rcount == 0)
    {
        cout << "No reader process present" << endl;
    }
    else
    {
        cout << "Reader process removed" << endl;
        s->mutex++;
        s->rcount--;
    }
    return;
}

void removeWriter(struct semaphore*s)
{
    if(s->wrt == 0)
    {
        cout << "No writer process present" << endl;
    }
    else
    {
        cout << "Writer process removed" << endl;
        s->mutex++;
        s->wrt = 0;
        if(s->rwait != 0)
        {
            s->mutex = s->rwait;
            s->rcount = s->rwait;
            s->rwait = 0;
            cout << "Reader process in the read queue are : " << s->rcount << endl;
        }
    }
    return;
}

int main()
{
    struct semaphore s1;
    int ch;
    do{
        cout << "\n1. Add reader" << endl;
        cout << "2. Add writer" << endl;
        cout << "3. Remove reader" << endl;
        cout << "4. Remove writer" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter Choice" << endl;
        cin >> ch;
        switch(ch)
        {
            case 1:
                addReader(&s1);
                break;
            case 2:
                addWriter(&s1);
                break;
            case 3:
                removeReader(&s1);
                break;
            case 4:
                removeWriter(&s1);
                break;
            case 5:
                cout << "Exiting Program" << endl;
                
        }
    } while (ch != 5);
    return 0;
}