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
        m_arr = nullptr; //nullptr - указатель, который ни на что не указывает
    }

    MyVector(size_t size, int value) { // Конструктор с параметрами
        m_arr = new int[size];
        m_cap = size;
        m_size = size;
    }

    ~MyVector() { //Деструктор
        if(m_arr != nullptr)
            delete[] m_arr;
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

    void reserve(size_t cap) { // реалакация памяти и новый массив копируем в старые ячейки
        if(m_size >= cap)
            return;
        m_cap = cap; 
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
    } 

    void shrink_to_fit() { // создание массива меньшего размера
        m_cap = m_size;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
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

    bool empty() { // пуст?
        return m_size == 0;
    }

    size_t capacity() { // емкость
        return m_cap;
    }

    void push_back(int value) {
        if(m_size + 1 <= m_cap) {
            m_arr[m_size] = value;
            m_size++;
            return;
        }
        m_cap = m_cap * 2 + 1; //+1 т.к. m_cap = 0
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        tmp[m_size] = value;
        delete[] m_arr;
        m_arr = tmp;
        m_size++;
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

    /*int& at(size_t index) {
        // Проверка
        return m_arr[index];
    }*/

    MyVector(const MyVector&) = delete; // конструктор копирования
    MyVector& operator=(const MyVector&) = delete; // оператор присваивания
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

    return 0;
}