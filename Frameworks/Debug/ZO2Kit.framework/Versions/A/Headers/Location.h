//
//  Location.h
//  RestKitUtilityAndTest
//
//  Created by Arup Saha on 17/05/12.
//  Copyright (c) 2012 Zomato Media Pvt. Ltd. All rights reserved.
//

#import "ZomatoObject.h"

@interface Location : ZomatoObject <NSCoding> {
    
}

@property (nonatomic, strong) NSString* address;
@property (nonatomic, strong) NSString* zipcode;
@property (nonatomic, strong) NSString* locality;
@property (nonatomic, strong) NSString* city;
@property (nonatomic, strong) NSString* lat;
@property (nonatomic, strong) NSString* lon;
@property (nonatomic, strong) NSNumber* cityId;
@property (nonatomic,strong) NSNumber *isGroup;
@property (nonatomic, strong) NSString *groupName;
@property (nonatomic, strong) NSNumber *countryId;

@end
