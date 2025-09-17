#ifndef STRING_H
#define STRING_H

#include "Vector.h"


class string {
    private :
    vector<char> str ;
    mutable char* cstr_cache ;
   
    public:
    static const size_t npos ; // Used to indicate not found
    string();
    string(const string&); 
    string(const char*);
    string(string&&) noexcept;
    string& operator=(const string&);
    string& operator=(const char*);
    string& operator+=(const string& );
    string operator+(const string&) ;
    const bool operator==(const string&)const;
    const bool operator!=(const string&)const;
    const bool operator>(const string&)const;
    const bool operator>=(const string&)const;
    const bool operator<(const string&)const;
    const bool operator<=(const string&)const;
    const char* c_str()const;
    size_t size();
    size_t size()const;
    size_t length()const;

    size_t length();
    string substr(size_t pos, size_t len)const;
    string substr(size_t pos)const;
    size_t find(const string&)const;
    size_t rfind(const string& )const;
    size_t compare(const string& )const;
    string& append(const string& );
    string& insert(size_t pos,const string& str);
    string& erase(size_t pos, size_t len);
    const bool starts_with(const string& str)const;
    const bool ends_with(const string& str)const;

    void clear();
    vector<string> split(char delimiter);
    string& join ( vector<string>& , char& );
    string& to_upper();
    string& to_lower();

    ~string();


};

#include "string.tpp"
#endif 