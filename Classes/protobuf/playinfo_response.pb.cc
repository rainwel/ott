// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: playinfo_response.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "playinfo_response.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace cloudbox {
namespace protobuf {

void protobuf_ShutdownFile_playinfo_5fresponse_2eproto() {
  delete EpisodeInfo::default_instance_;
  delete PlayInfo::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_playinfo_5fresponse_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_playinfo_5fresponse_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  ::cloudbox::protobuf::protobuf_AddDesc_common_2eproto();
  EpisodeInfo::default_instance_ = new EpisodeInfo();
  PlayInfo::default_instance_ = new PlayInfo();
  EpisodeInfo::default_instance_->InitAsDefaultInstance();
  PlayInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_playinfo_5fresponse_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_playinfo_5fresponse_2eproto_once_);
void protobuf_AddDesc_playinfo_5fresponse_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_playinfo_5fresponse_2eproto_once_,
                 &protobuf_AddDesc_playinfo_5fresponse_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_playinfo_5fresponse_2eproto {
  StaticDescriptorInitializer_playinfo_5fresponse_2eproto() {
    protobuf_AddDesc_playinfo_5fresponse_2eproto();
  }
} static_descriptor_initializer_playinfo_5fresponse_2eproto_;
#endif

// ===================================================================

#ifndef _MSC_VER
const int EpisodeInfo::kEpisodeFieldNumber;
const int EpisodeInfo::kNameFieldNumber;
const int EpisodeInfo::kSitesFieldNumber;
const int EpisodeInfo::kStageFieldNumber;
#endif  // !_MSC_VER

EpisodeInfo::EpisodeInfo()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void EpisodeInfo::InitAsDefaultInstance() {
}

EpisodeInfo::EpisodeInfo(const EpisodeInfo& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void EpisodeInfo::SharedCtor() {
  _cached_size_ = 0;
  episode_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  stage_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EpisodeInfo::~EpisodeInfo() {
  SharedDtor();
}

void EpisodeInfo::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (stage_ != &::google::protobuf::internal::kEmptyString) {
    delete stage_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void EpisodeInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const EpisodeInfo& EpisodeInfo::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_playinfo_5fresponse_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_playinfo_5fresponse_2eproto();
#endif
  return *default_instance_;
}

EpisodeInfo* EpisodeInfo::default_instance_ = NULL;

EpisodeInfo* EpisodeInfo::New() const {
  return new EpisodeInfo;
}

void EpisodeInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    episode_ = 0;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    if (has_stage()) {
      if (stage_ != &::google::protobuf::internal::kEmptyString) {
        stage_->clear();
      }
    }
  }
  sites_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool EpisodeInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 episode = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &episode_)));
          set_has_episode();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // optional string name = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_sites;
        break;
      }

      // repeated .cloudbox.protobuf.PlaySiteInfo sites = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_sites:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_sites()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_sites;
        if (input->ExpectTag(34)) goto parse_stage;
        break;
      }

      // optional string stage = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_stage:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_stage()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void EpisodeInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 episode = 1;
  if (has_episode()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->episode(), output);
  }

  // optional string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->name(), output);
  }

  // repeated .cloudbox.protobuf.PlaySiteInfo sites = 3;
  for (int i = 0; i < this->sites_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, this->sites(i), output);
  }

  // optional string stage = 4;
  if (has_stage()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->stage(), output);
  }

}

int EpisodeInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 episode = 1;
    if (has_episode()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->episode());
    }

    // optional string name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional string stage = 4;
    if (has_stage()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->stage());
    }

  }
  // repeated .cloudbox.protobuf.PlaySiteInfo sites = 3;
  total_size += 1 * this->sites_size();
  for (int i = 0; i < this->sites_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->sites(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void EpisodeInfo::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const EpisodeInfo*>(&from));
}

void EpisodeInfo::MergeFrom(const EpisodeInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  sites_.MergeFrom(from.sites_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_episode()) {
      set_episode(from.episode());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_stage()) {
      set_stage(from.stage());
    }
  }
}

