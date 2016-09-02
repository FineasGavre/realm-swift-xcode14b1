////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import "RLMSyncSession.h"

#import "RLMSyncUtil_Private.h"

@class RLMUser;

@interface RLMRealmBindingPackage : NSObject

NS_ASSUME_NONNULL_BEGIN

@property (nullable, nonatomic, copy) RLMErrorReportingBlock block;
@property (nonatomic) NSURL *fileURL;
@property (nonatomic) NSURL *realmURL;

- (instancetype)initWithFileURL:(NSURL *)fileURL
                       realmURL:(NSURL *)realmURL
                          block:(nullable RLMErrorReportingBlock)block;

@end

@interface RLMSyncSession ()

- (void)_refresh;
- (void)_invalidate;

- (void)setState:(RLMSyncSessionState)state;

/// The path on disk where the Realm file backing this synced Realm is stored.
@property (nonatomic) NSURL *fileURL;

@property (nullable, nonatomic) RLMRealmBindingPackage *deferredBindingPackage;
@property (nullable, nonatomic) RLMServerPath resolvedPath;

- (instancetype)initWithFileURL:(NSURL *)fileURL realmURL:(NSURL *)realmURL NS_DESIGNATED_INITIALIZER;

#pragma mark - per-Realm access token API

@property (nullable, nonatomic) RLMServerToken accessToken;
@property (nonatomic) NSTimeInterval accessTokenExpiry;

@property (nonatomic) NSTimer *refreshTimer;

- (void)configureWithAccessToken:(RLMServerToken)token expiry:(NSTimeInterval)expiry user:(RLMUser *)user;

NS_ASSUME_NONNULL_END

@end