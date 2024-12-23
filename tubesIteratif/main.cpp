#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    int usia;
    string status;
};

const int nData = 10;
typedef Pasien dataPasien[nData];
typedef Pasien pasienSembuh[nData];

int main() {
    dataPasien data = {
        {"Andi", 25, "sembuh"},
        {"Budi", 30, "sakit"},
        {"Citra", 22, "sembuh"},
        {"Dewi", 35, "sakit"},
        {"Eka", 28, "sembuh"},
        {"Fajar", 40, "sakit"},
        {"Gita", 19, "sembuh"},
        {"Hadi", 50, "sakit"},
        {"Indra", 27, "sembuh"},
        {"Joko", 33, "sakit"}
    };

    pasienSembuh dataSembuh;
    int i, j, maxIdx, m = 0;
    Pasien temp;

    for (i = 0; i < 10; i++) {
        if (data[i].status == "sembuh") {
            dataSembuh[m] = data[i];
            m++;
        }
    }

    for (i = 1; i < m; i++) {
        maxIdx = i - 1;
        for (j = i; j < m; j++) {
            if (dataSembuh[maxIdx].usia > dataSembuh[j].usia) {
                maxIdx = j;
            }
        }
        temp = dataSembuh[maxIdx];
        dataSembuh[maxIdx] = dataSembuh[i - 1];
        dataSembuh[i - 1] = temp;
    }

    if (m == 0) {
        cout << "Tidak ada pasien yang sembuh." << endl;
    } else {
        cout << "DATA PASIEN YANG SEMBUH:" << endl;
        for (i = 0; i < m; i++) {
            cout << "Nama: " << dataSembuh[i].nama << endl;
            cout << "Usia: " << dataSembuh[i].usia << endl;
            cout << endl;
        }
    }

    return 0;
}
