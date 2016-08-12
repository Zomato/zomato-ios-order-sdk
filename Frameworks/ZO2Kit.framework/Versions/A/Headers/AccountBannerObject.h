//
//  AccountBannerObject.h
//  Zomato
//
//  Created by Nikunj on 07/12/15.
//  Copyright © 2015 Zomato Media Pvt. Ltd. All rights reserved.
//

#import "ZomatoObject.h"
#import "DeliveryItem.h"

extern NSString * const AccountBannerObjectTypeExpressItem;
extern NSString * const AccountBannerObjectTypeRestaurantBanner;

@interface AccountBannerObject : ZomatoObject


@property (nonatomic, strong) NSString *imageUrl;       //Required
@property (nonatomic, strong) NSString *title;          //Required
@property (nonatomic, strong) NSString *subtitle;       //Optional
@property (nonatomic, strong) NSString *actionButtonText;
@property (nonatomic, strong) NSString *deeplinkUrl;    //Required
@property (nonatomic, strong) NSNumber *hasNoOverlay;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *buttonText;
@property (nonatomic, strong) NSString *tagline;        //Required

@property (nonatomic, strong) DeliveryItem *itemObject;

@end
