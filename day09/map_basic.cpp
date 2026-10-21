#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

int main() {
    // ---- 作る・入れる ----
    std::map<std::string, int> score;
    score["alice"] = 80;
    score["bob"] = 65;
    score.insert({"carol", 90});
    score.insert({"alice", 999});//aliceはすでにあるので、insertは無視される。

    std::cout << "alice = " << score["alice"] << "\n";
    std::cout << "size = " << score.size() << "\n";

    // ---- 全部を順に見る(キー順) ----
    for (const auto& kv : score) {
        std::cout << kv.first << ": " << kv.second << "\n";
    }

    // ---- 探す:find ----
    auto it = score.find("bob");
    if (it != score.end()) {
        std::cout << "found bob = " << it->second << "\n";
    }
    if (score.find("dave") == score.end()) {
        std::cout << "dave not found\n";
    }

    // ---- 数える:count(あれば1、なければ0) ----
    std::cout << "count(alice) = " << score.count("alice")
              << ", count(dave) = " << score.count("dave") << "\n";

    // ---- 落とし穴:[] は、なければ勝手に作る ----
    std::cout << "size before = " << score.size() << "\n";
    int x = score["dave"];
    std::cout << "dave = " << x << ", size after = " << score.size() << "\n";

    // ---- 消す ----
    score.erase("dave");
    std::cout << "size after erase = " << score.size() << "\n";

    // ---- unordered_map:使い方はほぼ同じ ----
    std::unordered_map<std::string, int> um;
    um["x"] = 1;
    um["y"] = 2;
    um["z"] = 3;

    std::cout << "um.size = " << um.size() << ", um[\"y\"] = " << um["y"] << "\n";

    for (const auto& kv : um) {
        std::cout << kv.first << ": " << kv.second << "\n";
    }    

    return 0;
}