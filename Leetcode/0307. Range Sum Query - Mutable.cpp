/* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val. */

class NumArray {
public:
    static const int TREE_DEFAULT_VALUE = 0;

    struct SegmentTreeNode {
        SegmentTreeNode *left, *right;
        int value;
        SegmentTreeNode(SegmentTreeNode *_left = NULL, SegmentTreeNode *_right = NULL, int _value = TREE_DEFAULT_VALUE)
        {
            left  = _left;
            right = _right;
            value = _value;
        }
    };

    int SegmentTreeMerge(int a, int b)
    {
        return a + b;
    }

    void SegmentTreeUpdate(SegmentTreeNode* &T, int value, int l, int r, int index)
    {
        if(T == NULL)
            T = new SegmentTreeNode();

        T->value = SegmentTreeMerge(T->value, value);

        if(r - l == 1) // is last level
            return;

        if(index < (l + r)/2)
            SegmentTreeUpdate(T->left,  value, l, (l+r)/2, index);
        else
            SegmentTreeUpdate(T->right, value, (l+r)/2, r, index);
    }

    int SegmentTreeResult(SegmentTreeNode* &T, int start, int end, int l, int r)
    {
        if(T == NULL)
            return TREE_DEFAULT_VALUE;
        if(l >= start && r-1 <= end)
            return T->value;
        if(l > end || r <= start)
            return TREE_DEFAULT_VALUE;

        int recL = SegmentTreeResult(T->left,  start, end, l, (l+r)/2);
        int recR = SegmentTreeResult(T->right, start, end, (l+r)/2, r);

        return SegmentTreeMerge(recL, recR);
    }

    
    SegmentTreeNode *T;
    int N;
    
    NumArray(vector<int>& nums) {
        N = nums.size();
        T = new SegmentTreeNode();
        for(int i = 0; i < nums.size(); i++)
        {
            SegmentTreeUpdate(T, nums[i], 0, N, i);
        }
    }
    
    void update(int i, int val) {
        int prevValue = sumRange(i, i);
        SegmentTreeUpdate(T, val-prevValue, 0, N, i);
    }
    
    int sumRange(int i, int j) {
        return SegmentTreeResult(T, i, j, 0, N);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */