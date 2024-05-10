
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
        std::cout << c << std::endl;
        std::cout << sMagazine.count(c) << std::endl;
        if (!sMagazine.count(c))
        {
            return false;
        }
        else
        {
            auto it = sMagazine.find(c);
            sMagazine.erase(it);
        }
    }

    return true;
}

void findStr(){
    std::string str="abcabd";

    std::cout<< (str + str).find(str, 1)<< std::endl;
    std::cout << ((str + str).find(str,1) != str.size())<< std::endl;
    return;
}

void topSet(){
       auto nums = std::vector<int>{1,1,1,2,2,3};
       auto topSet = std::multiset<int>(nums.begin(),nums.end());

       for(auto set : topSet){
        std::cout<<set<<std::endl;
       }
       std::cout<<topSet.size()<<std::endl;



}

// char* add = "word";
// char* target = "hello";
void MenMove(char* add,char* target,int size){
    
}


#include <mutex>
class display
{
public:
    std::shared_ptr<display> getIns(){
    
        // if (_dispaly == nullptr) {   
        //     std::unique_lock<std::mutex> lock(_mutex);
        //     if (_dispaly == nullptr){
        //         _dispaly = make_shared<display>();
        //     }
        // }

        std::unique_lock<std::mutex> lock(_mutex);
        
        if (_dispaly == nullptr){
            _dispaly = make_shared<display>();
        }
        return _dispaly;
    }
    ~display();
    
    display(/* args */);
private:

private:

    std::mutex _mutex;
    static std::shared_ptr<display> _dispaly;
};

display::display(/* args */)
{
}

display::~display()
{
    std::cout<<"display deconstruct"<<std::endl;
}


void ptr_1(display* ptr){
    std::cout<<"------------- ptr_1 start -------------"<<std::endl;
    display* ptr_1 = ptr;
    delete ptr_1;
    std::cout<<"------------- ptr_1 end -------------"<<std::endl;
}


void ptr_test(){
    std::cout<<"------------- ptr_test start -------------"<<std::endl;
    display* ptr = new display();

    ptr_1(ptr);
    std::cout<<"------------- ptr_test end  -------------"<<std::endl;
    // std::weak_ptr<display> weak(ptr);
    // std::shared_ptr<display> move =std::move(ptr);
    
    // if (ptr){
    //     std::cout<<"move ptr is not nullptr"<<std::endl;
    // }

    // std::shared_ptr<display> shared(weak.lock());
    // if (shared)
    // {
    //    std::cout<<"get shared ptr"<<std::endl;
    // }else{
    //     std::cout<<"get nullptr"<<std::endl;
    // }
    

}

// void reverseString(vector<char>& s) {
//     for (int i = 0,j= s.size(); i < j; i++,j--)
//     {
//         std::swap(s[i],s[j]);
//     }
//  }
//  void swap(char& a, char& b)
//     {
//         auto temp = a;
//         a = b;
//         b = temp;
//     }

// void reverseString(vector<char> &s)
// {

//     for (int i = 0, j = s.size() - 1; i < j; i++, j--)
//     {
//         std:swap(s[i],s[j]);
//     }
// }

#include "344.反转字符串.cpp"

int main()
{   
    std::cout<<"------------- begin -------------"<<std::endl;
    vector<char> s={'c','b','a'};

    auto ex = Solution();
    ex.reverseString(s);
    ex.reverseString(s);
    std::cout<<"s[0]: "<<s[0]<<std::endl;


    // g++ /home/zwhy/leetcode/display.cpp -o /home/zwhy/leetcode/display && /home/zwhy/leetcode/display
    // testSet();
    // eraseSet();

    //std::cout << calculate(47) << std::endl;
    //std::cout << canConstruct("aa", "aab");

    // findStr();
    // topSet();
     std::cout<<"------------- end -------------"<<std::endl;
}
