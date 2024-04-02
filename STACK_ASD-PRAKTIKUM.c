#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Fungsi untuk memeriksa apakah string mengandung kurung yang seimbang
bool isBalanced(const char *s) {
    int len = strlen(s); // Menghitung panjang string
    char stack[len]; // Membuat stack untuk menyimpan karakter kurung
    int top = -1; // Menandakan posisi teratas stack

    // Iterasi melalui setiap karakter dalam string
    for (int i = 0; i < len; i++) {
        // Jika karakter adalah kurung buka, masukkan ke dalam stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else if (s[i] == ')' && top >= 0 && stack[top] == '(') { // Jika karakter adalah kurung tutup sesuai, pop stack
            top--;
        } else if (s[i] == '}' && top >= 0 && stack[top] == '{') {
            top--;
        } else if (s[i] == ']' && top >= 0 && stack[top] == '[') {
            top--;
        } else { // Jika karakter tidak sesuai, string tidak seimbang
            return false;
        }
    }

    // String seimbang jika stack kosong
    return top == -1;
}

// Fungsi utama
int main() {
    char str[100]; // Deklarasi array untuk menyimpan string

    printf("Masukkan string: "); // Meminta input dari pengguna
    scanf("%s", str); // Membaca input string

    // Memeriksa apakah string seimbang menggunakan fungsi isBalanced
    if (isBalanced(str)) {
        printf("YES\n"); // Jika seimbang, cetak YES
    } else {
        printf("NO\n"); // Jika tidak seimbang, cetak NO
    }

    return 0; // Mengakhiri program
}
