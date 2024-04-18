
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstring>
#include <cassert>
#include <numeric>
#include <memory>
using namespace std;
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
    s.erase(1);
    cout << "set 中 4 出现的次数是 ：" << s.count(1) << endl;
}

void eraseSet()
{
    std::unordered_multiset<char> sMagazine = {'a', 'b', 'b', 'c'};

    char c = 'b';
    auto countBefore = sMagazine.count(c);
    std::cout << "元素 " << c << " 的数量: " << countBefore << std::endl;

    // 删除一个特定元素
    auto it = sMagazine.find(c);
    if (it != sMagazine.end())
    {
        sMagazine.erase(it);
    }

    auto countAfter = sMagazine.count(c);
    std::cout << "删除一个元素后，元素 " << c << " 的数量: " << countAfter << std::endl;

    // 删除所有特定元素
    sMagazine.erase(c);

    auto countAfterAllErased = sMagazine.count(c);
    std::cout << "删除所有元素后，元素 " << c << " 的数量: " << countAfterAllErased << std::endl;
}
bool canConstruct(string ransomNote, string magazine)
    {
        auto sMagazine = unordered_set<char>(magazine.begin(), magazine.end());
        
        for (auto c : ransomNote)
        {
            std::cout<<c<<std::endl;
            std::cout<<sMagazine.count(c)<<std::endl;
            if(!sMagazine.count(c)){
                return false;
            }else{
                auto it = sMagazine.find(c);
                sMagazine.erase(it);
            }
        }

        return true;
    }

int main()
{
    std::cout<<canConstruct("aa","aab");
    // testSet();
    // eraseSet();
    // std::cout << calculate(47) << std::endl;
}
