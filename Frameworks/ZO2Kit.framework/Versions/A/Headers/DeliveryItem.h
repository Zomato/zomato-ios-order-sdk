//
//  DeliveryItem.h
//  Zomato
//
//  Created by Nikunj on 10/02/15.
//  Copyright (c) 2015 Zomato Media Pvt. Ltd. All rights reserved.
//


#import "ZomatoObject.h"

#import "DeliveryGroup.h"

#define ICON_LABEL_WIDTH    20

@interface DeliveryItem : ZomatoObject<NSCopying>

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, strong) NSString *desc;
@property (nonatomic, strong) NSNumber *minPrice;
@property (nonatomic, strong) NSNumber *maxPrice;
@property (nonatomic, strong) NSNumber *taxId;
@property (nonatomic, strong) NSNumber *unitPrice;
@property (nonatomic, strong) NSNumber *totalPrice;
@property (nonatomic) BOOL isVeg;
@property (nonatomic) BOOL isNonVeg;
@property (nonatomic) BOOL isAgeRestricted;
@property (nonatomic, strong) NSMutableArray *tagsArray;
@property (nonatomic) NSInteger count;
@property (nonatomic) BOOL isSelected;
@property (nonatomic, strong) NSMutableArray *groupsArray;
@property (nonatomic) CGFloat deliveryItemHeightWithNormalWidth;
@property (nonatomic) CGFloat deliveryItemHeightWithLessWidth;
@property (nonatomic, strong) NSNumber *isOnMRP;
@property (nonatomic, strong) NSNumber *taxInclusive;
@property (nonatomic, strong) NSNumber *isDefault;
@property (nonatomic, strong) NSString *currency;
@property (nonatomic, strong) NSString *currencyAffix;
@property (nonatomic, strong) NSString *serves;
@property (nonatomic) BOOL isAnyItemInMenuVegOrNonVeg;

@end
