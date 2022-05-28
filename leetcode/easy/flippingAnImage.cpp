class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0; i < n; ++i) reverse(image[i].begin(), image[i].end());
        for(auto& i : image)
            for(auto& j : i) j = !j;
        return image;
    }
};