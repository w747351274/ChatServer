// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers_RuntimeSupport.h>
#else
 #import "GPBProtocolBuffers_RuntimeSupport.h"
#endif

#import <stdatomic.h>

#import "Chat.pbobjc.h"
// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#pragma mark - ChatRoot

@implementation ChatRoot

// No extensions in the file and no imports, so no need to generate
// +extensionRegistry.

@end

#pragma mark - ChatRoot_FileDescriptor

static GPBFileDescriptor *ChatRoot_FileDescriptor(void) {
  // This is called by +initialize so there is no need to worry
  // about thread safety of the singleton.
  static GPBFileDescriptor *descriptor = NULL;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    descriptor = [[GPBFileDescriptor alloc] initWithPackage:@"com.tencent.mars.sample.chat.proto"
                                                     syntax:GPBFileSyntaxProto2];
  }
  return descriptor;
}

#pragma mark - SendMessageRequest

@implementation SendMessageRequest

@dynamic hasAccessToken, accessToken;
@dynamic hasFrom, from;
@dynamic hasTo, to;
@dynamic hasText, text;
@dynamic hasTopic, topic;

typedef struct SendMessageRequest__storage_ {
  uint32_t _has_storage_[1];
  NSString *accessToken;
  NSString *from;
  NSString *to;
  NSString *text;
  NSString *topic;
} SendMessageRequest__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "accessToken",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageRequest_FieldNumber_AccessToken,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(SendMessageRequest__storage_, accessToken),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
      {
        .name = "from",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageRequest_FieldNumber_From,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(SendMessageRequest__storage_, from),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
      {
        .name = "to",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageRequest_FieldNumber_To,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(SendMessageRequest__storage_, to),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
      {
        .name = "text",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageRequest_FieldNumber_Text,
        .hasIndex = 3,
        .offset = (uint32_t)offsetof(SendMessageRequest__storage_, text),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
      {
        .name = "topic",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageRequest_FieldNumber_Topic,
        .hasIndex = 4,
        .offset = (uint32_t)offsetof(SendMessageRequest__storage_, topic),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[SendMessageRequest class]
                                     rootClass:[ChatRoot class]
                                          file:ChatRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(SendMessageRequest__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - SendMessageResponse

@implementation SendMessageResponse

@dynamic hasErrCode, errCode;
@dynamic hasErrMsg, errMsg;
@dynamic hasFrom, from;
@dynamic hasText, text;
@dynamic hasTopic, topic;

typedef struct SendMessageResponse__storage_ {
  uint32_t _has_storage_[1];
  int32_t errCode;
  NSString *errMsg;
  NSString *from;
  NSString *text;
  NSString *topic;
} SendMessageResponse__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "errCode",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageResponse_FieldNumber_ErrCode,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(SendMessageResponse__storage_, errCode),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeInt32,
      },
      {
        .name = "errMsg",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageResponse_FieldNumber_ErrMsg,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(SendMessageResponse__storage_, errMsg),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
      {
        .name = "from",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageResponse_FieldNumber_From,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(SendMessageResponse__storage_, from),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
      {
        .name = "text",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageResponse_FieldNumber_Text,
        .hasIndex = 3,
        .offset = (uint32_t)offsetof(SendMessageResponse__storage_, text),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
      {
        .name = "topic",
        .dataTypeSpecific.className = NULL,
        .number = SendMessageResponse_FieldNumber_Topic,
        .hasIndex = 4,
        .offset = (uint32_t)offsetof(SendMessageResponse__storage_, topic),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeString,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[SendMessageResponse class]
                                     rootClass:[ChatRoot class]
                                          file:ChatRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(SendMessageResponse__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum SendMessageResponse_Error

GPBEnumDescriptor *SendMessageResponse_Error_EnumDescriptor(void) {
  static _Atomic(GPBEnumDescriptor*) descriptor = nil;
  if (!descriptor) {
    static const char *valueNames =
        "ErrOk\000ErrSys\000";
    static const int32_t values[] = {
        SendMessageResponse_Error_ErrOk,
        SendMessageResponse_Error_ErrSys,
    };
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(SendMessageResponse_Error)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:SendMessageResponse_Error_IsValidValue];
    GPBEnumDescriptor *expected = nil;
    if (!atomic_compare_exchange_strong(&descriptor, &expected, worker)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL SendMessageResponse_Error_IsValidValue(int32_t value__) {
  switch (value__) {
    case SendMessageResponse_Error_ErrOk:
    case SendMessageResponse_Error_ErrSys:
      return YES;
    default:
      return NO;
  }
}


#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
