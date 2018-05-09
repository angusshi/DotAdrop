#include<iostream>
#include<ctime>
#include<cstdlib>
#include <numeric>

using namespace std;

int lcm(int, int);
int gcd(int, int);
double run();

int main()
{
    int rn=10;
    const int rnsize=1;
    double sum = 0, avg = 0;
    for(int i=0;i<rnsize;i++)
    {
        cin >>rn;
        if(rn)
        sum += run();
        avg = sum / (i+1);
        cout << "new avg = " << avg <<endl;
    }
    return 0;
}

double run()
{
    int treanum, accsize, droprate, up_droprate, n_lcm, num_boost;
    cout << "number of account is \n";
    //cin >> accsize;
    accsize = 100000;
    cout << "number of treasure is \n";
    //cin >> treanum;
    treanum = 260;
    cout << "drop rate is(one in x) \n";
    //cin >> droprate;
    droprate = 100;
    cout << "boosted drop rate is(one in x) \n";
    //cin >> up_droprate;
    up_droprate = 30;
    cout << "drop rate boost staring by\n";
    //cin >> num_boost;
    num_boost = 15;
    n_lcm = lcm(droprate, up_droprate);
    int constopen, rare = 0, rarenum[accsize], largest = 0;
    const int randsize = treanum;
    int treout[randsize];
    srand(time(0));
    for(int accnum=0;accnum<accsize;accnum++)
    {
        for(int n=0;n<randsize;n++)
        treout[n] = (rand()%(n_lcm - 1));
        for(int opentime = 0; opentime<randsize; opentime++)
        {
            if(constopen < num_boost)
            {
                if(treout[opentime] < n_lcm/droprate - 1)
                {
                    rare++;
                    constopen = 0;
                }
                else
                {
                    constopen++;
                }
            }
            else
            {
                if(treout[opentime] < n_lcm/up_droprate - 1)
                {
                    rare++;
                    constopen = 0;
                }
                else
                {
                    constopen++;
                }
            }
        }
        rarenum[accnum] = rare;
        rare = 0;
        treout[randsize] = {0};
    }
    for(int i = 0; i < accsize; i++)
    {
        if(rarenum[i]>largest)
            largest = rarenum[i];
    }
    cout << "rare_maximum = " << largest << ".\n";
    int cnt = 0;
    double sum = 0, avg = 0;
    for(int m = 0; m <= largest; m++)
    {
        for(int num = 0; num<= accsize; num++)
        {
            if(rarenum[num] == m)
                cnt++;
        }
        sum += (m*cnt);
        cout << m << ": " << cnt <<endl;
        cnt = 0;
    }
    avg = sum / accsize;
    cout << "avg = " << avg <<endl;

//    return 0;
    return avg;
}

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}
