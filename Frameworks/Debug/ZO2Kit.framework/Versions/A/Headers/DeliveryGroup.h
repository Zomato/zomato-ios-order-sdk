//
//  DeliveryGroup.h
//  Zomato
//
//  Created by Nikunj on 10/02/15.
//  Copyright (c) 2015 Zomato Media Pvt. Ltd. All rights reserved.
//


#import "DeliveryItem.h"
#import "ZomatoObject.h"

@interface DeliveryGroup : ZomatoObject<NSCopying>

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *label;
@property (nonatomic, strong) NSNumber *min;
@property (nonatomic, strong) NSNumber *max;
@property (nonatomic, strong) NSString *suggestText;
@property (nonatomic, strong) NSMutableArray *itemsArray;

@end
