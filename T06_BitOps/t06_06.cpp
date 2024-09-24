#include <iostream>
#include <bitset>
using namespace std;


int main() {
    uint8_t x = 0b00111000;
    //  x - 1 = 0b00110111
    //  x & (x - 1) = 0b00110000  // ������� ����������� ��
    //  (x & (x - 1)) > 0
    //  ���� ����� false, ���� x - ����, ��� ������ �����

    int8_t y = 0b00101110;
    cout << bitset<8>(y) << endl;
    cout << bitset<8>(~y + 1) << endl;
    cout << bitset<8>(-y) << endl;
    // y & (-y) = y & (~y + 1)
    cout << (y & (-y)) << endl;
    // ������ �����, �� ������� ���������� ��� �����
    return 0;
}
