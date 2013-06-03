namespace glext 
{
  /// Constructors
  template <typename T>
  vector_4d<T>::vector_4d()
    _x(0),
    _y(0),
    _z(0),
    _w(0)
  {}

  template <typename T>
  vector_4d<T>::vector_4d(const T &x, const T &y, const T &z, const T &w) :
    _x(x),
    _y(y),
    _z(z),
    _w(w)
  {}

  /// Copy constructor
  template <typename T>
  vector_4d<T>::vector_4d(const vector_4d<T> &rhs) :
    _x(rhs._x),
    _y(rhs._y),
    _z(rhs._z),
    _w(rhs._w)
  {}

  /// Destructor
  template <typename T>
  vector_4d<T>::~vector_4d()
  {}

  /// Assignment operator
  template <typename T>
  vector_4d<T> &vector_4d<T>::operator=(vector_4d<T> rhs)
  {
    swap((*this), rhs);
    
    return (*this);
  }

  /// Setters
  template <typename T>
  void vector_4d<T>::x(const T &x)
  {
    _x = x;
  }

  template <typename T>
  void vector_4d<T>::y(const T &y)
  {
    _y = y;
  }

  template <typename T>
  void vector_4d<T>::z(const T &z)
  {
    _z = z;
  }

  template <typename T>
  void vector_4d<T>::w(const T &w)
  {
    _w = w;
  }

  template <typename T>
  void vector_4d<T>::x_and_y_and_z_and_w(const T &x, const T &y, const T &z,
    const T &w)
  {
    _x = x;
    _y = y;
    _z = z;
  }

  /// Getters
  template <typename T>
  T& vector_4d<T>::xref()
  {
    return _x;
  }

  template <typename T>
  T& vector_4d<T>::yref()
  {
    return _y;
  }

  template <typename T>
  T& vector_4d<T>::zref()
  {
    return _z;
  }

  template <typename T>
  T& vector_4d<T>::wref()
  {
    return _w;
  }

  /// Internal math algorithms 
  template <typename T> 
  T vector_3d<T>::magnitude() const
  {
    return sqrt(_x * _x + _y * _y + _z * _z + _w * _w);
  }

  /// Getters
  template <typename T>
  T vector_4d<T>::x() const
  {
    return _x;
  }

  template <typename T>
  T vector_4d<T>::y() const
  {
    return _y;
  }

  template <typename T>
  T vector_4d<T>::z() const
  {
    return _z;
  }
 
  template <typename T>
  T vector_4d<T>::w() const
  {
    return _w;
  }

  /// Copy and swap idiom
  template <typename T>
  void swap(vector_4d<T> &lhs, vector_4d<T> &rhs)
  {
    std::swap(lhs.xref(), rhs.xref());
    std::swap(lhs.yref(), rhs.yref());
    std::swap(lhs.zref(), rhs.zref());
    std::swap(lhs.wref(), rhs.wref());
  }

  /// Comparison operators
  template <typename T>
  bool operator<(const vector_4d<T> &lhs, const vector_4d<T> &rhs)
  {
    return (lhs.x() < rhs.x() && lhs.y() < rhs.y() && lhs.z() < rhs.z() &&
      lhs.w() < rhs.w());
  }

  template <typename T>
  bool operator>(const vector_4d<T> &lhs, const vector_4d<T> &rhs)
  {
    return (lhs.x() > rhs.x() && lhs.y() > rhs.y() && lhs.z() > rhs.z() &&
      lhs.w() > rhs.w());
  }
  
  template <typename T>
  bool operator<=(const vector_4d<T> &lhs, const vector_4d<T> &rhs)
  {
    return (lhs.x() <= rhs.x() && lhs.y() <= rhs.y() && lhs.z() <= rhs.z() &&
      lhs.w() <= rhs.w());
  }

  template <typename T>
  bool operator>=(const vector_4d<T> &lhs, const vector_4d<T> &rhs)
  {
    return (lhs.x() >= rhs.x() && lhs.y() >= rhs.y() && lhs.z() >= rhs.z() &&
      lhs.w() >= rhs.w());
  }

  template <typename T>
  bool operator==(const vector_4d<T> &lhs, const vector_4d<T> &rhs)
  {
    return (lhs.x() == rhs.x() && lhs.y() == rhs.y() && lhs.z() == rhs.z() &&
      lhs.w() == rhs.w());
  }

  template <typename T>
  bool operator!=(const vector_4d<T> &lhs, const vector_4d<T> &rhs)
  {
    return (lhs.x() != rhs.x() || lhs.y() != rhs.y() || lhs.z() != rhs.z() ||
      lhs.w() == rhs.w());
  }
}