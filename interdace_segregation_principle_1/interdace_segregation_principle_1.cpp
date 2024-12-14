#include <iostream>

using namespace std;
// ��������� ��� �����
class Printable {
public:
    virtual void print() = 0;
    virtual ~Printable() = default;
};

// ��������� ��� ����������
class Scannable {
public:
    virtual void scan() = 0;
    virtual ~Scannable() = default;
};

// ��������� ��� ���������
class Copyable {
public:
    virtual void copy() = 0;
    virtual ~Copyable() = default;
};

// ���� �������� ������ ����� �������� ���������
class Printer : public Printable {
public:
    void print() override {
        cout << "Printing document..." << endl;
    }
};

// ���� ������� ������ ����� �������� ���������
class Scanner : public Scannable {
public:
    void scan() override {
       cout << "Scanning document..." << endl;
    }
};

// ���� ��������������������� �������� ������ ����� ����������
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
��������� �������� ISP
���������� �������, �� ��� ������� ����������:

������:
�������� ������� ��� ������ � ������ ����������, ���������, ���������� �� ��������������������� ���������� (�������, ��������, �����).

#include <iostream>

// ��������� ��� ��� ��������
class Device {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void copy() = 0;
};
����� ���� �������� �������� ������������ ������, �� ���� �� ������:

class Printer : public Device {
public:
    void print() override {
        std::cout << "Printing document..." << std::endl;
    }
    void scan() override {
        // ������� �� ������� ����������
        std::cout << "Scan not supported." << std::endl;
    }
    void copy() override {
        // ������� �� ������� ���������
        std::cout << "Copy not supported." << std::endl;
    }
};
��������:
���������� ���������:
������� �������� ������������ ������ scan � copy, �� �� ����� ����� ��� ����� �����.
��������� �������� ISP:
��������� Device ������� ������� � �� ������� ���������� �������� ����� ��������.
*/