
## Quick Start

####  1. Add following line in your Podfile
    pod 'zomato-ios-order-sdk'
#### 2.  Now run following command in your terminal
    pod install

* * *


## Initializing SDK

* ###   In Application's AppDelegate
		#import <ZO2Kit/ZOnlineOrderManager.h>    

* ### In didFinishLaunchingWithOptions initialize SDK
		 [ZOnlineOrderManager setAPIKey:@"orderingsdkapikey" andAPISecret:@"secretkey"];

* ### To set background color of Navigation bar,  pass color value in this function
		[ZOnlineOrderManager setThemeColor:0xcb202d];


	 *Note: The text color of Navigation bar items is white.*

* ### To set background color of Bottom Buttons, pass color value in this function
		 [ZOnlineOrderManager setBottomBarColor:0x099e44];

* ### Now when you want to place order pass your phone number in this function

  * #### For Modal Present

		 [[ZOnlineOrderManager sharedInitializer] startOnlineOrderWithPhoneNumber:@"phone-number-10-digit" viewController:self];
		 
  * #### For Navigation Push
		[[ZOnlineOrderManager sharedInitializer] startOnlineOrderWithPhoneNumber:@"phone-number-10-digit" pushOnNavViewController:self.navigationController];

* ### When order will be placed you will receive a notification with PlaceOrderTab Object inside it.

		extern NSString *const zOrderPlaced;

* ### When order status will change you will receive a notification with PlaceOrderTab Object inside it.

		extern NSString *const zOrderStatusChanged;

* ### To open order detail pass order id in the following function
		[[ZOnlineOrderManager sharedInitializer] showOrderDetailViewControllerForOrderID:@"<order-id-string>" viewController:self];




* ### To remove all user logs
		[ZOnlineOrderManager invalidate];

* ### _PlaceOrderTab Object reference:_

		PlaceOrderTabObject.tabId : To get orderId

		PlaceOrderTabObject.statusText : To get Order Status

		PlaceOrderTabObject.createdTimeString : To get order Timing

		PlaceOrderTabObject.restaurant.name : To get Restaurant Name

		PlaceOrderTabObject.restaurant.location.locality : To get Restaurant Subzone

		PlaceOrderTabObject.restaurant.restThumbURL : To get Restaurant image
		
		PlaceOrderTabObject.order.itemsArray : An array of PlaceOrderItem objects


* #### _PlaceOrderItem Object :_
		
	    PlaceOrderItem object has 'type' property which can take one of following values:
			"dish" : food item 
	
			"subtotal2" : subtotal (sum of the price of all dishes, without taxes or charges)

			"tax" : tax (eg. VAT, Service Tax)

			"charge" : extra charge (eg. Packaging Charge)

			"extra" : extra charge (eg. Delivery Charge)

			"voucher_discount" : discount given after applying any promo code

			"dominos_coupon" :  discount given on orders placed at Domino’s after applying any promo code

			"salt_discount", "salt_discounts" : discount automatically given by the merchant

			"total_merchant" : amount charged by the merchant ( (subtotal2 + taxes + charges)- promo discount given by merchant [salt_discount])

			"total", "total_user" : amount charged to the user (total_merchant - promo discount after applying code [voucher_discount])


		Other properties of PlaceOrderItem object are: 
			quantity
			totalCost
			itemName
			unitCost

