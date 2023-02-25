// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: enum.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_enum_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_enum_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021008 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_enum_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_enum_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_enum_2eproto;
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

enum ActorType : int {
  ACTOR_TYPE_NONE = 0,
  ACTOR_TYPE_BG = 1,
  ACTOR_TYPE_PLAYER = 2,
  ACTOR_TYPE_BLOCK = 3,
  ACTOR_TYPE_BOMB = 4,
  ActorType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  ActorType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool ActorType_IsValid(int value);
constexpr ActorType ActorType_MIN = ACTOR_TYPE_NONE;
constexpr ActorType ActorType_MAX = ACTOR_TYPE_BOMB;
constexpr int ActorType_ARRAYSIZE = ActorType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ActorType_descriptor();
template<typename T>
inline const std::string& ActorType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ActorType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ActorType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ActorType_descriptor(), enum_t_value);
}
inline bool ActorType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ActorType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ActorType>(
    ActorType_descriptor(), name, value);
}
enum PlayerType : int {
  PLAYER_TYPE_NONE = 0,
  PLAYER_TYPE_BAZZI = 1,
  PLAYER_TYPE_DAO = 2,
  PlayerType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PlayerType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PlayerType_IsValid(int value);
constexpr PlayerType PlayerType_MIN = PLAYER_TYPE_NONE;
constexpr PlayerType PlayerType_MAX = PLAYER_TYPE_DAO;
constexpr int PlayerType_ARRAYSIZE = PlayerType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PlayerType_descriptor();
template<typename T>
inline const std::string& PlayerType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PlayerType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PlayerType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PlayerType_descriptor(), enum_t_value);
}
inline bool PlayerType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PlayerType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PlayerType>(
    PlayerType_descriptor(), name, value);
}
enum BlockType : int {
  BLOCK_TYPE_NONE = 0,
  BLOCK_TYPE_BUSH1 = 3,
  BLOCK_TYPE_BUSH2 = 4,
  BLOCK_TYPE_BUSH3 = 8,
  BLOCK_TYPE_BUSH4 = 9,
  BLOCK_TYPE_BUSH5 = 16,
  BLOCK_TYPE_BUSH6 = 17,
  BLOCK_TYPE_BUSH7 = 18,
  BlockType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  BlockType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool BlockType_IsValid(int value);
constexpr BlockType BlockType_MIN = BLOCK_TYPE_NONE;
constexpr BlockType BlockType_MAX = BLOCK_TYPE_BUSH7;
constexpr int BlockType_ARRAYSIZE = BlockType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BlockType_descriptor();
template<typename T>
inline const std::string& BlockType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, BlockType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function BlockType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    BlockType_descriptor(), enum_t_value);
}
inline bool BlockType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, BlockType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<BlockType>(
    BlockType_descriptor(), name, value);
}
enum Action : int {
  ACTION_NONE = 0,
  ACTION_UP = 1,
  ACTION_DOWN = 2,
  ACTION_LEFT = 3,
  ACTION_RIGHT = 4,
  ACTION_STOP = 5,
  Action_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  Action_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool Action_IsValid(int value);
constexpr Action Action_MIN = ACTION_NONE;
constexpr Action Action_MAX = ACTION_STOP;
constexpr int Action_ARRAYSIZE = Action_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Action_descriptor();
template<typename T>
inline const std::string& Action_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Action>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Action_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Action_descriptor(), enum_t_value);
}
inline bool Action_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Action* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Action>(
    Action_descriptor(), name, value);
}
enum BroadCastType : int {
  BROADCAST_NONE = 0,
  BROADCAST_ENTER_GAME = 1,
  BROADCAST_LEAVE_GAME = 2,
  BROADCAST_ACTION = 3,
  BROADCAST_DIE = 4,
  BroadCastType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  BroadCastType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool BroadCastType_IsValid(int value);
constexpr BroadCastType BroadCastType_MIN = BROADCAST_NONE;
constexpr BroadCastType BroadCastType_MAX = BROADCAST_DIE;
constexpr int BroadCastType_ARRAYSIZE = BroadCastType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BroadCastType_descriptor();
template<typename T>
inline const std::string& BroadCastType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, BroadCastType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function BroadCastType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    BroadCastType_descriptor(), enum_t_value);
}
inline bool BroadCastType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, BroadCastType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<BroadCastType>(
    BroadCastType_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Protocol::ActorType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::ActorType>() {
  return ::Protocol::ActorType_descriptor();
}
template <> struct is_proto_enum< ::Protocol::PlayerType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::PlayerType>() {
  return ::Protocol::PlayerType_descriptor();
}
template <> struct is_proto_enum< ::Protocol::BlockType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::BlockType>() {
  return ::Protocol::BlockType_descriptor();
}
template <> struct is_proto_enum< ::Protocol::Action> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::Action>() {
  return ::Protocol::Action_descriptor();
}
template <> struct is_proto_enum< ::Protocol::BroadCastType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::BroadCastType>() {
  return ::Protocol::BroadCastType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_enum_2eproto