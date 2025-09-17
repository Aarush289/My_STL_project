#pragma once
#include "string.h"


const size_t string::npos = static_cast<size_t>(-1);
 // Initialize npos to the maximum value of size_t
string ::string() : str() {
    cstr_cache = nullptr; // Initialize cstr_cache to nullptr
    // No need to initialize str, as vector<char> already does that
};

string ::string(const string &other)
{
    this->str = other.str;
    cstr_cache = nullptr; // Initialize cstr_cache to nullptr
}

string::string(const char *other)
{
    while (*other != 0)
    {
        str.push_back(*other);
        other++;
    }
    cstr_cache = nullptr; // Initialize cstr_cache to nullptr
}

size_t string:: size(){return str.size();}

size_t string:: length(){return str.size();}

size_t string:: size()const{return str.size();}

size_t string:: length()const{return str.size();}

string::string(string &&other) noexcept : str(std::move(other.str)) {
    cstr_cache = other.cstr_cache; // Move the cache pointer
    other.cstr_cache = nullptr; // Set the moved-from object's cache to nullptr
};

string &string::operator=(const string &other)
{
    if (this != &other)
    {
        str = other.str;
    }
    return *this;
}

string& string::operator=(const char *other)
{
    str.clear();
    while (*other != 0)
    {
        str.push_back(*other);
        other++;
    }
    return *this;
}

string& string:: operator+=(const string& other){
    for(size_t i=0;i< other.str.size();i++){
        str.push_back(other.str[i]);
    }
    return *this;
}

string string:: operator+(const string& other){
    string result = *this;
    result+=other;
    return result;
}

const bool string:: operator==(const string& other)const{
    if(str.size() != other.str.size()){return false;}
    for(size_t i=0;i< str.size();i++){
        if(str[i]!=other.str[i]){return false;}
    }
    return true;
}

const bool string:: operator!=(const string& other)const{
   return !(*this == other);
}

const bool string:: operator>(const string& other)const{
    if(*this == other){return false;}
    size_t len;
    if(str.size() < other.str.size()){len= str.size();}
    else{len = other.str.size();}
    for(size_t i=0;i<len;i++){
        if(str[i]<other.str[i]){return false;}
        if(str[i]>other.str[i]){return true;}
    }
    return str.size() > other.str.size() ;
}

const bool string:: operator<(const string& other)const{
    if(*this == other){return false;}
    return !(*this>other) ;
}

const bool string:: operator<=(const string& other)const{
    return !(*this>other) ;
}

const bool string:: operator>=(const string& other)const{
    return !(*this<other) ;
}

const char* string::c_str() const {
    if(cstr_cache){delete[] cstr_cache; cstr_cache = nullptr;} // Clear previous cache if exists
    if (!cstr_cache) {
        cstr_cache = new char[str.size() + 1];
        for (size_t i = 0; i < str.size(); ++i) {
            cstr_cache[i] = str[i];
        }
        cstr_cache[str.size()] = '\0';
    }
    return cstr_cache;
}




string string:: substr(size_t pos, size_t len)const{
    if(pos + len > str.size()){throw std::overflow_error("substring range out of bounds");}
    string substr;
    for(size_t i=pos;i<pos+len;i++){
        substr.str.push_back(str[i]);
    }
    return substr;
}

string string:: substr(size_t pos)const{
    string substr;
    for(size_t i=pos;i<str.size();i++){
        substr.str.push_back(str[i]);
    }
    return substr;
}

// KMP Algorithm to find the first occurence 
size_t string::find(const string& pattern) const {
    size_t n = str.size();
    size_t m = pattern.str.size();

    if (m == 0) return 0;
    if (m > n) return npos;

    // Step 1: Build LPS array
    vector<size_t> lps(m, 0);
    size_t len = 0, i = 1;
    while (i < m) {
        if (pattern.str[i] == pattern.str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }

    // Step 2: Search pattern in text
    size_t j = 0; // index for pattern
    for (size_t i = 0; i < n;) {
        if (str[i] == pattern.str[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j;  // match found
        }

        if (i < n && str[i] != pattern.str[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return npos; // not found
}


size_t string::rfind(const string& pattern) const {
    size_t n = str.size();
    size_t m = pattern.str.size();

    if (m == 0) return 0;
    if (m > n) return npos;

    // Step 1: Build LPS array
    vector<size_t> lps(m, 0);
    size_t len = 0, i = 1;
    while (i < m) {
        if (pattern.str[i] == pattern.str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }

    // Step 2: Search pattern in text
    i = 0;
    size_t j = 0;
        int last_occurrence = -1;

        while (i < n) {
            if (str[i] == pattern.str[j]) {
                i++, j++;
                if (j == m) {
                    last_occurrence = i - m;
                    j = lps[j - 1]; // continue searching
                }
            } else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return last_occurrence;
}

size_t string:: compare(const string& other) const{
    if(*this == other){return 0;}
    return (*this > other ? 1 : npos);
}

string& string:: append(const string& other){
    for(size_t i=0;i<other.str.size();i++){
        str.push_back(other.str[i]);
    }
    return *this;
}

string& string::insert(size_t pos, const string& other){
    if (pos > str.size()) {
        throw std::out_of_range("Insert position out of bounds");
    }

    string result;

    for (size_t i = 0; i < pos; ++i) {
        result.str.push_back(str[i]);
    }

    result.append(other);  
    for (size_t i = pos; i < str.size(); ++i) {
        result.str.push_back(str[i]);
    }
    str = result.str;  
    return *this;
}

string& string:: erase(size_t pos , size_t len){
    if (pos > str.size()) {
        throw std::out_of_range("Starting position is out of bounds.");
    }

    if(pos + len > str.size()){throw std:: out_of_range("Attempt to erase beyond string size .");}

    string result;
    for(size_t i=0;i<pos ; i++){
        result.str.push_back(str[i]);
    }
    for(size_t i = pos+len ; i<str.size();i++){
         result.str.push_back(str[i]);
    }
    str = result.str;
    return *this;
}

const bool string:: starts_with(const string& other)const{
    if(str.size() < other.str.size()){return false;}
    for(size_t i=0;i<other.str.size();i++){
        if(str[i]!=other.str[i]){return false;}
    }
    return true;
}

const bool string:: ends_with(const string& other)const{
    if(str.size() < other.str.size()){return false;}
    for(size_t i=0;i<other.str.size();i++){
        if(str[str.size()-1-i]!=other.str[other.str.size()-1-i]){return false;}
    }
    return true;
}

void string :: clear(){
    str.clear();
    if(cstr_cache) delete[] cstr_cache;
    cstr_cache = nullptr; // Ensure cache is cleared
}
vector<string> string::split(char del) {
    vector<string> vec;
    string temp;
    temp.clear();

    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == del) {
            vec.push_back(temp);
            temp.clear();
        } else {
            temp.str.push_back(str[i]);  
        }
    }

    vec.push_back(temp); 
    return vec;
}

string& string:: join(vector<string>& v, char& del){
    string result;
    for(size_t i=0;i<v.size();i++){
        result.append(v[i]);
        result.str.push_back(del);

    }
    result.str.pop_back();
    str = result.str;
    return *this;
}

string& string:: to_lower(){
    for(size_t i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z'){str[i]+='a'-'A';}
    }
    return *this;
}

string& string :: to_upper(){
    for(size_t i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z'){str[i]-='a'-'A';}
    }
    return *this;
}

string:: ~string(){
    str.clear();
     if (cstr_cache) delete[] cstr_cache;
     cstr_cache = nullptr; // Ensure cache is cleared
}


