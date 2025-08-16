
    friend istream &operator >> (istream &is, NhanVien &a){
        getline(is, a.name);
        is >> a.gender >> a.dob >> a.address >> a.tax >> a.signedDay;
        return is;
    }
    friend ostream &operator << (ostream &os, NhanVien a){
        os << a.id << " " << a.name << " " << a.ChuanHoa(a.dob) << " ";
        os << a.address << " " << a.tax << " " << a.ChuanHoa(a.signedDay);
    }
};

int main(){
    NhanVien a;
    cin >> a;