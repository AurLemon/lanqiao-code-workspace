#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
  /**
   * 理解题目：
   * 就是班上有偶数个人，班级做活动，要分组，每组 2 个人，老师为了公平分组通过这个方式分组：每个人随机分配 id（正整数），然后后面再对 id 进行调整，只有 id 一样的才能凑一组。这道题就是计算调整 id 需要计算几步。
   * 总的来说：每个数都只能出现 2 次，如果是奇数次或者大于两次的，要把它改成只出现两次，题目就是计算修改的次数。
   * 
   * 原来的思路：
   * 首先去掉 id 出现次数为 2 的
   * 然后再把 value 中大于 2 的减
   * 然后再去重，分别计算
   * 用 map 数据结构来存储每个数的出现次数
   * 举个例子，map 把这些数据以 key-value 的形式存储下来：1, 2, 3, 3, 4, 7, 7, 8, 8, 8, 9, 9, 9, 2, 2, 2, 3, 4, 2, 2, 9, 9
   * {
   *  1: 1,
   *  2: 6,
   *  3: 3,
   *  4: 2,
   *  7: 2,
   *  8: 3,
   *  9: 5
   * }
   * 此时按照奇数和偶数分开，最后相加两个分类计算的计数和：
   * 如果是偶数 -> 大于 2 -> 计算偶数减 2 以后的个数，然后直接把个数放到总和里面
   *          -> 等于 2 -> 不用管，因为本来就不用计算
   * 如果是奇数 -> 大于 1 -> ① 把数据减 1，然后结果肯定是偶数，把偶数的个数放到总和里面 ② 执行完第一步以后肯定只剩下 1，此时计算 map 内 value 为 1 的 key 的数量，除 2 的结果存到总和里面（此时个数为 1 的 key 数量一定是偶数，第一是因为数据就必须是偶数的，第二是因为就算前面过滤数据也只是仅限于偶数 2，不可能影响到偶数，如果结果不是偶数那说明前面给的数据就有问题）
   *          -> 等于 1 -> 
   * 继续精简，其实这个时候就不用分奇偶了 -> ① value 等于 2 不用管 ② value 等于 1 要管，但是需要单独算一下等于 1 的有几个然后算总数 / 2 ③ value > 2 就把 value - 2 放到总计数里面就好了
   * 最终结果是 8，因为
   * 首先去掉
   * {
   *  1: 1,
   *  2: 6,
   *  3: 3,
   *  4: 2,
   *  7: 2,
   *  8: 3,
   *  9: 5
   * }
   * 里面出现 2 次的：
   * {
   *  1: 1,
   *  2: 6,
   *  3: 3,
   *  8: 3,
   *  9: 5
   * }
   * 然后等于1的单独算一下，大于2的，减掉2算到总数量里面（减2是因为已经是一组了，只需要算剩下的数据配对，配对只需要算减掉以后的数字，看看减掉以后的数是奇还是偶，如果等于1那就单独放等于1的计数，如果大于1的奇数那就继续算，一直到等于1，如果是偶数那就直接加到numcount里面去）
   * 所以最后是8
   * 
   * 正确的思路：
   * 但是上面这个思路里面有个错误的思路就是，一开始设想的目标就不是按照“最少更改次数”来的，包括后面 result 的计算也是。其实只要简单按照超过 2 的数量和小于 2 的数量来计算即可。大于 2 的 id 的数量和需要补到 2 的数量，两个用 overCount 和 underCount 来处理。最终结果按照 overCount >= underCount 进行分类：
   * 
   * ① 符合条件的时候，result 就是 overCount
   * ② 反过来 underCount 大的时候，以 1 2 3 4 5 6 7 7 7 7 为例，过滤后为 1 2 3 4 5 6 7 7，此时 overCount = 2, underCount = 6，因为 overCount 是超过 2 的 id 的数量，直接把多余的数改成数组内已有的数即可，此时 1 2 3 4 5 6 7 7 变成 1 2 3 4 5 6 1 2，所以 underCount - overCount 的数据就不需要额外计入修改数了，直接按 overCount 算即可，也就是最前面的 1 和 2。剩下需要处理的就是 (underCount - overCount) / 2 的部分，因为 underCount > overCount，所以还会有一点剩余的未处理的数字，此时把剩余的数据除 2 即可，让他们一一对应，结果就是需要操作的次数。即 overCount + (underCount - overCount) / 2。
   * 
   * 需要注意的是，underCount > overCount 的时候，overCount 是多出来的数据可以直接去补 underCount 内的数据。这点需要注意，否则就不是最小操作数了，就变成 overCount + underCount / 2 了。
   */

  int count;

  cin >> count;

  unordered_map<int, int> map;

  if (count % 2 != 0) {
    cout << "数据不能是奇数个" << endl;
    return 1;
  }

  for (int i = 0; i < count; ++i) {
    int n;
    cin >> n;
    map[n]++;
  }

  int overCount = 0;
  int underCount = 0;

  for (auto& pair: map) {
    int value = pair.second;
    if (value > 2) overCount += value - 2;
    if (value == 1) ++underCount;
  }

  int result = overCount >= underCount ? overCount : overCount + (underCount - overCount) / 2;
  cout << result << endl;

  return 0;
}