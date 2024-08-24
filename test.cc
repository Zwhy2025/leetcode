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

#include <gtest/gtest.h>
//#include "617.合并二叉树.cpp"
//#include "22.括号生成.cpp"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// std::mutex mtx;
// std::condition_variable cv;
// bool isOddTurn = true; // 控制奇数线程和偶数线程的交替
// int count = 1; // 初始计数

// void printOdd() {
//     while (count <= 10) {
//         std::cout << "1.Odd: " << count << std::endl;
//         std::unique_lock<std::mutex> lock(mtx);
//         std::cout << "2.Odd: " << count << std::endl;
//         cv.wait(lock, [] { return isOddTurn; });
//         std::cout << "3.Odd: " << count << std::endl;
//         if (count <= 10) {
//             std::cout << "Odd: " << count << std::endl;
//             count++;
//         }
//         std::cout << "4.Odd: " << count << std::endl;
//         isOddTurn = false;
//         cv.notify_one();
//         std::cout << "5.Odd: " << count << std::endl;
//     }
// }

// void printEven() {
//     while (count <= 10) {
//         std::cout << "1.Even: " << count << std::endl;
//         std::unique_lock<std::mutex> lock(mtx);
//         std::cout << "2.Even: " << count << std::endl;
//         cv.wait(lock, [] { return !isOddTurn; });
//         std::cout << "3.Even: " << count << std::endl;
//         if (count <= 10) {
//             std::cout << "Even: " << count << std::endl;
//             count++;
//         }
//         std::cout << "4.Even: " << count << std::endl;
//         isOddTurn = true;
//         cv.notify_one();
//         std::cout << "5.Even: " << count << std::endl;
//     }
// }

// int main(){
//     //Solution s;
//     //s.numberOfSubstrings("00011");

//     //std::thread oddThread(printOdd);
//     //std::thread evenThread(printEven);

//     //oddThread.join();
//     //evenThread.join();

// }

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
#include <iostream>
#include <bitset>
#include <gtest/gtest.h>
using namespace std;


int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(MEET, test1) {
    std::cout << "hello world!" << std::endl;
    EXPECT_EQ(false, true);
}

