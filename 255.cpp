#include <vector>
#include <iostream>

class MyVector {
    int* m_arr;
    size_t m_size;
    size_t m_cap;
public:
    MyVector() { // Базовый конструктор
        m_size = 0;
        m_cap = 0;
        m_arr = nullptr;
    }
    MyVector(size_t size, int value) { // Конструктор с параметрами
        m_arr = new int[size];
        m_cap = size;
        m_size = size;
    }

    /*// Конструктор копирования
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
    }*/

    ~MyVector() { // Деструктор
        if(m_arr != nullptr)
            delete[] m_arr;
    }

    void push_back(int value) {
        if(m_size + 1 <= m_cap) {
            m_arr[m_size] = value;
            m_size++;
            return;
        }
        m_cap = m_cap * 2 + 1;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        tmp[m_size] = value;
        delete[] m_arr;
        m_arr = tmp;
        m_size++;
    }

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
        if(m_size >= cap)
            return;
        m_cap = cap;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
    } 

    void shrink_to_fit() {
        m_cap = m_size;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
    }

    size_t size() {
        return m_size;
    }

    size_t capacity() {
        return m_cap;
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
        return m_arr[index];
    }

    int& front() {
        return m_arr[0];
    }

    int& back() {
        return m_arr[m_size - 1];
    }

    bool empty() {
        return m_size == 0;
    }

    int& at(size_t index) {
        // Проверка
        return m_arr[index];
    }

    MyVector(const MyVector&) = delete;
    MyVector& operator=(const MyVector&) = delete;
};

void foo(MyVector vec) {

}

int main() {
    std::vector<int> mas;
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

    // Дополнение для демонстрации работы MyVector
    MyVector myVec;
    for (int i = 0; i < 10; ++i) {
        myVec.push_back(i);
        std::cout << "MyVector size: " << myVec.size() << ", capacity: " << myVec.capacity() << std::endl;
    }

    std::cout << "Front element: " << myVec.front() << std::endl;
    std::cout << "Back element: " << myVec.back() << std::endl;

    myVec.insert(5, 99);
    std::cout << "After insert at index 5: " << myVec[5] << std::endl;

    myVec.erase(5);
    std::cout << "After erase at index 5: " << myVec[5] << std::endl;

    myVec.resize(15, 100);
    std::cout << "After resize to 15: " << myVec.size() << ", capacity: " << myVec.capacity() << std::endl;

    myVec.shrink_to_fit();
    std::cout << "After shrink_to_fit: " << myVec.size() << ", capacity: " << myVec.capacity() << std::endl;

    return 0;
}