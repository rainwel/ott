//
//  ProtobufWarpper.h
//  cloudbox
//
//  Created by freeman on 12/4/13.
//
//

#ifndef __cloudbox__ProtobufWarpper__
#define __cloudbox__ProtobufWarpper__

#include <iostream>

template <class T> class ProtobufWarpper {
  T *m_pProtobufObject;

public:
  ProtobufWarpper() : m_pProtobufObject(NULL) {}

  ~ProtobufWarpper() { CC_SAFE_DELETE(m_pProtobufObject); }

  static ProtobufWarpper<T> *create(T &pObj2) {

    ProtobufWarpper<T> *pObj = new ProtobufWarpper<T>();
    if (pObj && pObj->init(pObj2)) {
      pObj->autorelease();
      return pObj;
    }

    CC_SAFE_DELETE(pObj);
    return NULL;
  }

  static ProtobufWarpper<T> *create(const void *data, int size) {
    T obj;

    if (obj.ParseFromArray(data, size)) {
      return ProtobufWarpper<T>::create(obj);
    }
    return NULL;
  }

  bool init(T &pObj) {
    m_pProtobufObject = new T();
    m_pProtobufObject->CopyFrom(pObj);
    return true;
  }

  T *getObject() { return m_pProtobufObject; }
};

// ProtobufWarpper<Index_ListPages>* protobuf =
// ProtobufWarpper<Index_ListPages>::create("", 1);

#endif /* defined(__cloudbox__ProtobufWarpper__) */
