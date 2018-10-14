// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.proto

#ifndef PROTOBUF_INCLUDED_chat_2eproto
#define PROTOBUF_INCLUDED_chat_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_chat_2eproto 

namespace protobuf_chat_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_chat_2eproto
namespace chat {
namespace proto {
class SendMessageRequest;
class SendMessageRequestDefaultTypeInternal;
extern SendMessageRequestDefaultTypeInternal _SendMessageRequest_default_instance_;
class SendMessageResponse;
class SendMessageResponseDefaultTypeInternal;
extern SendMessageResponseDefaultTypeInternal _SendMessageResponse_default_instance_;
}  // namespace proto
}  // namespace chat
namespace google {
namespace protobuf {
template<> ::chat::proto::SendMessageRequest* Arena::CreateMaybeMessage<::chat::proto::SendMessageRequest>(Arena*);
template<> ::chat::proto::SendMessageResponse* Arena::CreateMaybeMessage<::chat::proto::SendMessageResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace chat {
namespace proto {

enum SendMessageResponse_Error {
  SendMessageResponse_Error_ERR_OK = 0,
  SendMessageResponse_Error_ERR_SYS = -1,
  SendMessageResponse_Error_SendMessageResponse_Error_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SendMessageResponse_Error_SendMessageResponse_Error_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SendMessageResponse_Error_IsValid(int value);
const SendMessageResponse_Error SendMessageResponse_Error_Error_MIN = SendMessageResponse_Error_ERR_SYS;
const SendMessageResponse_Error SendMessageResponse_Error_Error_MAX = SendMessageResponse_Error_ERR_OK;
const int SendMessageResponse_Error_Error_ARRAYSIZE = SendMessageResponse_Error_Error_MAX + 1;

const ::google::protobuf::EnumDescriptor* SendMessageResponse_Error_descriptor();
inline const ::std::string& SendMessageResponse_Error_Name(SendMessageResponse_Error value) {
  return ::google::protobuf::internal::NameOfEnum(
    SendMessageResponse_Error_descriptor(), value);
}
inline bool SendMessageResponse_Error_Parse(
    const ::std::string& name, SendMessageResponse_Error* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SendMessageResponse_Error>(
    SendMessageResponse_Error_descriptor(), name, value);
}
// ===================================================================

class SendMessageRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:chat.proto.SendMessageRequest) */ {
 public:
  SendMessageRequest();
  virtual ~SendMessageRequest();

  SendMessageRequest(const SendMessageRequest& from);

  inline SendMessageRequest& operator=(const SendMessageRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SendMessageRequest(SendMessageRequest&& from) noexcept
    : SendMessageRequest() {
    *this = ::std::move(from);
  }

  inline SendMessageRequest& operator=(SendMessageRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SendMessageRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SendMessageRequest* internal_default_instance() {
    return reinterpret_cast<const SendMessageRequest*>(
               &_SendMessageRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(SendMessageRequest* other);
  friend void swap(SendMessageRequest& a, SendMessageRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SendMessageRequest* New() const final {
    return CreateMaybeMessage<SendMessageRequest>(NULL);
  }

  SendMessageRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SendMessageRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SendMessageRequest& from);
  void MergeFrom(const SendMessageRequest& from);
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
  void InternalSwap(SendMessageRequest* other);
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

  // string access_token = 1;
  void clear_access_token();
  static const int kAccessTokenFieldNumber = 1;
  const ::std::string& access_token() const;
  void set_access_token(const ::std::string& value);
  #if LANG_CXX11
  void set_access_token(::std::string&& value);
  #endif
  void set_access_token(const char* value);
  void set_access_token(const char* value, size_t size);
  ::std::string* mutable_access_token();
  ::std::string* release_access_token();
  void set_allocated_access_token(::std::string* access_token);

  // string from = 2;
  void clear_from();
  static const int kFromFieldNumber = 2;
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

  // string to = 3;
  void clear_to();
  static const int kToFieldNumber = 3;
  const ::std::string& to() const;
  void set_to(const ::std::string& value);
  #if LANG_CXX11
  void set_to(::std::string&& value);
  #endif
  void set_to(const char* value);
  void set_to(const char* value, size_t size);
  ::std::string* mutable_to();
  ::std::string* release_to();
  void set_allocated_to(::std::string* to);

  // string text = 4;
  void clear_text();
  static const int kTextFieldNumber = 4;
  const ::std::string& text() const;
  void set_text(const ::std::string& value);
  #if LANG_CXX11
  void set_text(::std::string&& value);
  #endif
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  ::std::string* mutable_text();
  ::std::string* release_text();
  void set_allocated_text(::std::string* text);

  // string topic = 5;
  void clear_topic();
  static const int kTopicFieldNumber = 5;
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

  // @@protoc_insertion_point(class_scope:chat.proto.SendMessageRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr access_token_;
  ::google::protobuf::internal::ArenaStringPtr from_;
  ::google::protobuf::internal::ArenaStringPtr to_;
  ::google::protobuf::internal::ArenaStringPtr text_;
  ::google::protobuf::internal::ArenaStringPtr topic_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_chat_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SendMessageResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:chat.proto.SendMessageResponse) */ {
 public:
  SendMessageResponse();
  virtual ~SendMessageResponse();

  SendMessageResponse(const SendMessageResponse& from);

  inline SendMessageResponse& operator=(const SendMessageResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SendMessageResponse(SendMessageResponse&& from) noexcept
    : SendMessageResponse() {
    *this = ::std::move(from);
  }

  inline SendMessageResponse& operator=(SendMessageResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SendMessageResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SendMessageResponse* internal_default_instance() {
    return reinterpret_cast<const SendMessageResponse*>(
               &_SendMessageResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(SendMessageResponse* other);
  friend void swap(SendMessageResponse& a, SendMessageResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SendMessageResponse* New() const final {
    return CreateMaybeMessage<SendMessageResponse>(NULL);
  }

  SendMessageResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SendMessageResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SendMessageResponse& from);
  void MergeFrom(const SendMessageResponse& from);
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
  void InternalSwap(SendMessageResponse* other);
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

  typedef SendMessageResponse_Error Error;
  static const Error ERR_OK =
    SendMessageResponse_Error_ERR_OK;
  static const Error ERR_SYS =
    SendMessageResponse_Error_ERR_SYS;
  static inline bool Error_IsValid(int value) {
    return SendMessageResponse_Error_IsValid(value);
  }
  static const Error Error_MIN =
    SendMessageResponse_Error_Error_MIN;
  static const Error Error_MAX =
    SendMessageResponse_Error_Error_MAX;
  static const int Error_ARRAYSIZE =
    SendMessageResponse_Error_Error_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Error_descriptor() {
    return SendMessageResponse_Error_descriptor();
  }
  static inline const ::std::string& Error_Name(Error value) {
    return SendMessageResponse_Error_Name(value);
  }
  static inline bool Error_Parse(const ::std::string& name,
      Error* value) {
    return SendMessageResponse_Error_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // string err_msg = 2;
  void clear_err_msg();
  static const int kErrMsgFieldNumber = 2;
  const ::std::string& err_msg() const;
  void set_err_msg(const ::std::string& value);
  #if LANG_CXX11
  void set_err_msg(::std::string&& value);
  #endif
  void set_err_msg(const char* value);
  void set_err_msg(const char* value, size_t size);
  ::std::string* mutable_err_msg();
  ::std::string* release_err_msg();
  void set_allocated_err_msg(::std::string* err_msg);

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

  // string text = 4;
  void clear_text();
  static const int kTextFieldNumber = 4;
  const ::std::string& text() const;
  void set_text(const ::std::string& value);
  #if LANG_CXX11
  void set_text(::std::string&& value);
  #endif
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  ::std::string* mutable_text();
  ::std::string* release_text();
  void set_allocated_text(::std::string* text);

  // string topic = 5;
  void clear_topic();
  static const int kTopicFieldNumber = 5;
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

  // int32 err_code = 1;
  void clear_err_code();
  static const int kErrCodeFieldNumber = 1;
  ::google::protobuf::int32 err_code() const;
  void set_err_code(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:chat.proto.SendMessageResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr err_msg_;
  ::google::protobuf::internal::ArenaStringPtr from_;
  ::google::protobuf::internal::ArenaStringPtr text_;
  ::google::protobuf::internal::ArenaStringPtr topic_;
  ::google::protobuf::int32 err_code_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_chat_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SendMessageRequest

// string access_token = 1;
inline void SendMessageRequest::clear_access_token() {
  access_token_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageRequest::access_token() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageRequest.access_token)
  return access_token_.GetNoArena();
}
inline void SendMessageRequest::set_access_token(const ::std::string& value) {
  
  access_token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageRequest.access_token)
}
#if LANG_CXX11
inline void SendMessageRequest::set_access_token(::std::string&& value) {
  
  access_token_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageRequest.access_token)
}
#endif
inline void SendMessageRequest::set_access_token(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  access_token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageRequest.access_token)
}
inline void SendMessageRequest::set_access_token(const char* value, size_t size) {
  
  access_token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageRequest.access_token)
}
inline ::std::string* SendMessageRequest::mutable_access_token() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageRequest.access_token)
  return access_token_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageRequest::release_access_token() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageRequest.access_token)
  
  return access_token_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageRequest::set_allocated_access_token(::std::string* access_token) {
  if (access_token != NULL) {
    
  } else {
    
  }
  access_token_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), access_token);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageRequest.access_token)
}

// string from = 2;
inline void SendMessageRequest::clear_from() {
  from_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageRequest::from() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageRequest.from)
  return from_.GetNoArena();
}
inline void SendMessageRequest::set_from(const ::std::string& value) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageRequest.from)
}
#if LANG_CXX11
inline void SendMessageRequest::set_from(::std::string&& value) {
  
  from_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageRequest.from)
}
#endif
inline void SendMessageRequest::set_from(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageRequest.from)
}
inline void SendMessageRequest::set_from(const char* value, size_t size) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageRequest.from)
}
inline ::std::string* SendMessageRequest::mutable_from() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageRequest.from)
  return from_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageRequest::release_from() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageRequest.from)
  
  return from_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageRequest::set_allocated_from(::std::string* from) {
  if (from != NULL) {
    
  } else {
    
  }
  from_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageRequest.from)
}

