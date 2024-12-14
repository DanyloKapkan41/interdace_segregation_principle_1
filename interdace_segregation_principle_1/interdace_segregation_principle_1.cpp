#include <iostream>

using namespace std;
// Інтерфейс для друку
class Printable {
public:
    virtual void print() = 0;
    virtual ~Printable() = default;
};

// Інтерфейс для сканування
class Scannable {
public:
    virtual void scan() = 0;
    virtual ~Scannable() = default;
};

// Інтерфейс для копіювання
class Copyable {
public:
    virtual void copy() = 0;
    virtual ~Copyable() = default;
};

// Клас принтера реалізує тільки потрібний інтерфейс
class Printer : public Printable {
public:
    void print() override {
        cout << "Printing document..." << endl;
    }
};

// Клас сканера реалізує тільки потрібний інтерфейс
class Scanner : public Scannable {
public:
    void scan() override {
       cout << "Scanning document..." << endl;
    }
};

// Клас багатофункціонального пристрою реалізує кілька інтерфейсів
class MultifunctionalDevice : public Printable, public Scannable, public Copyable {
public:
    void print() override {
        cout << "Printing document..." << endl;
    }
    void scan() override {
        cout << "Scanning document..." << endl;
    }
    void copy() override {
        cout << "Copying document..." << endl;
    }
};

int main() {
    Printer printer;
    Scanner scanner;
    MultifunctionalDevice mfd;

    printer.print();
    scanner.scan();
    mfd.print();
    mfd.scan();
    mfd.copy();

    return 0;
}
/*
Порушення принципу ISP
Розглянемо приклад, де цей принцип порушується:

Задача:
Створити систему для роботи з різними пристроями, наприклад, принтерами та багатофункціональними пристроями (сканери, принтери, копіри).

#include <iostream>

// Інтерфейс для всіх пристроїв
class Device {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void copy() = 0;
};
Тепер клас принтера змушений реалізовувати методи, які йому не потрібні:

class Printer : public Device {
public:
    void print() override {
        std::cout << "Printing document..." << std::endl;
    }
    void scan() override {
        // Принтер не підтримує сканування
        std::cout << "Scan not supported." << std::endl;
    }
    void copy() override {
        // Принтер не підтримує копіювання
        std::cout << "Copy not supported." << std::endl;
    }
};
Проблеми:
Надлишкова реалізація:
Принтер змушений реалізовувати методи scan і copy, які не мають сенсу для цього класу.
Порушення принципу ISP:
Інтерфейс Device занадто великий і не відповідає конкретним потребам різних пристроїв.
*/