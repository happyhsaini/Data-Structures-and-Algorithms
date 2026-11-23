class ProductOfNumbers {
    vector<int> prefix;
public:
    ProductOfNumbers() {
        prefix = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            // 0 aate hi sab reset kar do, kyunki iske pehle ka koi bhi product 0 hi hoga
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        // Agar last k numbers mein 0 aaya tha, toh prefix ka size k ya usse kam hoga
        if (k >= n) {
            return 0;
        }
        return prefix.back() / prefix[n - 1 - k];
    }
};