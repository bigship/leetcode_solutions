// 1352. Product of the Last K Numbers
/*
 * Implement the class ProductOfNumbers that supports two methods:

1. add(int num)

    Adds the number num to the back of the current list of numbers.

2. getProduct(int k)

    Returns the product of the last k numbers in the current list.
    You can assume that always the current list has at least k numbers.

At any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.
*/

// 类似前缀和的做法, 这里使用前缀积
// 如果遇到加入的值是0, 就将product数组重置为{1}
// 后K个数的积就是product.back() / product[len - K - 1]
// 如果K >= product.size() 表示一定包含了0, 此时的乘积就是0
class ProductOfNumbers {
public:
  ProductOfNumbers() {
    product.push_back(1);
  }

  void add(int num) {
    if (num) {
      product.push_back(product.back() * num);
    } else {
      product = {1};
    }
  }

  int getProduct(int k) {
    return k < product.size() ? product.back() / product[product.size() - k - 1] : 0;
  }
private:
  vector<int> product;
};
