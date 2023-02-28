// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "enum.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_struct_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_struct_2eproto;
namespace Protocol {
class PActor;
struct PActorDefaultTypeInternal;
extern PActorDefaultTypeInternal _PActor_default_instance_;
class Pos;
struct PosDefaultTypeInternal;
extern PosDefaultTypeInternal _Pos_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::PActor* Arena::CreateMaybeMessage<::Protocol::PActor>(Arena*);
template<> ::Protocol::Pos* Arena::CreateMaybeMessage<::Protocol::Pos>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class Pos final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.Pos) */ {
 public:
  inline Pos() : Pos(nullptr) {}
  ~Pos() override;
  explicit PROTOBUF_CONSTEXPR Pos(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Pos(const Pos& from);
  Pos(Pos&& from) noexcept
    : Pos() {
    *this = ::std::move(from);
  }

  inline Pos& operator=(const Pos& from) {
    CopyFrom(from);
    return *this;
  }
  inline Pos& operator=(Pos&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Pos& default_instance() {
    return *internal_default_instance();
  }
  static inline const Pos* internal_default_instance() {
    return reinterpret_cast<const Pos*>(
               &_Pos_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Pos& a, Pos& b) {
    a.Swap(&b);
  }
  inline void Swap(Pos* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Pos* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Pos* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Pos>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Pos& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Pos& from) {
    Pos::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Pos* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.Pos";
  }
  protected:
  explicit Pos(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
  };
  // float x = 1;
  void clear_x();
  float x() const;
  void set_x(float value);
  private:
  float _internal_x() const;
  void _internal_set_x(float value);
  public:

  // float y = 2;
  void clear_y();
  float y() const;
  void set_y(float value);
  private:
  float _internal_y() const;
  void _internal_set_y(float value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.Pos)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    float x_;
    float y_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_struct_2eproto;
};
// -------------------------------------------------------------------

class PActor final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.PActor) */ {
 public:
  inline PActor() : PActor(nullptr) {}
  ~PActor() override;
  explicit PROTOBUF_CONSTEXPR PActor(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PActor(const PActor& from);
  PActor(PActor&& from) noexcept
    : PActor() {
    *this = ::std::move(from);
  }

  inline PActor& operator=(const PActor& from) {
    CopyFrom(from);
    return *this;
  }
  inline PActor& operator=(PActor&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PActor& default_instance() {
    return *internal_default_instance();
  }
  static inline const PActor* internal_default_instance() {
    return reinterpret_cast<const PActor*>(
               &_PActor_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PActor& a, PActor& b) {
    a.Swap(&b);
  }
  inline void Swap(PActor* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PActor* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PActor* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PActor>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PActor& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const PActor& from) {
    PActor::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PActor* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.PActor";
  }
  protected:
  explicit PActor(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPositionFieldNumber = 3,
    kIdFieldNumber = 1,
    kTypeFieldNumber = 2,
    kActionFieldNumber = 4,
    kPlayerTypeFieldNumber = 5,
    kBlockTypeFieldNumber = 6,
  };
  // .Protocol.Pos position = 3;
  bool has_position() const;
  private:
  bool _internal_has_position() const;
  public:
  void clear_position();
  const ::Protocol::Pos& position() const;
  PROTOBUF_NODISCARD ::Protocol::Pos* release_position();
  ::Protocol::Pos* mutable_position();
  void set_allocated_position(::Protocol::Pos* position);
  private:
  const ::Protocol::Pos& _internal_position() const;
  ::Protocol::Pos* _internal_mutable_position();
  public:
  void unsafe_arena_set_allocated_position(
      ::Protocol::Pos* position);
  ::Protocol::Pos* unsafe_arena_release_position();

  // uint64 id = 1;
  void clear_id();
  uint64_t id() const;
  void set_id(uint64_t value);
  private:
  uint64_t _internal_id() const;
  void _internal_set_id(uint64_t value);
  public:

  // .Protocol.ActorType type = 2;
  void clear_type();
  ::Protocol::ActorType type() const;
  void set_type(::Protocol::ActorType value);
  private:
  ::Protocol::ActorType _internal_type() const;
  void _internal_set_type(::Protocol::ActorType value);
  public:

  // .Protocol.Action action = 4;
  void clear_action();
  ::Protocol::Action action() const;
  void set_action(::Protocol::Action value);
  private:
  ::Protocol::Action _internal_action() const;
  void _internal_set_action(::Protocol::Action value);
  public:

  // optional .Protocol.PlayerType playerType = 5;
  bool has_playertype() const;
  private:
  bool _internal_has_playertype() const;
  public:
  void clear_playertype();
  ::Protocol::PlayerType playertype() const;
  void set_playertype(::Protocol::PlayerType value);
  private:
  ::Protocol::PlayerType _internal_playertype() const;
  void _internal_set_playertype(::Protocol::PlayerType value);
  public:

  // optional .Protocol.BlockType blockType = 6;
  bool has_blocktype() const;
  private:
  bool _internal_has_blocktype() const;
  public:
  void clear_blocktype();
  ::Protocol::BlockType blocktype() const;
  void set_blocktype(::Protocol::BlockType value);
  private:
  ::Protocol::BlockType _internal_blocktype() const;
  void _internal_set_blocktype(::Protocol::BlockType value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.PActor)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::Protocol::Pos* position_;
    uint64_t id_;
    int type_;
    int action_;
    int playertype_;
    int blocktype_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Pos

// float x = 1;
inline void Pos::clear_x() {
  _impl_.x_ = 0;
}
inline float Pos::_internal_x() const {
  return _impl_.x_;
}
inline float Pos::x() const {
  // @@protoc_insertion_point(field_get:Protocol.Pos.x)
  return _internal_x();
}
inline void Pos::_internal_set_x(float value) {
  
  _impl_.x_ = value;
}
inline void Pos::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:Protocol.Pos.x)
}

// float y = 2;
inline void Pos::clear_y() {
  _impl_.y_ = 0;
}
inline float Pos::_internal_y() const {
  return _impl_.y_;
}
inline float Pos::y() const {
  // @@protoc_insertion_point(field_get:Protocol.Pos.y)
  return _internal_y();
}
inline void Pos::_internal_set_y(float value) {
  
  _impl_.y_ = value;
}
inline void Pos::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:Protocol.Pos.y)
}

// -------------------------------------------------------------------

// PActor

// uint64 id = 1;
inline void PActor::clear_id() {
  _impl_.id_ = uint64_t{0u};
}
inline uint64_t PActor::_internal_id() const {
  return _impl_.id_;
}
inline uint64_t PActor::id() const {
  // @@protoc_insertion_point(field_get:Protocol.PActor.id)
  return _internal_id();
}
inline void PActor::_internal_set_id(uint64_t value) {
  
  _impl_.id_ = value;
}
inline void PActor::set_id(uint64_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:Protocol.PActor.id)
}

// .Protocol.ActorType type = 2;
inline void PActor::clear_type() {
  _impl_.type_ = 0;
}
inline ::Protocol::ActorType PActor::_internal_type() const {
  return static_cast< ::Protocol::ActorType >(_impl_.type_);
}
inline ::Protocol::ActorType PActor::type() const {
  // @@protoc_insertion_point(field_get:Protocol.PActor.type)
  return _internal_type();
}
inline void PActor::_internal_set_type(::Protocol::ActorType value) {
  
  _impl_.type_ = value;
}
inline void PActor::set_type(::Protocol::ActorType value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:Protocol.PActor.type)
}

