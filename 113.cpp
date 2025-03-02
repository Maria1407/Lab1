#include <iostream>
#include <vector>

class MyVector {
    int* m_arr;
    size_t m_size;
    size_t m_cap;
public:
    MyVector() {
        m_size = 0;
        m_cap = 0;
        m_arr = nullptr;
    }

    MyVector(size_t size, int value) {
        m_arr = new int[size];
        m_cap = size;
        m_size = size;
            for(int i = 0; i < m_size; ++i) {
                m_arr[i] = value;
            }
    }

    MyVector(const MyVector& other) : m_size(other.m_size), m_cap(other.m_cap) {
        m_arr = new int[m_cap];
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = other.m_arr[i];
        }
    }

    MyVector(MyVector&& other) noexcept
        : m_arr(other.m_arr), m_size(other.m_size), m_cap(other.m_cap) {
        other.m_arr = nullptr;

        other.m_size = 0;

        other.m_cap = 0;

    }

    // Copy assignment operator

    MyVector& operator=(const MyVector& other) {

        if (this == &other) {

            return *this;

        }

        delete[] m_arr;

        m_size = other.m_size;

        m_cap = other.m_cap;

        m_arr = new int[m_cap];

        for (size_t i = 0; i < m_size; ++i) {

            m_arr[i] = other.m_arr[i];

        }

        return *this;

    }

    // Move assignment operator

    MyVector& operator=(MyVector&& other) noexcept {

        if (this == &other) {

            return *this;

        }

        delete[] m_arr;

        m_arr = other.m_arr;

        m_size = other.m_size;

        m_cap = other.m_cap;

        other.m_arr = nullptr;

        other.m_size = 0;

        other.m_cap = 0;

        return *this;

    }

    ~MyVector() {

        if (m_arr != nullptr)

            delete[] m_arr;

    }

    void push_back(int value) {

        if (m_size + 1 <= m_cap) {

            if (m_arr == nullptr && m_cap == 0) {

                reserve(1);  

            }

            m_arr[m_size] = value;

            m_size++;

            return;

        }

        size_t new_cap = (m_cap == 0) ? 1 : m_cap * 2 + 1;

        reserve(new_cap);

        m_arr[m_size] = value;

        m_size++;

    }

    void reserve(size_t cap) {

        if (m_size >= cap)

            return;

        m_cap = cap;

        int* tmp = new int[m_cap];

        if (m_arr != nullptr) {

            for (int i = 0; i < m_size; i++)

                tmp[i] = m_arr[i];

            delete[] m_arr;

        }

        m_arr = tmp;

    }

    void resize(size_t size) {

        resize(size, 0);

    }

    void resize(size_t size, int value) {

        if (size > m_cap) {

            reserve(size);

        }

        if (size > m_size) {

            for (size_t i = m_size; i < size; ++i) {

                m_arr[i] = value;

            }

        }

        m_size = size;

    }

    void shrink_to_fit() {

        if (m_size == m_cap)

            return;

        m_cap = m_size;

        int* tmp = new int[m_cap];

        for (int i = 0; i < m_size; i++)

            tmp[i] = m_arr[i];

        delete[] m_arr;

        m_arr = tmp;

    }

    size_t size() const {

        return m_size;

    }

    bool empty() const {

        return m_size == 0;

    }

    size_t capacity() const {

        return m_cap;

    }

    int& operator[](size_t index) {

         if (index >= m_size) {

            throw std::out_of_range("Index out of bounds");

        }

        return m_arr[index];

    }

    const int& operator[](size_t index) const {

        if (index >= m_size) {

            throw std::out_of_range("Index out of bounds");

        }

        return m_arr[index];

    }

    int& back() {

        if (empty()) {

            throw std::out_of_range("Vector is empty");

        }

        return m_arr[m_size - 1];

    }

    const int& back() const {

        if (empty()) {

            throw std::out_of_range("Vector is empty");

        }

        return m_arr[m_size - 1];

    }

    int& front() {

        if (empty()) {

            throw std::out_of_range("Vector is empty");

        }

        return m_arr[0];

    }

    const int& front() const {

        if (empty()) {

            throw std::out_of_range("Vector is empty");

        }

        return m_arr[0];

    }

    int& at(size_t index) {

         if (index >= m_size) {

            throw std::out_of_range("Index out of bounds");

        }

        return m_arr[index];

    }

   

    void insert(size_t index, int value) {

        if (index > m_size) {

            throw std::out_of_range("Index out of bounds for insertion");

        }

        if (m_size == m_cap) {

            size_t new_cap = (m_cap == 0) ? 1 : m_cap * 2 + 1;

            reserve(new_cap);

        }

        for (size_t i = m_size; i > index; --i) {

            m_arr[i] = m_arr[i - 1];

        }

        m_arr[index] = value;

        m_size++;

    }

   

    void erase(size_t index) {

        if (index >= m_size) {

            throw std::out_of_range("Index out of bounds for deletion");

        }

        for (size_t i = index; i < m_size - 1; ++i) {

            m_arr[i] = m_arr[i + 1];

        }

        m_size--;

    }

};

void foo(MyVector vec) {

}

int main() {

    MyVector mas;

    mas.resize(20);

    mas[10] = 2;

    for(int i=0;i<100;i++) {

        mas.push_back(i);

        std::cout << mas.size() << " " << mas.capacity() << std::endl;

    }

    mas.shrink_to_fit();

    std::cout << mas.size() << " " << mas.capacity() << std::endl;

    std::cout << mas[10] << std::endl;

    mas[10] = 2;

    std::cout << mas[10] << std::endl;

    return 0;

}