// string to = 3;
inline void SendMessageRequest::clear_to() {
  to_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageRequest::to() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageRequest.to)
  return to_.GetNoArena();
}
inline void SendMessageRequest::set_to(const ::std::string& value) {
  
  to_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageRequest.to)
}
#if LANG_CXX11
inline void SendMessageRequest::set_to(::std::string&& value) {
  
  to_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageRequest.to)
}
#endif
inline void SendMessageRequest::set_to(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  to_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageRequest.to)
}
inline void SendMessageRequest::set_to(const char* value, size_t size) {
  
  to_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageRequest.to)
}
inline ::std::string* SendMessageRequest::mutable_to() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageRequest.to)
  return to_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageRequest::release_to() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageRequest.to)
  
  return to_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageRequest::set_allocated_to(::std::string* to) {
  if (to != NULL) {
    
  } else {
    
  }
  to_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), to);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageRequest.to)
}

// string text = 4;
inline void SendMessageRequest::clear_text() {
  text_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageRequest::text() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageRequest.text)
  return text_.GetNoArena();
}
inline void SendMessageRequest::set_text(const ::std::string& value) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageRequest.text)
}
#if LANG_CXX11
inline void SendMessageRequest::set_text(::std::string&& value) {
  
  text_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageRequest.text)
}
#endif
inline void SendMessageRequest::set_text(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageRequest.text)
}
inline void SendMessageRequest::set_text(const char* value, size_t size) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageRequest.text)
}
inline ::std::string* SendMessageRequest::mutable_text() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageRequest.text)
  return text_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageRequest::release_text() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageRequest.text)
  
  return text_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageRequest::set_allocated_text(::std::string* text) {
  if (text != NULL) {
    
  } else {
    
  }
  text_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), text);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageRequest.text)
}

