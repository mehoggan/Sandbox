namespace glext
{
  /// Constructors
  template <typename T1, typename T2, typename T3, typename T4>        
  renderer_data_4d<T>::renderer_data_4d()
  {}

  template <typename T1, typename T2, typename T3, typename T4>        
  renderer_data_4d<T>::renderer_data_4d(std::vector<T1> &data_1,
    std::vector<T2> &data_2, std::vector<T3> &data_3, std::vector<T4> &data_4) :
    _data_1(data_1),
    _data_2(data_2),
    _data_3(data_3),
    _data_4(data_4)
  {}

  /// Copy constructor
  template <typename T1, typename T2, typename T3, typename T4>        
  renderer_data_4d<T>::renderer_data_4d(const renderer_data_4d &rhs) :
    _data_1(rhs._data_1),
    _data_2(rhs._data_2),
    _data_3(rhs._data_3),
    _data_4(rhs._data_4)
  {}

  /// Destructor
  template <typename T1, typename T2, typename T3, typename T4>        
  renderer_data_4d<T>::~renderer_data_4d()
  {
    _data_1.clear();
    _data_2.clear();
    _data_3.clear();
    _data_4.clear();
  }

  /// Assignment operator
  template <typename T1, typename T2, typename T3, typename T4>        
  renderer_data_4d &renderer_data_4d<T>::operator=(renderer_data_4d &rhs)
  {
    swap((*this), rhs);

    return (*this); 
  }

  /// VBO parameters
  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::t1_offset() const
  {
    return 0;
  }

  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::t2_offset() const
  {
    return _data_1.size() * sizeof(internal_type1);
  }

  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::t3_offset() const
  {
    return t2_offset() + _data_2.size() * sizeof(internal_type2);
  }

  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::t4_offset() const
  {

  }

  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::size_of() const
  {

  }

  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::data1_size_of() const
  {

  }

  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::data2_size_of() const
  {

  }

  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::data3_size_of() const
  {

  }

  template <typename T1, typename T2, typename T3, typename T4>
  size_t renderer_data_4d<T>::data4_size_of() const
  {

  }

  /// Copy and swap idiom
  template <typename T1, typename T2, typename T3, typename T4>
  void swap(renderer_data_4d<T1> &lhs, renderer_data_4d<T1> &rhs)
  {
    lhs._data_1.swap(rhs.data_1);
    lhs._data_2.swap(rhs.data_2);
    lhs._data_3.swap(rhs.data_3);
    lhs._data_4.swap(rhs.data_4);
  }

  template <typename T1, typename T2, typename T3, typename T4>        
  bool operator==(const renderer_data_4d<T1> &lhs, 
    const renderer_data_4d<T1> &rhs)
  {   
    return (lhs._data_1 == rhs._data_1 && lhs._data_2 == rhs._data_2 &&
      lhs._data_3 == rhs._data_3 && lhs._data_4 == rhs._data_4); 
  }
  
  template <typename T1, typename T2, typename T3, typename T4>        
  bool operator!=(const renderer_data_4d<T1> &lhs, 
    const renderer_data_4d<T1> &rhs)
  {
    return (lhs._data_1 != rhs._data_1 || lhs._data_2 != rhs._data_2 ||
      lhs._data_3 != lhs._data_3 || rhs._data_4 != rhs._data_4); 
  }
}

