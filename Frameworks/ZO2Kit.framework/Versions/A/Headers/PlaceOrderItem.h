//
//  PlaceOrderItem.h
//  Zomato
//
//  Created by Nikunj on 13/02/15.
//  Copyright (c) 2015 Zomato Media Pvt. Ltd. All rights reserved.
//

#import "ZomatoObject.h"

#import "AllDeliveryCharge.h"
#import "DeliveryItem.h"

@class DeliveryItem;

@interface PlaceOrderItem : ZomatoObject

@property (nonatomic, strong) NSNumber *quantity;
@property (nonatomic, strong) NSMutableArray *groupsArray;
@property (nonatomic, strong) NSNumber *totalCost;
@property (nonatomic, strong) NSNumber *taxRate;
@property (nonatomic, strong) NSString *choiceText;
@property (nonatomic, strong) NSString *itemName;
@property (nonatomic, strong) NSNumber *unitCost;
@property (nonatomic, strong) NSString *comment;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSNumber *orderItemId;
@property (nonatomic, strong) NSNumber *oldUnitCost;
@property (nonatomic, strong) NSNumber *oldTotalCost;
@property (nonatomic, strong) NSNumber *itemUnavailable;
@property (nonatomic, strong) NSNumber *customizationsUnavailable;

@property (nonatomic) BOOL isVeg;
@property (nonatomic) BOOL isNonVeg;
@property (nonatomic) BOOL isAgeResticted;

- (id) initWithDeliveryCharge:(AllDeliveryCharge *)deliveryCharge;
- (id) initWithDeliveryItem:(DeliveryItem *)deliveryItem;
- (NSDictionary *)convertSelfToDictWithGroups;
+ (NSDictionary *)dictionaryWithDeliveryCharge:(AllDeliveryCharge *)deliveryCharge;
+ (NSDictionary *)dictionaryWithDeliveryItem:(DeliveryItem *)deliveryItem;

@end