// .Protocol.Pos position = 3;
inline bool PActor::_internal_has_position() const {
  return this != internal_default_instance() && _impl_.position_ != nullptr;
}
inline bool PActor::has_position() const {
  return _internal_has_position();
}
inline void PActor::clear_position() {
  if (GetArenaForAllocation() == nullptr && _impl_.position_ != nullptr) {
    delete _impl_.position_;
  }
  _impl_.position_ = nullptr;
}
inline const ::Protocol::Pos& PActor::_internal_position() const {
  const ::Protocol::Pos* p = _impl_.position_;
  return p != nullptr ? *p : reinterpret_cast<const ::Protocol::Pos&>(
      ::Protocol::_Pos_default_instance_);
}
inline const ::Protocol::Pos& PActor::position() const {
  // @@protoc_insertion_point(field_get:Protocol.PActor.position)
  return _internal_position();
}
inline void PActor::unsafe_arena_set_allocated_position(
    ::Protocol::Pos* position) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.position_);
  }
  _impl_.position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Protocol.PActor.position)
}
inline ::Protocol::Pos* PActor::release_position() {
  
  ::Protocol::Pos* temp = _impl_.position_;
  _impl_.position_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::Protocol::Pos* PActor::unsafe_arena_release_position() {
  // @@protoc_insertion_point(field_release:Protocol.PActor.position)
  
  ::Protocol::Pos* temp = _impl_.position_;
  _impl_.position_ = nullptr;
  return temp;
}
inline ::Protocol::Pos* PActor::_internal_mutable_position() {
  
  if (_impl_.position_ == nullptr) {
    auto* p = CreateMaybeMessage<::Protocol::Pos>(GetArenaForAllocation());
    _impl_.position_ = p;
  }
  return _impl_.position_;
}
inline ::Protocol::Pos* PActor::mutable_position() {
  ::Protocol::Pos* _msg = _internal_mutable_position();
  // @@protoc_insertion_point(field_mutable:Protocol.PActor.position)
  return _msg;
}
inline void PActor::set_allocated_position(::Protocol::Pos* position) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.position_;
  }
  if (position) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(position);
    if (message_arena != submessage_arena) {
      position = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.position_ = position;
  // @@protoc_insertion_point(field_set_allocated:Protocol.PActor.position)
}

