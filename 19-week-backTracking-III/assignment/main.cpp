#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int i, int j,
    vector<vector<int>> &maze,
    vector<vector<int>> &vis,
    int n,
    string path,
    vector<string> &ans) {

    // destination reached
    if (i == n - 1 && j == n - 1) {
      ans.push_back(path);
      return;
    }

    vis[i][j] = 1;

    // D L R U -> lexicographical order

    // Down
    if (i + 1 < n &&
      maze[i + 1][j] == 1 &&
      !vis[i + 1][j]) {

      solve(i + 1, j, maze, vis, n, path + 'D', ans);
    }

    // Left
    if (j - 1 >= 0 &&
      maze[i][j - 1] == 1 &&
      !vis[i][j - 1]) {

      solve(i, j - 1, maze, vis, n, path + 'L', ans);
    }

    // Right
    if (j + 1 < n &&
      maze[i][j + 1] == 1 &&
      !vis[i][j + 1]) {

      solve(i, j + 1, maze, vis, n, path + 'R', ans);
    }

    // Up
    if (i - 1 >= 0 &&
      maze[i - 1][j] == 1 &&
      !vis[i - 1][j]) {

      solve(i - 1, j, maze, vis, n, path + 'U', ans);
    }

    vis[i][j] = 0;
}

void ratInMaze() {
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> maze[i][j];
      }
    }

    // start or end blocked
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
      cout << 0 << endl;
      // return 0;
    }

    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<string> ans;

    solve(0, 0, maze, vis, n, "", ans);

    if (ans.empty()) {
      cout << 0 << endl;
    } else {
      cout << ans.size() << endl;

      for (string &s : ans) {
        cout << s << endl;
      }
    }

    // return 0;
}


void generatePermutations(
    vector<int>&nums,
    vector<int>&current,
    vector<int>&used,
    vector<vector<int>>&ans
) {
    // one permutation completed
    if((current.size()) == nums.size()){
      ans.push_back(current);
      return;
    }


    for(int i = 0; i < nums.size(); i++){
      if(used[i]) continue;

      used[i] = 1;
      current.push_back(nums[i]);
      generatePermutations(nums, current, used, ans);
      current.pop_back();

      used[i] = 0;
    }

}



void permutation(){
  int n;
  cin >> n;

  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }

  vector<vector<int>> ans;
  vector<int> current;
  vector<int> used(n, 0);

  generatePermutations(nums, current, used, ans);

  cout << ans.size() << endl;

  for(auto &perm: ans){
    for(int x: perm){
      cout << x << " ";
    }

    cout << endl;
  }

}

int main(){
  // ratInMaze();
  permutation();
}