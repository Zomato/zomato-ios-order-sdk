//
//  ZomatoObject.h
//  RestKitUtilityAndTest
//
//  Created by Arup Saha on 16/05/12.
//  Copyright (c) 2012 Zomato Media Pvt. Ltd. All rights reserved.
//

#define SUCCESSFUL RKStatusCodeIndexSetForClass(RKStatusCodeClassSuccessful)
#import <Foundation/Foundation.h>
#import "NSNull+NSNull_Nil.h"
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ApiCallPriority) {
    ApiCallPriorityLow,
    ApiCallPriorityMedium,
    ApiCallPriorityHigh
};

@class ZomatoObject;
@interface ZomatoObject : NSObject <NSCopying>

@property (nonatomic, strong) NSNumber *zid;
@property (nonatomic, strong) NSNumber *unixTimeStamp;


- (NSString *) inspect;

- (void) setUnixTimeStamp:(NSNumber *)timeStamp;
- (NSNumber *) unixTimeStamp;
- (BOOL) isObjectWithSameZid : (ZomatoObject *) zObject;

/*=========================================== Z11 ============================================*/
- (void) parseObject:(NSDictionary *)responseObject withInitialParams:(NSDictionary *)params;
+ (NSInteger) getRetryCount;
+ (NSString *) getAPIPath;
+ (NSString *) getAPIPathWithParams:(NSDictionary *)params;
- (NSString *) getStringForKey:(NSString *)key fromDictionary:(NSDictionary *)dictionary withInitialValue:(NSString *)initialValue;
- (NSNumber *) getNumberForKey:(NSString *)key fromDictionary:(NSDictionary *)dictionary withInitialValue:(NSNumber *)initialValue;
- (ApiCallPriority) getApiCallPriorityWithParams:(NSDictionary *)params;

- (void)copyToZomatoObject:(ZomatoObject *)zomatoObject;

@end
