#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <string>

using namespace std;

#if 1
// ref: https://blog.csdn.net/li1615882553/article/details/83716065
//        https://www.jianshu.com/p/4931d461466f
// istream_iterator source code: https://code.woboq.org/gcc/include/c++/7.2.1/bits/stream_iterator.h.html#std::istream_iterator::_M_stream
//                               https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stream_iterator.h
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

            iterator() : _ok(false) {
                // cout << "iterator ctor" << endl;
            }
            iterator(istream& is) : _iss(&is) {
                cout << "itrator istream ctor" << endl;
                read();
            }

            iterator& operator++() {        // use for ++iterator
                // cout << "iterator, operator++" << endl;
                read();
                return *this;
            }

            iterator operator++(int) {      // use for iterator++
                cout << "iterator, operator++(int)" << endl;
                iterator tmp(*this);
                read();
                return tmp;
            }

            string* operator->() const {
                return __addressof((operator*()));
            }

            string& operator*() {
                // cout << "iterator, operator*" << endl;
                return str;
            }

            bool operator==(const iterator& rhs) {
                cout << "iterator operator ==" << endl;
                // return (this->_ok == rhs._ok);
                // return (this->_ok == rhs._ok) && (!this->_ok || this->_iss == rhs._iss);
                return (this->_ok == rhs._ok) && (!this->_ok);
            }

            bool operator!=(const iterator& rhs) {
                cout << "iterator operator !=" << endl;
                // return !(this->_ok == rhs._ok);
                // return !( (this->_ok == rhs._ok) && (!this->_ok || this->_iss == rhs._iss));
                return !( (this->_ok == rhs._ok) && (!this->_ok));
            }

        private:
            istream* _iss;
            string str;
            bool _ok;

            void read() {
                // cout << "iterator, read()" << endl;
                _ok = (_iss && *_iss) ? true : false;
                if (_ok) {
                    *_iss >> str;    // 遇到'\n'停止且忽略前綴空白及空白行
                    // getline(*_iss, str);    // 預設遇到'\n'停止, 不會忽略前綴空白及空白行
                    // getline(*_iss, str, ' ');   // 遇到空白停止
                    _ok = *_iss ? true : false;
                } 
                // if (_iss && !(*_iss >> str))
                // {
                //     _iss = 0;
                //     _ok = false;    
                // }
            }
    };

    Solution(istream& is) : _is(&is) {
        cout << "Solution istream ctor" << endl;
    }

    Solution() {
        cout << "Solution ctor" << endl;
    }

    iterator begin() {
        cout << "Solution begin" << endl;
        return iterator(*_is);
    }

    iterator end() {
        // cout << "Solution end" << endl;
        return iterator();
    }

private:
    istream* _is;
};
#endif

#if 1
template <typename T, typename _CharT = char,
           typename _Traits = char_traits<_CharT>>
class Solution2 {
public:
    class iterator {
        public:
            typedef string              value_type;
            typedef string*             pointer;
            typedef string&             reference;
            typedef int                 difference_type;
            typedef input_iterator_tag  iterator_category;

            typedef _CharT                         char_type;
            typedef _Traits                        traits_type;
            typedef basic_istream<_CharT, _Traits> istream_type;

            iterator() : _ok(false) {
                // cout << "iterator ctor" << endl;
            }
            iterator(istream_type& is) : _iss(&is) {
                cout << "itrator istream ctor" << endl;
                read();
            }

            iterator& operator++() {        // use for ++iterator
                // cout << "iterator, operator++" << endl;
                read();
                return *this;
            }

            iterator operator++(int) {      // use for iterator++
                cout << "iterator, operator++(int)" << endl;
                iterator tmp(*this);
                read();
                return tmp;
            }

            string* operator->() const {
                return __addressof((operator*()));
            }

            string& operator*() {
                // cout << "iterator, operator*" << endl;
                return str;
            }

            bool operator==(const iterator& rhs) {
                cout << "iterator operator ==" << endl;
                // return (this->_ok == rhs._ok);
                // return (this->_ok == rhs._ok) && (!this->_ok || this->_iss == rhs._iss);
                return (this->_ok == rhs._ok) && (!this->_ok);
            }

            bool operator!=(const iterator& rhs) {
                cout << "iterator operator !=" << endl;
                // return !(this->_ok == rhs._ok);
                // return !( (this->_ok == rhs._ok) && (!this->_ok || this->_iss == rhs._iss));
                return !( (this->_ok == rhs._ok) && (!this->_ok));
            }

