
#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;

int calculate(int num)
{

    int ret = 0;
    while (num)
    {
        ret += (num % 10) * (num % 10);
        num /= 10;
    }
    return ret;
}

void testSet()
{
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    s.insert(1);
    s.insert(1);

    std::cout << "std::set 的元素:" << std::endl;
    for (const int &element : s)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    cout << "set 中 1 出现的次数是 ：" << s.count(1) << endl;
    cout << "set 中 4 出现的次数是 ：" << s.count(4) << endl;
}

int main()
{
    // testSet()
    std::cout << calculate(47) << std::endl;
}