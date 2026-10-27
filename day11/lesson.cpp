#include <iostream>
#include <queue>
#include <vector>
#include <functional>

struct Node
{
    int x;
    int y;
    int cost;
};

struct CompareCost
{
    bool operator()(const Node& a, const Node& b) const
    {
        return a.cost > b.cost;
    }
};

int main()
{
    std::priority_queue<
        Node,
        std::vector<Node>,
        CompareCost
    > open_set;

    open_set.push(Node{0, 0, 10});
    open_set.push(Node{1, 0, 3});
    open_set.push(Node{2, 0, 7});

    while (!open_set.empty())
    {
        Node current = open_set.top();
        open_set.pop();

        std::cout
            << "(" << current.x << ", " << current.y << ") "
            << "cost = " << current.cost
            << '\n';
    }

    return 0;
}