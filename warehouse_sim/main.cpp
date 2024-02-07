#include <iostream>
#include <vector>

struct Product {
  std::string name;
  float price;
};

class Warehouse {
private:
  std::vector<Product> products;

public:
  Warehouse(std::vector<Product> products) { this->products = products; }

  std::vector<Product> getProducts() { return products; }

  void setProducts(std::vector<Product> products) {
    this->products = products;
  };

  void addProduct(Product product) { products.push_back(product); }
};

int main() { return 0; }