        private:
            istream_type* _iss;
            string str;
            bool _ok;

            void read() {
                // cout << "iterator, read()" << endl;
                _ok = (_iss && *_iss) ? true : false;
                if (_ok) {
                    *_iss >> str;    // 遇到'\n'停止且忽略前綴空白及空白行
                    // getline(*_iss, str);    // 預設遇到'\n'停止, 不會忽略前綴空白及空白行
                    // getline(*_iss, str, ' ');   // 遇到空白停止
                    _ok = *_iss ? true : false;
                } 
                // if (_iss && !(*_iss >> str))
                // {
                //     _iss = 0;
                //     _ok = false;    
                // }
            }
    };

    typedef basic_istream<_CharT, _Traits> istream_type;

    Solution2(istream_type& is) : _is(&is) {
        cout << "Solution2 istream ctor" << endl;
    }

    Solution2() {
        cout << "Solution2 ctor" << endl;
    }

    iterator begin() {
        cout << "Solution2 begin" << endl;
        return iterator(*_is);
    }

    iterator end() {
        // cout << "Solution end" << endl;
        return iterator();
    }

private:
    istream_type* _is;
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

bool is_number(const string &str) {
    return (!str.empty() && (str.find_first_not_of("-+0123456789") == string::npos));
}

int main(int argc, char** argv) {

#if 1
    // filebuf buf;
    // if(buf.open("test.txt", ios::in) == nullptr) {
    //     cout << "fail to open file" << endl;
    //     return 0;
    // }
    // istream is(&buf);
    // Solution<istream> sol(is);

    // istream &iis(cin);
    // Solution<istream> sol2(iis);

    // -----  test Solution 2 -----------------------
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    Solution2<istream> sol_if(ifs);

    // filebuf buf;
    // if(buf.open("test.txt", ios::in) == nullptr) {
    //     cout << "fail to open file" << endl;
    //     return 0;
    // }
    // istream is(&buf);
    // Solution2<istream> sol_if(is);

    // Solution2<istream> sol_if(cin);
    // ----------------------------------------------

    // Solution<istream>::iterator iter = sol.begin(); 
    // Solution<istream>::iterator ed = sol.end();
    vector<int> res;

    cout << "test6" << endl;

    // if (iter != ed) {
    //     string str = *iter;
    //     cout << str << endl;
    //     ++iter;
    //     string str2 = *iter;
    //     cout << str2 << endl;
    //     iter++;
    //     string str3 = *iter;
    //     cout << str3 << endl;
    // } else {
    //     cout << "iter == ed" << endl;
    // }

    // string ss;
    // while (iter != ed) {
    //     ss = *iter;
    //     cout << ss << endl;
    //     ++iter;
    // }

    for (Solution2<istream>::iterator beg = sol_if.begin(); beg != sol_if.end(); ++beg) {
    // for (Solution<istream>::iterator beg = sol.begin(); beg != sol.end(); ++beg) {
        cout << *beg << endl;
        // if (is_number(*beg)) {
        //     res.push_back(stoi(*beg));
        // }
    }

    cout << "finish!" << endl;

    // for (auto &num : res) {
    //     cout << num << endl;
    // }
#endif
    // string str1, str2;
    // cout << "inser two strings: ";

    // istream_iterator<string> iit(cin);
    // istream_iterator<string> eos;

    // if (iit != eos)
    //     str1 = *iit;
    // ++iit;
    // if (iit != eos)
    //     str2 = *iit;

    // cout << "str1: " << str1 << ", str2: " << str2 << endl;

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
        
        // if (is_digit(str3))
        if (is_number(str3))
            cout << "nums: " << stoi(str3) << endl;
    }
#endif

// test for fixed_array class
#if 0
    fixed_array<double> farray(3);
    farray[0] = 3.5;
    farray[1] = 4.7;
    farray[2] = 8;
    
    // fixed_array<double>::iterator ite;
    // fixed_array<double>::iterator ite = farray.begin();
    // cout << *(++ite) << endl;
    // ite++;
    // cout << *ite << endl;

    for (fixed_array<double>::iterator iter = farray.begin(); iter != farray.end(); ++iter) {
    //     cout << *iter << endl;
    }
    
    cout << endl;
#endif

    return 0;
}