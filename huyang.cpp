#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    int total, deadCount;
    cin >> total >> deadCount;

    // 初始化数组，所有树最初都是成活的，0表示成活，1表示未成活
    vector<int> nums(total, 0);

    // 根据输入，将未成活的树的位置标记为1
    for (int i = 0; i < deadCount; i++) {
        int num;
        cin >> num;
        nums[num - 1] = 1; // 树的编号从1开始，因此需要减1
    }

    // 读取可以补种的树的数量
    int supplementCount;
    cin >> supplementCount;

    // 初始化滑动窗口的左右边界
    int left = 0, maxLen = 0, sumLeft = 0, sumRight = 0;

    // 遍历所有的树，right代表滑动窗口的右边界
    for (int right = 0; right < total; right++) {
        sumRight += nums[right]; // 更新右边界的未成活树数量

        // 如果窗口内的未成活树数量大于可以补种的数量
        while (sumRight - sumLeft > supplementCount) {
            sumLeft += nums[left]; // 缩小窗口，左边界右移
            left++;
        }

        // 更新最大成活区域的长度
        maxLen = max(maxLen, right - left + 1);
    }

    // 输出最大连续成活区域的长度
    cout << maxLen << endl;

    return 0;
}