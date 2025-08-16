#include <bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    string maSV, hoTen, lop, ngaySinh;
    float GPA;
public:
    SinhVien() {
        maSV = hoTen = lop = ngaySinh = "";
        GPA = 0;
    }
    
    void nhap() {
        maSV = "B20DCCN001";
       
        getline(cin, hoTen);
        stringstream ss(hoTen);
        hoTen = "";
        string word;
        while (ss >> word) {
            for (char &c : word) c = tolower(c);
            word[0] = toupper(word[0]);
            hoTen += word + " ";
        }
        hoTen.pop_back(); 
        
        getline(cin, lop);
        
        getline(cin, ngaySinh);
        string day, month, year;
        stringstream ssDate(ngaySinh);
        getline(ssDate, day, '/');
        getline(ssDate, month, '/');
        getline(ssDate, year);
        if (day.size() == 1) day = "0" + day;
        if (month.size() == 1) month = "0" + month;
        ngaySinh = day + "/" + month + "/" + year;
        cin >> GPA;
    }
    
    void xuat() {
        cout << maSV << " " << hoTen << " " << lop << " " 
             << ngaySinh << " " << fixed << setprecision(2) << GPA << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}
