
#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;

int main(){

   multiset<int> s;
   s.insert(1);
   s.insert(2);
   s.insert(3);
   s.insert(1);
   s.insert(1);
   s.insert(1);

   std::cout << "std::set 的元素:" << std::endl;
    for (const int& element : s) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
   cout<<"set 中 1 出现的次数是 ："<<s.count(1)<<endl;
   cout<<"set 中 4 出现的次数是 ："<<s.count(4)<<endl;

}