// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: local.proto

#ifndef PROTOBUF_local_2eproto__INCLUDED
#define PROTOBUF_local_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
// @@protoc_insertion_point(includes)

namespace cloudbox {
namespace protobuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_local_2eproto();
void protobuf_AssignDesc_local_2eproto();
void protobuf_ShutdownFile_local_2eproto();

class IDList;

// ===================================================================

class IDList : public ::google::protobuf::MessageLite {
 public:
  IDList();
  virtual ~IDList();

  IDList(const IDList& from);

  inline IDList& operator=(const IDList& from) {
    CopyFrom(from);
    return *this;
  }

  static const IDList& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const IDList* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(IDList* other);

  // implements Message ----------------------------------------------

  IDList* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const IDList& from);
  void MergeFrom(const IDList& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated string id = 1;
  inline int id_size() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline const ::std::string& id(int index) const;
  inline ::std::string* mutable_id(int index);
  inline void set_id(int index, const ::std::string& value);
  inline void set_id(int index, const char* value);
  inline void set_id(int index, const char* value, size_t size);
  inline ::std::string* add_id();
  inline void add_id(const ::std::string& value);
  inline void add_id(const char* value);
  inline void add_id(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& id() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_id();

  // optional int64 version = 2;
  inline bool has_version() const;
  inline void clear_version();
  static const int kVersionFieldNumber = 2;
  inline ::google::protobuf::int64 version() const;
  inline void set_version(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:cloudbox.protobuf.IDList)
 private:
  inline void set_has_version();
  inline void clear_has_version();

  ::google::protobuf::RepeatedPtrField< ::std::string> id_;
  ::google::protobuf::int64 version_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_local_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_local_2eproto();
  #endif
  friend void protobuf_AssignDesc_local_2eproto();
  friend void protobuf_ShutdownFile_local_2eproto();

  void InitAsDefaultInstance();
  static IDList* default_instance_;
};
// ===================================================================


// ===================================================================

// IDList

// repeated string id = 1;
inline int IDList::id_size() const {
  return id_.size();
}
inline void IDList::clear_id() {
  id_.Clear();
}
inline const ::std::string& IDList::id(int index) const {
  return id_.Get(index);
}
inline ::std::string* IDList::mutable_id(int index) {
  return id_.Mutable(index);
}
inline void IDList::set_id(int index, const ::std::string& value) {
  id_.Mutable(index)->assign(value);
}
inline void IDList::set_id(int index, const char* value) {
  id_.Mutable(index)->assign(value);
}
inline void IDList::set_id(int index, const char* value, size_t size) {
  id_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* IDList::add_id() {
  return id_.Add();
}
inline void IDList::add_id(const ::std::string& value) {
  id_.Add()->assign(value);
}
inline void IDList::add_id(const char* value) {
  id_.Add()->assign(value);
}
inline void IDList::add_id(const char* value, size_t size) {
  id_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
IDList::id() const {
  return id_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
IDList::mutable_id() {
  return &id_;
}

// optional int64 version = 2;
inline bool IDList::has_version() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void IDList::set_has_version() {
  _has_bits_[0] |= 0x00000002u;
}
inline void IDList::clear_has_version() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void IDList::clear_version() {
  version_ = GOOGLE_LONGLONG(0);
  clear_has_version();
}
inline ::google::protobuf::int64 IDList::version() const {
  return version_;
}
inline void IDList::set_version(::google::protobuf::int64 value) {
  set_has_version();
  version_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace cloudbox

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_local_2eproto__INCLUDED
