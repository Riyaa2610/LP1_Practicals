#include<iostream>
using namespace std;

void firstfit(int process[],int block[],int m,int n)
{
    int allocate[m];
    for (int i = 0; i < m;i++)
    {
        allocate[i] = -1;
    }
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < n;j++)
        {
            if(block[j]>=process[i])
            {
                allocate[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    cout << "First Fit" << endl;
    cout << "ProcessNo. ProcessSize BlockNo" << endl;
    for (int i = 0; i < m;i++)
    {
        cout << " " << i + 1 << "\t\t" << process[i] << "\t";
        if(allocate[i]!=-1)
        {
            cout << allocate[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

void bestfit(int process[],int block[],int m,int n)
{
    int allocate[m];
    for (int i = 0; i < m;i++)
    {
        allocate[i] = -1;
    }

    for (int i = 0; i < m;i++)
    {
        int bestindex = -1;
        for (int j = 0; j < n;j++)
        {
            if(block[j]>=process[i])
            {
                if(bestindex==-1)
                {
                    bestindex = j;
                }
                else if(block[bestindex] > block[j])
                {
                    bestindex = j;
                }
            }
        }
        if(bestindex!=-1)
        {
            allocate[i] = bestindex;
            block[bestindex] -= process[i];
        }
    }

    cout << "Best fit" << endl;
    cout << "ProcessNo ProcessSize BlockNo" << endl;
    for (int i = 0; i < m;i++)
    {
        cout << " " << i + 1 << "\t\t" << process[i] << "\t";
        if(allocate[i]!=-1)
        {
            cout << allocate[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

void worstfit(int process[],int block[],int m,int n)
{
    int allocate[m];
    for (int i = 0; i < m;i++)
    {
        allocate[i] = -1;
    }

    for (int i = 0; i < m;i++)
    {
        int worstindex = -1;
        for (int j = 0; j < n;j++)
        {
            if(block[j]>=process[i])
            {
                if(worstindex==-1)
                {
                    worstindex = j;
                }
                else if(block[worstindex] < block[i])
                {
                    worstindex = j;
                }
            }
        }
        if(worstindex!=-1)
        {
            allocate[i] = worstindex;
            block[worstindex] -= process[i];
        }
    }

    cout << "worst fit" << endl;
    cout << "ProcessNo ProcessSize BlockNo" << endl;
    for (int i = 0; i < m;i++)
    {
        cout << " " << i + 1 << "\t\t" << process[i] << "\t";
        if(allocate[i]!=-1)
        {
            cout << allocate[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

void nextfit(int process[],int block[],int m,int n)
{
    int allocate[m];
    int j = 0;
    int t = n - 1;

    for (int i = 0; i < m;i++)
    {
        while(j<n)
        {
            if(block[j]>=process[i])
            {
                allocate[i] = j;
                block[j] -= process[i];

                t = (j - 1) % n;
                break;
            }
            if(t == j)
            {
                t = (j - 1) % n;
                break;
            }

            j = (j + 1) % n;
        }
    }

    cout << "next fit" << endl;
    cout << "ProcessNo ProcessSize BlockNo" << endl;
    for (int i = 0; i < m;i++)
    {
        cout << " " << i + 1 << "\t\t" << process[i] << "\t";
        if(allocate[i]!=-1)
        {
            cout << allocate[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

int main()
{
    cout << "executing memory management" << endl;
    int m, n;
    
    cout << "enter total processes: " << endl;
    cin >> m;
    cout << "enter total blocks" << endl;
    cin >> n;
    int process[m];
    int block[n];
    
    int y = sizeof(process) / sizeof(process[0]);
    int z = sizeof(block) / sizeof(block[0]);

    
    cout << "\nenter process sizes: " << endl;
    for (int i = 0; i < m;i++)
    {
        cin >> process[i];
    }
     for (int i = 0; i < m;i++)
    {
        cout<< process[i]<<" ";
    }

    cout << "\nenter block size: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> block[i];
    }
     for (int i = 0; i < n;i++)
    {
        cout<<block[i]<<" ";
    }
    int ch;
    cout << "\nEnter choice: ";
    cin >> ch;
    cout << "\nMenu";
    cout << "1. First Fit" << endl;
    cout << "2. Best Fit" << endl;
    cout << "3. Worst Fit" << endl;
    cout << "4. Next Fit" << endl;
    cout << "5. Exit Programe" << endl;
    while(1)
    {
    if(ch==1)
    {
        cout << "First fit" << endl;
        firstfit(process, block, m, n);
        break;
    }
    else if(ch == 2)
    {
        cout << "Best Fit" << endl;
        bestfit(process, block, m, n);
        break;
    }
    else if(ch == 3)
    {
        cout << "Worst Fit" << endl;
        worstfit(process, block, m, n);
        break;
    }
    else if(ch == 4)
    {
        cout << "Next Fit" << endl;
        nextfit(process, block, y, z);
        break;
    }
    else
    {
        cout << "Exit Programe" << endl;
        break;
    }
    }

    return 0;
}