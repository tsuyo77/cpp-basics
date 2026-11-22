#include "box.h"

template <typename T>
Box<T>::Box(const T& v) : value_(v) {}

template <typename T>
T Box<T>::get() const { return value_; }