class Node {
    public:
    Node* left; // assume 0
    Node* right; // assume 1
    Node(){
        this->left = this->right = NULL;
    }
};
class Solution {
public:
    int maxXor(Node* head, int val){
        int cur_xor = 0;
        Node* cur = head;
        for(int i = 31; i >= 0; i--){
            int bit = ((1 << i) & val);
            if(bit == 0){
                if(cur->right != NULL){
                    cur_xor += (1 << i);
                    cur = cur->right;
                }
                else{
                    // left child exist ( 0 exist )
                    cur = cur->left;
                }
            }
            else {
                // bit = 1
                if(cur->left != NULL){
                    cur_xor += (1 << i);
                    cur = cur->left;
                }
                else{
                    if(cur->right != NULL) {
                        cur = cur->right;
                    }
                }
            }
        }
        return cur_xor;
    }
    void insert(Node* head, int val){
        Node* cur = head;
        for(int i = 31; i >= 0; i--){
            int bit = ((1 << i) & val);
            if(bit  == 0){
                if(cur->left == NULL){
                    Node* newNode = new Node();
                    cur->left = newNode;
                }
                cur = cur->left;
            }
            else {
                // bit is 1
                if(cur->right == NULL){
                    Node* newNode = new Node();
                    cur->right = newNode;
                }
                cur = cur->right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* head = new Node();
        insert(head, nums[0]);
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            ans = max(ans, maxXor(head, nums[i]));
            insert(head, nums[i]);
        }
        return ans;


    }
};