// .Protocol.Action action = 4;
inline void PActor::clear_action() {
  _impl_.action_ = 0;
}
inline ::Protocol::Action PActor::_internal_action() const {
  return static_cast< ::Protocol::Action >(_impl_.action_);
}
inline ::Protocol::Action PActor::action() const {
  // @@protoc_insertion_point(field_get:Protocol.PActor.action)
  return _internal_action();
}
inline void PActor::_internal_set_action(::Protocol::Action value) {
  
  _impl_.action_ = value;
}
inline void PActor::set_action(::Protocol::Action value) {
  _internal_set_action(value);
  // @@protoc_insertion_point(field_set:Protocol.PActor.action)
}

// optional .Protocol.PlayerType playerType = 5;
inline bool PActor::_internal_has_playertype() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool PActor::has_playertype() const {
  return _internal_has_playertype();
}
inline void PActor::clear_playertype() {
  _impl_.playertype_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::Protocol::PlayerType PActor::_internal_playertype() const {
  return static_cast< ::Protocol::PlayerType >(_impl_.playertype_);
}
inline ::Protocol::PlayerType PActor::playertype() const {
  // @@protoc_insertion_point(field_get:Protocol.PActor.playerType)
  return _internal_playertype();
}
inline void PActor::_internal_set_playertype(::Protocol::PlayerType value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.playertype_ = value;
}
inline void PActor::set_playertype(::Protocol::PlayerType value) {
  _internal_set_playertype(value);
  // @@protoc_insertion_point(field_set:Protocol.PActor.playerType)
}

// optional .Protocol.BlockType blockType = 6;
inline bool PActor::_internal_has_blocktype() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool PActor::has_blocktype() const {
  return _internal_has_blocktype();
}
inline void PActor::clear_blocktype() {
  _impl_.blocktype_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::Protocol::BlockType PActor::_internal_blocktype() const {
  return static_cast< ::Protocol::BlockType >(_impl_.blocktype_);
}
inline ::Protocol::BlockType PActor::blocktype() const {
  // @@protoc_insertion_point(field_get:Protocol.PActor.blockType)
  return _internal_blocktype();
}
inline void PActor::_internal_set_blocktype(::Protocol::BlockType value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.blocktype_ = value;
}
inline void PActor::set_blocktype(::Protocol::BlockType value) {
  _internal_set_blocktype(value);
  // @@protoc_insertion_point(field_set:Protocol.PActor.blockType)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_struct_2eproto