// string topic = 5;
inline void SendMessageRequest::clear_topic() {
  topic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageRequest::topic() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageRequest.topic)
  return topic_.GetNoArena();
}
inline void SendMessageRequest::set_topic(const ::std::string& value) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageRequest.topic)
}
#if LANG_CXX11
inline void SendMessageRequest::set_topic(::std::string&& value) {
  
  topic_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageRequest.topic)
}
#endif
inline void SendMessageRequest::set_topic(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageRequest.topic)
}
inline void SendMessageRequest::set_topic(const char* value, size_t size) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageRequest.topic)
}
inline ::std::string* SendMessageRequest::mutable_topic() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageRequest.topic)
  return topic_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageRequest::release_topic() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageRequest.topic)
  
  return topic_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageRequest::set_allocated_topic(::std::string* topic) {
  if (topic != NULL) {
    
  } else {
    
  }
  topic_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), topic);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageRequest.topic)
}

// -------------------------------------------------------------------

// SendMessageResponse

// int32 err_code = 1;
inline void SendMessageResponse::clear_err_code() {
  err_code_ = 0;
}
inline ::google::protobuf::int32 SendMessageResponse::err_code() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageResponse.err_code)
  return err_code_;
}
inline void SendMessageResponse::set_err_code(::google::protobuf::int32 value) {
  
  err_code_ = value;
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageResponse.err_code)
}

