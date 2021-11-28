#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

#if 1
// ref: https://blog.csdn.net/li1615882553/article/details/83716065
        https://www.jianshu.com/p/4931d461466f
template <typename T>
class Solution {
public:
    class iterator {
        public:
            typedef string              value_type;
            typedef string*             pointer;
            typedef string&             reference;
            typedef int                 difference_type;
            typedef input_iterator_tag  iterator_category;

            iterator() : end_marker(false) {
                cout << "iterator ctor" << endl;
            }
            iterator(istream& is) : _iss(&is) {
                cout << "itrator istream ctor" << endl;
            }

            // iterator& operator++() {     // use for ++iterator
            //     return *this;
            // }

            // iterator operator++(int) {  // use for iterator++
            //     iterator tmp(*this);
            //     ++(*this);
            //     // ++_ptr;
            //     return tmp;
            // }

            // string* operator->() {
            //     return &str;
            // }

            // string& operator*() {
            //     return str;
            // }

        private:
            istream* _iss;
            string str;
            bool end_marker;
    };

    Solution(istream& is) : _is(&is) {
        cout << "Solution istream ctor" << endl;
    }

    Solution() {
        cout << "Solution ctor" << endl;
    }

    // iterator begin();
    // iterator end();

    iterator begin() {
        cout << "Solution begin" << endl;
        return iterator(*_is);
    }

    iterator end() {
        cout << "Solution end" << endl;
        return iterator();
    }

private:
    istream* _is;
};
#endif

template <typename T>
class fixed_array {
public:

    class iterator {
        public:
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(T* ptr) : _ptr(ptr) {
                cout << "ite, ctor(ptr)" << endl;
            }
            iterator() {
                cout << "ite ctor" << endl;
            }

            iterator& operator++() {     // use for ++iterator
                cout << "ite, operator++" << endl;
                ++_ptr;
                return *this;
            }

            iterator operator++(int) {  // use for iterator++
                cout << "ite, operator++(int)" << endl;
                iterator tmp(*this);
                ++(*this);
                // ++_ptr;
                return tmp;
                // return *this;
            }

            T* operator->() {
                cout << "ite, operator->" << endl;
                return _ptr;
            }

            T& operator*() {
                cout << "ite, operator*" << endl;
                return *_ptr;
            }

            bool operator==(const iterator& rhs) {
                cout << "ite, operator==" << endl;
                return _ptr == rhs._ptr;
            }

            bool operator!=(const iterator& rhs) {
                cout << "ite, operator!=" << endl;
                return _ptr != rhs._ptr;
            }

        private:
            T* _ptr;
    };

    fixed_array(int size) : _size(size) {
        // cout << "fixed_array ctor" << endl;
        _data = new T[_size];
    }

    int size() const { 
        // cout << "fixed_array size()" << endl;
        return _size ;
    };

    T& operator[](int idx) {
        // assert(idx < _size);
        return _data[idx];
    }

    iterator begin() {
        return iterator(_data);
    }

    iterator end() {
        return iterator(_data + _size);
    }

private:
    T* _data;
    int _size;
};

bool is_digit(const string &str) {
    return (!str.empty() && all_of(str.begin(), str.end(), ::isdigit));
}

int main(int argc, char** argv) {

    // Solution<istream> solution;
    filebuf buf;
    if(buf.open("test.txt", ios::in) == nullptr) {
        cout << "fail to open file" << endl;
        return 0;
    }
    istream is(&buf);
    Solution<istream> sol(is);

    // Solution<istream>::iterator iter;
    Solution<istream>::iterator iter = sol.begin(); 
    Solution<istream>::iterator ed = sol.end();

// test for how to use istream 
#if 0
    filebuf buf;
    if(buf.open("test.txt", ios::in) == nullptr) {
        cout << "fail to open file" << endl;
        return 0;
    }

    istream is(&buf);
    string str1, str2;
    int count = 0;

    getline(is, str1);
    // count = is.gcount();    // use std::getline will be stay at 0
    cout << "str1: " << str1 << ", str1 to int: " << stoi(str1) << endl;

    getline(is, str2);
    cout << "str2: " << str2 << ", str2 to int: " << stoi(str2) << endl;

    int sum = stoi(str1) + stoi(str2);
    cout << "sum: " << sum << endl;

    string str3;
    int nums = 0;
    while (!is.eof()) {
        getline(is, str3);
        cout << "str3: " << str3 << endl;
        
        if (is_digit(str3))
            cout << "nums: " << stoi(str3) << endl;
    }
#endif

// test for fixed_array class
#if 0
    fixed_array<double> farray(3);
    farray[0] = 3.5;
    farray[1] = 4.7;
    farray[2] = 8;
    
    fixed_array<double>::iterator ite;
    // fixed_array<double>::iterator ite = farray.begin();
    // cout << *(++ite) << endl;
    // ite++;
    // cout << *ite << endl;

    // for (fixed_array<double>::iterator iter = farray.begin(); iter != farray.end(); ++iter) {
    //     cout << *iter << endl;
    // }
    
    cout << endl;
#endif

    return 0;
}