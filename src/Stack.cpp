
template<typename T>
Stack<T>::Stack(int capacity){
    _data = new T(capacity);
    _top = -1;
    _capacity = capacity;
}

template<typename T>
void Stack<T>::Push(T object){
    if(_top + 1 >= _capacity){
        throw std::overflow_error("Stack Overflow");
        return;
    }
    _top++;
    _data[_top] = object;
}

template<typename T>
T Stack<T>::Pop(){
    if(_top <= -1){
        throw std::underflow_error("Stack Underflow");
    }
    return _data[_top--];
}

template<typename T>
T Stack<T>::Top() const{
    if(_top <= -1){
        throw std::range_error("Stack Empty");
    }
    return _data[_top];
}
