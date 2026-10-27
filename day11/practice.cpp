#include <iostream>
#include <queue>
#include <vector>
#include <functional>

// 問題1：整数の優先順位
// 1. int型のpriority_queueを作る
// 2. 小さい値を優先する設定にする
// 3. 8、2、6、1、5を追加する
// 4. 小さい順にすべて表示する


// 問題2：Node構造体
// x、y、costを持つNode構造体を定義する
struct Node{
int x;
int y;
int cost;
};

// 問題3：比較関数
// costが小さいNodeを優先するCompareCostを定義する
struct CompareCost{
    bool operator()(const Node& a , const Node& b)const
    {
        return a.cost > b.cost;
    }
};

// 問題4：ロボットの候補地点
// 次の3つのNodeをpriority_queueに追加する
// Node{0, 1, 9}
// Node{1, 1, 4}
// Node{2, 1, 6}
//
// costが小さい順に、座標とcostを表示する


int main()
{
    // 問題1のコードを書く
    std::priority_queue<
    int,
    std::vector<int>,
    std::greater<int>
    > q;

    q.push(8);
    q.push(2);
    q.push(6);
    q.push(1);
    q.push(5);

    while(!q.empty())
    {
        std::cout << q.top() << '\n';
        q.pop();
    }
    // 問題4のコードを書く
    std::priority_queue<
    Node,
    std::vector<Node>,
    CompareCost
    > set;

    set.push(Node{0, 1, 9});
    set.push(Node{1, 1, 4});
    set.push(Node{2, 1, 6});

        while(!set.empty())
    {
        Node current = set.top();
        set.pop();

        std::cout
            << "(" << current.x << ", " << current.y << ") "
            << "cost = " << current.cost
            << '\n';
    }

    return 0;
}