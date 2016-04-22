//
//  DeliveryAddress.h
//  Zomato
//
//  Created by Nikunj on 13/02/15.
//  Copyright (c) 2015 Zomato Media Pvt. Ltd. All rights reserved.
//


#import "ZomatoObject.h"

@interface DeliveryAddress : ZomatoObject

@property (nonatomic, strong) NSString *address;
@property (nonatomic, strong) NSString *alias;
@property (nonatomic, strong) NSNumber *deliverySubzoneID;
@property (nonatomic, strong) NSString *deliverySubzoneName;
@property (nonatomic, strong) NSString *deliverySubzoneFullName;
@property (nonatomic, strong) NSString *pinCode;
@property (nonatomic, strong) NSString *instructions;
@property (nonatomic, strong) NSNumber *isRestaurantDelivers;
@property (nonatomic) BOOL isSelected;
@property (nonatomic) BOOL doesDeliver;

@end
