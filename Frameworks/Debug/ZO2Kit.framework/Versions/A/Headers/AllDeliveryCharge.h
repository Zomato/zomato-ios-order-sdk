//
//  AllDeliveryCharge.h
//  Zomato
//
//  Created by Nikunj on 12/02/15.
//  Copyright (c) 2015 Zomato Media Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AllDeliveryCharge : NSObject

@property (nonatomic, strong) NSNumber *taxRate;
@property (nonatomic, strong) NSNumber *primaryId;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSNumber *price;

- (id) initWithType:(NSString *)type withText:(NSString *)text withPrice:(double)price withPrimaryId:(NSNumber *)primaryId withTaxRate:(NSNumber *)taxRate;

@end
