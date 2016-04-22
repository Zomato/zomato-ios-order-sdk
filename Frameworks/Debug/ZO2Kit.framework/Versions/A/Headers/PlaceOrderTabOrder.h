//
//  PlaceOrderTabOrder.h
//  Zomato
//
//  Created by Nikunj on 14/02/15.
//  Copyright (c) 2015 Zomato Media Pvt. Ltd. All rights reserved.
//


#import "PlaceOrderItem.h"

@interface PlaceOrderTabOrder : ZomatoObject

@property (nonatomic, strong) NSNumber *totalCost;
@property (nonatomic, strong) NSMutableArray *itemsArray;

@end
