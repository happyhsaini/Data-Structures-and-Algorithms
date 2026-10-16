
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *prev = nullptr, *curr = root;

        while (curr) {
            if (curr->left == nullptr) {
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } 
            else {
                TreeNode* temp = curr->left;

                while (temp->right && temp->right != curr) {
                    temp = temp->right;
                }

                if (!temp->right) {
                    temp->right = curr;
                    curr = curr->left;
                } 
                else {
                    temp->right = nullptr;

                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }

                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
