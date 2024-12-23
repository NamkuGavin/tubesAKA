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

void pindahkanSembuh(dataPasien data, pasienSembuh &dataSembuh, int n, int index, int &m) {
    if (index < n) {
        if (data[index].status == "sembuh") {
            dataSembuh[m] = data[index];
            m++;
        }
        pindahkanSembuh(data, dataSembuh, n, index + 1, m);
    }
}

void findMinIndex(pasienSembuh &dataSembuh, int &minIndex, int j, int m) {
    if (j < m) {
        if (dataSembuh[j].usia < dataSembuh[minIndex].usia) {
            minIndex = j;
        }
        findMinIndex(dataSembuh, minIndex, j + 1, m);
    }
}

void seleksiMaksimum(pasienSembuh &dataSembuh, int i, int m) {
    if (i < m) {
        int minIndex = i;
        findMinIndex(dataSembuh, minIndex, i + 1, m);

        Pasien temp = dataSembuh[minIndex];
        dataSembuh[minIndex] = dataSembuh[i];
        dataSembuh[i] = temp;

        seleksiMaksimum(dataSembuh, i + 1, m);
    }
}

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
    int m = 0;

    pindahkanSembuh(data, dataSembuh, 10, 0, m);
    seleksiMaksimum(dataSembuh, 0, m);

    if (m == 0) {
        cout << "Tidak ada pasien yang sembuh." << endl;
    } else {
        cout << "DATA PASIEN YANG SEMBUH:" << endl;
        for (int i = 0; i < m; i++) {
            cout << "Nama: " << dataSembuh[i].nama << endl;
            cout << "Usia: " << dataSembuh[i].usia << endl;
            cout << endl;
        }
    }

    return 0;
}
