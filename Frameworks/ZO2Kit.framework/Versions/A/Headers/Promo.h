//
//  Promo.h
//  Zomato
//
//  Created by Nikunj on 13/11/14.
//  Copyright (c) 2014 Zomato Media Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZomatoObject.h"

@class Restaurant;

@interface Promo : ZomatoObject<NSCoding>

@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSNumber *restaurantId;
@property (nonatomic, strong) NSString *summary;
@property (nonatomic, strong) NSNumber *promoId;
@property (nonatomic, strong) NSNumber *status;
@property (nonatomic, strong) NSString *startDate;
@property (nonatomic, strong) NSString *endDate;
@property (nonatomic, strong) NSString *disclaimer;
@property (nonatomic, strong) NSNumber *isOfferSaved;
@property (nonatomic, strong) NSNumber *isExpired;
@property (nonatomic, strong) NSNumber *isActive;
@property (nonatomic, strong) Restaurant *restaurant;
@property (nonatomic, strong) NSString *offerType;
@property (nonatomic, strong) NSNumber *typeCode;

@end
