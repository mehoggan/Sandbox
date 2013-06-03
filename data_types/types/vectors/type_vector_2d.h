#ifndef POINT2D_H_INCLUDED
#define POINT2D_H_INCLUDED

#include <glext.h>
#include <math/sqrt.h>

namespace glext 
{
  /*! \class Point 2D class geometry based
   *  \brief This class defines a 2D vector
   */
  template <typename T>
  class vector_2d
  {
  private:
    /// The first element in the ordered pair
    T _x;
    
    /// The second element in the ordered pair
    T _y;
  
  public:
    /*! \brief default constructor sets both elements using default constructor
     */  
    vector_2d();

    /*! \brief constructor sets both elements to the paramaters provided
     */  
    vector_2d(const T &x, const T &y);

    /*! \brief copy constructor
     */  
    vector_2d(const vector_2d &rhs);

    /*! \brief destructor 
     */
    ~vector_2d();

    /*! \brief assignment uses copy-swap idiom 
     */ 
    vector_2d &operator=(vector_2d rhs);

    /*! \brief setter for x element
     */ 
    void x(const T &x);

    /*! \brief setter for y element
     */
    void y(const T &y);

    /*! \brief setter for both x and y element
     */
    void x_and_y(const T &x, const T &y);

    /*! \brief getter for x element returns a reference to x of type T
     */
    T& xref();

    /*! \brief getter for y element returns a reference to y of type T
     */
    T& yref();
    
    /*! \brief getter for x element returns a copy of x of type T
     */
    T x() const;

    /*! \brief getter for y element returns a copy of y of type T
     */
    T y() const;

    /*! \brief get the magnitude of a 2d vector
     */
    T magnitude() const;
  };

  template <typename U>
  void swap(vector_2d<U> &lhs, vector_2d<U> &rhs);

  template <typename T>
  bool operator<(const vector_2d<T> &lhs, const vector_2d<T> &rhs);

  template <typename T>
  bool operator>(const vector_2d<T> &lhs, const vector_2d<T> &rhs);

  template <typename T>
  bool operator<=(const vector_2d<T> &lhs, const vector_2d<T> &rhs);

  template <typename T>
  bool operator>=(const vector_2d<T> &lhs, const vector_2d<T> &rhs);

  template <typename T>
  bool operator==(const vector_2d<T> &lhs, const vector_2d<T> &rhs);

  template <typename T>
  bool operator!=(const vector_2d<T> &lhs, const vector_2d<T> &rhs);
}
#include "type_vector_2d.inl"
#endif