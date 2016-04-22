//
//  PlaceOrderTab.h
//  Zomato
//
//  Created by Nikunj on 14/02/15.
//  Copyright (c) 2015 Zomato Media Pvt. Ltd. All rights reserved.
//


#import "Restaurant.h"
#import "PlaceOrderTabOrder.h"
#import "DeliveryAddress.h"
@class PlaceOrderTab;

@class Restaurant;
@class DeliveryAddress;
@class PlaceOrderTabOrder;
@class UserDetail;
@class ZomatoOrder;

@protocol PlaceOrderTabDelegate <NSObject>

@optional
- (void) placeOrderTabFetchedSuccessfully;

@optional
- (void) placeOrderTabFetchingFailedWithError:(NSError *)error;

@end

typedef void(^CompletionHandlerForZomatoOrderObject)(NSError *error, PlaceOrderTab *zomatoOrderObject);

@interface PlaceOrderTab : ZomatoObject

@property (nonatomic, strong) NSString *tabId;
@property (nonatomic, strong) NSNumber *dominosOrderId;
@property (nonatomic, strong) NSNumber *status;
@property (nonatomic, strong) NSNumber *deliveryStatus;
@property (nonatomic, strong) NSString *statusText;
@property (nonatomic, strong) NSString *shortStatusText;
@property (nonatomic, strong) NSNumber *resTableId;
@property (nonatomic, strong) NSString *createdTimeString;
@property (nonatomic, strong) NSNumber *deliveredTimestamp;
@property (nonatomic, strong) NSNumber *covers;
@property (nonatomic, strong) NSString *billNumber;
@property (nonatomic, strong) NSString *currency;
@property (nonatomic, strong) NSString *currencyAffix;
@property (nonatomic, strong) DeliveryAddress *deliveryAddressObject;
@property (nonatomic, strong) NSString *deliveryPhoneNumber;
@property (nonatomic, strong) NSNumber *deliveryPhoneNumberCountryId;
@property (nonatomic, strong) NSNumber *deliveryPhoneNumberVerified;
@property (nonatomic, strong) NSString *specialInstructions;
@property (nonatomic, strong) NSString *addressSpecialInstructions;
@property (nonatomic, strong) NSString *dishesText;
@property (nonatomic, strong) NSMutableAttributedString *addressAttributedString;
@property (nonatomic, strong) NSNumber *isFavorite;
@property (nonatomic, strong) NSNumber *cityId;
@property (nonatomic , strong) NSNumber *totalCost;
@property (nonatomic, strong) NSNumber *yourDeliveryRating;
@property (nonatomic, strong) NSString *paymentMethodText;
@property (nonatomic, strong) NSNumber *paymentStatus;
@property (nonatomic, strong) NSString *deliveryModeString;

@property (nonatomic, strong) PlaceOrderTabOrder *order;
@property (nonatomic, strong) UserDetail *creator;
@property (nonatomic, strong) Restaurant *restaurant;
@property (nonatomic, weak) id<PlaceOrderTabDelegate> delegateVariable;
@property (nonatomic, strong) CompletionHandlerForZomatoOrderObject completionHandler;

- (void) fetchTabWithTabId:(NSString *)tabId withDelegate:(id<PlaceOrderTabDelegate>)delegate;

@end
