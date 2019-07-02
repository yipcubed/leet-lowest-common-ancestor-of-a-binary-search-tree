#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    TreeNode* lowestCommonAncestorR(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (q->val < root->val)
            return lowestCommonAncestorR(root->left, p, q);
        if (p->val > root->val)
            return lowestCommonAncestorR(root->right, p, q);
        return root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (p->val < q->val)
            return lowestCommonAncestorR(root, p, q);
        else
            return lowestCommonAncestorR(root, q, p);
    }
};

void func(TreeNode *tx) {
    cout << tx->val << ",";
}

void test1() {
    vector<int> v1{6,2,8,0,4,7,9,-1,-1,3,5};

    TreeNode *t1 = new TreeNode(v1, -1);
    cout << "2 ? " << Solution().lowestCommonAncestor(t1, t1->findItem(2), t1->findItem(4)) << endl;
    cout << "6 ? " << Solution().lowestCommonAncestor(t1, t1->findItem(2), t1->findItem(8)) << endl;
//    cout << " ? " << Solution().func() << endl;
}

void test2() {

}

void test3() {

}