void EpisodeInfo::CopyFrom(const EpisodeInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EpisodeInfo::IsInitialized() const {

  return true;
}

void EpisodeInfo::Swap(EpisodeInfo* other) {
  if (other != this) {
    std::swap(episode_, other->episode_);
    std::swap(name_, other->name_);
    sites_.Swap(&other->sites_);
    std::swap(stage_, other->stage_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string EpisodeInfo::GetTypeName() const {
  return "cloudbox.protobuf.EpisodeInfo";
}


// ===================================================================

#ifndef _MSC_VER
const int PlayInfo::kImgFieldNumber;
const int PlayInfo::kTotalFieldNumber;
const int PlayInfo::kResultFieldNumber;
const int PlayInfo::kSizeFieldNumber;
const int PlayInfo::kNameFieldNumber;
#endif  // !_MSC_VER

PlayInfo::PlayInfo()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void PlayInfo::InitAsDefaultInstance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  img_ = const_cast< ::cloudbox::protobuf::ImageInfo*>(
      ::cloudbox::protobuf::ImageInfo::internal_default_instance());
#else
  img_ = const_cast< ::cloudbox::protobuf::ImageInfo*>(&::cloudbox::protobuf::ImageInfo::default_instance());
#endif
}

PlayInfo::PlayInfo(const PlayInfo& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void PlayInfo::SharedCtor() {
  _cached_size_ = 0;
  img_ = NULL;
  total_ = 0;
  size_ = GOOGLE_LONGLONG(0);
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PlayInfo::~PlayInfo() {
  SharedDtor();
}

void PlayInfo::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
    delete img_;
  }
}

void PlayInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const PlayInfo& PlayInfo::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_playinfo_5fresponse_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_playinfo_5fresponse_2eproto();
#endif
  return *default_instance_;
}

PlayInfo* PlayInfo::default_instance_ = NULL;

PlayInfo* PlayInfo::New() const {
  return new PlayInfo;
}

void PlayInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_img()) {
      if (img_ != NULL) img_->::cloudbox::protobuf::ImageInfo::Clear();
    }
    total_ = 0;
    size_ = GOOGLE_LONGLONG(0);
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
  }
  result_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool PlayInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .cloudbox.protobuf.ImageInfo img = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_img()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_total;
        break;
      }

      // optional int32 total = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_total:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &total_)));
          set_has_total();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_result;
        break;
      }

      // repeated .cloudbox.protobuf.EpisodeInfo result = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_result:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_result()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_result;
        if (input->ExpectTag(32)) goto parse_size;
        break;
      }

      // optional int64 size = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &size_)));
          set_has_size();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_name;
        break;
      }

      // optional string name = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void PlayInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional .cloudbox.protobuf.ImageInfo img = 1;
  if (has_img()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->img(), output);
  }

  // optional int32 total = 2;
  if (has_total()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->total(), output);
  }

  // repeated .cloudbox.protobuf.EpisodeInfo result = 3;
  for (int i = 0; i < this->result_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, this->result(i), output);
  }

  // optional int64 size = 4;
  if (has_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->size(), output);
  }

  // optional string name = 5;
  if (has_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->name(), output);
  }

}

int PlayInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .cloudbox.protobuf.ImageInfo img = 1;
    if (has_img()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->img());
    }

    // optional int32 total = 2;
    if (has_total()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->total());
    }

    // optional int64 size = 4;
    if (has_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->size());
    }

    // optional string name = 5;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

  }
  // repeated .cloudbox.protobuf.EpisodeInfo result = 3;
  total_size += 1 * this->result_size();
  for (int i = 0; i < this->result_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->result(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PlayInfo::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const PlayInfo*>(&from));
}

void PlayInfo::MergeFrom(const PlayInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  result_.MergeFrom(from.result_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_img()) {
      mutable_img()->::cloudbox::protobuf::ImageInfo::MergeFrom(from.img());
    }
    if (from.has_total()) {
      set_total(from.total());
    }
    if (from.has_size()) {
      set_size(from.size());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
  }
}

void PlayInfo::CopyFrom(const PlayInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayInfo::IsInitialized() const {

  return true;
}

void PlayInfo::Swap(PlayInfo* other) {
  if (other != this) {
    std::swap(img_, other->img_);
    std::swap(total_, other->total_);
    result_.Swap(&other->result_);
    std::swap(size_, other->size_);
    std::swap(name_, other->name_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string PlayInfo::GetTypeName() const {
  return "cloudbox.protobuf.PlayInfo";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace cloudbox

// @@protoc_insertion_point(global_scope)
