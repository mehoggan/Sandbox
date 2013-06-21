namespace glext
{
  /// Constructors
  template <typename T1>        
  renderer_data_1d<T1>::renderer_data_1d() :
    _type_count(1)
  {}

  template <typename T1>        
  renderer_data_1d<T1>::renderer_data_1d(const std::vector<T1> &data_1) :
    _type_count(1),
    _data_1(data_1)
  {}

  /// Copy constructor
  template <typename T1>        
  renderer_data_1d<T1>::renderer_data_1d(const renderer_data_1d &rhs) :
    _type_count(1),
    _data_1(rhs._data_1)
  {}

  /// Destructor
  template <typename T1>        
  renderer_data_1d<T1>::~renderer_data_1d()
  {
    _data_1.clear();
  }

  /// Assignment operator
  template <typename T1>        
  renderer_data_1d<T1> &renderer_data_1d<T1>::operator=(renderer_data_1d &rhs)
  {
    swap((*this), rhs);

    return (*this); 
  }

  /// VBO parameters
  template <typename T1>
  size_t renderer_data_1d<T1>::t1_offset() const
  {
    return 0;
  }

  template <typename T1>
  size_t renderer_data_1d<T1>::size_of() const
  {
    return data1_size_of();
  }

  template <typename T1>
  size_t renderer_data_1d<T1>::data1_size_of() const
  {
    return _data_1.size() * sizeof(internal_type1);
  }

  /// Copy and swap idiom
  template <typename T1>
  void swap(renderer_data_1d<T1> &lhs, renderer_data_1d<T1> &rhs)
  {
    lhs._data_1.swap(rhs.data_1);
    std::swap(lhs.type_count, rhs.type_count);
  }

  template <typename T1>        
  bool operator==(const renderer_data_1d<T1> &lhs, 
    const renderer_data_1d<T1> &rhs)
  {   
    return (lhs._data_1 == rhs._data_1); 
  }
  
  template <typename T1>        
  bool operator!=(const renderer_data_1d<T1> &lhs, 
    const renderer_data_1d<T1> &rhs)
  {
    return (lhs._data_1 != rhs._data_1); 
  }
}
