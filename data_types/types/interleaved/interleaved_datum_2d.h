#ifndef INTERLEAVED_DATUM_2D_H_INCLUDED
#define INTERLEAVED_DATUM_2D_H_INCLUDED

#include <glext.h>

namespace glext
{
  template <typename T1, typename T2>
  struct interleaved_datum_2d
  {
  public:
    /*! \brief determine type of the first interleaved type
     */
    typedef T1 internal_type1;

    /*! \brief determine type of the first interleaved type
     */
    typedef T2 internal_type2;

    /*! \brief first component in interleaved data 
     */
    T1 _datum1;
    
    /*! \brief second component in interleaved data
     */
    T2 _datum2;

    /*! \brief default constructor
     */
    interleaved_datum_2d();

    /*! \brief constructor
     */
    interleaved_datum_2d(const T1 &datum_1, const T2 &datum_2);

    /*! \brief copy constructor
     */
    interleaved_datum_2d(const interleaved_datum_2d &rhs);

    /*! \brief destructor
     */
    ~interleaved_datum_2d();

    /*! \brief assignment uses copy-swap idiom
     */
    interleaved_datum_2d &operator=(interleaved_datum_2d &rhs);
  };
}

#include "interleaved_datum_2d.inl"
#endif