struct Node{
    int val;
    int left, right;
    Node():val(-1),left(-1),right(-1){}
};

class Solution {
private:
    const static int MAX = 1000000000;
    void buildTree(vector<Node>& tree, int root,int left,int right){
        if(left==right){
            tree[root].val=MAX;
            tree[root].right = tree[root].left = left;
            return ;
        }
        int mid = (left+right)/2;
        buildTree(tree,root*2,left,mid);
        buildTree(tree,root*2+1,mid+1,right);
        tree[root].val = min(tree[root*2].val,tree[root*2+1].val);
        tree[root].left = left;
        tree[root].right = right;
        return ;
    }
    
    void insert(vector<Node>& tree, int root, int ind, int val){
        if(tree[root].left==tree[root].right){
            tree[root].val = val;
            return ;
        }
        int mid = (tree[root].left + tree[root].right)/2;
        if(ind<=mid){
            insert(tree,root*2,ind,val);
        }
        else{
            insert(tree,root*2+1,ind,val);
        }
        
        tree[root].val = min(tree[root*2].val,tree[root*2+1].val);
    }
    
    int query(vector<Node>& tree, int root, int l, int r){
        if(l<=tree[root].left && tree[root].right <= r){
            return tree[root].val;
        }
        
        int mid = (tree[root].left + tree[root].right)/2;
        
        int a = MAX; int b = MAX;
        
        if(l<=mid) a = query(tree,root*2,l,r);
        if(r>mid) b = query(tree,root*2+1,l,r);
        
        return min(a,b);
        
    }
    
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1) return 0;
        vector<int> dp(n,MAX);
        
        vector<Node> tree(n*4);
        
        buildTree(tree,1,0,n-1);
        
        dp[n-1]=0;
        insert(tree,1,n-1,0);
        
        for(int i=n-2;i>=0;i--){
            if(A[i]){
                dp[i] = query(tree,1,i+1,min(n-1,i+A[i])) + 1;
                insert(tree,1,i,dp[i]);
            }
        }
        
        return dp[0];
    }
};