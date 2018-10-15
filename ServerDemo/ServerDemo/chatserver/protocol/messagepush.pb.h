// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messagepush.proto

#ifndef PROTOBUF_INCLUDED_messagepush_2eproto
#define PROTOBUF_INCLUDED_messagepush_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_messagepush_2eproto 

namespace protobuf_messagepush_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_messagepush_2eproto
namespace chat {
namespace proto {
class MessagePush;
class MessagePushDefaultTypeInternal;
extern MessagePushDefaultTypeInternal _MessagePush_default_instance_;
}  // namespace proto
}  // namespace chat
namespace google {
namespace protobuf {
template<> ::chat::proto::MessagePush* Arena::CreateMaybeMessage<::chat::proto::MessagePush>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace chat {
namespace proto {

// ===================================================================

class MessagePush : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:chat.proto.MessagePush) */ {
 public:
  MessagePush();
  virtual ~MessagePush();

  MessagePush(const MessagePush& from);

  inline MessagePush& operator=(const MessagePush& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MessagePush(MessagePush&& from) noexcept
    : MessagePush() {
    *this = ::std::move(from);
  }

  inline MessagePush& operator=(MessagePush&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MessagePush& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MessagePush* internal_default_instance() {
    return reinterpret_cast<const MessagePush*>(
               &_MessagePush_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(MessagePush* other);
  friend void swap(MessagePush& a, MessagePush& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MessagePush* New() const final {
    return CreateMaybeMessage<MessagePush>(NULL);
  }

  MessagePush* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MessagePush>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MessagePush& from);
  void MergeFrom(const MessagePush& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MessagePush* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string topic = 1;
  void clear_topic();
  static const int kTopicFieldNumber = 1;
  const ::std::string& topic() const;
  void set_topic(const ::std::string& value);
  #if LANG_CXX11
  void set_topic(::std::string&& value);
  #endif
  void set_topic(const char* value);
  void set_topic(const char* value, size_t size);
  ::std::string* mutable_topic();
  ::std::string* release_topic();
  void set_allocated_topic(::std::string* topic);

  // string content = 2;
  void clear_content();
  static const int kContentFieldNumber = 2;
  const ::std::string& content() const;
  void set_content(const ::std::string& value);
  #if LANG_CXX11
  void set_content(::std::string&& value);
  #endif
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  ::std::string* mutable_content();
  ::std::string* release_content();
  void set_allocated_content(::std::string* content);

  // string from = 3;
  void clear_from();
  static const int kFromFieldNumber = 3;
  const ::std::string& from() const;
  void set_from(const ::std::string& value);
  #if LANG_CXX11
  void set_from(::std::string&& value);
  #endif
  void set_from(const char* value);
  void set_from(const char* value, size_t size);
  ::std::string* mutable_from();
  ::std::string* release_from();
  void set_allocated_from(::std::string* from);

  // @@protoc_insertion_point(class_scope:chat.proto.MessagePush)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr topic_;
  ::google::protobuf::internal::ArenaStringPtr content_;
  ::google::protobuf::internal::ArenaStringPtr from_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_messagepush_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MessagePush

// string topic = 1;
inline void MessagePush::clear_topic() {
  topic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MessagePush::topic() const {
  // @@protoc_insertion_point(field_get:chat.proto.MessagePush.topic)
  return topic_.GetNoArena();
}
inline void MessagePush::set_topic(const ::std::string& value) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.MessagePush.topic)
}
#if LANG_CXX11
inline void MessagePush::set_topic(::std::string&& value) {
  
  topic_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.MessagePush.topic)
}
#endif
inline void MessagePush::set_topic(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.MessagePush.topic)
}
inline void MessagePush::set_topic(const char* value, size_t size) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.MessagePush.topic)
}
inline ::std::string* MessagePush::mutable_topic() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.MessagePush.topic)
  return topic_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MessagePush::release_topic() {
  // @@protoc_insertion_point(field_release:chat.proto.MessagePush.topic)
  
  return topic_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessagePush::set_allocated_topic(::std::string* topic) {
  if (topic != NULL) {
    
  } else {
    
  }
  topic_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), topic);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.MessagePush.topic)
}

// string content = 2;
inline void MessagePush::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MessagePush::content() const {
  // @@protoc_insertion_point(field_get:chat.proto.MessagePush.content)
  return content_.GetNoArena();
}
inline void MessagePush::set_content(const ::std::string& value) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.MessagePush.content)
}
#if LANG_CXX11
inline void MessagePush::set_content(::std::string&& value) {
  
  content_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.MessagePush.content)
}
#endif
inline void MessagePush::set_content(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.MessagePush.content)
}
inline void MessagePush::set_content(const char* value, size_t size) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.MessagePush.content)
}
inline ::std::string* MessagePush::mutable_content() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.MessagePush.content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MessagePush::release_content() {
  // @@protoc_insertion_point(field_release:chat.proto.MessagePush.content)
  
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessagePush::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    
  } else {
    
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.MessagePush.content)
}

// string from = 3;
inline void MessagePush::clear_from() {
  from_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MessagePush::from() const {
  // @@protoc_insertion_point(field_get:chat.proto.MessagePush.from)
  return from_.GetNoArena();
}
inline void MessagePush::set_from(const ::std::string& value) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.MessagePush.from)
}
#if LANG_CXX11
inline void MessagePush::set_from(::std::string&& value) {
  
  from_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.MessagePush.from)
}
#endif
inline void MessagePush::set_from(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.MessagePush.from)
}
inline void MessagePush::set_from(const char* value, size_t size) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.MessagePush.from)
}
inline ::std::string* MessagePush::mutable_from() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.MessagePush.from)
  return from_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MessagePush::release_from() {
  // @@protoc_insertion_point(field_release:chat.proto.MessagePush.from)
  
  return from_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessagePush::set_allocated_from(::std::string* from) {
  if (from != NULL) {
    
  } else {
    
  }
  from_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.MessagePush.from)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace chat

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_messagepush_2eproto