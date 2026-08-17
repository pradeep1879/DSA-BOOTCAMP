#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    vector<int> result;
    result.push_back(root->val);

    vector<int> left = preorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    vector<int> right = preorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++)
        cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    vector<int> result = preorderTraversal(root);

    for (int i = 0; i < result.size(); i++) {
        if (i) cout << " ";
        cout << result[i];
    }

    cout << '\n';
}