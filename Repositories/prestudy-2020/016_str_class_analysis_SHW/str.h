#ifndef STR_H
#define STR_H
#include <iostream>

//-----------------------------------------------
// This file is not complete. You will need to
// add prototypes for the needed member functions
// based on the usage of str_test.cpp.
//-----------------------------------------------
class Str {
public:
  /**
   * Default constructor should create a string
   * equal to ""
   */
  Str();

  ~Str();
  /**
   * Character array constructor
   *  If s is NULL create a string that contains
   *  only the null character (i.e. "")
   */
  Str(const char* s);

  // ADDED NEW FUNCTION
  // String constructor
  Str(const Str& s);

  
  /**
   * Assignment operator
   * If s is NULL, set this to a blank string ("")
   */
  Str& operator=(const char* s);

  // ADDED NEW FUNCTION
  // Assignment operator for when the other side is a Str object, not a char*
  Str& operator=(const Str& s);

  
  /**
   * Str concatenation-assignment operator
   *  E.g. s += t
   */
  Str& operator+=(const Str& s);
  /**
   * Char. array concatenation-assignment operator
   *  E.g. s += " more"
   *  If s is NULL simply return this Str
   */
  Str& operator+=(const char* s);

  /**
   * Return the size of the string (e.g. "Hello" => 5)
   */
   size_t size() const;

   /**
    * Non-const index operator
    *  E.g.  str s1("103");  s1[2] = '4';
    * Should throw std::out_of_range if invalid index is passed
    */
   char& operator[](unsigned int i);
   /**
    * Const index operator
    *  E.g. str s1("104");  char c = s1[2];
    * Should throw std::out_of_range if invalid index is passed
    */
   char const & operator[](unsigned int i) const;

   
   /**
    * String concatenation operator
    *  E.g. str s1; cout << s1 + " world" << endl;
    *  If rhs is NULL, simply return a copy of this Str
    */

   //all additional operators that were required to run the tests

   Str operator+(const char* rhs) const;

   Str operator+(const Str& rhs) const;

   bool operator==(const Str& rhs);

   bool operator!=(const Str& rhs);

   bool operator>(const Str& rhs);
   
   bool operator<(const Str& rhs);


   /**
    * istream (<<) operator
    */
   friend std::istream& operator>>(std::istream& istr, Str& s);
   friend std::ostream& operator<<(std::ostream& ostr, const Str& s);
   private:
   // You must use this data member
   char* data_;
   // New data member size_ to track size
   int size_;
   // You may add another member of two if needed
   // (e.g. think about whether it may save time to store
   //  the size in a separate member)

 };
#endif