// string err_msg = 2;
inline void SendMessageResponse::clear_err_msg() {
  err_msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageResponse::err_msg() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageResponse.err_msg)
  return err_msg_.GetNoArena();
}
inline void SendMessageResponse::set_err_msg(const ::std::string& value) {
  
  err_msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageResponse.err_msg)
}
#if LANG_CXX11
inline void SendMessageResponse::set_err_msg(::std::string&& value) {
  
  err_msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageResponse.err_msg)
}
#endif
inline void SendMessageResponse::set_err_msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  err_msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageResponse.err_msg)
}
inline void SendMessageResponse::set_err_msg(const char* value, size_t size) {
  
  err_msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageResponse.err_msg)
}
inline ::std::string* SendMessageResponse::mutable_err_msg() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageResponse.err_msg)
  return err_msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageResponse::release_err_msg() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageResponse.err_msg)
  
  return err_msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageResponse::set_allocated_err_msg(::std::string* err_msg) {
  if (err_msg != NULL) {
    
  } else {
    
  }
  err_msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), err_msg);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageResponse.err_msg)
}

// string from = 3;
inline void SendMessageResponse::clear_from() {
  from_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageResponse::from() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageResponse.from)
  return from_.GetNoArena();
}
inline void SendMessageResponse::set_from(const ::std::string& value) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageResponse.from)
}
#if LANG_CXX11
inline void SendMessageResponse::set_from(::std::string&& value) {
  
  from_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageResponse.from)
}
#endif
inline void SendMessageResponse::set_from(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageResponse.from)
}
inline void SendMessageResponse::set_from(const char* value, size_t size) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageResponse.from)
}
inline ::std::string* SendMessageResponse::mutable_from() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageResponse.from)
  return from_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageResponse::release_from() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageResponse.from)
  
  return from_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageResponse::set_allocated_from(::std::string* from) {
  if (from != NULL) {
    
  } else {
    
  }
  from_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageResponse.from)
}

// string text = 4;
inline void SendMessageResponse::clear_text() {
  text_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageResponse::text() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageResponse.text)
  return text_.GetNoArena();
}
inline void SendMessageResponse::set_text(const ::std::string& value) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageResponse.text)
}
#if LANG_CXX11
inline void SendMessageResponse::set_text(::std::string&& value) {
  
  text_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageResponse.text)
}
#endif
inline void SendMessageResponse::set_text(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageResponse.text)
}
inline void SendMessageResponse::set_text(const char* value, size_t size) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageResponse.text)
}
inline ::std::string* SendMessageResponse::mutable_text() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageResponse.text)
  return text_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageResponse::release_text() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageResponse.text)
  
  return text_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageResponse::set_allocated_text(::std::string* text) {
  if (text != NULL) {
    
  } else {
    
  }
  text_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), text);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageResponse.text)
}

// string topic = 5;
inline void SendMessageResponse::clear_topic() {
  topic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendMessageResponse::topic() const {
  // @@protoc_insertion_point(field_get:chat.proto.SendMessageResponse.topic)
  return topic_.GetNoArena();
}
inline void SendMessageResponse::set_topic(const ::std::string& value) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.proto.SendMessageResponse.topic)
}
#if LANG_CXX11
inline void SendMessageResponse::set_topic(::std::string&& value) {
  
  topic_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.proto.SendMessageResponse.topic)
}
#endif
inline void SendMessageResponse::set_topic(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.proto.SendMessageResponse.topic)
}
inline void SendMessageResponse::set_topic(const char* value, size_t size) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.proto.SendMessageResponse.topic)
}
inline ::std::string* SendMessageResponse::mutable_topic() {
  
  // @@protoc_insertion_point(field_mutable:chat.proto.SendMessageResponse.topic)
  return topic_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendMessageResponse::release_topic() {
  // @@protoc_insertion_point(field_release:chat.proto.SendMessageResponse.topic)
  
  return topic_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendMessageResponse::set_allocated_topic(::std::string* topic) {
  if (topic != NULL) {
    
  } else {
    
  }
  topic_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), topic);
  // @@protoc_insertion_point(field_set_allocated:chat.proto.SendMessageResponse.topic)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace chat

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::chat::proto::SendMessageResponse_Error> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::chat::proto::SendMessageResponse_Error>() {
  return ::chat::proto::SendMessageResponse_Error_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_chat_2eproto
