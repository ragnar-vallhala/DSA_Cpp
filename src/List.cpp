

template<typename T>
List<T>::List(){
    _count = 0;
    _capacity = _initialSize;
    _data  = new T(_capacity); 
}

template<typename T>
List<T>::List(int capacity){
    _count = 0;
    _capacity = capacity;
    _data  = new T(_capacity); 
}

template<typename T>
List<T>::List(std::initializer_list<T> values){
    _count = values.size();
    _capacity = _count;
    _data  = new T(_capacity);
    int i{};
    for(int k : values){
        _data[i] = k;
        i++;
    }

}

template<typename T>
T List<T>::operator[](int index) const{
    if(index>=_count || index<0)
        throw std::out_of_range("index out of bound");
    return _data[index];
}


template<typename T>
void List<T>::Add(T object){
    if(_capacity==_count)
        Resize();
    _data[_count] = object;
    _count++;
}

template<typename T>
void List<T>::Insert(T object){
    if(_capacity==_count)
        Resize();
    
    Shift(0);
    _data[0] = object;
}


template<typename T>
void List<T>::InsertAt(int index, T object){
    if(_capacity==_count)
        Resize();
    
    Shift(index);
    _data[index] = object;
}

template<typename T>
int List<T>::Remove(T object){
    int index = Find(object);
    RemoveAt(index);
    return index;
}

template<typename T>
T List<T>::RemoveAt(int index){
    T object = _data[index];
    Shift(index,0);
    return object;
}

template<typename T>
int List<T>::Find(T object) const{
    for(int i{};i<_count;i++){
        if(_data[i]==object)
            return i;
    }
    return -1;
}

template<typename T>
int List<T>::GetCount() const{
    return _count;
}


template<typename T>
int List<T>::GetCapacity() const{
    return _capacity;
}

template<typename T>
void List<T>::Sort(bool order){
    if(order){
        std::sort(_data,_data+_count);
    }
    else{
        std::sort(_data,_data+_count,std::greater<T>());
    }
}

template<typename T>
void List<T>::Shift(int index, bool right){
    if(index>=_count || index<0)
        throw std::out_of_range("index out of bound");

    if(right){
        if(_capacity==_count)
            Resize();

        for(int i{_count-1};i>=index;i--){
            _data[i+1] = _data[i];
        }
        _count++;
    }
    else{
        for(int i{index};i<_count;i++){
            _data[i] = _data[i+1];
        }
        _count--;
    }
}

template<typename T>
void List<T>::Resize(bool increase, bool verbose){
    if(increase){
        T *new_array = new T(_capacity + _initialSize);
        for(int i{};i<_count;i++){
            new_array[i] = _data[i];
        }
        _data = new_array;
    }
    else{
        if(_capacity - _count< _initialSize){
            throw std::underflow_error("_count can't be greater than alloted alloted space.");
        }
        T *new_array = new T(_capacity - _initialSize);
        for(int i{};i<_count;i++){
            new_array[i] = _data[i];
        }
        _data = new_array;
    }

    if(verbose)
        std::cout<<"Resize called  with increase set to "<<increase<<std::endl;
}
