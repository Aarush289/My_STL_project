#ifndef STRING_H
#define STRING_H

#include "Vector.h"

/**
 * @file string.hpp
 * @brief simple std::string like class backed by vector<char>
 * 
 * This class implements a lightweight string with basic concatenation,
 * search, substring, case conversion, and splitting/joining utilities.
 * It maintains an optional cached C-string view for interop via @ref c_str().
 */
/**
 * @class string
 * @brief A simple dynamic string backed by @ref vector<char>.
 * 
 * The implementation stores characters in a contiguous buffer and exposes
 * common string operations (append/insert/erase/find/substr/compare).
 * A mutable cache holds a null-terminated snapshot for @ref c_str().
 * 
 */
class string {
    private :
    vector<char> str ;              ///< character storage ( Not necessarily null terminated)
    mutable char* cstr_cache ;      ///< Null-terminated cache for @ref c_str()
   
    public:
    static const size_t npos ; // Used to indicate not found
    ///@name Contructor / destructor / assignment
    ///@{
    string();
    string(const string&);              ///< copy constructor
    string(const char*);                ///< copy constructor for c-type string
    string(string&&) noexcept;          ///< move constructor
    string& operator=(const string&);   ///< copy operator
    string& operator=(const char*);     ///< copy operator for c-type string
    ~string();
    ///@}

    /// Concatenation 
    string& operator+=(const string& );
    string operator+(const string&) ;

    // Comparison operators 
    bool operator==(const string&)const;
    bool operator!=(const string&)const;
    bool operator>(const string&)const;
    bool operator>=(const string&)const;
    bool operator<(const string&)const;
    bool operator<=(const string&)const;
    
    // Access / Size
    const char* c_str()const;
    size_t size();
    size_t size()const;
    size_t length()const;
    size_t length();

    ///@name Substring /search
    ///@{
    string substr(size_t pos, size_t len)const;     ///< Returns substring from index "pos" of given length as string
    string substr(size_t pos)const;                 ///< Returns substring starting at index "pos" upto the last element of string ( of length "length-pos")
    size_t find(const string&)const;                ///< substring search in O(N+M) time complexity using KMP algorithm ,returns index of first occurrence of the substring
                                                    /// returns -1 incase substring is not found in the string else the index of first character of the substring found
    size_t rfind(const string& )const;              /// Substring search similar to @ref find but it returns the index of last occurance
    int compare(const string& )const;
    ///@}

    // Modifiers 
    string& append(const string& );
    string& insert(size_t pos,const string& str);
    string& erase(size_t pos, size_t len);
    void clear();

    // Prefix/suffix
    bool starts_with(const string& str)const;     ///< returns true iff str is prefix of the string
    bool ends_with(const string& str)const;       ///< returns true iff str is suffix of the string


    // split /join/ case transformation
    vector<string> split(char delimiter);
    string& join ( vector<string>& , char& );
    string& to_upper();
    string& to_lower();

   


};

#include "./Details/string.tpp"
#endif 