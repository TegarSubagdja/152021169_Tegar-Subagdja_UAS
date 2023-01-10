//Nama : Tegar Subagdja
//NRP : 152021169
//Kelas : DD

#include <iostream>
#include <cmath>

using namespace std;

float pembilang(int n, float x[20], float y[20]) {
    float a, b, c;
    float hasil;

    for (int i = 0; i < n; i++) {
        a += x[i] * y[i];
        b += x[i];
        c += y[i];
    }
    hasil = (n * a) - (b * c);

    cout << "Sigma X     : " << b << endl;
    cout << "Sigma Y     : " << c << endl;
    cout << "Sigma XY    : " << a << endl;
    return hasil;
}

float penyebut(int n, float x[20], float y[20]) {
    float d, e, he, f, g, hf, hg;
    float hasil;

    for (int i = 0; i < n; i++) {
        d += x[i] * x[i];
        e += x[i];
        f += y[i] * y[i];
        g += y[i];
    }
    he = e * e;
    hg = g * g;
    hasil = sqrt((n*d)-he) * sqrt((n*f)-hg);

    cout << "Sigma X^2   : " << d << endl;
    cout << "Sigma Y^2   : " << f << endl;
    cout << "(Sigma X)^2 : " << he << endl;
    cout << "(Sigma Y)^2 : " << hg << endl;
    return hasil;
}


int main() {

    system("cls");

    float x[100];
    float y[100];
    int n;
    float hasilPembilang, hasilPenyebut, rdeterminasi;
    float r;

    //Menentukan Jumlah Data
    cout << "================================" << endl;
    cout << "MASUKAN BANYAK DATA : ";
    cin >> n;
    cout << "================================" << endl;

    for (int i = 0; i < n; i++) {

        do {
            cout << "X[" << i << "] : ";
            cin >> x[i];
            if (x[i] < 0) {
                cout << "Nilai (X) harus lebih dari sama dengan 0!" << endl;
            }
        } while (x[i] < 0);

        do {
            cout << "Y[" << i << "] : ";
            cin >> y[i];
            if (y[i] < 0) {
                cout << "Nilai (Y) harus lebih dari sama dengan 0!" << endl;
            }
        } while (y[i] < 0);

        cout << "--------------------------------" << endl;

    }

    //Porses perhitungan
    hasilPembilang = pembilang(n,x,y);
    hasilPenyebut = penyebut(n,x,y);
    r = hasilPembilang / hasilPenyebut;
    rdeterminasi = (r*r) / 100;

    cout << "================================" << endl;
    cout << "Pembilang : " << hasilPembilang << endl;
    cout << "Penyebut  : " << hasilPenyebut << endl;
    cout << "================================" << endl;

    cout << "Maka korelasi r yang didapat adalah : " << r << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Nilai koefisien determinasi adalah : " << rdeterminasi << endl;
    cout << "------------------------------------------------------" << endl;

    if ((r >= 0) && (r <= 0.09)) {
        cout << "Kekuatan hubungan dan nilai korelasi (r) adalah : Hugungan korelasinya diabaikan" << endl;
    } else if ((r >= 0.10) && (r <= 0.29)) {
        cout << "Kekuatan hubungan dan nilai korelasi (r) adalah : Hugungan korelasi rendah" << endl;
    } else if ((r >= 0.30) && (r <= 0.49)) {
        cout << "Kekuatan hubungan dan nilai korelasi (r) adalah : Hugungan korelasi moderat" << endl;
    } else if ((r >= 0.50) && (r <= 0.70)) {
        cout << "Kekuatan hubungan dan nilai korelasi (r) adalah : Hugungan korelasi sedang" << endl;
    } else if ((r >= 0.50) && (r <= 0.70)) {
        cout << "Kekuatan hubungan dan nilai korelasi (r) adalah : Hugungan korelasi kuat" << endl;
    };
    cout << "------------------------------------------------------" << endl;

    if (r > 0) {
        cout << "Hubungan antara variable X dan Y adalah positif, dimana jika nilai Y akan bertambah, dan juga sebaliknya" << endl;
    } else if (r = 0) {
        cout << "Tidak ada hubungan antara variable X dan Y" << endl;
    } else {
        cout << "Hubungan antara variable X dan Y adalah negatif, dimana jika nilai X bertambah, maka nilai Y akan mengecil, dan juga sebaliknya" << endl;
    }
    cout << "======================================================" << endl;

    return 0;
}