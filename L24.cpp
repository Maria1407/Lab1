#include <iostream>
#define N_Max 1000

class BigInt{
    char m_value[1000];
    short m_size = 0;

    public:
    BigInt() = default;
    BigInt(const std::string& value) {
        size_t len = value.length();
        for(int i=0;i<len;i++)
            m_value[i] = value[len-i-1] - '0';
        for(int i=len;i<N_Max;i++) {
            m_value[i] = 0;
        }
        m_size = len;
    }

    BigInt& operator+=(const BigInt& other) {
        for(int i=0;i<m_size;i++) {
            m_value[i] += other.m_value[i];
            if(m_value[i] > 9) {
                m_value[i] -= 10;
                m_value[i+1]++;
                if(i+1 == m_size)
                    m_size++;
               
            }
        }
        return *this;
    }

    BigInt operator+(const BigInt& other){
        BigInt result(*this);
        result += other;
        return result;
    }

    
    BigInt& BigInt::operator*=(const BigInt& other) {
        int* result = new int[m_size + other.m_size](); // Инициализация нулями
        int resultSize = m_size + other.m_size;
    
        // Умножение цифр
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < other.m_size; ++j) {
                result[i + j] += m_value[i] * other.m_value[j];
            }
        }
    
        // Обработка переносов
        for (int i = 0; i < resultSize - 1; ++i) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    
        // Определение фактического размера результата
        while (resultSize > 1 && result[resultSize - 1] == 0) {
            resultSize--;
        }
    
        // Освобождаем старую память m_value
        delete[] m_value;
    
        // Копируем результат в m_value
        m_value = new int[resultSize];
        for (int i = 0; i < resultSize; ++i) {
            m_value[i] = result[i];
        }
    
        m_size = resultSize;
    
        // Освобождаем память, выделенную для result
        delete[] result;
    
        return *this;
    }
    

    BigInt operator*(const BigInt& other) const {
        BigInt result(*this);
        result *= other;
        return result;
    }

    bool operator<(const BigInt& other) const {
        if (m_size < other.m_size) {
            return true;
        } else if (m_size > other.m_size) {
            return false;
        } else {
            for (int i = m_size - 1; i >= 0; --i) {
                if (m_value[i] < other.m_value[i]) {
                    return true;
                } else if (m_value[i] > other.m_value[i]) {
                    return false;
                }
            }
            return false;
        }
    }

    bool operator>(const BigInt& other) const {
        return other < *this;
    }

    bool operator==(const BigInt& other) const {
        if (m_size != other.m_size) {
            return false;
        }
        for (int i = 0; i < m_size; ++i) {
            if (m_value[i] != other.m_value[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }


    friend std::ostream& operator<<(std::ostream& out, const BigInt& other);
};

std::istream& operator>>(std::istream& in, BigInt& other) {
    std::string s;
    in >> s;
    other = BigInt(s);
    return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& other) {
    for(int i=0; i<other.m_size; i++) {
        out << static_cast<short>(other.m_value[other.m_size - i - 1]);
    }
    return out;
}

int main() {
    BigInt x("1");
    std::cin >> x;
    BigInt y("999");

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    BigInt sum = x + y;
    std::cout << "x + y = " << sum << std::endl;

    BigInt product = x * y;
    std::cout << "x * y = " << product << std::endl;

    if (x < y) {
        std::cout << "x < y" << std::endl;
    }

    if (x > y) {
        std::cout << "x > y" << std::endl;
    }

    if (x == y) {
        std::cout << "x == y" << std::endl;
    } else {
        std::cout << "x != y" << std::endl;
    }

    x += y;
    std::cout << "x += y: x = " << x << std::endl;

    x *= y;
    std::cout << "x *= y: x = " << x << std::endl;

    return 0;
}
