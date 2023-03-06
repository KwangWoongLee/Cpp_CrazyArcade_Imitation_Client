// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: match.proto

#include "match.pb.h"
#include "match.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

static const char* MatchService_method_names[] = {
  "/MatchService/GetRoomList",
  "/MatchService/CreateRoom",
  "/MatchService/EnterRoom",
  "/MatchService/LeaveRoom",
  "/MatchService/StartGame",
  "/MatchService/CreateRoomTCP",
  "/MatchService/RegistServer",
  "/MatchService/RemoveServer",
};

std::unique_ptr< MatchService::Stub> MatchService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< MatchService::Stub> stub(new MatchService::Stub(channel, options));
  return stub;
}

MatchService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetRoomList_(MatchService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CreateRoom_(MatchService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_EnterRoom_(MatchService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_LeaveRoom_(MatchService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_StartGame_(MatchService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CreateRoomTCP_(MatchService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_RegistServer_(MatchService_method_names[6], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RemoveServer_(MatchService_method_names[7], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status MatchService::Stub::GetRoomList(::grpc::ClientContext* context, const ::GetRoomListRequest& request, ::GetRoomListResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::GetRoomListRequest, ::GetRoomListResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetRoomList_, context, request, response);
}

void MatchService::Stub::async::GetRoomList(::grpc::ClientContext* context, const ::GetRoomListRequest* request, ::GetRoomListResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::GetRoomListRequest, ::GetRoomListResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetRoomList_, context, request, response, std::move(f));
}

void MatchService::Stub::async::GetRoomList(::grpc::ClientContext* context, const ::GetRoomListRequest* request, ::GetRoomListResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetRoomList_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GetRoomListResponse>* MatchService::Stub::PrepareAsyncGetRoomListRaw(::grpc::ClientContext* context, const ::GetRoomListRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::GetRoomListResponse, ::GetRoomListRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetRoomList_, context, request);
}

::grpc::ClientAsyncResponseReader< ::GetRoomListResponse>* MatchService::Stub::AsyncGetRoomListRaw(::grpc::ClientContext* context, const ::GetRoomListRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRoomListRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MatchService::Stub::CreateRoom(::grpc::ClientContext* context, const ::CreateRoomRequest& request, ::CreateRoomResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::CreateRoomRequest, ::CreateRoomResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CreateRoom_, context, request, response);
}

void MatchService::Stub::async::CreateRoom(::grpc::ClientContext* context, const ::CreateRoomRequest* request, ::CreateRoomResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::CreateRoomRequest, ::CreateRoomResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreateRoom_, context, request, response, std::move(f));
}

void MatchService::Stub::async::CreateRoom(::grpc::ClientContext* context, const ::CreateRoomRequest* request, ::CreateRoomResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreateRoom_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::CreateRoomResponse>* MatchService::Stub::PrepareAsyncCreateRoomRaw(::grpc::ClientContext* context, const ::CreateRoomRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::CreateRoomResponse, ::CreateRoomRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CreateRoom_, context, request);
}

::grpc::ClientAsyncResponseReader< ::CreateRoomResponse>* MatchService::Stub::AsyncCreateRoomRaw(::grpc::ClientContext* context, const ::CreateRoomRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateRoomRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MatchService::Stub::EnterRoom(::grpc::ClientContext* context, const ::EnterRoomRequest& request, ::EnterRoomResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::EnterRoomRequest, ::EnterRoomResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_EnterRoom_, context, request, response);
}

void MatchService::Stub::async::EnterRoom(::grpc::ClientContext* context, const ::EnterRoomRequest* request, ::EnterRoomResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::EnterRoomRequest, ::EnterRoomResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_EnterRoom_, context, request, response, std::move(f));
}

void MatchService::Stub::async::EnterRoom(::grpc::ClientContext* context, const ::EnterRoomRequest* request, ::EnterRoomResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_EnterRoom_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::EnterRoomResponse>* MatchService::Stub::PrepareAsyncEnterRoomRaw(::grpc::ClientContext* context, const ::EnterRoomRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::EnterRoomResponse, ::EnterRoomRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_EnterRoom_, context, request);
}

::grpc::ClientAsyncResponseReader< ::EnterRoomResponse>* MatchService::Stub::AsyncEnterRoomRaw(::grpc::ClientContext* context, const ::EnterRoomRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncEnterRoomRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MatchService::Stub::LeaveRoom(::grpc::ClientContext* context, const ::LeaveRoomRequest& request, ::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::LeaveRoomRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_LeaveRoom_, context, request, response);
}

void MatchService::Stub::async::LeaveRoom(::grpc::ClientContext* context, const ::LeaveRoomRequest* request, ::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::LeaveRoomRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_LeaveRoom_, context, request, response, std::move(f));
}

void MatchService::Stub::async::LeaveRoom(::grpc::ClientContext* context, const ::LeaveRoomRequest* request, ::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_LeaveRoom_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Response>* MatchService::Stub::PrepareAsyncLeaveRoomRaw(::grpc::ClientContext* context, const ::LeaveRoomRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Response, ::LeaveRoomRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_LeaveRoom_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Response>* MatchService::Stub::AsyncLeaveRoomRaw(::grpc::ClientContext* context, const ::LeaveRoomRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncLeaveRoomRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MatchService::Stub::StartGame(::grpc::ClientContext* context, const ::StartGameRequest& request, ::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::StartGameRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_StartGame_, context, request, response);
}

void MatchService::Stub::async::StartGame(::grpc::ClientContext* context, const ::StartGameRequest* request, ::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::StartGameRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_StartGame_, context, request, response, std::move(f));
}

void MatchService::Stub::async::StartGame(::grpc::ClientContext* context, const ::StartGameRequest* request, ::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_StartGame_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Response>* MatchService::Stub::PrepareAsyncStartGameRaw(::grpc::ClientContext* context, const ::StartGameRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Response, ::StartGameRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_StartGame_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Response>* MatchService::Stub::AsyncStartGameRaw(::grpc::ClientContext* context, const ::StartGameRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncStartGameRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReaderWriter< ::CreateRoomTCPRequest, ::CreateRoomTCPResponse>* MatchService::Stub::CreateRoomTCPRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::CreateRoomTCPRequest, ::CreateRoomTCPResponse>::Create(channel_.get(), rpcmethod_CreateRoomTCP_, context);
}

void MatchService::Stub::async::CreateRoomTCP(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::CreateRoomTCPRequest,::CreateRoomTCPResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::CreateRoomTCPRequest,::CreateRoomTCPResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_CreateRoomTCP_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::CreateRoomTCPRequest, ::CreateRoomTCPResponse>* MatchService::Stub::AsyncCreateRoomTCPRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::CreateRoomTCPRequest, ::CreateRoomTCPResponse>::Create(channel_.get(), cq, rpcmethod_CreateRoomTCP_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::CreateRoomTCPRequest, ::CreateRoomTCPResponse>* MatchService::Stub::PrepareAsyncCreateRoomTCPRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::CreateRoomTCPRequest, ::CreateRoomTCPResponse>::Create(channel_.get(), cq, rpcmethod_CreateRoomTCP_, context, false, nullptr);
}

::grpc::Status MatchService::Stub::RegistServer(::grpc::ClientContext* context, const ::RegistServerRequest& request, ::RegistServerResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::RegistServerRequest, ::RegistServerResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RegistServer_, context, request, response);
}

void MatchService::Stub::async::RegistServer(::grpc::ClientContext* context, const ::RegistServerRequest* request, ::RegistServerResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::RegistServerRequest, ::RegistServerResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RegistServer_, context, request, response, std::move(f));
}

void MatchService::Stub::async::RegistServer(::grpc::ClientContext* context, const ::RegistServerRequest* request, ::RegistServerResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RegistServer_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::RegistServerResponse>* MatchService::Stub::PrepareAsyncRegistServerRaw(::grpc::ClientContext* context, const ::RegistServerRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::RegistServerResponse, ::RegistServerRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RegistServer_, context, request);
}

::grpc::ClientAsyncResponseReader< ::RegistServerResponse>* MatchService::Stub::AsyncRegistServerRaw(::grpc::ClientContext* context, const ::RegistServerRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRegistServerRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MatchService::Stub::RemoveServer(::grpc::ClientContext* context, const ::RemoveServerRequest& request, ::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::RemoveServerRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RemoveServer_, context, request, response);
}

void MatchService::Stub::async::RemoveServer(::grpc::ClientContext* context, const ::RemoveServerRequest* request, ::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::RemoveServerRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveServer_, context, request, response, std::move(f));
}

void MatchService::Stub::async::RemoveServer(::grpc::ClientContext* context, const ::RemoveServerRequest* request, ::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveServer_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Response>* MatchService::Stub::PrepareAsyncRemoveServerRaw(::grpc::ClientContext* context, const ::RemoveServerRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Response, ::RemoveServerRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RemoveServer_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Response>* MatchService::Stub::AsyncRemoveServerRaw(::grpc::ClientContext* context, const ::RemoveServerRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRemoveServerRaw(context, request, cq);
  result->StartCall();
  return result;
}

MatchService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MatchService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MatchService::Service, ::GetRoomListRequest, ::GetRoomListResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MatchService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::GetRoomListRequest* req,
             ::GetRoomListResponse* resp) {
               return service->GetRoomList(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MatchService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MatchService::Service, ::CreateRoomRequest, ::CreateRoomResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MatchService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::CreateRoomRequest* req,
             ::CreateRoomResponse* resp) {
               return service->CreateRoom(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MatchService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MatchService::Service, ::EnterRoomRequest, ::EnterRoomResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MatchService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::EnterRoomRequest* req,
             ::EnterRoomResponse* resp) {
               return service->EnterRoom(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MatchService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MatchService::Service, ::LeaveRoomRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MatchService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::LeaveRoomRequest* req,
             ::Response* resp) {
               return service->LeaveRoom(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MatchService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MatchService::Service, ::StartGameRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MatchService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::StartGameRequest* req,
             ::Response* resp) {
               return service->StartGame(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MatchService_method_names[5],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< MatchService::Service, ::CreateRoomTCPRequest, ::CreateRoomTCPResponse>(
          [](MatchService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::CreateRoomTCPResponse,
             ::CreateRoomTCPRequest>* stream) {
               return service->CreateRoomTCP(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MatchService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MatchService::Service, ::RegistServerRequest, ::RegistServerResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MatchService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::RegistServerRequest* req,
             ::RegistServerResponse* resp) {
               return service->RegistServer(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MatchService_method_names[7],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MatchService::Service, ::RemoveServerRequest, ::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MatchService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::RemoveServerRequest* req,
             ::Response* resp) {
               return service->RemoveServer(ctx, req, resp);
             }, this)));
}

MatchService::Service::~Service() {
}

::grpc::Status MatchService::Service::GetRoomList(::grpc::ServerContext* context, const ::GetRoomListRequest* request, ::GetRoomListResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MatchService::Service::CreateRoom(::grpc::ServerContext* context, const ::CreateRoomRequest* request, ::CreateRoomResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MatchService::Service::EnterRoom(::grpc::ServerContext* context, const ::EnterRoomRequest* request, ::EnterRoomResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MatchService::Service::LeaveRoom(::grpc::ServerContext* context, const ::LeaveRoomRequest* request, ::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MatchService::Service::StartGame(::grpc::ServerContext* context, const ::StartGameRequest* request, ::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MatchService::Service::CreateRoomTCP(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::CreateRoomTCPResponse, ::CreateRoomTCPRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MatchService::Service::RegistServer(::grpc::ServerContext* context, const ::RegistServerRequest* request, ::RegistServerResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MatchService::Service::RemoveServer(::grpc::ServerContext* context, const ::RemoveServerRequest* request, ::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

