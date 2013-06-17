#ifndef VECTOR4D_H_INCLUDED
#define VECTOR4D_H_INCLUDED

#include <glext.h>
#include <math/sqrt.h>

#include <cassert>

namespace glext 
{
  /*! \class Point 3D class geometry based
   *  \brief This class defines a 3D vector
   */
  template <typename T>
  class vector_4d
  {
  private:
    /// The first element in the ordered pair
    T _x;
    
    /// The second element in the ordered pair
    T _y;
 
    /// The third element in the ordered pair
    T _z;

    /// The fourth element in the ordered pair
    T _w;

  public:
    /*! \brief default constructor sets three elements using default constructor
     */  
    vector_4d();

    /*! \brief constructor sets three elements to the paramaters provided
     */  
    vector_4d(const T &x, const T &y, const T &z, const T &w);

    /*! \brief copy constructor
     */  
    vector_4d(const vector_4d &rhs);

    /*! \brief destructor 
     */
    ~vector_4d();

    /*! \brief assignment uses copy-swap idiom 
     */ 
    vector_4d &operator=(vector_4d rhs);

    /*! \brief index operator wich allows you to change internal data
     */
    T &operator[] (unsigned short index);

    /*! \brief index operator wich allows you to change internal data
     */
    const T &operator[] (unsigned short index) const;

    /*! \brief setter for x element
     */ 
    void x(const T &x);

    /*! \brief setter for y element
     */
    void y(const T &y);

    /*! \brief setter for z element
     */
    void z(const T &z);

    /*! \brief setter for z element
     */
    void w(const T &w);

    /*! \brief setter for three elements x and y and z 
     */
    void x_and_y_and_z_and_w(const T &x, const T &y, const T &z, const T &w);

    /*! \brief getter for x element returns a reference to x of type T
     */
    T& xref();

    /*! \brief getter for y element returns a reference to y of type T
     */
    T& yref();

    /*! \brief getter for z element returns a reference to z of type T
     */
    T& zref();

    /*! \brief getter for w element returns a reference to w of type T
     */
    T& wref();

    /*! \brief getter for x element returns a copy of x of type T
     */
    T x() const;

    /*! \brief getter for y element returns a copy of y of type T
     */
    T y() const;

    /*! \brief getter for z element returns a copy of z of type T
     */
    T z() const;
    
    /*! \brief getter for w element returns a copy of w of type T
     */
    T w() const;
    
    /*! \brief get the magnitude of a 4d vector
     */
    T magnitude() const;
    
    /*! \brief normalize the instace of this vector
     */
    void normalize();

    /*! \brief dot prodcuct between this vector and another
     */
    T dot(const vector_4d &rhs) const;

    /*! \brief add a vector to this vector
     */
    void operator+=(const vector_4d &rhs);

    /*! \brief subtract a vector from this vector
     */
    void operator-=(const vector_4d &rhs);

    /*! \brief scale this vector by a constant T
     */
    void operator*=(const T &rhs);
  };
}
#include "type_vector_4d.inl"
#endif
