#include <iostream>
using namespace std;

struct Node {
    int data; // 4 + 4
    Node* prev; // 8
    Node* next; // 8
};

void AddBack(Node* sent, int data) { // указатель на страж и передача данных
    Node* p = new Node; // создаем ячейку 
    p->data = data; // в нее положим данные 
    p->next = sent;
    p->prev = sent->prev;
    sent->prev->next = p;
    sent->prev = p;
}

void Print(Node* sent) {
    Node* p = sent->next;
    while (p != sent) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

void Clear(Node* sent) { // чтобы не было утечки памяти
    Node* p = sent->next;
    while (p != sent) {
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void DuplicateEven(Node* sent) {
    Node* p = sent->next;
    while (p != sent) {
        if (isPrime(p->data)) {
            Node* q = new Node;
            q->data = p->data;
            q->prev = p;
            q->next = p->next;
            p->next->prev = q;
            p->next = q;
            p = p->next;
        }
        p = p->next;
    }
}

void Remove15(Node* sent) {
    Node* p = sent->next;
    while (p != sent) {
        Node* nextNode = p->next; // Сохраняем указатель на следующий узел
        if (p->data % 15 == 0) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
        p = nextNode; // Переходим к следующему узлу
    }
}

int GetFirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

void SwapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void SortByFirstDigit(Node* sent) {
    bool swapped;
    Node* p;
    Node* last = sent;

    do {
        swapped = false;
        p = sent->next;

        while (p->next != last) {
            // Получаем первую цифру без преобразования в строку
            int firstDigitA = GetFirstDigit(p->data);
            int firstDigitB = GetFirstDigit(p->next->data);
            // Сортируем по невозрастанию первой цифры
            if (firstDigitA < firstDigitB) {
                SwapData(p, p->next);
                swapped = true;
            }
            p = p->next;
        }
        last = p;
    } while (swapped);
}

bool Check(Node* sent) {
    Node* p = sent->next;
    bool increasing = true;
    bool decreasing = true;

    while (p->next != sent) {
        if (p->data > p->next->data) {
            increasing = false;
        }
        if (p->data < p->next->data) {
            decreasing = false;
        }
        p = p->next;
    }

    return increasing || decreasing;
}

int main() {
    Node* sent = new Node;
    sent->next = sent; // -> === (*sent).next
    sent->prev = sent;

    int n;
    cout << "Enter numbers of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int elem;
        cout << "Enter an element > 0: ";
        cin >> elem;
        if (elem > 0) { 
            AddBack(sent, elem);
        } else {
            cout << "Please enter a positive integer!" << endl;
            i--; 
        }
    }

    if (Check(sent)) {
        Remove15(sent);
        DuplicateEven(sent);
    } else {
        SortByFirstDigit(sent);
    }

    Print(sent);

    Clear(sent);
    delete sent;
}