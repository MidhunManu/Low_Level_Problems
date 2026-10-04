#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cstddef>

class BloomFilter
{
public:
   BloomFilter(std::size_t size)
       :m_size(size)
   {
       m_bit_vector.resize(m_size, false);
   }

   std::size_t hash(std::string str)
   {
       std::hash<std::string> hasher;
       return hasher(str) % m_size;
   }

   void add(std::string str)
   {
       size_t bit_index = hash(str);
       std::cout << bit_index << "\n";
       m_bit_vector[bit_index] = true;
   }

   bool exists(std::string str)
   {
       size_t bit_index = hash(str);
       return m_bit_vector[bit_index];
   }

private:
    std::size_t  m_size;    
    std::vector<bool> m_bit_vector;
};

int main()
{
    BloomFilter filter(10);
    std::string cat = "cat";
    filter.add(cat);
    std::cout << filter.exists(cat) << "\n";
    std::cout << filter.exists("dog") << "\n";
}

