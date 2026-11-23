class ProductOfNumbers {
public:
    int n;
    vector<int> nums;
    ProductOfNumbers() {
        nums.clear();
        n=0;
    }    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        n=nums.size();
        int product=1;

        for(int i=n-k;i<n;i++){
            product*=nums[i];
        }
        return product;       
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */