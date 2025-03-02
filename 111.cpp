#include <vector>
#include <iostream>

class MyVector {
    int* m_arr;
    size_t m_size;
    size_t m_cap;
public:
    // Базовый конструктор
    MyVector() {
        m_size = 0;
        m_cap = 0;
        m_arr = nullptr;
    }

    // Конструктор с параметрами
    MyVector(size_t size, int value) {
        m_arr = new int[size];
        m_cap = size;
        m_size = size;
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = value;
        }
    }

    // Конструктор копирования
    MyVector(const MyVector& other) {
        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = new int[m_cap];
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = other.m_arr[i];
        }
    }

    // Оператор присваивания с копированием
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] m_arr;

            m_size = other.m_size;
            m_cap = other.m_cap;
            m_arr = new int[m_cap];
            for (size_t i = 0; i < m_size; ++i) {
                m_arr[i] = other.m_arr[i];
            }
        }
        return *this;
    }

    // Деструктор
    ~MyVector() {
        delete[] m_arr;
    }

    // Методы
    void resize(size_t newSize, int value = 0) {
        if (newSize < m_size) {
            m_size = newSize;
        } else {
            reserve(newSize);
            for (size_t i = m_size; i < newSize; ++i) {
                m_arr[i] = value;
            }
            m_size = newSize;
        }
    }

    void reserve(size_t cap) {
        if (m_size >= cap) return;
        int* tmp = new int[cap];
        for (size_t i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
        m_cap = cap;
    }

    void shrink_to_fit() {
        reserve(m_size);
    }

    int& front() {
        return m_arr[0];
    }

    int& back() {
        return m_arr[m_size - 1];
    }

    size_t size() {
        return m_size;
    }

    size_t capacity() {
        return m_cap;
    }

    bool empty() {
        return m_size == 0;
    }

    void push_back(int value) {
        if (m_size >= m_cap) {
            reserve(m_cap == 0 ? 1 : m_cap * 2);
        }
        m_arr[m_size++] = value;
    }

    void insert(size_t index, int value) {
        if (index > m_size) throw std::out_of_range("Index out of range");
        push_back(0); // Увеличиваем размер
        for (size_t i = m_size - 1; i > index; --i) {
            m_arr[i] = m_arr[i - 1];
        }
        m_arr[index] = value;
    }

    void erase(size_t index) {
        if (index >= m_size) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < m_size - 1; ++i) {
            m_arr[i] = m_arr[i + 1];
        }
        m_size--;
    }

    int& operator[](size_t index) {
        if (index >= m_size) throw std::out_of_range("Index out of range");
        return m_arr[index];
    }
};

void foo(MyVector vec) {

}

int main() {
    MyVector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl; // Size: 3, Capacity: 4
    std::cout << "Front: " << vec.front() << ", Back: " << vec.back() << std::endl; // Front: 1, Back: 3

    vec.insert(1, 5);
    std::cout << "After insertion at index 1: ";
    for(size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; // 1 5 2 3

    vec.erase(1);
    std::cout << "After erasing at index 1: ";
    for(size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; // 1 2 3

    vec.resize(5, 10); // Resize with default value
    std::cout << "After resizing to size 5 with default value: ";
    for(size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; // 1 2 3 10 10

    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit: Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    return 0;
}