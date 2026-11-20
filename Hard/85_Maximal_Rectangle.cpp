
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                }
                else {
                    height[j] = 0;
                }
            }

            stack<int> st;

            for (int j = 0; j <= cols; j++) {
                int h = (j == cols) ? 0 : height[j];

                while (!st.empty() && height[st.top()] > h) {
                    int H = height[st.top()];
                    st.pop();

                    int width;

                    if (st.empty()) {
                        width = j;
                    }
                    else {
                        width = j - st.top() - 1;
                    }

                    ans = max(ans, H * width);
                }

                st.push(j);
            }
        }

        return ans;
    }
};
