#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Nhập số lượng khách hàng: ";
    cin >> n;
    vector<int> s(n + 1), e(n + 1), v(n + 1);
    s[0] = 0; e[0] = 0; v[0] = 0; // chèn đầu list các phần tử 0

    // Nhập dữ liệu cho từng khách hàng
    for (int i = 1; i <= n; i++) {
        cout << "Nhập thời gian bắt đầu, thời gian kết thúc và lợi nhuận cho khách hàng " << i << ": ";
        cin >> s[i] >> e[i] >> v[i];
    }

    // Sắp xếp các cuộc họp theo thời gian kết thúc tăng dần
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (e[i] < e[j]) {
                // Đổi chỗ các phần tử để sắp xếp
                swap(e[i], e[j]);
                swap(s[i], s[j]);
                swap(v[i], v[j]);
            }
        }
    }

    // Xây dựng bảng phương án động
    vector<int> f(n + 1, 0);
    f[1] = v[1];

    for (int i = 1; i <= n; i++) {
        f[i] = v[i]; // Khởi tạo giá trị f[i] bằng giá trị lợi nhuận v[i]
        for (int j = 1; j < i; j++) {
            if (s[i] >= e[j] && f[i] < f[j] + v[i]) {
                // Nếu cuộc họp i có thể chọn sau cuộc họp j và lợi nhuận được tăng lên
                f[i] = f[j] + v[i];
            }
        }
    }

    // Tìm giá trị lớn nhất trong bảng f để lấy lợi nhuận tối đa
    int max_profit = *max_element(f.begin(), f.end());
    cout << "Lợi nhuận tối đa là: " << max_profit << endl;

    return 0;
}
